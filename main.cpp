/*
 * ===============================================================
 *                           main.cpp
 * ===============================================================
 *
 * Autor: Qt
 * Última Atualização: -/-/-
 *
 * Descrição:
 * - O arquivo main.cpp é criado por padrão em todos os projetos do Qt/C++
 * nenhuma alteração foi feita neste arquivo
 *
 * Instruções de Uso:
 * - A função main apenas convoca a interface. Não é necessário alterar esse codigo
 * até o momento.
 *
 * Histórico de Versões:
 * - Versão Unica.
 */


#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include "patientPanel.h"
#include "channelPanel.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Carrega o estilo global incluído nos recursos da aplicação.
    QFile styleFile(":/styles/style.qss");

    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        a.setStyleSheet(QString::fromUtf8(styleFile.readAll()));
    } else {
        qWarning() << "Não foi possível carregar o estilo:"
                   << styleFile.errorString();
    }


  MainWindow w;
   w.show();
  return a.exec();
    // // Janela temporária para testar os dois painéis.
    // // A MainWindow não é criada durante esta verificação.
    // QWidget testWindow;
    // testWindow.setWindowTitle("Teste dos painéis de canal");
    // testWindow.resize(1100, 750);

    // // Organiza os dois canais lado a lado.
    // auto *layout = new QHBoxLayout(&testWindow);

    // // Cria duas instâncias independentes do mesmo componente.
    // auto *channel1Panel = new ChannelPanel(&testWindow);
    // auto *channel2Panel = new ChannelPanel(&testWindow);

    // // Identifica cada painel.
    // channel1Panel->setChannelNumber(1);
    // channel2Panel->setChannelNumber(2);

    // // Distribui igualmente o espaço horizontal.
    // layout->addWidget(channel1Panel, 1);
    // layout->addWidget(channel2Panel, 1);

    // testWindow.show();
    // return a.exec();
}
