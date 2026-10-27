#ifndef CHANNELPANEL_H
#define CHANNELPANEL_H

#include <QWidget>
#include <QCheckBox>

namespace Ui {
class ChannelPanel;

}
// Declara o tipo sem incluir toda a biblioteca neste cabeçalho.
class QCustomPlot;
class RampSettingsPanel;
// Interruptor visual para habilitar ou desabilitar o canal.
class ChannelSwitch : public QCheckBox
{
public:
    explicit ChannelSwitch(QWidget *parent = nullptr);

protected:
    // Desenha o fundo, o círculo e o texto ON/OFF.
    void paintEvent(QPaintEvent *event) override;

    // Permite clicar em toda a área do interruptor.
    bool hitButton(const QPoint &position) const override;
};

class ChannelPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelPanel(QWidget *parent = nullptr);
    ~ChannelPanel();

    void setChannelNumber(int number); //CH1 CH2
    bool isChannelEnabled() const; //ON OFF

    // Consulta e atualiza a frequência configurada.
    int frequencyHz() const;
    void setFrequencyHz(int frequency);
    // Consulta e atualiza a amplitude configurada.
    int amplitudeUa() const;
    void setAmplitudeUa(int amplitude);
    // Consulta e seleciona a forma de onda selecionada  pelo índice da lista.
    int waveformIndex() const;
    void setWaveformIndex(int index);
    // Retorna o nome da forma de onda selecionada para o registro.
    QString waveformText() const;
    // Alterna entre os ajustes de Rampa e a apresentação comum.
    void setRampMode(bool enabled);


protected:
    // Trata eventos dos campos antes do processamento padrão do Qt.
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::ChannelPanel *ui;

    int m_frequencyHz = 0;
    int m_amplitudeUa = 0;
    // Cada instância do painel possui seus próprios gráficos.
    QCustomPlot *waveformPlot = nullptr;
    QCustomPlot *protocolPlot = nullptr;

    // Cria e configura os gráficos uma única vez.
    void inicializarGraficos();
    // Cada canal possui sua própria instância dos ajustes de Rampa.
    RampSettingsPanel *rampSettingsPanel = nullptr;


signals:
    void channelEnabledChanged(bool enabled);
    void frequencyChanged(int frequencyHz);
    void amplitudeChanged(int amplitudeUa);
    void waveformChanged(int index);
};

#endif // CHANNELPANEL_H
