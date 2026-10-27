/*
 * ===============================================================
 *                      mainwindow.cpp
 * ===============================================================
 *
 * Autor: Danilo Molina e Julio Cesar S. Fernandes
 * Última Atualização: 09-nov-2024
 * Versão: 1.0
 *
 * Target/Board
 * - Estimulador Elétrico v7 (Brasil)
 *
 * Descrição:
 * - mainwindow.cpp é o codigo fonte responsavel por todo o funcionamento da interface.
 * para incluir novas funções ou objetos de classes não originais do Qt, devem ser feitas
 * as declarações necessárias no mainwindow.h
 * Este arquivo ja tem a função send_parameters() que é responsável por enviar os pacotes
 * para o estimulador e configurar o estimulo de saída. Outras funcções como iniciarEstimulos()
 * e pararEstimulos() usam flags da comunicação UDP para enviar um simples comando por meio da
 * função implementada em ES_UdpClient.cpp.
 *
 * Dependências:
 * - "ES_UdpClient.h", "ES_UdpClient.cpp", "mainwindow.h"
 *
 * Instruções de Uso:
 * - Apos declarar a nova função no mainwindow.h, implemente a funçãi declarada aqui e
 * conecte a função a um botão, caso seja necessário.
 *
 * Histórico de Versões:
 * - Versão 1.0 (05-nov-2024): Teste e comprovação de funcionamento com senoidal. Não foi
 * avaliado completamente.
 */

#include <memory>
#include <math.h>
#include <cstdint> // para usar uint16_t
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <QThread>
#include <QPixmap>
#include <QGroupBox>
#include <QMessageBox>
#include <QDebug>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyle>

#define PI 3.14159265

//Modulos de Comunicação
#include "ES_UdpClient.h"
#include "ES_WiFiClient.h"


//Interface
#include "patient.h"
#include "session.h"
#include "patientRepository.h"
#include "sessionRepository.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "protocolSelector.h"
#include "durationPanel.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , comm(new ES_UdpClient)
{
    ui->setupUi(this);
    // O carregamento é uma ação, não uma opção de protocolo.
    ui->loadProtocol->setCheckable(false);
    ui->loadProtocol->setText("Carregar protocolo");
    LogType level = ERRO;
    //QPainter painter(this);
    comm->SetLogLevel(level);
    comm->esConfig();
    comm->esStart();

    //test_connection();
    connect(ui->testeCanais_pushButton, &QPushButton::clicked, this, &MainWindow::test_connection);
    connect(ui->iniciarEstimulo_pushButton, &QPushButton::clicked, this, &MainWindow::startStimulations);
    connect(ui->pararEstimulo_pushButton, &QPushButton::clicked, this, &MainWindow::stopStimulations);
    // Configura o menu lateral e suas ações.
    configurarMenuLateral();
    // Integra os painéis após configurar os controles existentes.
    integrarPaineisCanais();
}
void MainWindow::configurarMenuLateral()
{
    //Menu
    sidebar = new sideBar(this);
    QDockWidget *sidebarDock = new QDockWidget(this);

    sidebarDock->setWidget(sidebar);
    sidebarDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    sidebarDock->setTitleBarWidget(new QWidget());
    sidebarDock->setFixedWidth(240);
    // Ajusta o contêiner quando o menu muda de apresentação.
    connect(sidebar, &sideBar::widthRequested,
            sidebarDock, [sidebarDock](int width) {
                sidebarDock->setFixedWidth(width);
            });
    addDockWidget(Qt::LeftDockWidgetArea, sidebarDock);

    //Registrar paciente
    connect(
        sidebar,
        &sideBar::registrarPacienteClicked,
        this,
        &MainWindow::openRegisterPanel
        );
    //Salvar sessão
    connect(
        sidebar,
        &sideBar::salvarSessaoClicked,
        this,
        &MainWindow::saveSession
        );
    // Sobre
    connect(
        sidebar,
        &sideBar::sobreClicked,
        this,
        &MainWindow::on_actionSobre_triggered
        );
}

