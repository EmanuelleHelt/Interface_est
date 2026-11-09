/*
 * ===============================================================
 *                      mainwindow.cpp
 * ===============================================================
 *
 * Autor: Danilo Molina e Julio Cesar S. Fernandes
 * Coautor: Emanuelle Helt
 * Última Atualização: Nov-2026
 * Versão: 1.1
 *
 * Target/Board
 * - Estimulador Elétrico v7 (Brasil)
 *
 * Descrição:
 * - Implementação da lógica principal. O método send_parameters()
 *   monta e envia os vetores de estimulação para a placa.
 *
 * Dependências:
 * - "ES_UdpClient.h", "Aud_UdpClient.h", etc.
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QScrollArea>
#include <QTabBar>
#include <QTabWidget>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyle>
#include <QTimer>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <cmath>
#include <vector>

// Módulos de Comunicação
#include "ES_UdpClient.h"
#include "ES_WiFiClient.h"
#include "Aud_UdpClient.h"

// Interface e Modelos
#include "components/side/sidePanel.h"
#include "patient.h"
#include "session.h"
#include "patientRepository.h"
#include "sessionRepository.h"
#include "protocolSelector.h"
#include "durationPanel.h"
#include "channelPanel.h"
#include "sideBar.h"
#include "patientPanel.h"

#define PI 3.14159265

// =========================================================
// CONSTRUTOR / DESTRUTOR
// =========================================================

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , comm(new ES_UdpClient)
    , comm_aud(new Aud_UdpClient)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->loadProtocol->setCheckable(false);
    ui->loadProtocol->setText("Carregar protocolo");

    // Configuração dos Clientes UDP
    LogType level = ERRO;
    comm->SetLogLevel(level);
    comm->esConfig();
    comm->esStart();

    comm_aud->SetLogLevel(level);
    comm_aud->esConfig();
    comm_aud->esStart();
    aud_testar_conexao();

    // Timers
    timerAudio = new QTimer(this);
    connect(timerAudio, &QTimer::timeout, this, &MainWindow::verificarPedidoAudio);

    // Conexões de Botões Base
    connect(ui->testeCanais_pushButton, &QPushButton::clicked, this, &MainWindow::test_connection);
    connect(ui->iniciarEstimulo_pushButton, &QPushButton::clicked, this, &MainWindow::startStimulations);
    connect(ui->pararEstimulo_pushButton, &QPushButton::clicked, this, &MainWindow::stopStimulations);

    // Inicialização da UI
    configurarMenuLateral();
    integrarPaineisCanais();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete comm;
    delete comm_aud; // Corrigido: Estava faltando deletar o cliente auditivo.
}

// =========================================================
// CONFIGURAÇÃO DE INTERFACE
// =========================================================

void MainWindow::configurarMenuLateral()
{
    sidebar = new sideBar(this);
    QDockWidget *sidebarDock = new QDockWidget(this);

    sidebarDock->setWidget(sidebar);
    sidebarDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    sidebarDock->setTitleBarWidget(new QWidget());
    sidebarDock->setFixedWidth(240);

    connect(sidebar, &sideBar::widthRequested,
            sidebarDock, [sidebarDock](int width) {
                sidebarDock->setFixedWidth(width);
            });

    addDockWidget(Qt::LeftDockWidgetArea, sidebarDock);

    connect(sidebar, &sideBar::registrarPacienteClicked, this, &MainWindow::openRegisterPanel);
    connect(sidebar, &sideBar::salvarSessaoClicked, this, &MainWindow::saveSession);
    connect(sidebar, &sideBar::sobreClicked, this, &MainWindow::on_actionSobre_triggered);
}

void MainWindow::integrarPaineisCanais()
{
    QWidget *acoes = ui->iniciarEstimulo_pushButton->parentWidget();
    durationPanel = new DurationPanel(this);

    QWidget *areaAntiga = takeCentralWidget();
    auto *novaArea = new QWidget(this);
    auto *principalLayout = new QVBoxLayout(novaArea);
    principalLayout->setContentsMargins(0, 0, 0, 0);

    QTabWidget *tabWidget = new QTabWidget(novaArea);

    // -------------------------------------------------------------
    // ABA 1: ESTIMULAÇÃO ELÉTRICA
    // -------------------------------------------------------------
    QScrollArea *scrollEletrico = new QScrollArea(tabWidget);
    scrollEletrico->setWidgetResizable(true);
    scrollEletrico->setFrameShape(QFrame::NoFrame);

    QWidget *conteudoEletrico = new QWidget(scrollEletrico);
    QVBoxLayout *eletricoMainLayout = new QVBoxLayout(conteudoEletrico);
    eletricoMainLayout->setContentsMargins(12, 12, 12, 12);
    eletricoMainLayout->setSpacing(12);

    auto *cabecalhoLayout = new QHBoxLayout;
    auto *protocolos = new ProtocolSelector(
        { ui->loadProtocol, ui->continuousProtocol, ui->rampProtocol, ui->thresholdProtocol, ui->limitedProtocol, ui->customProtocol },
        conteudoEletrico
        );

    ui->testeCanais_pushButton->setText("Testar conexão");
    ui->testeCanais_pushButton->setToolTip("Verificar a comunicação com o estimulador");
    cabecalhoLayout->addWidget(protocolos, 1);
    cabecalhoLayout->addWidget(ui->testeCanais_pushButton);
    eletricoMainLayout->addLayout(cabecalhoLayout);

    auto *acoesLayout = new QHBoxLayout;
    acoesLayout->addWidget(durationPanel);
    acoesLayout->addStretch();
    auto *enviarButton = new QPushButton("Enviar", conteudoEletrico);
    connect(enviarButton, &QPushButton::clicked, this, &MainWindow::send_parameters);
    acoesLayout->addWidget(enviarButton);
    acoesLayout->addWidget(acoes);
    eletricoMainLayout->addLayout(acoesLayout);

    QHBoxLayout *canaisLayout = new QHBoxLayout;
    channel1Panel = new ChannelPanel(conteudoEletrico);
    channel2Panel = new ChannelPanel(conteudoEletrico);
    channel1Panel->setChannelNumber(1);
    channel2Panel->setChannelNumber(2);

    connect(ui->rampProtocol, &QToolButton::toggled, channel1Panel, &ChannelPanel::setRampMode);
    connect(ui->rampProtocol, &QToolButton::toggled, channel2Panel, &ChannelPanel::setRampMode);
    channel1Panel->setRampMode(ui->rampProtocol->isChecked());
    channel2Panel->setRampMode(ui->rampProtocol->isChecked());

    canaisLayout->addWidget(channel1Panel, 1);
    canaisLayout->addWidget(channel2Panel, 1);
    eletricoMainLayout->addLayout(canaisLayout);

    scrollEletrico->setWidget(conteudoEletrico);
    tabWidget->addTab(scrollEletrico, "Estimulação Elétrica");

    // -------------------------------------------------------------
    // ABA 2: ESTIMULAÇÃO AUDITIVA
    // -------------------------------------------------------------
    QScrollArea *scrollAuditivo = new QScrollArea(tabWidget);
    scrollAuditivo->setWidgetResizable(true);
    scrollAuditivo->setFrameShape(QFrame::NoFrame);

    QWidget *conteudoAuditivo = new QWidget(scrollAuditivo);
    QVBoxLayout *auditivoMainLayout = new QVBoxLayout(conteudoAuditivo);
    auditivoMainLayout->setContentsMargins(12, 12, 12, 12);
    auditivoMainLayout->setSpacing(12);

    auto *protocolosAuditivo = new ProtocolSelector(
        { ui->loadProtocolAuditivo, ui->AudiometerProtocol, ui->PEAProtocol },
        conteudoAuditivo
        );
    auditivoMainLayout->addWidget(protocolosAuditivo);

    painelAuditivo = new sidePanel(conteudoAuditivo);
    auditivoMainLayout->addWidget(painelAuditivo);

    ui->loadProtocolAuditivo->setCheckable(true);
    ui->AudiometerProtocol->setCheckable(true);
    ui->PEAProtocol->setCheckable(true);
    ui->AudiometerProtocol->setAutoExclusive(true);
    ui->loadProtocolAuditivo->setAutoExclusive(true);
    ui->PEAProtocol->setAutoExclusive(true);

    connect(ui->AudiometerProtocol, &QToolButton::toggled, painelAuditivo, &QWidget::setVisible);

    // Conexões de Botões Auditivos
    connect(painelAuditivo, &sidePanel::iniciarAuditivoClicado, this, &MainWindow::aud_iniciar_estimulo);
    connect(painelAuditivo, &sidePanel::pararAuditivoClicado, this, &MainWindow::aud_parar_estimulo);
    connect(painelAuditivo, &sidePanel::selecionarAudioClicado, this, &MainWindow::aud_selecionar_audio);
    connect(painelAuditivo, &sidePanel::volumeAlterado, this, &MainWindow::aud_alterar_volume);

    // Conexões de Parâmetros Auditivos
    connect(painelAuditivo, &sidePanel::canalEstimuloAlterado, this, &MainWindow::aud_canalEstimuloAlterado);
    connect(painelAuditivo, &sidePanel::tipoEstimuloAlterado, this, &MainWindow::aud_tipoEstimuloAlterado);
    connect(painelAuditivo, &sidePanel::reproducaoCiclicaToggled, this, &MainWindow::aud_reproducaoCiclicaToggled);
    connect(painelAuditivo, &sidePanel::tempoReproducaoCiclicaAlterado, this, &MainWindow::aud_tempoReproducaoCiclicaAlterado);
    connect(painelAuditivo, &sidePanel::duracaoEstimuloAlterada, this, &MainWindow::aud_duracaoEstimuloAlterada);
    connect(painelAuditivo, &sidePanel::freqAudioAlterada, this, &MainWindow::aud_freqAudioAlterada);
    connect(painelAuditivo, &sidePanel::duracaoMsAlterada, this, &MainWindow::aud_duracaoMsAlterada);
    connect(painelAuditivo, &sidePanel::amplitudeAlterada, this, &MainWindow::aud_amplitudeAlterada);
    connect(painelAuditivo, &sidePanel::freqPortadoraAlterada, this, &MainWindow::aud_freqPortadoraAlterada);
    connect(painelAuditivo, &sidePanel::freqModulacaoAlterada, this, &MainWindow::aud_freqModulacaoAlterada);
    connect(painelAuditivo, &sidePanel::fatorAMAlterado, this, &MainWindow::aud_fatorAMAlterado);
    connect(painelAuditivo, &sidePanel::exponencialModAlterada, this, &MainWindow::aud_exponencialModAlterada);
    connect(painelAuditivo, &sidePanel::faseFMAlterada, this, &MainWindow::aud_faseFMAlterada);
    connect(painelAuditivo, &sidePanel::fatorFMAlterado, this, &MainWindow::aud_fatorFMAlterado);

    ui->AudiometerProtocol->setChecked(true);
    painelAuditivo->setVisible(ui->AudiometerProtocol->isChecked());

    scrollAuditivo->setWidget(conteudoAuditivo);
    tabWidget->addTab(scrollAuditivo, "Estimulação Auditiva");

    // -------------------------------------------------------------
    // ABA 3: MODO MISTO
    // -------------------------------------------------------------
    QWidget *abaMisto = new QWidget(tabWidget);
    tabWidget->addTab(abaMisto, "Modo Misto");

    principalLayout->addWidget(tabWidget, 1);
    areaAntiga->setParent(novaArea);
    areaAntiga->hide();
    setCentralWidget(novaArea);

    ui->iniciarEstimulo_pushButton->setEnabled(true);
}

// =========================================================
// LÓGICA DO ESTIMULADOR ELÉTRICO
// =========================================================

void MainWindow::test_connection()
{
    uint8_t ip[4] = {0,0,0,0};
    uint8_t mask[4] = {0,0,0,0};
    uint8_t getway[4] = {0,0,0,0};
    unsigned int port = 0;

    comm->esGetNetworkConfig(ip, mask, getway, &port);
    comm->Log(INFO, "IP client: {" + std::to_string(ip[0]) + ", " + std::to_string(ip[1]) + ", " + std::to_string(ip[2]) + ", " + std::to_string(ip[3]) + "}");

    if (port == ES_PORT) {
        ui->testeCanais_pushButton->setProperty("connectionState", "success");
    } else {
        ui->testeCanais_pushButton->setProperty("connectionState", "error");
        QMessageBox::critical(this, "Erro de Conexão", "Falha ao conectar com o dispositivo.");
    }

    auto *button = ui->testeCanais_pushButton;
    button->setText("Testar conexão");
    button->style()->unpolish(button);
    button->style()->polish(button);
    button->update();
}

/**
 * @brief Monta a forma de onda, prepara os bytes de configuração
 *        e transmite os pacotes para o estimulador.
 */
