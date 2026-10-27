#include "rampSettingsPanel.h"
#include "ui_rampSettingsPanel.h"
#include <QIntValidator>
#include <QLineEdit>
#include <QPushButton>
#include <QDoubleValidator>
#include <QLocale>
#include <cmath>
#include <QEvent>
#include <QGridLayout>
#include <QLabel>

RampSettingsPanel::RampSettingsPanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RampSettingsPanel)
{
    ui->setupUi(this);
    // Organiza os controles antes de configurar seu comportamento.
    organizarLayout();
    // Usa o intervalo de amplitude da interface atual.
    // Os limites físicos do equipamento serão verificados separadamente.
    ui->stepAmplitudeValueEdit->setValidator(
        new QIntValidator(0, 10000, this)
        );
    // Mostra o valor inicialmente armazenado neste painel.
    ui->stepAmplitudeValueEdit->setText(
        QString::number(m_stepAmplitudeUa)
        );

    // Diminui o passo configurado em 1 µA.
    connect(ui->stepAmplitudeMinusButton, &QPushButton::clicked,
            this, [this]() {
                setStepAmplitudeUa(m_stepAmplitudeUa - 1);
            });
    // Aumenta o passo configurado em 1 µA.
    connect(ui->stepAmplitudePlusButton, &QPushButton::clicked,
            this, [this]() {
                setStepAmplitudeUa(m_stepAmplitudeUa + 1);
            });

    // Confirma entradas válidas ao concluir a edição.
    // O tratamento de campos vazios será adicionado depois.
    connect(ui->stepAmplitudeValueEdit, &QLineEdit::editingFinished,
            this, [this]() {
                if (ui->stepAmplitudeValueEdit->hasAcceptableInput()) {
                    setStepAmplitudeUa(
                        ui->stepAmplitudeValueEdit->text().toInt()
                        );
                }
            });

    // Aceita segundos não negativos com uma casa decimal.
    // Usa ponto como separador decimal, por exemplo: 0.5.
    auto *timeValidator = new QDoubleValidator(this);
    timeValidator->setBottom(0.0);
    timeValidator->setDecimals(1);
    timeValidator->setNotation(QDoubleValidator::StandardNotation);
    timeValidator->setLocale(QLocale::c());

    ui->stimulationTimeValueEdit->setValidator(timeValidator);
    ui->stimulationTimeValueEdit->setText("0.0");

    // Reduz o tempo configurado em 0,1 segundo.
    connect(ui->stimulationTimeMinusButton, &QPushButton::clicked,
            this, [this]() {
                setStimulationTimeS(m_stimulationTimeS - 0.1);
            });

    // Aumenta o tempo configurado em 0,1 segundo.
    connect(ui->stimulationTimePlusButton, &QPushButton::clicked,
            this, [this]() {
                setStimulationTimeS(m_stimulationTimeS + 0.1);
            });

    // Confirma o número digitado usando o mesmo separador do validador.
    connect(ui->stimulationTimeValueEdit, &QLineEdit::editingFinished,
            this, [this]() {
                if (!ui->stimulationTimeValueEdit->hasAcceptableInput())
                    return;

                bool ok = false;
                const double value = QLocale::c().toDouble(
                    ui->stimulationTimeValueEdit->text(), &ok
                    );

                if (ok)
                    setStimulationTimeS(value);
            });
    // Aceita segundos não negativos com uma casa decimal.
    // Usa ponto como separador decimal, por exemplo: 0.5.
    auto *restValidator = new QDoubleValidator(this);
    restValidator->setBottom(0.0);
    restValidator->setDecimals(1);
    restValidator->setNotation(QDoubleValidator::StandardNotation);
    restValidator->setLocale(QLocale::c());

    ui->restTimeValueEdit->setValidator(restValidator);
    ui->restTimeValueEdit->setText("0.0");

    // Reduz o repouso em 0,1 segundo.
    connect(ui->restTimeMinusButton, &QPushButton::clicked,
            this, [this]() {
                setRestTimeS(m_restTimeS - 0.1);
            });

    // Aumenta o repouso em 0,1 segundo.
    connect(ui->restTimePlusButton, &QPushButton::clicked,
            this, [this]() {
                setRestTimeS(m_restTimeS + 0.1);
            });

    // Confirma a entrada válida usando o mesmo formato do validador.
    connect(ui->restTimeValueEdit, &QLineEdit::editingFinished,
            this, [this]() {
                if (!ui->restTimeValueEdit->hasAcceptableInput())
                    return;

                bool ok = false;
                const double value = QLocale::c().toDouble(
                    ui->restTimeValueEdit->text(), &ok
                    );

                if (ok)
                    setRestTimeS(value);
            });
    // Observa a saída dos campos, inclusive quando estão vazios.
    ui->stepAmplitudeValueEdit->installEventFilter(this);
    ui->stimulationTimeValueEdit->installEventFilter(this);
    ui->restTimeValueEdit->installEventFilter(this);
}




int RampSettingsPanel::stepAmplitudeUa() const
{
    // Retorna o passo configurado neste canal.
    return m_stepAmplitudeUa;
}

void RampSettingsPanel::setStepAmplitudeUa(int value)
{
    // Limita o valor ao intervalo da interface.
    const int newValue = qBound(0, value, 10000);

    // Sincroniza o campo com o valor aceito.
    ui->stepAmplitudeValueEdit->setText(
        QString::number(newValue)
        );

    // Evita notificações repetidas.
    if (newValue == m_stepAmplitudeUa)
        return;

    m_stepAmplitudeUa = newValue;
    emit stepAmplitudeChanged(m_stepAmplitudeUa);
}
double RampSettingsPanel::stimulationTimeS() const
{
    // Retorna o tempo configurado neste painel.
    return m_stimulationTimeS;
}