void MainWindow::integrarPaineisCanais()
{
    // Preserva o contêiner dos botões gerais.
    QWidget *acoes = ui->iniciarEstimulo_pushButton->parentWidget();
    // Cria o componente independente de duração.
    durationPanel = new DurationPanel(this);
    // Retira a área antiga sem destruir seus controles.
    QWidget *areaAntiga = takeCentralWidget();

    // Cria a nova área central com organização por layouts.
    auto *novaArea = new QWidget(this);
    auto *principalLayout = new QVBoxLayout(novaArea);
    principalLayout->setContentsMargins(12, 12, 12, 12);
    principalLayout->setSpacing(12);
    // Agrupa o carregamento e a seleção dos protocolos.
    auto *protocolos = new ProtocolSelector(
        {
            ui->loadProtocol,
            ui->continuousProtocol,
            ui->rampProtocol,
            ui->thresholdProtocol,
            ui->limitedProtocol,
            ui->customProtocol
        },
        novaArea
        );

    // Reutiliza o carregamento, os seletores e o botão de conexão.
    auto *cabecalhoLayout = new QHBoxLayout;
    ui->testeCanais_pushButton->setText("Testar conexão");
    ui->testeCanais_pushButton->setToolTip(
        "Verificar a comunicação com o estimulador"
        );   cabecalhoLayout->addWidget(protocolos, 1);
    // Identifica a ação de verificar a conexão com o equipamento.
    cabecalhoLayout->addWidget(ui->testeCanais_pushButton);
    principalLayout->addLayout(cabecalhoLayout);

    // Reutiliza a duração e os botões gerais.
    auto *acoesLayout = new QHBoxLayout;
    acoesLayout->addWidget(durationPanel);
    acoesLayout->addStretch();

    // Cria o botão que utiliza a função de envio existente.
    auto *enviarButton = new QPushButton("Enviar", novaArea);
    acoesLayout->addWidget(enviarButton);

    // Mantém os botões Iniciar e Parar.
    acoesLayout->addWidget(acoes);

    // Executa o envio sem alterar a geração ou os pacotes.
    connect(enviarButton, &QPushButton::clicked,
            this, &MainWindow::send_parameters);

    principalLayout->addLayout(acoesLayout);

    // Cria os dois painéis com estados independentes.
    channel1Panel = new ChannelPanel(novaArea);
    channel2Panel = new ChannelPanel(novaArea);

    channel1Panel->setChannelNumber(1);
    channel2Panel->setChannelNumber(2);
    // Atualiza os dois painéis ao selecionar ou sair de Rampa.
    connect(ui->rampProtocol, &QToolButton::toggled,
            channel1Panel, &ChannelPanel::setRampMode);

    connect(ui->rampProtocol, &QToolButton::toggled,
            channel2Panel, &ChannelPanel::setRampMode);

    // Aplica a seleção inicial do protocolo.
    channel1Panel->setRampMode(ui->rampProtocol->isChecked());
    channel2Panel->setRampMode(ui->rampProtocol->isChecked());

    // Distribui igualmente o espaço disponível entre os canais.
    auto *canaisLayout = new QHBoxLayout;
    canaisLayout->addWidget(channel1Panel, 1);
    canaisLayout->addWidget(channel2Panel, 1);
    principalLayout->addLayout(canaisLayout, 1);

    // Preserva os controles antigos ocultos durante a migração.
    areaAntiga->setParent(novaArea);
    areaAntiga->hide();

    setCentralWidget(novaArea);

    // O envio ainda utiliza os controles antigos.
    // Será habilitado após a adaptação da leitura dos parâmetros.
    ui->iniciarEstimulo_pushButton->setEnabled(true);
}

// Função que testa a conexão com o dispositivo de estimulação elétrica.
// Atualiza o botão de conexão conforme o sucesso ou falha.
void MainWindow::test_connection() {
    byte ip[4] = {0,0,0,0};
    byte mask[4] = {0,0,0,0};
    byte getway[4] = {0,0,0,0};
    unsigned int port = 0;
    comm->esGetNetworkConfig(ip, mask, getway, &port);
    comm->Log(INFO, "IP client: {" + std::to_string(ip[0]) + ", " + std::to_string(ip[1]) + ", " + std::to_string(ip[2]) + ", " + std::to_string(ip[3]) + "}");
    comm->Log(INFO, "Mask client: {" + std::to_string(mask[0]) + ", " + std::to_string(mask[1]) + ", " + std::to_string(mask[2]) + ", " + std::to_string(mask[3]) + "}");
    comm->Log(INFO, "Getway client: {" + std::to_string(getway[0]) + ", " + std::to_string(getway[1]) + ", " + std::to_string(getway[2]) + ", " + std::to_string(getway[3]) + "}");
    comm->Log(INFO, "Port client: " + std::to_string(port));

    if (port == ES_PORT) {  // Sucesso na conexão
        // Indica que a última verificação foi bem-sucedida.
        ui->testeCanais_pushButton->setProperty(
            "connectionState", "success"
            );
    } else {  // Falha na conexão
        // Indica que a verificação de conexão falhou.
        ui->testeCanais_pushButton->setProperty("connectionState", "error");
        QMessageBox::critical(this, "Erro de Conexão", "Falha ao conectar com o dispositivo.\n "
                                                       "Verifique as configurações de rede ou se o dispositivo está conectado.\n");
    }
    // Atualiza a aparência após qualquer resultado da verificação.
    auto *button = ui->testeCanais_pushButton;
    button->setText("Testar conexão");
    button->style()->unpolish(button);
    button->style()->polish(button);
    button->update();
}

