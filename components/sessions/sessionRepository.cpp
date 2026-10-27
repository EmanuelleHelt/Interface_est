#include "sessionRepository.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

bool SessionRepository::saveSession(const Session &session)
{
    QString pastaProjeto = QDir::currentPath();
    QString pastaDados = QDir(pastaProjeto).filePath("Registros");

    if (!QDir().mkpath(pastaDados)) {
        qDebug() << "Erro ao criar a pasta:" << pastaDados;
        return false;
    }

    QString caminhoArquivo =
        QDir(pastaDados).filePath("sessions.csv");

    qDebug() << "Diretorio atual:" << pastaProjeto;
    qDebug() << "Salvando sessao em:" << caminhoArquivo;

    QFile file(caminhoArquivo);
    bool exists = file.exists();

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Erro ao abrir o arquivo:"
                 << file.errorString();
        return false;
    }

    QTextStream out(&file);

    if (!exists)
        out << "patient_id,amplitudeCh1,frequencyCh1,waveformCh1,amplitudeCh2,frequencyCh2,waveformCh2,date\n";

    out << session.patientId() << ","
        << session.amplitudeCh1() << ","
        << session.frequencyCh1() << ","
        << session.waveformCh1() << ","
        << session.amplitudeCh2() << ","
        << session.frequencyCh2() << ","
        << session.waveformCh2() << ","

        << session.date().toString("yyyy-MM-dd")
        << "\n";

    file.close();

    qDebug()<< "Sessão salva em:"
             <<caminhoArquivo;
    return true;
}