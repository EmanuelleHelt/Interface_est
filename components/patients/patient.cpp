
#include "patient.h"

Patient::Patient(const QString &name,
                 const QString &identifier,
                 const QDate &birthDate,
                 const QString &gender,
                 const QString &examiner,
                 const QString &observations)

    :   m_name(name),
    m_identifier(identifier),
    m_birthDate(birthDate),
    m_gender(gender),
    m_examiner(examiner),
    m_observations(observations)

{
}

QString Patient :: name() const {
    return m_name;
}
QString Patient :: identifier() const {
    return m_identifier;
}
QDate Patient :: birthDate () const {
    return m_birthDate;
}
QString Patient ::gender() const{
    return m_gender;
}
QString Patient :: examiner() const{
    return m_examiner;
}
QString Patient :: observations() const{
    return m_observations;
}

void Patient:: setName (const QString &name)
{ m_name =name;}

void Patient :: setIdentifier (const QString &identifier)
{ m_identifier= identifier;}

void Patient :: setBirthDate (const QDate &date)
{ m_birthDate= date;}

void Patient :: setGender(const QString &gender)
{ m_gender= gender;}

void Patient :: setExaminer(const QString &examiner)
{ m_examiner= examiner;}

void Patient :: setObservations(const QString &observations)
{ m_observations= observations;}