void MainWindow::send_parameters()
{
    uint8_t ch1_state = channel1Panel->isChannelEnabled() ? 0x01 : 0x00;
    uint8_t ch2_state = channel2Panel->isChannelEnabled() ? 0x01 : 0x00;

    if (ch1_state || ch2_state) {
        int sampling_freq = 32000;
        int ch1_freq = channel1Panel->frequencyHz();
        int ch2_freq = channel2Panel->frequencyHz();

        unsigned int size_vectorCh1 = ch1_freq != 0 ? sampling_freq/ch1_freq : 0;
        unsigned int size_vectorCh2 = ch2_freq != 0 ? sampling_freq/ch2_freq : 0;
        unsigned int biggest_vector_size = size_vectorCh1 >= size_vectorCh2 ? size_vectorCh1 : size_vectorCh2;

        double* stimulus_ch1 = new double[biggest_vector_size]{0};
        double* stimulus_ch2 = new double[biggest_vector_size]{0};

        unsigned int i;
        for (i = 0; i < size_vectorCh1; i++) {
            stimulus_ch1[i] = sin(2*PI/size_vectorCh1*i);
        }
        for (i = 0; i < size_vectorCh2; i++) {
            stimulus_ch2[i] = sin(2*PI/size_vectorCh2*i);
        }

        float amplitude = 50.0;
        for (i = 0; i < size_vectorCh1; i++) {
            stimulus_ch1[i] = stimulus_ch1[i]*amplitude*(4096.0/200.0) + 2047.0;
        }
        for (i = 0; i < size_vectorCh2; i++) {
            stimulus_ch2[i] = stimulus_ch2[i]*amplitude*(4096.0/200.0) + 2047.0;
        }

        biggest_vector_size *= 2;
        double* vectorCh1Ch2 = new double[biggest_vector_size];
        for (i = 0; i < biggest_vector_size/2; i++){
            vectorCh1Ch2[i*2] = stimulus_ch1[i];
            vectorCh1Ch2[i*2+1] = stimulus_ch2[i];
        }

        uint16_t* vectorU16bits = new uint16_t[biggest_vector_size];
        for (i = 0; i < biggest_vector_size; i++){
            vectorU16bits[i] = static_cast<uint16_t>(vectorCh1Ch2[i]);
        }

        int estim_size_16b = biggest_vector_size;
        estim_size_16b = ceil(estim_size_16b * 2.0 / 256.0);

        std::vector<uint8_t> vector_Estimulus(biggest_vector_size * 2);
        for (i = 0; i < biggest_vector_size; i++) {
            vector_Estimulus[i * 2] = vectorU16bits[i] & 0xFF;
            vector_Estimulus[i * 2 + 1] = (vectorU16bits[i]>>8) & 0xFF;
        }

        int initial_estim_size_8b = biggest_vector_size * 2;
        int num_packets_per_buff  = 100;

        if (estim_size_16b <= num_packets_per_buff ) {
            int dif = estim_size_16b*256 - initial_estim_size_8b;
            vector_Estimulus.resize(vector_Estimulus.size() + dif, 0);
        } else {
            int num_elements_to_erase = estim_size_16b * 256.0 - initial_estim_size_8b;
            std::vector<uint8_t> shortVetorEstimulus(vector_Estimulus.begin(), vector_Estimulus.begin() + initial_estim_size_8b);

            if (num_elements_to_erase > 0 && num_elements_to_erase <= shortVetorEstimulus.size()) {
                vector_Estimulus.erase(vector_Estimulus.end() - num_elements_to_erase, vector_Estimulus.end());
            }
            int quotient = 16;
            while ( (estim_size_16b % quotient) == 0 || quotient < 8){
                quotient -= 1;
            }
        }

        int npackages_stim_sent = estim_size_16b;

        delete[] stimulus_ch1;
        delete[] stimulus_ch2;
        delete[] vectorCh1Ch2;
        delete[] vectorU16bits;

        // Configuração de Canais
        uint8_t channel_states[2] = {ch1_state, ch2_state};
        comm->esSendConfig(ES_CMD_STATE_CHANNELS, channel_states, 2);

        uint8_t term_0 = (npackages_stim_sent >> 24) & 0x0F;
        uint8_t term_1 = (npackages_stim_sent >> 16) & 0x0F;
        uint8_t term_2 = (npackages_stim_sent >> 8) & 0x0F;
        uint8_t term_3 = npackages_stim_sent & 0x0F;
        uint8_t N_packages_estim_enviados[4] = {term_0, term_1, term_2, term_3};
        comm->esSendConfig(ES_CMD_PACKAGE_NUM, N_packages_estim_enviados,4);

        uint8_t ciclico = ui->ciclicoCheckBox->isChecked()? 0x01 : 0x00;
        uint8_t stimulation_mode_pkg[] = {static_cast<uint8_t>(ui->protocoloEstimulacao_comboBox->currentIndex()+ ciclico)};
        comm->esSendConfig(ES_CMD_STIMULATION_MODE, stimulation_mode_pkg,1);

        uint32_t n_samples_ch1_tmp = size_vectorCh1;
        uint32_t n_samples_ch2_tmp = size_vectorCh2;
        int personalized_estimulus_ch1 = 1;

        if (ui->protocoloEstimulacao_comboBox->currentText()=="Personalizado"){
            if (ch1_state == 0x00) {
                n_samples_ch1_tmp = 0;
            } else {
                personalized_estimulus_ch1 = 10;
            }
            if (ch2_state == 0x00) {
                n_samples_ch2_tmp = 0;
            }
        }

        int personalized_estimulus_ch2 = personalized_estimulus_ch1;
        uint32_t total_samples_ch1 = n_samples_ch1_tmp * personalized_estimulus_ch1;
        uint32_t total_samples_ch2 = n_samples_ch2_tmp * personalized_estimulus_ch2;

        uint8_t sample_num_pkg[8];
        sample_num_pkg[0] = (total_samples_ch1 >> 24) & 0xFF;
        sample_num_pkg[1] = (total_samples_ch1 >> 16) & 0xFF;
        sample_num_pkg[2] = (total_samples_ch1 >> 8) & 0xFF;
        sample_num_pkg[3] = total_samples_ch1 & 0xFF;

        sample_num_pkg[4] = (total_samples_ch2 >> 24) & 0xFF;
        sample_num_pkg[5] = (total_samples_ch2 >> 16) & 0xFF;
        sample_num_pkg[6] = (total_samples_ch2 >> 8) & 0xFF;
        sample_num_pkg[7] = total_samples_ch2 & 0xFF;
        comm->esSendConfig(ES_CMD_SAMPLE_NUM, sample_num_pkg, 8);

        int num_cycles_ch1 = ui->protocoloEstimulacao_comboBox->currentText()=="Limitado" ? ui->ch1_spinBox_ciclos->value() : 1;
        int num_cycles_ch2 = ui->protocoloEstimulacao_comboBox->currentText()=="Limitado" ? ui->ch2_spinBox_ciclos->value() : 1;
        uint8_t cycles_num_pkg[1] = {static_cast<uint8_t>(num_cycles_ch1 + num_cycles_ch2)};
        comm->esSendConfig(ES_CMD_CYCLES_NUM, cycles_num_pkg, 1);

        int ch1_stimulus_type = ch1_state == 0x01 ? channel1Panel->waveformIndex() : 0;
        int ch2_stimulus_type = ch2_state == 0x01 ? channel2Panel->waveformIndex() : 0;
        uint8_t stimulus_type_pkg[1] = {static_cast<uint8_t>(ch1_stimulus_type+ch2_stimulus_type)};
        comm->esSendConfig(ES_CMD_STIMULUS_TYPE,stimulus_type_pkg,1);

        const uint32_t FS_ch1 = 32000;
        const uint32_t FS_ch2 = 32000;
        uint8_t sampling_frequency_pkg[8];
        sampling_frequency_pkg[0] = (FS_ch2 >> 24) & 0xFF;
        sampling_frequency_pkg[1] = (FS_ch2 >> 16) & 0xFF;
        sampling_frequency_pkg[2] = (FS_ch2 >> 8) & 0xFF;
        sampling_frequency_pkg[3] = FS_ch2 & 0xFF;
        sampling_frequency_pkg[4] = (FS_ch1 >> 24) & 0xFF;
        sampling_frequency_pkg[5] = (FS_ch1 >> 16) & 0xFF;
        sampling_frequency_pkg[6] = (FS_ch1 >> 8) & 0xFF;
        sampling_frequency_pkg[7] = FS_ch1 & 0xFF;
        comm->esSendConfig(ES_CMD_SAMPLING_FREQUENCY, sampling_frequency_pkg, 8);

        double ton_ch1 = ui->doubleSpinBox_ton->value();
        double toff_ch1 = ui->doubleSpinBox_toff->value();
        double ton_ch2 = ton_ch1;
        double toff_ch2 = toff_ch1;

        uint32_t ton_ch1_ms = static_cast<uint32_t>(1000 * ton_ch1);
        uint32_t toff_ch1_ms = static_cast<uint32_t>(1000 * toff_ch1);
        uint32_t ton_ch2_ms = static_cast<uint32_t>(1000 * ton_ch2);
        uint32_t toff_ch2_ms = static_cast<uint32_t>(1000 * toff_ch2);

        uint8_t ton_toff_pkg[16];
        ton_toff_pkg[0] = (ton_ch1_ms >> 24) & 0xFF;
        ton_toff_pkg[1] = (ton_ch1_ms >> 16) & 0xFF;
        ton_toff_pkg[2] = (ton_ch1_ms >> 8) & 0xFF;
        ton_toff_pkg[3] = ton_ch1_ms & 0xFF;
        ton_toff_pkg[4] = (toff_ch1_ms >> 24) & 0xFF;
        ton_toff_pkg[5] = (toff_ch1_ms >> 16) & 0xFF;
        ton_toff_pkg[6] = (toff_ch1_ms >> 8) & 0xFF;
        ton_toff_pkg[7] = toff_ch1_ms & 0xFF;
        ton_toff_pkg[8] = (ton_ch2_ms >> 24) & 0xFF;
        ton_toff_pkg[9] = (ton_ch2_ms >> 16) & 0xFF;
        ton_toff_pkg[10] = (ton_ch2_ms >> 8) & 0xFF;
        ton_toff_pkg[11] = ton_ch2_ms & 0xFF;
        ton_toff_pkg[12] = (toff_ch2_ms >> 24) & 0xFF;
        ton_toff_pkg[13] = (toff_ch2_ms >> 16) & 0xFF;
        ton_toff_pkg[14] = (toff_ch2_ms >> 8) & 0xFF;
        ton_toff_pkg[15] = toff_ch2_ms & 0xFF;
        comm->esSendConfig(ES_CMD_TON_TOFF, ton_toff_pkg, 16);

        int protocol = ui->spinBox_protocol->value();
        uint8_t protocol_pkg[1] = { static_cast<uint8_t>(protocol) };
        comm->esSendConfig(ES_CMD_PROTOCOL, protocol_pkg, 1);

        double trigger = ui->ch1_doubleSpinBox_trigger->value();
        uint32_t trigger_ms = static_cast<uint32_t>(1000 * trigger);
        uint8_t time_trigg_pkg[4];
        time_trigg_pkg[0] = (trigger_ms >> 24) & 0xFF;
        time_trigg_pkg[1] = (trigger_ms >> 16) & 0xFF;
        time_trigg_pkg[2] = (trigger_ms >> 8) & 0xFF;
        time_trigg_pkg[3] = trigger_ms & 0xFF;
        comm->esSendConfig(ES_CMD_TIME_TRIGG, time_trigg_pkg, 4);

        int i1i = static_cast<int>(ui->ch1_doubleSpinBox_I1i->value());
        int i2i = static_cast<int>(ui->ch2_doubleSpinBox_I2i->value());

        const bool customCh1 = channel1Panel->waveformIndex() == 5;
        const bool customCh2 = channel2Panel->waveformIndex() == 5;

        int personalized_stimulus_ch1_p1 = 0;
        int personalized_stimulus_ch1_p2 = 0;
        if (customCh1) {
            personalized_stimulus_ch1_p1 = i1i;
            personalized_stimulus_ch1_p2 = 10;
        }

        int personalized_stimulus_ch2_p1 = 0;
        int personalized_stimulus_ch2_p2 = 0;
        if (customCh2) {
            personalized_stimulus_ch2_p1 = i2i;
            personalized_stimulus_ch2_p2 = 20;
        }

        uint8_t stimulus_intensity_pkg[6];
        stimulus_intensity_pkg[0] = static_cast<uint8_t>(personalized_stimulus_ch1_p2);
        stimulus_intensity_pkg[1] = (personalized_stimulus_ch1_p1 >> 8) & 0xFF;
        stimulus_intensity_pkg[2] = personalized_stimulus_ch1_p1 & 0xFF;
        stimulus_intensity_pkg[3] = static_cast<uint8_t>(personalized_stimulus_ch2_p2);
        stimulus_intensity_pkg[4] = (personalized_stimulus_ch2_p1 >> 8) & 0xFF;
        stimulus_intensity_pkg[5] = personalized_stimulus_ch2_p1 & 0xFF;
        comm->esSendConfig(ES_CMD_STIMULUS_INTENSITY, stimulus_intensity_pkg, 6);

        for (int i = 0; i < npackages_stim_sent; ++i) {
            std::vector<uint8_t> current_package(
                vector_Estimulus.begin() + i * 256,
                vector_Estimulus.begin() + i * 256 + 256
                );

            current_package.insert(current_package.begin(), static_cast<uint8_t>(0 & 0xFF));
            current_package.insert(current_package.begin(), static_cast<uint8_t>(i & 0xFF));

            enviaEstimEletr(current_package.data(), static_cast<int>(current_package.size()));
        }

        char data_out[4096];
        comm->esSendCmd(ES_CMD_END_TRANSMISION, data_out);
    }
}