void RampSettingsPanel::setStimulationTimeS(double value)
{
    // Ignora valores que não representam um número finito.
    if (!std::isfinite(value))
        return;

    // Impede tempos negativos e mantém uma casa decimal.
    const double nonNegativeValue = qMax(0.0, value);
    const QString text = QString::number(nonNegativeValue, 'f', 1);
    const double newValue = text.toDouble();

    // Sincroniza o campo com o valor armazenado.
    ui->stimulationTimeValueEdit->setText(text);

    if (newValue == m_stimulationTimeS)
        return;

    m_stimulationTimeS = newValue;
    emit stimulationTimeChanged(m_stimulationTimeS);
}
double RampSettingsPanel::restTimeS() const
{
    // Retorna o tempo de repouso configurado neste painel.
    return m_restTimeS;
}

void RampSettingsPanel::setRestTimeS(double value)
{
    // Ignora valores que não representam um número finito.
    if (!std::isfinite(value))
        return;

    // Impede valores negativos e mantém uma casa decimal.
    const double nonNegativeValue = qMax(0.0, value);
    const QString text = QString::number(nonNegativeValue, 'f', 1);
    const double newValue = text.toDouble();

    // Sincroniza a apresentação com o valor aceito.
    ui->restTimeValueEdit->setText(text);

    if (newValue == m_restTimeS)
        return;

    m_restTimeS = newValue;
    emit restTimeChanged(m_restTimeS);
}
bool RampSettingsPanel::eventFilter(QObject *watched, QEvent *event)
{
    // Confirma ou restaura o conteúdo ao sair do campo.
    if (event->type() == QEvent::FocusOut) {

        if (watched == ui->stepAmplitudeValueEdit) {
            const int value =
                ui->stepAmplitudeValueEdit->hasAcceptableInput()
                    ? ui->stepAmplitudeValueEdit->text().toInt()
                    : m_stepAmplitudeUa;

            setStepAmplitudeUa(value);
        }

        else if (watched == ui->stimulationTimeValueEdit) {
            // Usa o valor armazenado caso a entrada não seja válida.
            double value = m_stimulationTimeS;

            if (ui->stimulationTimeValueEdit->hasAcceptableInput()) {
                bool ok = false;
                const double typedValue = QLocale::c().toDouble(
                    ui->stimulationTimeValueEdit->text(), &ok
                    );

                if (ok)
                    value = typedValue;
            }

            setStimulationTimeS(value);
        }

        else if (watched == ui->restTimeValueEdit) {
            double value = m_restTimeS;

            if (ui->restTimeValueEdit->hasAcceptableInput()) {
                bool ok = false;
                const double typedValue = QLocale::c().toDouble(
                    ui->restTimeValueEdit->text(), &ok
                    );

                if (ok)
                    value = typedValue;
            }

            setRestTimeS(value);
        }
    }

    // Preserva o processamento normal dos eventos do Qt.
    return QWidget::eventFilter(watched, event);
}
void RampSettingsPanel::organizarLayout()
{
    auto *grid = ui->rampSettingsGridLayout;

    // Remove os itens do layout sem destruir os controles.
    while (QLayoutItem *item = grid->takeAt(0)) {
        delete item;
    }

    grid->setContentsMargins(0, 6, 0, 0);
    grid->setHorizontalSpacing(8);
    grid->setVerticalSpacing(6);

    // Limpa a distribuição anterior das colunas.
    for (int column = 0; column < grid->columnCount(); ++column) {
        grid->setColumnStretch(column, 0);
    }

    // Permite que o campo numérico aproveite o espaço disponível.
    grid->setColumnStretch(2, 1);

    // Organiza cada parâmetro em uma única linha.
    auto adicionarParametro =
        [grid](int row, QLabel *label, QPushButton *minusButton,
               QLineEdit *valueEdit, QPushButton *plusButton)
    {
        minusButton->setFixedWidth(32);
        plusButton->setFixedWidth(32);

        grid->addWidget(label, row, 0);
        grid->addWidget(minusButton, row, 1);
        grid->addWidget(valueEdit, row, 2);
        grid->addWidget(plusButton, row, 3);
    };

    adicionarParametro(
        0, ui->stepAmplitudeLabel,
        ui->stepAmplitudeMinusButton,
        ui->stepAmplitudeValueEdit,
        ui->stepAmplitudePlusButton);

    adicionarParametro(
        1, ui->stimulationTimeLabel,
        ui->stimulationTimeMinusButton,
        ui->stimulationTimeValueEdit,
        ui->stimulationTimePlusButton);

    adicionarParametro(
        2, ui->restTimeLabel,
        ui->restTimeMinusButton,
        ui->restTimeValueEdit,
        ui->restTimePlusButton);

    // Posiciona a resposta do participante abaixo dos ajustes.
    grid->addWidget(ui->feltButton, 3, 0, 1, 4);

    // Exibe as informações do protocolo abaixo do botão.
    grid->addWidget(ui->currentAmplitudeLabel, 4, 0, 1, 2);
    grid->addWidget(ui->resultLabel, 4, 2, 1, 2);

    ui->statusLabel->setWordWrap(true);
    grid->addWidget(ui->statusLabel, 5, 0, 1, 4);
}
RampSettingsPanel::~RampSettingsPanel()
{
    delete ui;
}
