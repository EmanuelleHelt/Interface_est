#include "channelPanel.h"
#include "ui_channelPanel.h"
#include <QIntValidator>
#include <QEvent>
#include "qcustomplot.h"
#include <QVBoxLayout>
#include <QPainter>
#include "rampSettingsPanel.h"
ChannelSwitch::ChannelSwitch(QWidget *parent)
    : QCheckBox(parent)
{
    // Define o tamanho e os dois estados do interruptor.
    setFixedSize(84, 32);
    setTristate(false);
    setCursor(Qt::PointingHandCursor);
    setFocusPolicy(Qt::StrongFocus);
}

void ChannelSwitch::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const bool ligado = isChecked();

    // Seleciona a cor correspondente ao estado.
    QColor fundo = ligado
                       ? QColor("#2FB344")
                       : QColor("#ED171F");

    if (!isEnabled()) {
        fundo = QColor("#BDBDBD");
    }

    // Desenha o fundo arredondado.
    painter.setPen(Qt::NoPen);
    painter.setBrush(fundo);
    painter.drawRoundedRect(
        QRectF(0, 0, width(), height()), 16, 16);

    // Posiciona o círculo à direita em ON e à esquerda em OFF.
    const qreal diametro = height() - 6;
    const qreal circuloX = ligado
                               ? width() - diametro - 3
                               : 3;

    painter.setBrush(Qt::white);
    painter.drawEllipse(
        QRectF(circuloX, 3, diametro, diametro));

    // Posiciona o texto no lado oposto ao círculo.
    QFont fonte = font();
    fonte.setBold(true);
    fonte.setPixelSize(13);
    painter.setFont(fonte);
    painter.setPen(Qt::white);

    const QRect areaTexto = ligado
                                ? QRect(4, 0, 44, height())
                                : QRect(33, 0, 47, height());

    painter.drawText(
        areaTexto,
        Qt::AlignCenter,
        ligado ? "ON" : "OFF");

    // Mostra o foco durante a navegação pelo teclado.
    if (hasFocus()) {
        painter.setBrush(Qt::NoBrush);
        painter.setPen(QPen(Qt::white, 1, Qt::DotLine));
        painter.drawRoundedRect(
            QRectF(2, 2, width() - 4, height() - 4),
            14, 14);
    }
}