void MainWindow::startStimulations()
{
    char data_out[4096];
    comm->esSendCmd(ES_CMD_PLAY_STIMULUS, data_out);
}

void MainWindow::stopStimulations()
{
    char data_out[4096];
    comm->esSendCmd(ES_CMD_STOP_STIMULUS, data_out);
}

int MainWindow::enviaEstimEletr(uint8_t *data_in, int size_data_in)
{
    char data_out[4096];
    int resultado;
    int contador = 0;
    do{
        resultado = comm->esSendReceivePackage(ES_CMD_RECIVE_PACKAGE, data_in, size_data_in, data_out);
        contador++;
        if (contador > 100) {
            qDebug() << "Limite de tentativas excedido ao enviar estimulação elétrica.";
            break;
        }
    }
    while(resultado != OK || (uint8_t)data_out[3] != (uint8_t)25);
    return (int)data_out[4];
}

// =========================================================
// SESSÃO E BANCO DE DADOS
// =========================================================

void MainWindow::openRegisterPanel()
{
    patientPanel = new PatientPanel();
    patientPanel->show();
    patientPanel->raise();
    patientPanel->activateWindow();
}

void MainWindow::on_actionRegistrar_paciente_triggered()
{
    openRegisterPanel();
}

void MainWindow::saveSession()
{
    if (patientPanel == nullptr) {
        QMessageBox::warning(this, "Erro", "Registre um paciente antes de salvar a sessão.");
        return;
    }

    QString name = patientPanel->getName();
    QString identifier = patientPanel->getIdentifier();
    QDate birthDate = patientPanel->getBirthDate();
    QString gender = patientPanel->getGender();
    QString examiner = patientPanel->getExaminer();
    QString observations = patientPanel->getObservations();

    int amplitudeCh1 = channel1Panel->amplitudeUa();
    int frequencyCh1 = channel1Panel->frequencyHz();
    QString waveformCh1 = channel1Panel->waveformText();

    int amplitudeCh2 = channel2Panel->amplitudeUa();
    int frequencyCh2 = channel2Panel->frequencyHz();
    QString waveformCh2 = channel2Panel->waveformText();

    if (name.isEmpty() || identifier.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Dados do paciente ausentes");
        return;
    }

    const bool ch1Enabled = channel1Panel->isChannelEnabled();
    const bool ch2Enabled = channel2Panel->isChannelEnabled();

    if (!ch1Enabled && !ch2Enabled) {
        QMessageBox::warning(this, "Erro", "Ative pelo menos um canal antes de salvar a sessão.");
        return;
    }

    if (ch1Enabled && (amplitudeCh1 < 1 || amplitudeCh1 > 10000 || frequencyCh1 < 1 || frequencyCh1 > 5000)) {
        QMessageBox::warning(this, "Erro", "Verifique a amplitude e a frequência do canal 1.");
        return;
    }

    if (ch2Enabled && (amplitudeCh2 < 1 || amplitudeCh2 > 10000 || frequencyCh2 < 1 || frequencyCh2 > 5000)) {
        QMessageBox::warning(this, "Erro", "Verifique a amplitude e a frequência do canal 2.");
        return;
    }

    Patient patient(name, identifier, birthDate, gender, examiner, observations);
    PatientRepository patientRepo;

    int patientId = patientRepo.savePatient(patient);

    if (patientId == -1) {
        QMessageBox::critical(this, "Erro", "Paciente não salvo");
        return;
    }

    Session session(patientId, amplitudeCh1, frequencyCh1, waveformCh1, amplitudeCh2, frequencyCh2, waveformCh2);
    SessionRepository sessionRepo;

    if (!sessionRepo.saveSession(session)) {
        QMessageBox::critical(this, "Erro", "Parâmetros não salvos");
        return;
    }

    QMessageBox::information(this, "Sucesso", "Dados do paciente e parâmetros salvos corretamente.");
}

