#include "sideBar.h"
#include <QVBoxLayout>
#include <QIcon>
#include <QSize>
#include <QSizePolicy>
#include <QLabel>
#include <QPixmap>

sideBar::sideBar(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(10, 16, 10, 16);
    layout->setSpacing(8);
    // Cria o botão para recolher ou expandir o menu.
    toggleButton = new QToolButton(this);
    toggleButton->setText(QString::fromUtf8("\xE2\x98\xB0"));
    toggleButton->setToolTip("Recolher menu");
    toggleButton->setSizePolicy(
        QSizePolicy::Expanding,
        QSizePolicy::Fixed
        );
    layout->addWidget(toggleButton);

    connect(toggleButton, &QToolButton::clicked,
            this, [this]() {
                setCollapsed(!m_collapsed);
            });

    // ===== LOGO =====

    logoLabel = new QLabel(this);


    QPixmap logo(":/images/logo.png");

    logoLabel->setPixmap(
        logo.scaled(
            170,
            110,
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            )
        );

    logoLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(logoLabel);
    layout->addSpacing(15);


    // ===== BOTÕES =====

    btnRegistrarPaciente =
        crearBotonMenu("Registrar Paciente", ":/images/user.png");

    btnSalvarSessao =
        crearBotonMenu("Salvar Sessão", ":/images/save.png");

    btnSobre =
        crearBotonMenu("Sobre", ":/images/info.png");

    btnSalvarSessao->setCheckable(false);
    layout->addWidget(btnRegistrarPaciente);
    layout->addWidget(btnSalvarSessao);

    layout->addStretch();

    layout->addWidget(btnSobre);

    connect(
        btnRegistrarPaciente,
        &QToolButton::clicked,
        this,
        [this]()
        {
            setBotonActivo(btnRegistrarPaciente);
            emit registrarPacienteClicked();
        }
        );

    connect(
        btnSalvarSessao,
        &QToolButton::clicked,
        this,
        [this]()
        {
            emit salvarSessaoClicked();
        }
        );


    connect(
        btnSobre,
        &QToolButton::clicked,
        this,
        [this]()
        {
            setBotonActivo(btnSobre);
            emit sobreClicked();
        }
        );
}


sideBar::~sideBar()
{
}


QToolButton *sideBar::crearBotonMenu(
    const QString &texto,
    const QString &rutaIcono
    )
{
    QToolButton *btn = new QToolButton(this);

    btn->setText(texto);
    // Identifica a ação mesmo quando o texto estiver oculto.
    btn->setToolTip(texto);
    btn->setIcon(QIcon(rutaIcono));

    // Mantém os ícones proporcionais à altura dos botões.
    btn->setIconSize(QSize(24, 24));
    // Posiciona o texto ao lado do ícone.
    btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    // Define uma altura mínima para os botões do menu.
    btn->setMinimumHeight(44);

    btn->setSizePolicy(
        QSizePolicy::Expanding,
        QSizePolicy::Fixed
        );

    btn->setCheckable(true);

    // Identifica os botões que pertencem ao menu lateral.
    btn->setProperty("buttonRole", "sidebar");
    return btn;
}


void sideBar::setBotonActivo(QToolButton *btnActivo)
{
    for (QToolButton *btn :
         {  btnRegistrarPaciente,
             btnSobre
         })
    {
        btn->setChecked(btn == btnActivo);
    }
}
void sideBar::setCollapsed(bool collapsed)
{
    m_collapsed = collapsed;

    // Oculta o logotipo para liberar espaço no modo compacto.
    logoLabel->setVisible(!collapsed);

    // Mantém os mesmos botões, sinais e estados de seleção.
    for (QToolButton *button :
         {btnRegistrarPaciente, btnSalvarSessao, btnSobre}) {

        button->setToolButtonStyle(
            collapsed
                ? Qt::ToolButtonIconOnly
                : Qt::ToolButtonTextBesideIcon
            );
    }

    toggleButton->setToolTip(
        collapsed ? "Expandir menu" : "Recolher menu"
        );

    // Reduz as margens quando apenas os ícones são apresentados.
    layout()->setContentsMargins(
        collapsed ? 6 : 10,
        16,
        collapsed ? 6 : 10,
        16
        );

    // Informa à janela a largura necessária.
    emit widthRequested(collapsed ? 72 : 240);
}