void MainWindow::send_parameters() {
    // Consulta a ativação selecionada nos novos painéis.
    byte ch1_state = channel1Panel->isChannelEnabled() ? 0x01 : 0x00;
    byte ch2_state = channel2Panel->isChannelEnabled() ? 0x01 : 0x00;

    if (ch1_state || ch2_state) {

    //parte zero
    int sampling_freq = 32000;
    int ch1_freq = channel1Panel->frequencyHz();
    //int ch1_ciclos = ui->ch1_spinBox_cycles->value(); //nao usar agora
    //int offset ch1?

    int ch2_freq = channel2Panel->frequencyHz();
    //int ch2_ciclos = ui->ch2_spinBox_cycles->value(); //nao usar agora

    // a freq do canal é diferente de zero? se sim... calcula, senão zero.
    unsigned int size_vectorCh1 = ch1_freq != 0 ? sampling_freq/ch1_freq : 0;
    unsigned int size_vectorCh2 = ch2_freq != 0 ? sampling_freq/ch2_freq : 0;
    unsigned int biggest_vector_size = size_vectorCh1 >= size_vectorCh2 ? size_vectorCh1 : size_vectorCh2;
    double* stimulus_ch1 = new double[biggest_vector_size]{0}; // inicializando com zeros
    double* stimulus_ch2 = new double[biggest_vector_size]{0};

    unsigned int i;

    //ou qualquer outra funcao que gera funcao
    for (i = 0; i < size_vectorCh1; i++) { //gerando a senoide do canal 1 com o tamanho_vetor1
        stimulus_ch1[i] = sin(2*PI/size_vectorCh1*i);
    }

    for (i = 0; i < size_vectorCh2; i++) { //gerando a senoide do canal 2 com o tamanho_vetor2
        stimulus_ch2[i] = sin(2*PI/size_vectorCh2*i);
    }

    // configurando valores no vetor conforme Parte Zero sem escrever onde tem Zero
    float amplitude = 50.0; // varia de 0 a 100.0 -> * ainda não tem verificação de erro para ampliture = 0;
                           // quando for receber a amplitude na interface, o valor deverá ser dividido por 10 para usá-lo
    for (i = 0; i < size_vectorCh1; i++) {
        stimulus_ch1[i] = stimulus_ch1[i]*amplitude*(4096.0/200.0) + 2047.0;
    }
    for (i = 0; i < size_vectorCh2; i++) {
        stimulus_ch2[i] = stimulus_ch2[i]*amplitude*(4096.0/200.0) + 2047.0;
    }

    //gerando um vetor com o dobro do tamanho e intercalando ch_1[0],ch_2[0],ch_1[1],ch_2[1]....
    biggest_vector_size *= 2; // o maior tamanho é o dobro do maior
    double* vectorCh1Ch2 = new double[biggest_vector_size];
    for (i = 0; i < biggest_vector_size/2; i++){
        vectorCh1Ch2[i*2] = stimulus_ch1[i];
        vectorCh1Ch2[i*2+1] = stimulus_ch2[i];
    }

    //até aqui foi passo zero e intercalando os dois estimulos num unico vetor double (conforme LabView)

    uint16_t* vectorU16bits = new uint16_t[biggest_vector_size];
    for (i = 0; i < biggest_vector_size; i++){
        vectorU16bits[i] = static_cast<uint16_t>(vectorCh1Ch2[i]);
    } // converte o vetor de double em U16

    int estim_size_16b = biggest_vector_size; // Salvando variavel

    estim_size_16b = ceil(estim_size_16b * 2.0 / 256.0);

    //tentando converter para vector
    std::vector<byte> vector_Estimulus(biggest_vector_size * 2);

    for (i = 0; i < biggest_vector_size; i++) {
        vector_Estimulus[i * 2] = vectorU16bits[i] & 0xFF;//os 8 menores bits
        vector_Estimulus[i * 2 + 1] = (vectorU16bits[i]>>8) & 0xFF; // os 8 maiores bits
    }

    int initial_estim_size_8b = biggest_vector_size * 2; // salvando variavel

    int num_packets_per_buff  = 100; // definido na interdace original (main)

    if (estim_size_16b <= num_packets_per_buff ) { // true
        int dif = estim_size_16b*256 - initial_estim_size_8b;
        vector_Estimulus.resize(vector_Estimulus.size() + dif, 0); // Preenche com zeros
        //SAIDAS : vector_Estimulus e estim_size_16b
    }

    else { // false
        int num_elements_to_erase = estim_size_16b * 256.0 - initial_estim_size_8b;

        // Uso std::vector<byte> para facilitar a remoção usando a copia de uma parte
        std::vector<byte> shortVetorEstimulus(vector_Estimulus.begin(), vector_Estimulus.begin() + initial_estim_size_8b);

        // Remover os num_elements_to_erase do final
        if (num_elements_to_erase > 0 && num_elements_to_erase <= shortVetorEstimulus.size()) {
            vector_Estimulus.erase(vector_Estimulus.end() - num_elements_to_erase, vector_Estimulus.end());
        }

        int quotient = 16;
        while ( (estim_size_16b % quotient) == 0 || quotient < 8){
            quotient -= 1;
        }
        int N_packages_each_buffer = quotient;
        int N_buffer_stim = estim_size_16b/N_packages_each_buffer;//desnecessario?
        //depois de apagar, o vetor está completo... para SAIDA
    }

    qDebug() << "npackages_stim_sent: " << estim_size_16b;
    int npackages_stim_sent = estim_size_16b;

    //atualizacao de variaveis da interface
    unsigned size_stim_8b_sent = static_cast<unsigned>(vector_Estimulus.size());//só depois de converter corretamente para vector!!

    // Libere a memória após o uso
    delete[] stimulus_ch1;
    delete[] stimulus_ch2;
    delete[] vectorCh1Ch2;
    delete[] vectorU16bits;


    //parte 2
    byte channel_states[2] = {ch1_state, ch2_state};
    comm->esSendConfig(ES_CMD_STATE_CHANNELS, channel_states, 2);

    //parte 3
    byte term_0 = (npackages_stim_sent >> 24) & 0x0F;
    byte term_1 = (npackages_stim_sent >> 16) & 0x0F;
    byte term_2 = (npackages_stim_sent >> 8) & 0x0F;
    byte term_3 = npackages_stim_sent & 0x0F;
    byte N_packages_estim_enviados[4] = {term_0, term_1, term_2, term_3};
    comm->esSendConfig(ES_CMD_PACKAGE_NUM, N_packages_estim_enviados,4);

    //parte 4
    byte ciclico = ui->ciclicoCheckBox->isChecked()? 0x01 : 0x00;
    byte stimulation_mode_pkg[] = {static_cast<byte>(ui->protocoloEstimulacao_comboBox->currentIndex()+ ciclico)};
    comm->esSendConfig(ES_CMD_STIMULATION_MODE, stimulation_mode_pkg,1);

    //parte 5......
    uint32_t n_samples_ch1_tmp = size_vectorCh1;
    uint32_t n_samples_ch2_tmp = size_vectorCh2;

    int personalized_estimulus_ch1 = 1;

    if (ui->protocoloEstimulacao_comboBox->currentText()=="Personalizado"){
        if (ch1_state == 0x00 /*desligado*/ ) {
            n_samples_ch1_tmp = 0;
            int num_cycles_ch1 = 0;
        }
        else {
            personalized_estimulus_ch1 = 10;//repetitions_ch1 -> permitir que o valor seja escolhido na interface
        }

        if (ch2_state == 0x00 /*desligado*/ ) {
            n_samples_ch2_tmp = 0;
            int num_cycles_ch2 = 0;
        }
    }

    int personalized_estimulus_ch2 = personalized_estimulus_ch1;

    // Multiplicar o número de amostras personalizadas
    uint32_t total_samples_ch1 = n_samples_ch1_tmp * personalized_estimulus_ch1;
    uint32_t total_samples_ch2 = n_samples_ch2_tmp * personalized_estimulus_ch2;


    byte sample_num_pkg[8]; // Para armazenar 4 bytes para ch1 e 4 bytes para ch2

    // Canal 1
    sample_num_pkg[0] = (total_samples_ch1 >> 24) & 0xFF; // Byte mais significativo
    sample_num_pkg[1] = (total_samples_ch1 >> 16) & 0xFF;
    sample_num_pkg[2] = (total_samples_ch1 >> 8) & 0xFF;
    sample_num_pkg[3] = total_samples_ch1 & 0xFF;         // Byte menos significativo

    // Canal 2
    sample_num_pkg[4] = (total_samples_ch2 >> 24) & 0xFF; // Byte mais significativo
    sample_num_pkg[5] = (total_samples_ch2 >> 16) & 0xFF;
    sample_num_pkg[6] = (total_samples_ch2 >> 8) & 0xFF;
    sample_num_pkg[7] = total_samples_ch2 & 0xFF;         // Byte menos significativo
    comm->esSendConfig(ES_CMD_SAMPLE_NUM, sample_num_pkg, 8);

    // parte 6
    int num_cycles_ch1 = ui->protocoloEstimulacao_comboBox->currentText()=="Limitado" ? ui->ch1_spinBox_ciclos->value() : 1;
    int num_cycles_ch2 = ui->protocoloEstimulacao_comboBox->currentText()=="Limitado" ? ui->ch2_spinBox_ciclos->value() : 1;
    byte cycles_num_pkg[1] = {static_cast<byte>(num_cycles_ch1 + num_cycles_ch2)}; //deveria garantir que não passe de 1 byte
    comm->esSendConfig(ES_CMD_CYCLES_NUM, cycles_num_pkg, 1);

    // parte 7
    // Consulta o tipo selecionado em cada painel.
    // Mantém a convenção anterior de enviar zero para canais desativados.
    int ch1_stimulus_type = ch1_state == 0x01
                                ? channel1Panel->waveformIndex()
                                : 0;

    int ch2_stimulus_type = ch2_state == 0x01
                                ? channel2Panel->waveformIndex()
                                : 0;

    byte stimulus_type_pkg[1] = {static_cast<byte>(ch1_stimulus_type+ch2_stimulus_type)};
    comm->esSendConfig(ES_CMD_STIMULUS_TYPE,stimulus_type_pkg,1);

    // parte 8 - #1 /5
    // Pacote de frequência de amostragem
    const uint32_t FS_ch1 = 32000; // Constante 1 criada.
    const uint32_t FS_ch2 = 32000; // Constante 2 criada.

    byte sampling_frequency_pkg[8];

    // FS_ch2
    sampling_frequency_pkg[0] = (FS_ch2 >> 24) & 0xFF;
    sampling_frequency_pkg[1] = (FS_ch2 >> 16) & 0xFF;
    sampling_frequency_pkg[2] = (FS_ch2 >> 8) & 0xFF;
    sampling_frequency_pkg[3] = FS_ch2 & 0xFF;

    // FS_ch1
    sampling_frequency_pkg[4] = (FS_ch1 >> 24) & 0xFF;
    sampling_frequency_pkg[5] = (FS_ch1 >> 16) & 0xFF;
    sampling_frequency_pkg[6] = (FS_ch1 >> 8) & 0xFF;
    sampling_frequency_pkg[7] = FS_ch1 & 0xFF;

    comm->esSendConfig(ES_CMD_SAMPLING_FREQUENCY, sampling_frequency_pkg, 8);

    // Parte 8 - #2 /5
    // Tempo em ms
    double ton_ch1 = ui->doubleSpinBox_ton->value();
    double toff_ch1 = ui->doubleSpinBox_toff->value();

    double ton_ch2 = ton_ch1;
    double toff_ch2 = toff_ch1;

    uint32_t ton_ch1_ms = static_cast<uint32_t>(1000 * ton_ch1);
    uint32_t toff_ch1_ms = static_cast<uint32_t>(1000 * toff_ch1);
    uint32_t ton_ch2_ms = static_cast<uint32_t>(1000 * ton_ch2);
    uint32_t toff_ch2_ms = static_cast<uint32_t>(1000 * toff_ch2);

    byte ton_toff_pkg[16];

    // ton_ch1_ms
    ton_toff_pkg[0] = (ton_ch1_ms >> 24) & 0xFF;
    ton_toff_pkg[1] = (ton_ch1_ms >> 16) & 0xFF;
    ton_toff_pkg[2] = (ton_ch1_ms >> 8) & 0xFF;
    ton_toff_pkg[3] = ton_ch1_ms & 0xFF;

    // toff_ch1_ms
    ton_toff_pkg[4] = (toff_ch1_ms >> 24) & 0xFF;
    ton_toff_pkg[5] = (toff_ch1_ms >> 16) & 0xFF;
    ton_toff_pkg[6] = (toff_ch1_ms >> 8) & 0xFF;
    ton_toff_pkg[7] = toff_ch1_ms & 0xFF;

    // ton_ch2_ms
    ton_toff_pkg[8] = (ton_ch2_ms >> 24) & 0xFF;
    ton_toff_pkg[9] = (ton_ch2_ms >> 16) & 0xFF;
    ton_toff_pkg[10] = (ton_ch2_ms >> 8) & 0xFF;
    ton_toff_pkg[11] = ton_ch2_ms & 0xFF;

    // toff_ch2_ms
    ton_toff_pkg[12] = (toff_ch2_ms >> 24) & 0xFF;
    ton_toff_pkg[13] = (toff_ch2_ms >> 16) & 0xFF;
    ton_toff_pkg[14] = (toff_ch2_ms >> 8) & 0xFF;
    ton_toff_pkg[15] = toff_ch2_ms & 0xFF;

    comm->esSendConfig(ES_CMD_TON_TOFF, ton_toff_pkg, 16);

    // parte 8 - #3 /5
    // Protocolo
    int protocol = ui->spinBox_protocol->value(); // Modo personalizado
    byte protocol_pkg[1] = { static_cast<byte>(protocol) };
    comm->esSendConfig(ES_CMD_PROTOCOL, protocol_pkg, 1);

    // parte 8 - #4 /5
    // Tempo de disparo
    double trigger = ui->ch1_doubleSpinBox_trigger->value(); //só um trigger para 2 canais?
    uint32_t trigger_ms = static_cast<uint32_t>(1000 * trigger);

    byte time_trigg_pkg[4];
    time_trigg_pkg[0] = (trigger_ms >> 24) & 0xFF;
    time_trigg_pkg[1] = (trigger_ms >> 16) & 0xFF;
    time_trigg_pkg[2] = (trigger_ms >> 8) & 0xFF;
    time_trigg_pkg[3] = trigger_ms & 0xFF;

    comm->esSendConfig(ES_CMD_TIME_TRIGG, time_trigg_pkg, 4);

    // parte 8 - #5 /5
    // Intensidade do estímulo
    int i1i = static_cast<int>(ui->ch1_doubleSpinBox_I1i->value()); // Confirmar o tipo depois
    int i2i = static_cast<int>(ui->ch2_doubleSpinBox_I2i->value());

    // Identifica se a forma de onda selecionada é Personalizado.
    // O índice 5 corresponde à sexta opção da lista.
    const bool customCh1 = channel1Panel->waveformIndex() == 5;
    const bool customCh2 = channel2Panel->waveformIndex() == 5;

    // Prepara os parâmetros personalizados do canal 1.
    int personalized_stimulus_ch1_p1 = 0;
    int personalized_stimulus_ch1_p2 = 0;

    if (customCh1) {
        // Mantém os valores utilizados pelo código anterior.
        personalized_stimulus_ch1_p1 = i1i;
        personalized_stimulus_ch1_p2 = 10;
    }

    // Prepara os parâmetros personalizados do canal 2.
    int personalized_stimulus_ch2_p1 = 0;
    int personalized_stimulus_ch2_p2 = 0;

    if (customCh2) {
        // Mantém os valores utilizados pelo código anterior.
        personalized_stimulus_ch2_p1 = i2i;
        personalized_stimulus_ch2_p2 = 20;
    }

    // int personalized_stimulus_ch1_p1, personalized_stimulus_ch1_p2;
    // if (selected_stimulus == "Personalizado") {
    //     personalized_stimulus_ch1_p1 = i1i;
    //     personalized_stimulus_ch1_p2 = 10;
    // } else {
    //     personalized_stimulus_ch1_p1 = 0;
    //     personalized_stimulus_ch1_p2 = 0;
    // }

    // int personalized_stimulus_ch2_p1, personalized_stimulus_ch2_p2;
    // if (selected_stimulus_ch2 == "Personalizado") {
    //     personalized_stimulus_ch2_p1 = i2i;
    //     personalized_stimulus_ch2_p2 = 20;
    // } else {
    //     personalized_stimulus_ch2_p1 = 0;
    //     personalized_stimulus_ch2_p2 = 0;
    // }

    byte stimulus_intensity_pkg[6];
    stimulus_intensity_pkg[0] = static_cast<byte>(personalized_stimulus_ch1_p2);

    // personalized_stimulus_ch1_p1 (2 bytes)
    stimulus_intensity_pkg[1] = (personalized_stimulus_ch1_p1 >> 8) & 0xFF;
    stimulus_intensity_pkg[2] = personalized_stimulus_ch1_p1 & 0xFF;

    stimulus_intensity_pkg[3] = static_cast<byte>(personalized_stimulus_ch2_p2);

    // personalized_stimulus_ch2_p1 (2 bytes)
    stimulus_intensity_pkg[4] = (personalized_stimulus_ch2_p1 >> 8) & 0xFF;
    stimulus_intensity_pkg[5] = personalized_stimulus_ch2_p1 & 0xFF;

    comm->esSendConfig(ES_CMD_STIMULUS_INTENSITY, stimulus_intensity_pkg, 6);

    for (int i = 0; i < 10; i++){
        //qDebug()<<"data_out size:" <<strlen(data_out);
        //qDebug()<<"vetor size:" <<sizeof(data_out)/sizeof(data_out[0]);
        qDebug() << "npackages_stim_sent: " << npackages_stim_sent;
    }

    for (int i = 0; i < npackages_stim_sent; ++i) {
        std::vector<byte> current_package( /* copia parte de um vetor, do inicio ao fim de uma parte */
            vector_Estimulus.begin() + i * 256,/*inicio*/
            vector_Estimulus.begin() + i * 256 + 256/*fim*/
            );

        // Inserir 'i' no início do pacote -> * aqui o int i não será sendo devidamente separado e incluido no inicio
        //                                    * apenas um i de 0 até 255 e incluido corretamente
        current_package.insert(current_package.begin(), static_cast<byte>(0 & 0xFF));
        current_package.insert(current_package.begin(), static_cast<byte>(i & 0xFF));
        //printf("\ncurrent_package\n");
        unsigned k;
        for (k = 0; k < current_package.size(); k++){
            printf("%d\t",current_package[k]);
            if (k % 16 == 0 && k != 0)
                printf("\n");
        }
        //printf("c size: %d\n", k);

        for (unsigned index = 0; index < current_package.size(); index += 2){
            uint16_t valor = (( (uint16_t)current_package[index+1])<<8) | ((uint16_t)current_package[index]);
            printf("%d\t",valor);
            if (index % 16 == 0 && index != 0)
                printf("\n");
        }

        //cout<<"Tamanho vetor final: "<<current_package.size();

        // Enviar o pacote
        enviaEstimEletr(current_package.data(), static_cast<int>(current_package.size()));
    }


    // Chamar a função de finalização da transmissão
    char data_out[4096];
    comm->esSendCmd(ES_CMD_END_TRANSMISION, data_out);

    }//do if canal 1 ou 2 ativado
}

