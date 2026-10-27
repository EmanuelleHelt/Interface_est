#include "patientPanel.h"
#include "ui_patientPanel.h"
#include <QMessageBox>


PatientPanel::PatientPanel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientPanel)
{
    ui->setupUi(this);
    //ui->birthDateEdit->setCalendarPopup(true);
    this->setStyleSheet(
        "QPushButton {"
        "   background-color: #2E86C1;"
        "   color: white;"
        "   border-radius: 8px;"
        "   padding: 10px 20px;"
        "}"
        );

}

PatientPanel::~PatientPanel()
{
    delete ui;
}

void PatientPanel::on_closeButton_clicked()
{
    close();
}

QString PatientPanel::getName() const
{
    return ui->nameLineEdit->text();
}

QString PatientPanel::getIdentifier() const
{
    return ui->identifierLineEdit->text();
}

QDate PatientPanel::getBirthDate() const
{
    return ui->birthDateEdit->date();
}
QString PatientPanel::getGender() const
{
    return ui->genderComboBox->currentText();
}

QString PatientPanel::getExaminer() const
{
    return ui->examinerLineEdit->text();
}

QString PatientPanel::getObservations() const
{
    return ui->observationsPlainTextEdit->toPlainText();
}
void PatientPanel::on_okpushButton_clicked()
{
    this->setFocus();

    QString nome = ui->nameLineEdit->text().trimmed();
    QString cpf = ui->identifierLineEdit->text().trimmed();

    if (nome.isEmpty() || cpf.isEmpty())
    {
        m_isValid = false;

        QMessageBox::warning(this,
                             "Erro",
                             "Preencha nome e CPF");
        return;
    }

    m_isValid = true;

    QMessageBox::information(this,
                             "Sucesso",
                             "Paciente validado com sucesso");
}
bool PatientPanel::isValid() const
{
    return m_isValid;
}

