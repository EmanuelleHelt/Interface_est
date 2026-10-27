#include "patientRepository.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

int PatientRepository::savePatient(const Patient &patient)
{
    QString pastaProjeto = QDir::currentPath();
    QString pastaDados = QDir(pastaProjeto).filePath("Registros");

    if (!QDir().mkpath(pastaDados)) {
        qDebug() << "Erro ao criar a pasta:" << pastaDados;
        return -1;
    }

    QString caminhoArquivo =
        QDir(pastaDados).filePath("patients.csv");

    qDebug() << "Diretorio atual:" << pastaProjeto;
    qDebug() << "Salvando paciente em:" << caminhoArquivo;

    QFile file(caminhoArquivo);
    bool exists = file.exists();

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Erro ao abrir o arquivo:"
                 << file.errorString();
        return -1;
    }

    QTextStream out(&file);

    if (!exists)
        out << "id,name,identifier,birthdate\n,gender,examiner,observations";

    static int idCounter = 1;
    int id = idCounter++;

    QString nomePaciente = patient.name();
    nomePaciente.replace(",", " ");

    out << id << ","
        << nomePaciente << ","
        << patient.identifier() << ","
        << patient.birthDate().toString("yyyy-MM-dd")<<","
        <<patient.gender()<<","
        <<patient.examiner()<<","
        <<patient.observations()
        << "\n";

    file.close();
    return id;
}