#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDate>

class Patient
{
public:
    Patient(
        const QString &name,
        const QString &identifier,
        const QDate &birthDate,
        const QString &gender,
        const QString &examiner,
        const QString &observations
        );


    QString name() const;
    QString identifier() const;
    QDate birthDate() const;
    QString gender() const;
    QString examiner() const;
    QString observations() const;

    void setName(const QString &name);
    void setIdentifier( const QString &identifier);
    void setBirthDate(const QDate &date);
    void setGender(const QString &gender);
    void setExaminer(const QString &examiner);
    void setObservations(const QString &observations);


private:
    QString m_name;
    QString m_identifier;
    QDate m_birthDate;
    QString m_gender;
    QString m_examiner;
    QString m_observations;

};

#endif // PATIENT_H
