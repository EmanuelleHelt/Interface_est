#include "session.h"

Session::Session( int patientId,
                 int amplitudeCh1,
                 int frequencyCh1,
                 const QString &waveformCh1,
                 int amplitudeCh2,
                 int frequencyCh2,
                 const QString &waveformCh2)

    :m_patientId (patientId),
    m_amplitudeCh1 (amplitudeCh1),
    m_frequencyCh1 (frequencyCh1),
    m_waveformCh1 (waveformCh1),

    m_amplitudeCh2 (amplitudeCh2),
    m_frequencyCh2 (frequencyCh2),
    m_waveformCh2 (waveformCh2),
    m_date(QDateTime::currentDateTime())
{
}
int Session::patientId() const
{return m_patientId;}

int Session::amplitudeCh1() const
{ return m_amplitudeCh1; }
int Session::frequencyCh1() const
{ return m_frequencyCh1; }
QString Session::waveformCh1() const
{ return m_waveformCh1;}

int Session::amplitudeCh2() const
{ return m_amplitudeCh2; }
int Session::frequencyCh2() const
{ return m_frequencyCh2; }
QString Session::waveformCh2() const
{ return m_waveformCh2;}
QDateTime Session::date() const
{ return m_date; }