void MainWindow::startStimulations(){
    char data_out[4096];
    comm->esSendCmd(ES_CMD_PLAY_STIMULUS,data_out);
}

void MainWindow::stopStimulations() {
    char data_out[4096];
    comm->esSendCmd(ES_CMD_STOP_STIMULUS,data_out);
}

int MainWindow::enviaEstimEletr(byte *data_in,int size_data_in) {
    char data_out[4096];
    int resultado;
    int contador = 0;
    do{
        resultado = comm->esSendReceivePackage(ES_CMD_RECIVE_PACKAGE, data_in, size_data_in, data_out);
        qDebug()<<"resultado:"<<resultado;
        contador++;
        if (contador > 100) {
            qDebug()<<"passou do limite";
            break;
        }
    }
    while(resultado != OK || (byte)data_out[3] != (byte)25 );//std::strlen(data_out) < 5
    return (int)data_out[4];
}

void MainWindow::openRegisterPanel()
{
    patientPanel= new PatientPanel();

    patientPanel->show();
    patientPanel->raise();
    patientPanel->activateWindow();
}
void MainWindow::on_actionRegistrar_paciente_triggered()
{
    openRegisterPanel();
}

//Função salvar sessão
void MainWindow::saveSession()
{
    if (patientPanel == nullptr)
    {
        QMessageBox::warning(
            this,
            "Erro",
            "Registre um paciente antes de salvar a sessão."
            );
        return;
    }
    // Dados paciente (PatientPanel)
    QString name = patientPanel->getName();
    QString identifier = patientPanel->getIdentifier();
    QDate birthDate = patientPanel->getBirthDate();
    QString gender = patientPanel->getGender();
    QString examiner = patientPanel ->getExaminer();
    QString observations = patientPanel->getObservations();


    // Dados sessão (MainWindow UI)
    // Obtém os parâmetros configurados no novo painel do canal 1.
    int amplitudeCh1 = channel1Panel->amplitudeUa();
    int frequencyCh1 = channel1Panel->frequencyHz();
    QString waveformCh1 = channel1Panel->waveformText();

    // Obtém os parâmetros configurados no novo painel do canal 2.
    int amplitudeCh2 = channel2Panel->amplitudeUa();
    int frequencyCh2 = channel2Panel->frequencyHz();
    QString waveformCh2 = channel2Panel->waveformText();

    // //CH1
    // int amplitudeCh1 = ui->ch1_spinBox_ampl->value();
    // int frequencyCh1 = ui->ch1_spinBox_freq->value();
    // QString waveformCh1 = ui->ch1_comboBox_tipoEstimulo->currentText();

    // //CH2
    // int amplitudeCh2 = ui->ch2_spinBox_ampl->value();
    // int frequencyCh2 = ui->ch2_spinBox_freq->value();
    // QString waveformCh2 = ui->ch2_comboBox_tipoEstimulo->currentText();


    // Validacões
    if (name.isEmpty() || identifier.isEmpty())
    {
        QMessageBox::warning(this, "Erro", "Dados do paciente ausentes");
        return;
    }
    // Consulta quais canais estão selecionados na interface.
    const bool ch1Enabled = channel1Panel->isChannelEnabled();
    const bool ch2Enabled = channel2Panel->isChannelEnabled();

    // Exige pelo menos um canal selecionado para registrar a sessão.
    if (!ch1Enabled && !ch2Enabled) {
        QMessageBox::warning(
            this,
            "Erro",
            "Ative pelo menos um canal antes de salvar a sessão."
            );
        return;
    }

    // Valida apenas os parâmetros do canal 1 quando ele está selecionado.
    if (ch1Enabled) {
        if (amplitudeCh1 < 1 || amplitudeCh1 > 10000 ||
            frequencyCh1 < 1 || frequencyCh1 > 5000) {
            QMessageBox::warning(
                this,
                "Erro",
                "Verifique a amplitude e a frequência do canal 1."
                );
            return;
        }
    }

    // Valida apenas os parâmetros do canal 2 quando ele está selecionado.
    if (ch2Enabled) {
        if (amplitudeCh2 < 1 || amplitudeCh2 > 10000 ||
            frequencyCh2 < 1 || frequencyCh2 > 5000) {
            QMessageBox::warning(
                this,
                "Erro",
                "Verifique a amplitude e a frequência do canal 2."
                );
            return;
        }
    }
    // if (amplitudeCh1 < 1 || amplitudeCh1 > 10000)
    // {
    //     QMessageBox::warning(this, "Erro", "Amplitude inválida ");
    //     return;
    // }
    // if (frequencyCh1 < 1 || frequencyCh1 > 5000)
    // {
    //     QMessageBox::warning(this, "Erro", "Frequência inválida");
    //     return;
    // }

    // Salvar paciente
    Patient patient(name, identifier, birthDate, gender, examiner, observations);
    PatientRepository patientRepo;

    int patientId = patientRepo.savePatient(patient);

    if (patientId == -1)
    {
        QMessageBox::critical(this, "Erro", "Paciente não salvo");
        return;
    }

    // Salvar sessão
    Session session(
        patientId,
        amplitudeCh1,
        frequencyCh1,
        waveformCh1,

        amplitudeCh2,
        frequencyCh2,
        waveformCh2
        );
    SessionRepository sessionRepo;

    if (!sessionRepo.saveSession(session))
    {
        QMessageBox::critical(this, "Erro", "Parâmetros não salvos");
        return;
    }

    QMessageBox::information(this,
                             "Successo",
                             "Dados do paciente e parâmetros salvados corretamente");
}
//void MainWindow::on_saveDatapushButton_clicked()
//{saveSession();}

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
                          "<p>Equipamento de uso experimental. "));
}

//destrutor da classe MainWindow
MainWindow::~MainWindow()
{
    delete ui;
    delete comm;
}
