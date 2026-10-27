#ifndef DURATIONPANEL_H
#define DURATIONPANEL_H

#include <QWidget>

class QLineEdit;

class DurationPanel : public QWidget
{
public:
    explicit DurationPanel(QWidget *parent = nullptr);

    // Consulta a duração configurada, em segundos.
    int durationSeconds() const;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QLineEdit *m_valueEdit = nullptr;
    int m_seconds = 300;

    void ajustarDuracao(int direction);
    void restaurarCampo();
    QString textoDuracao() const;
};

#endif // DURATIONPANEL_H