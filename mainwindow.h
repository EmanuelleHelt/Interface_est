/*
 * ===============================================================
 *                      mainwindow.h
 * ===============================================================
 *
 * Autor: Julio Cesar S. Fernandes & Emanuelle Helt
 * Última Atualização: Novembro-2026
 * Versão: 1.1
 *
 * Target/Board
 * - Estimulador Elétrico v7 (Brasil)
 *
 * Descrição:
 * - Declaração da classe MainWindow, responsável por atuar como o
 *   controlador principal da aplicação, orquestrando a UI e os
 *   protocolos de comunicação (Elétrica e Auditiva).
 *
 * Histórico de Versões:
 * - Versão 1.0 (05-nov-2024): Teste final e comprovação de funcionamento.
 * - Versão 1.1 (nov-2026): Implementação de abas (Elétrico/Auditivo/Misto),
 *   conexões de sinais do sidePanel e documentação Doxygen.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTime>
#include <QByteArray>

// Forward declarations para otimizar o tempo de compilação
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ES_UdpClient;
class Aud_UdpClient;
class sidePanel;
class PatientPanel;
class sideBar;
class ChannelPanel;
class DurationPanel;
class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Deixado público caso classes externas precisem acessar a rede diretamente,
    // mas o ideal futuro é criar métodos 'getters'.
    ES_UdpClient *comm;

private:
    // ==========================================
    // INSTÂNCIAS DA INTERFACE (UI)
    // ==========================================
    Ui::MainWindow *ui;
    PatientPanel *patientPanel = nullptr;
    sideBar *sidebar = nullptr;
    ChannelPanel *channel1Panel = nullptr;
    ChannelPanel *channel2Panel = nullptr;
    DurationPanel *durationPanel = nullptr;
    sidePanel *painelAuditivo = nullptr;

    // ==========================================
    // GERENCIAMENTO DO ESTIMULADOR AUDITIVO
    // ==========================================
    Aud_UdpClient *comm_aud;
    QTimer *timerAudio;
    QByteArray bufferAudioCompleto;
    int indiceLeitura = 0;
    const int TAM_PACOTE = 128;

    // ==========================================
    // MÉTODOS DE CONFIGURAÇÃO DA UI
    // ==========================================
    /**
     * @brief Configura e integra o menu lateral (sideBar).
     */
    void configurarMenuLateral();

    /**
     * @brief Constrói a área central com abas (Elétrico, Auditivo, Misto)
     *        e instancia os sub-painéis de controle.
     */
    void integrarPaineisCanais();

    /**
     * @brief Abre o painel de registro de novo paciente.
     */
    void openRegisterPanel();

    /**
     * @brief Salva os dados do paciente e da sessão atual no banco de dados.
     */
    void saveSession();

private slots:
    // ==========================================
    // SLOTS: CONTROLES GERAIS E ELÉTRICOS
    // ==========================================
    void test_connection();
    void send_parameters();
    void startStimulations();
    void stopStimulations();

    /**
     * @brief Envia um pacote de dados para o estimulador elétrico e aguarda resposta.
     * @param data_in Ponteiro para o array de bytes a ser enviado.
     * @param size_data_in Tamanho do pacote.
     * @return Retorna o status/código de erro recebido do estimulador.
     */
    int enviaEstimEletr(uint8_t *data_in, int size_data_in);

    // ==========================================
    // SLOTS: MENUS SUPERIORES
    // ==========================================
    void on_actionRegistrar_paciente_triggered();
    void on_actionSalvar_sessao_triggered();
    void on_actionSobre_triggered();

    // ==========================================
    // SLOTS: CONTROLES DO ESTIMULADOR AUDITIVO
    // ==========================================
    void aud_testar_conexao();
    void aud_iniciar_estimulo();
    void aud_parar_estimulo();
    void verificarPedidoAudio();
    void prepararSinalWAV(QString caminho);
    void aud_selecionar_audio();
    void aud_alterar_volume(int vol_dir, int vol_esq);

    // ==========================================
    // SLOTS: PAINEL AUDITIVO (UI -> MAINWINDOW)
    // ==========================================
    void aud_canalEstimuloAlterado(int index);
    void aud_tipoEstimuloAlterado(int index);
    void aud_reproducaoCiclicaToggled(bool checked);
    void aud_tempoReproducaoCiclicaAlterado(const QTime &tempo);
    void aud_duracaoEstimuloAlterada(const QTime &tempo);
    void aud_freqAudioAlterada(int valor);
    void aud_duracaoMsAlterada(int valor);
    void aud_amplitudeAlterada(int valor);
    void aud_freqPortadoraAlterada(int valor);
    void aud_freqModulacaoAlterada(int valor);
    void aud_fatorAMAlterado(int valor);
    void aud_exponencialModAlterada(int valor);
    void aud_faseFMAlterada(int valor);
    void aud_fatorFMAlterado(int valor);
};

#endif // MAINWINDOW_H