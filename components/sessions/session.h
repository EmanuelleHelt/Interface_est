#ifndef SESSION_H
#define SESSION_H
#include <QString>
#include <QDateTime>

class Session
{
public:
    Session(int patientId,
            int amplitudeCh1,
            int frequencyCh1,
            const QString &waveformCh1,

            int amplitudeCh2,
            int frequencyCh2,
            const QString &waveformCh2);

    int patientId() const;

    int amplitudeCh1() const;
    int frequencyCh1 () const;
    QString waveformCh1() const;

    int amplitudeCh2() const;
    int frequencyCh2 () const;
    QString waveformCh2() const;

    QDateTime date() const;

    private:
        int m_patientId;

        int m_amplitudeCh1;
        int m_frequencyCh1;
        QString m_waveformCh1;

        int m_amplitudeCh2;
        int m_frequencyCh2;
        QString m_waveformCh2;

        QDateTime m_date;
};


#endif // SESSION_H