void MainWindow::on_actionSalvar_sessao_triggered()
{
    saveSession();
}

void MainWindow::on_actionSobre_triggered()
{
    QMessageBox::about(this, tr("Sobre"),
                       tr("<h3>Estimulador Elétrico</h3>"
                          "<p>Versão 1.0.0</p>"
                          "<p>Desenvolvido no LAPIS, 2026.</p>"
                          "<p>Equipamento de uso experimental.</p>"));
}

// =========================================================
// LÓGICA DO ESTIMULADOR AUDITIVO E SLOTS DO SIDEPANEL
// =========================================================

void MainWindow::aud_testar_conexao()
{
    int status = comm_aud->iniciaEstimAud();
    if (status == 1) {
        qDebug() << "[OK] Dispositivo auditivo respondendo.";
    } else {
        qDebug() << "[ERRO] Falha código: " << status;
    }
}

void MainWindow::aud_iniciar_estimulo()
{
    int status = comm_aud->iniciaEstimAud();
    if(status == 1) {
        timerAudio->start(20);
    }
}

void MainWindow::aud_parar_estimulo()
{
    int status = comm_aud->finEstimAud();
    if(status == 1) {
        qDebug() << "[OK] Comando PARAR AUDITIVO enviado.";
        timerAudio->stop();
    }
}