bool ChannelSwitch::hitButton(const QPoint &position) const
{
    // Aceita cliques em toda a área do interruptor.
    return rect().contains(position);
}
ChannelPanel::ChannelPanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChannelPanel)
{
    ui->setupUi(this);
    // Inicializa os gráficos apenas durante a criação deste painel.
    inicializarGraficos();
    ui->channelEnabledCheckBox->setChecked(false);
    ui->channelEnabledCheckBox->setText("OFF");

    connect(ui->channelEnabledCheckBox, &QCheckBox::toggled,
            this, [this](bool enabled) {
                ui->channelEnabledCheckBox->setText(enabled ? "ON" : "OFF");
                emit channelEnabledChanged(enabled);
            });

    //------------------FREQUENCY
    ui->frequencyValueEdit->setValidator(
        new QIntValidator(0, 5000, this)
        );
    ui->frequencyValueEdit->setText(
        QString::number(m_frequencyHz)
        );

    // Reduz a frequência
    connect(ui->frequencyMinusButton, &QPushButton::clicked,
            this, [this]() {
                setFrequencyHz(m_frequencyHz - 1);
            });
    // Aumenta a frequência
    connect(ui->frequencyPlusButton, &QPushButton::clicked,
            this, [this]() {
                setFrequencyHz(m_frequencyHz + 1);
            });

    connect(ui->frequencyValueEdit, &QLineEdit::editingFinished,
            this, [this]() {
                if (ui->frequencyValueEdit->hasAcceptableInput()) {
                    setFrequencyHz(ui->frequencyValueEdit->text().toInt());
                } else {
                    ui->frequencyValueEdit->setText(
                        QString::number(m_frequencyHz)
                        );
                }
            });

    //------------------AMPLITUDE
    // Define o intervalo de entrada da interface anterior.
    ui->amplitudeValueEdit->setValidator(
        new QIntValidator(0, 10000, this)
        );
    // Mostra a amplitude inicialmente armazenada.
    ui->amplitudeValueEdit->setText(
        QString::number(m_amplitudeUa)
        );
    // Reduz a amplitude
    connect(ui->amplitudeMinusButton, &QPushButton::clicked,
            this, [this]() {
                setAmplitudeUa(m_amplitudeUa - 1);
            });
    // Aumenta a amplitude
    connect(ui->amplitudePlusButton, &QPushButton::clicked,
            this, [this]() {
                setAmplitudeUa(m_amplitudeUa + 1);
            });
    // Confirma o valor digitado quando a entrada é válida.
    connect(ui->amplitudeValueEdit, &QLineEdit::editingFinished,
            this, [this]() {
                if (ui->amplitudeValueEdit->hasAcceptableInput()) {
                    setAmplitudeUa(ui->amplitudeValueEdit->text().toInt());
                }
            });

    //---------------WAVEFORM
    // Encaminha a alteração do seletor para os outros componentes.
    // Funciona tanto para seleção manual quanto por código.
    connect(
        ui->waveformComboBox,
        QOverload<int>::of(&QComboBox::currentIndexChanged),
        this,
        &ChannelPanel::waveformChanged
        );

    // Observa a perda de foco, inclusive quando o campo está vazio.
    ui->frequencyValueEdit->installEventFilter(this);
    ui->amplitudeValueEdit->installEventFilter(this);

    //------------------ RAMPA
    // Insere os ajustes de Rampa no contêiner de protocolos.
    rampSettingsPanel = new RampSettingsPanel(ui->protocolSettingsStack);
    ui->protocolSettingsStack->addWidget(rampSettingsPanel);

    // Começa sem mostrar ajustes específicos de Rampa.
    setRampMode(false);
}

// ---------------- CHANNELS 1-2
void ChannelPanel::setChannelNumber(int number)
{
    // Atualiza o título para identificar o canal correspondente.
    ui->channelTitleLabel->setText(
        QString("Canal %1").arg(number)
        );
}
bool ChannelPanel::isChannelEnabled() const
{
    // Consulta a seleção na interface; não confirma o estado do equipamento.
    return ui->channelEnabledCheckBox->isChecked();
}

//------------------FREQUENCY
int ChannelPanel::frequencyHz() const
{
    // Permite consultar a frequência sem acessar os widgets diretamente.
    return m_frequencyHz;
}

void ChannelPanel::setFrequencyHz(int frequency)
{
    // Limita o valor ao intervalo de 0 a 5000 Hz.
    const int newFrequency = qBound(0, frequency, 5000);

    // Atualiza o texto, inclusive quando o valor armazenado não muda.
    ui->frequencyValueEdit->setText(
        QString::number(newFrequency)
        );

    // Evita emitir um sinal quando a frequência permanece igual.
    if (newFrequency == m_frequencyHz)
        return;

    // Armazena o novo valor nesta instância do painel.
    m_frequencyHz = newFrequency;

    // Comunica a alteração, sem enviar comandos ao equipamento.
    emit frequencyChanged(m_frequencyHz);
}

//------------- AMPLITUDE
int ChannelPanel::amplitudeUa() const
{
    // Retorna o valor configurado; não é uma medição da saída.
    return m_amplitudeUa;
}
void ChannelPanel::setAmplitudeUa(int amplitude)
{
    // Mantém o valor dentro do intervalo definido para a interface.
    const int newAmplitude = qBound(0, amplitude, 10000);
    // Sincroniza o campo visível com o valor aceito.
    ui->amplitudeValueEdit->setText(
        QString::number(newAmplitude)
        );
    // Evita notificações quando o valor não muda.
    if (newAmplitude == m_amplitudeUa)
        return;
    // Atualiza apenas o estado desta instância do painel.
    m_amplitudeUa = newAmplitude;

    // Informa a alteração sem enviar comandos ao equipamento.
    emit amplitudeChanged(m_amplitudeUa);
}
// -----------------WAVEFORM
int ChannelPanel::waveformIndex() const
{
    return ui->waveformComboBox->currentIndex();
}

