#include "sidePanel.h"
#include "ui_sidePanel.h"
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <QTimeEdit>
#include <QCheckBox>

sidePanel::sidePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sidePanel)
{
    ui->setupUi(this);

    // Botões
    connect(ui->aud_iniciar_estimulo, &QPushButton::clicked, this, &sidePanel::iniciarAuditivoClicado);
    connect(ui->aud_parar_estimulo, &QPushButton::clicked, this, &sidePanel::pararAuditivoClicado);
    connect(ui->aud_selecionar_audio, &QPushButton::clicked, this, &sidePanel::selecionarAudioClicado);
    connect(ui->spinVolume, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::aoMudarVolume);
    connect(ui->comboCanalEstimulo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &sidePanel::canalEstimuloAlterado);
    connect(ui->comboTipoEstimulo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &sidePanel::tipoEstimuloAlterado);
    connect(ui->checkReproducaoCiclica, &QCheckBox::toggled, this, &sidePanel::reproducaoCiclicaToggled);
    connect(ui->timeReproducaoCiclica, &QTimeEdit::timeChanged, this, &sidePanel::tempoReproducaoCiclicaAlterado);
    connect(ui->spinDuracaoEstimulo, &QTimeEdit::timeChanged, this, &sidePanel::duracaoEstimuloAlterada);
    connect(ui->spinFreqAudio, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::freqAudioAlterada);
    connect(ui->spinDuracaoMs, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::duracaoMsAlterada);
    connect(ui->spinAmplitude, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::amplitudeAlterada);
    connect(ui->spinFreqPortadora, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::freqPortadoraAlterada);
    connect(ui->spinFreqModulacao, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::freqModulacaoAlterada);
    connect(ui->spinFatorAM, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::fatorAMAlterado);
    connect(ui->spinExponencialMod, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::exponencialModAlterada);
    connect(ui->spinFaseFM, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::faseFMAlterada);
    connect(ui->spinFatorFM, QOverload<int>::of(&QSpinBox::valueChanged), this, &sidePanel::fatorFMAlterado);
}

sidePanel::~sidePanel()
{
    delete ui;
}

void sidePanel::aoMudarVolume()
{
    int vol = ui->spinVolume->value();
    emit volumeAlterado(vol, vol); // Seu panfleto original
}