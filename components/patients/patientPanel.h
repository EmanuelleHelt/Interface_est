#ifndef PATIENTPANEL_H
#define PATIENTPANEL_H

#include <QDialog>
#include <QWidget>
#include "patient.h"

namespace Ui {
class PatientPanel;
}

class PatientPanel : public QDialog
{
    Q_OBJECT

public:
    explicit PatientPanel(QWidget *parent = nullptr);
    ~PatientPanel();
public:
    bool isValid() const;
    QString getName() const;
    QString getIdentifier() const;
    QDate getBirthDate() const;
    QString getGender() const;
    QString getExaminer() const;
    QString getObservations () const;



private slots:

    void on_closeButton_clicked();
    void on_okpushButton_clicked();

private:
    Ui::PatientPanel *ui;
    bool m_isValid = false;
};


#endif // PATIENTPANEL_H