void MainWindow::verificarPedidoAudio()
{
    uint8_t ch_direito = 0;
    uint8_t ch_esquerdo = 0;
    int status = comm_aud->EstadoPugs(ch_direito, ch_esquerdo);

    if (status == OK) {
        // qDebug() << "Estado dos canais -> Dir:" << ch_direito << "Esq:" << ch_esquerdo;
    }
}

void MainWindow::prepararSinalWAV(QString caminho)
{
    QFile arquivoWav(caminho);
    if (!arquivoWav.open(QIODevice::ReadOnly)) {
        qDebug() << "[ERRO] Não foi possível abrir o arquivo de áudio.";
        return;
    }
    bufferAudioCompleto.clear();
    arquivoWav.read(44); // Pula o cabeçalho
    bufferAudioCompleto = arquivoWav.readAll();
    arquivoWav.close();
    indiceLeitura = 0;
    qDebug() << "[AUDITIVO] Arquivo WAV carregado na memória (" << bufferAudioCompleto.size() << " bytes).";
}

void MainWindow::aud_selecionar_audio()
{
    QString caminhoArquivo = QFileDialog::getOpenFileName(this, "Selecione o arquivo de áudio", "", "Arquivos de Áudio (*.wav)");
    if (!caminhoArquivo.isEmpty()) {
        prepararSinalWAV(caminhoArquivo);
    }
}