void ChannelPanel::setWaveformIndex(int index)
{
    // Ignora índices que não correspondem a uma opção existente.
    if (index < 0 || index >= ui->waveformComboBox->count())
        return;

    // A mudança emite currentIndexChanged e, consequentemente,
    // waveformChanged. Não é necessário emitir o sinal novamente.
    ui->waveformComboBox->setCurrentIndex(index);

}

//---------- ENTRADAS VÁLIDAS
bool ChannelPanel::eventFilter(QObject *watched, QEvent *event)
{
    // Confirma ou restaura o conteúdo quando o usuário sai do campo.
    if (event->type() == QEvent::FocusOut) {

        if (watched == ui->frequencyValueEdit) {
            if (ui->frequencyValueEdit->hasAcceptableInput()) {
                // Confirma a frequência digitada.
                setFrequencyHz(
                    ui->frequencyValueEdit->text().toInt()
                    );
            } else {
                // Restaura a última frequência válida.
                setFrequencyHz(m_frequencyHz);
            }
        }

        else if (watched == ui->amplitudeValueEdit) {
            if (ui->amplitudeValueEdit->hasAcceptableInput()) {
                // Confirma a amplitude digitada.
                setAmplitudeUa(
                    ui->amplitudeValueEdit->text().toInt()
                    );
            } else {
                // Restaura a última amplitude válida.
                setAmplitudeUa(m_amplitudeUa);
            }
        }
    }

    // Mantém o processamento normal dos eventos do widget.
    return QWidget::eventFilter(watched, event);
}

QString ChannelPanel::waveformText() const
{
    // Consulta o texto apresentado no seletor deste canal.
    return ui->waveformComboBox->currentText();
}
// ----------------- GRAPHICS

void ChannelPanel::inicializarGraficos()
{
    // Cria o gráfico dentro da aba de forma de onda.
    waveformPlot = new QCustomPlot(ui->tab_1);

    auto *waveformLayout = new QVBoxLayout(ui->tab_1);
    waveformLayout->setContentsMargins(0, 0, 0, 0);
    waveformLayout->addWidget(waveformPlot);

    // Cria o gráfico dentro da aba de evolução do protocolo.
    protocolPlot = new QCustomPlot(ui->tab_2);

    auto *protocolLayout = new QVBoxLayout(ui->tab_2);
    protocolLayout->setContentsMargins(0, 0, 0, 0);
    protocolLayout->addWidget(protocolPlot);

    // Prepara uma curva em cada gráfico.
    QCustomPlot *graficos[] = {waveformPlot, protocolPlot};

    for (QCustomPlot *grafico : graficos) {
        grafico->addGraph();
        grafico->xAxis->setLabel("Tempo (s)");
        grafico->yAxis->setLabel("Amplitude (µA)");
    }

    // Mostra inicialmente a aba de forma de onda.
    ui->channelGraphsTabWidget->setCurrentIndex(0);
}
//------------------ RAMPA
void ChannelPanel::setRampMode(bool enabled)
{
    if (enabled) {
        // Mostra os ajustes de Rampa deste canal.
        ui->protocolSettingsStack->setCurrentWidget(rampSettingsPanel);
        ui->amplitudeLabel->setText("Amplitude inicial (µA)");
    } else {
        // Retorna à página sem ajustes específicos.
        ui->protocolSettingsStack->setCurrentWidget(ui->emptyProtocolPage);
        ui->amplitudeLabel->setText("Amplitude (µA)");
    }

    // Oculta o espaço de ajustes quando não está em modo Rampa.
    ui->protocolSettingsStack->setVisible(enabled);
}

ChannelPanel::~ChannelPanel()
{
    delete ui;
}

