#ifndef RAMPSETTINGSPANEL_H
#define RAMPSETTINGSPANEL_H

#include <QWidget>

namespace Ui {
class RampSettingsPanel;
}

class RampSettingsPanel : public QWidget
{
    Q_OBJECT

public:
    explicit RampSettingsPanel(QWidget *parent = nullptr);
    ~RampSettingsPanel();
    // Consulta e atualiza o incremento de amplitude da rampa.
    int stepAmplitudeUa() const;
    void setStepAmplitudeUa(int value);
    // Consulta e atualiza o tempo de estimulação, em segundos.
    double stimulationTimeS() const;
    void setStimulationTimeS(double value);
    // Consulta e atualiza o tempo de repouso, em segundos.
    double restTimeS() const;
    void setRestTimeS(double value);
signals:
    // Informa alterações do passo configurado.
    void stepAmplitudeChanged(int value);
    // Informa alterações do tempo de estimulação configurado.
    void stimulationTimeChanged(double seconds);
    // Informa alterações do tempo de repouso configurado.
    void restTimeChanged(double seconds);
protected:
    // Verifica os campos quando eles perdem o foco.
    bool eventFilter(QObject *watched, QEvent *event) override;
private:
    Ui::RampSettingsPanel *ui;
    int m_stepAmplitudeUa = 0;
    double m_stimulationTimeS = 0.0;
    double m_restTimeS = 0.0;
    // Organiza os parâmetros de Rampa em três linhas compactas.
    void organizarLayout();
};

#endif // RAMPSETTINGSPANEL_H
