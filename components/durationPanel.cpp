#include "durationPanel.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QEvent>
#include <QKeyEvent>
#include <QStringList>

DurationPanel::DurationPanel(QWidget *parent)
    : QWidget(parent)
{
    // Cria os controles exclusivos da duração geral.
    auto *label = new QLabel(
        "Duração da estimulação (hh:mm:ss)", this
        );
    auto *minusButton = new QPushButton("-", this);
    auto *plusButton = new QPushButton("+", this);
    m_valueEdit = new QLineEdit(this);

    auto *panelLayout = new QHBoxLayout(this);
    panelLayout->setContentsMargins(0, 0, 0, 0);
    panelLayout->setSpacing(8);
    panelLayout->addWidget(label);
    panelLayout->addWidget(minusButton);
    panelLayout->addWidget(m_valueEdit);
    panelLayout->addWidget(plusButton);

    // Aceita o formato completo ou o campo vazio durante a edição.
    m_valueEdit->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(
                "([0-9]{2}:[0-5][0-9]:[0-5][0-9])?"
                ),
            m_valueEdit
            )
        );

    m_valueEdit->setAlignment(Qt::AlignCenter);
    m_valueEdit->setMinimumWidth(120);
    m_valueEdit->setText(textoDuracao());
    m_valueEdit->installEventFilter(this);

    // Preserva a posição do cursor ao clicar nos botões.
    minusButton->setFocusPolicy(Qt::NoFocus);
    plusButton->setFocusPolicy(Qt::NoFocus);

    // Memoriza apenas valores completos e válidos.
    connect(m_valueEdit, &QLineEdit::textChanged,
            this, [this](const QString &text) {
                if (text.isEmpty() || !m_valueEdit->hasAcceptableInput())
                    return;

                const QStringList parts = text.split(':');
                m_seconds = parts[0].toInt() * 3600
                            + parts[1].toInt() * 60
                            + parts[2].toInt();
            });

    // Cada botão possui uma única conexão.
    connect(minusButton, &QPushButton::clicked,
            this, [this]() {
                ajustarDuracao(-1);
            });

    connect(plusButton, &QPushButton::clicked,
            this, [this]() {
                ajustarDuracao(1);
            });
}

int DurationPanel::durationSeconds() const
{
    return m_seconds;
}

QString DurationPanel::textoDuracao() const
{
    // Converte os segundos armazenados para hh:mm:ss.
    return QString("%1:%2:%3")
        .arg(m_seconds / 3600, 2, 10, QChar('0'))
        .arg((m_seconds % 3600) / 60, 2, 10, QChar('0'))
        .arg(m_seconds % 60, 2, 10, QChar('0'));
}

void DurationPanel::restaurarCampo()
{
    // Recupera o último valor válido após uma edição incompleta.
    if (m_valueEdit->text().isEmpty()
        || !m_valueEdit->hasAcceptableInput()) {
        m_valueEdit->setText(textoDuracao());
    }
}

void DurationPanel::ajustarDuracao(int direction)
{
    const int position = m_valueEdit->cursorPosition();

    restaurarCampo();

    // Define o passo conforme a parte indicada pelo cursor.
    const int step = position <= 2 ? 3600
                     : position <= 5 ? 60
                                     : 1;

    m_seconds = qBound(
        0,
        m_seconds + direction * step,
        99 * 3600 + 59 * 60 + 59
        );

    m_valueEdit->setText(textoDuracao());
    m_valueEdit->setFocus();
    m_valueEdit->setCursorPosition(position);
}

bool DurationPanel::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_valueEdit) {
        // Restaura entradas vazias ou incompletas ao sair do campo.
        if (event->type() == QEvent::FocusOut) {
            restaurarCampo();
        }

        // Também permite restaurar o campo pressionando Enter.
        if (event->type() == QEvent::KeyPress) {
            auto *keyEvent = static_cast<QKeyEvent *>(event);

            if (keyEvent->key() == Qt::Key_Return
                || keyEvent->key() == Qt::Key_Enter) {
                restaurarCampo();
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}