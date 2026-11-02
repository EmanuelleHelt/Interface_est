#include "sidePanel.h"
#include "ui_sidePanel.h"
#include <QPushButton>
#include <QSpinBox>

sidePanel::sidePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sidePanel)
{
    ui->setupUi(this);

    connect(ui->aud_iniciar_estimulo, &QPushButton::clicked, this, &sidePanel::iniciarAuditivoClicado);
    connect(ui->aud_parar_estimulo, &QPushButton::clicked, this, &sidePanel::pararAuditivoClicado);
    connect(ui->aud_selecionar_audio, &QPushButton::clicked, this, &sidePanel::selecionarAudioClicado);

    connect(ui->spinVolume, &QSpinBox::valueChanged, this, &sidePanel::aoMudarVolume);
}

sidePanel::~sidePanel()
{
    delete ui;
}

void sidePanel::aoMudarVolume()
{
    int vol = ui->spinVolume->value();
    emit volumeAlterado(vol, vol);
}