void MainWindow::aud_alterar_volume(int vol_dir, int vol_esq)
{
    int status = comm_aud->estabVolume((uint8_t)vol_dir, (uint8_t)vol_esq);
    if (status == OK) {
        qDebug() << "[AUDITIVO] Volume -> Dir:" << vol_dir << "| Esq:" << vol_esq;
    } else {
        qDebug() << "[ERRO] Falha ao atualizar volume.";
    }
}

void MainWindow::aud_canalEstimuloAlterado(int index) {
    qDebug() << "[UI] Canal de Estímulo alterado para índice:" << index;
}

void MainWindow::aud_tipoEstimuloAlterado(int index) {
    qDebug() << "[UI] Tipo de Estímulo alterado para índice:" << index;
}

void MainWindow::aud_reproducaoCiclicaToggled(bool checked) {
    qDebug() << "[UI] Reprodução Cíclica está:" << (checked ? "Ativada" : "Desativada");
}

void MainWindow::aud_tempoReproducaoCiclicaAlterado(const QTime &tempo) {
    qDebug() << "[UI] Tempo de Reprodução Cíclica alterado para:" << tempo.toString("HH:mm:ss");
}

void MainWindow::aud_duracaoEstimuloAlterada(const QTime &tempo) {
    qDebug() << "[UI] Duração do Estímulo alterada para:" << tempo.toString("HH:mm:ss");
}

