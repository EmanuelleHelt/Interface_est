/*
 * ===============================================================
 *                      mainwindow.cpp
 * ===============================================================
 *
 * Autor: Julio Cesar S. Fernandes
 * Última Atualização: 09-nov-2024
 * Versão: 1.0
 *
 * ESP-IDF:
 * -
 *
 * Target/Board
 * - Estimulador Elétrico **Nome especifico?**
 *
 * Descrição:
 * - mainwindow.h é o header que declara as novas funções e classes que serão usadas
 * dentro do codigo mainwindow.cpp
 *
 * Dependências:
 * - "ES_UdpClient.h", "ES_WiFiClient.h"
 *
 * Instruções de Uso:
 * - Declare os prototipos das novas funções dentro do escopo de "private slots"
 * - Novos atributos que devem ser constantes durante a execução da interface podem ser
 * declarados em "private", ou onde for mais coerente.
 *
 * Histórico de Versões:
 * - Versão 1.0 (05-nov-2024): Teste final e comprovação de funcionamento.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPlainTextEdit>
#include <QDockWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QAction>
#include <QMessageBox>
#include <Qpainter>

#include "ES_UdpClient.h"
#include "ES_WiFiClient.h"

//Interface
#include "patientPanel.h"
#include "sideBar.h"
#include "channelPanel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class DurationPanel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ES_UdpClient *comm;  // Declare o objeto comm aqui
    ~MainWindow();

//signals:
//    void variableReceived();  // Sinal emitido quando a variável é recebida

private:
    Ui::MainWindow *ui;
    PatientPanel *patientPanel = nullptr;
    sideBar *sidebar = nullptr;
    //float* stim_ch1;
    //float* stim_ch2;
    void openRegisterPanel();
    void saveSession();
    // Painéis independentes dos dois canais.
    ChannelPanel *channel1Panel = nullptr;
    ChannelPanel *channel2Panel = nullptr;
    // Mantém o componente de duração geral.
    DurationPanel *durationPanel = nullptr;

    // Monta a nova área central da janela.
    void integrarPaineisCanais();
    // Integra o menu lateral e conecta suas ações.
    void configurarMenuLateral();

private slots:
    void test_connection();
    void send_parameters();
    void startStimulations();
    void stopStimulations();
    int enviaEstimEletr(byte *data_in, int size_data_in);
    void on_actionRegistrar_paciente_triggered();
    void on_actionSalvar_sessao_triggered();
    void on_actionSobre_triggered();

};
#endif // MAINWINDOW_H
