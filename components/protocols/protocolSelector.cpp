
#include <QLabel>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include "protocolSelector.h"
#include <QButtonGroup>

ProtocolSelector::ProtocolSelector(
    const QList<QToolButton *> &buttons,
    QWidget *parent
    )
    : QWidget(parent)
{
    // Organiza o título acima dos botões.
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(10);

    auto *title = new QLabel("Protocolo de estimulação", this);
    title->setProperty("textRole", "section");
    mainLayout->addWidget(title);

    // Agrupa os protocolos com espaçamento uniforme.
    auto *buttonsLayout = new QHBoxLayout;
    buttonsLayout->setSpacing(10);
    // Permite selecionar apenas um protocolo por vez.
    auto *protocolGroup = new QButtonGroup(this);
    protocolGroup->setExclusive(true);
    for (QToolButton *button : buttons) {
        // Inclui apenas protocolos; o carregamento é uma ação.
        if (button->isCheckable()) {
            protocolGroup->addButton(button);
        }
        // Identifica os botões do seletor de protocolos.
        button->setProperty("buttonRole", "protocol");
        // Reutiliza o botão e preserva suas conexões existentes.
        button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button->setIconSize(QSize(60, 36));

        // Reserva espaço para o ícone, o texto e as margens.
        button->setMinimumSize(130, 90);
        button->setSizePolicy(
            QSizePolicy::Preferred,
            QSizePolicy::Fixed
            );

        buttonsLayout->addWidget(button);
    }
    // Seleciona o primeiro protocolo quando não houver seleção inicial.
    if (!protocolGroup->checkedButton()
        && !protocolGroup->buttons().isEmpty()) {
        protocolGroup->buttons().first()->setChecked(true);
    }
    buttonsLayout->addStretch();
    mainLayout->addLayout(buttonsLayout);
}