void MainWindow::aud_freqAudioAlterada(int valor) {
    qDebug() << "[UI] Frequência de Áudio alterada para:" << valor;
}

void MainWindow::aud_duracaoMsAlterada(int valor) {
    qDebug() << "[UI] Duração (ms) alterada para:" << valor;
}

void MainWindow::aud_amplitudeAlterada(int valor) {
    qDebug() << "[UI] Amplitude alterada para:" << valor;
}

void MainWindow::aud_freqPortadoraAlterada(int valor) {
    qDebug() << "[UI] Frequência Portadora alterada para:" << valor;
}

void MainWindow::aud_freqModulacaoAlterada(int valor) {
    qDebug() << "[UI] Frequência Modulação alterada para:" << valor;
}

void MainWindow::aud_fatorAMAlterado(int valor) {
    qDebug() << "[UI] Fator AM alterado para:" << valor;
}

void MainWindow::aud_exponencialModAlterada(int valor) {
    qDebug() << "[UI] Exponencial Modulação alterada para:" << valor;
}

void MainWindow::aud_faseFMAlterada(int valor) {
    qDebug() << "[UI] Fase FM alterada para:" << valor;
}

void MainWindow::aud_fatorFMAlterado(int valor) {
    qDebug() << "[UI] Fator FM alterado para:" << valor;
}