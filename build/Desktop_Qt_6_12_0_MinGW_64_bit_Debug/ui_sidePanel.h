/********************************************************************************
** Form generated from reading UI file 'sidePanel.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEPANEL_H
#define UI_SIDEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sidePanel
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *stimulusGroupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *aud_selecionar_audio;
    QPushButton *aud_iniciar_estimulo;
    QPushButton *aud_parar_estimulo;
    QHBoxLayout *horizontalLayout;
    QLabel *waveformLabel;
    QComboBox *comboCanalEstimulo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *waveformLabel_2;
    QComboBox *comboTipoEstimulo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *frequencyLabel;
    QTimeEdit *spinDuracaoEstimulo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *amplitudeLabel;
    QCheckBox *checkReproducaoCiclica;
    QTimeEdit *timeReproducaoCiclica;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_11;
    QFrame *frame_ch1_ciclos_4;
    QHBoxLayout *horizontalLayout_49;
    QLabel *label_61;
    QSpinBox *spinVolume;
    QFrame *frame_ch1_ciclos_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_31;
    QSpinBox *spinFreqAudio;
    QFrame *frame_ch1_freq_2;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_ch1_freq_2;
    QSpinBox *spinDuracaoMs;
    QFrame *frame_ch1_ampl_2;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_ch1_ampl_2;
    QSpinBox *spinAmplitude;
    QFrame *frame_20;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_38;
    QSpinBox *spinFreqPortadora;
    QFrame *frame_21;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_39;
    QSpinBox *spinFreqModulacao;
    QFrame *frame_16;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_34;
    QSpinBox *spinFatorAM;
    QFrame *frame_17;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_35;
    QSpinBox *spinExponencialMod;
    QFrame *frame_18;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_36;
    QSpinBox *spinFaseFM;
    QFrame *frame_19;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_37;
    QSpinBox *spinFatorFM;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *sidePanel)
    {
        if (sidePanel->objectName().isEmpty())
            sidePanel->setObjectName("sidePanel");
        sidePanel->resize(830, 879);
        verticalLayout_2 = new QVBoxLayout(sidePanel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stimulusGroupBox = new QGroupBox(sidePanel);
        stimulusGroupBox->setObjectName("stimulusGroupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stimulusGroupBox->sizePolicy().hasHeightForWidth());
        stimulusGroupBox->setSizePolicy(sizePolicy);
        stimulusGroupBox->setMinimumSize(QSize(0, 300));
        stimulusGroupBox->setFlat(false);
        verticalLayout_3 = new QVBoxLayout(stimulusGroupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        aud_selecionar_audio = new QPushButton(stimulusGroupBox);
        aud_selecionar_audio->setObjectName("aud_selecionar_audio");
        aud_selecionar_audio->setMinimumSize(QSize(0, 29));

        horizontalLayout_5->addWidget(aud_selecionar_audio);

        aud_iniciar_estimulo = new QPushButton(stimulusGroupBox);
        aud_iniciar_estimulo->setObjectName("aud_iniciar_estimulo");
        aud_iniciar_estimulo->setMinimumSize(QSize(0, 29));

        horizontalLayout_5->addWidget(aud_iniciar_estimulo);

        aud_parar_estimulo = new QPushButton(stimulusGroupBox);
        aud_parar_estimulo->setObjectName("aud_parar_estimulo");
        aud_parar_estimulo->setMinimumSize(QSize(0, 29));

        horizontalLayout_5->addWidget(aud_parar_estimulo);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        waveformLabel = new QLabel(stimulusGroupBox);
        waveformLabel->setObjectName("waveformLabel");

        horizontalLayout->addWidget(waveformLabel);

        comboCanalEstimulo = new QComboBox(stimulusGroupBox);
        comboCanalEstimulo->addItem(QString());
        comboCanalEstimulo->addItem(QString());
        comboCanalEstimulo->setObjectName("comboCanalEstimulo");

        horizontalLayout->addWidget(comboCanalEstimulo);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        waveformLabel_2 = new QLabel(stimulusGroupBox);
        waveformLabel_2->setObjectName("waveformLabel_2");

        horizontalLayout_2->addWidget(waveformLabel_2);

        comboTipoEstimulo = new QComboBox(stimulusGroupBox);
        comboTipoEstimulo->addItem(QString());
        comboTipoEstimulo->setObjectName("comboTipoEstimulo");

        horizontalLayout_2->addWidget(comboTipoEstimulo);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        frequencyLabel = new QLabel(stimulusGroupBox);
        frequencyLabel->setObjectName("frequencyLabel");

        horizontalLayout_3->addWidget(frequencyLabel);

        spinDuracaoEstimulo = new QTimeEdit(stimulusGroupBox);
        spinDuracaoEstimulo->setObjectName("spinDuracaoEstimulo");

        horizontalLayout_3->addWidget(spinDuracaoEstimulo);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        amplitudeLabel = new QLabel(stimulusGroupBox);
        amplitudeLabel->setObjectName("amplitudeLabel");

        horizontalLayout_4->addWidget(amplitudeLabel);

        checkReproducaoCiclica = new QCheckBox(stimulusGroupBox);
        checkReproducaoCiclica->setObjectName("checkReproducaoCiclica");

        horizontalLayout_4->addWidget(checkReproducaoCiclica);

        timeReproducaoCiclica = new QTimeEdit(stimulusGroupBox);
        timeReproducaoCiclica->setObjectName("timeReproducaoCiclica");

        horizontalLayout_4->addWidget(timeReproducaoCiclica);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addWidget(stimulusGroupBox);

        frame_11 = new QFrame(sidePanel);
        frame_11->setObjectName("frame_11");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(4);
        sizePolicy1.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy1);
        frame_11->setMinimumSize(QSize(350, 546));
        frame_11->setFrameShape(QFrame::Shape::Box);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
        frame_11->setLineWidth(0);
        verticalLayout_11 = new QVBoxLayout(frame_11);
        verticalLayout_11->setObjectName("verticalLayout_11");
        frame_ch1_ciclos_4 = new QFrame(frame_11);
        frame_ch1_ciclos_4->setObjectName("frame_ch1_ciclos_4");
        frame_ch1_ciclos_4->setFrameShape(QFrame::Shape::Box);
        frame_ch1_ciclos_4->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_49 = new QHBoxLayout(frame_ch1_ciclos_4);
        horizontalLayout_49->setObjectName("horizontalLayout_49");
        label_61 = new QLabel(frame_ch1_ciclos_4);
        label_61->setObjectName("label_61");
        label_61->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_49->addWidget(label_61);

        spinVolume = new QSpinBox(frame_ch1_ciclos_4);
        spinVolume->setObjectName("spinVolume");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinVolume->sizePolicy().hasHeightForWidth());
        spinVolume->setSizePolicy(sizePolicy2);
        spinVolume->setMinimumSize(QSize(110, 0));
        spinVolume->setMaximumSize(QSize(90, 16777215));
        spinVolume->setMaximum(100);
        spinVolume->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        spinVolume->setValue(100);

        horizontalLayout_49->addWidget(spinVolume);


        verticalLayout_11->addWidget(frame_ch1_ciclos_4);

        frame_ch1_ciclos_2 = new QFrame(frame_11);
        frame_ch1_ciclos_2->setObjectName("frame_ch1_ciclos_2");
        frame_ch1_ciclos_2->setFrameShape(QFrame::Shape::Box);
        frame_ch1_ciclos_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_22 = new QHBoxLayout(frame_ch1_ciclos_2);
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        label_31 = new QLabel(frame_ch1_ciclos_2);
        label_31->setObjectName("label_31");
        label_31->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_22->addWidget(label_31);

        spinFreqAudio = new QSpinBox(frame_ch1_ciclos_2);
        spinFreqAudio->setObjectName("spinFreqAudio");
        sizePolicy2.setHeightForWidth(spinFreqAudio->sizePolicy().hasHeightForWidth());
        spinFreqAudio->setSizePolicy(sizePolicy2);
        spinFreqAudio->setMinimumSize(QSize(110, 0));
        spinFreqAudio->setMaximumSize(QSize(90, 16777215));
        spinFreqAudio->setMaximum(10000);
        spinFreqAudio->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        spinFreqAudio->setValue(100);

        horizontalLayout_22->addWidget(spinFreqAudio);


        verticalLayout_11->addWidget(frame_ch1_ciclos_2);

        frame_ch1_freq_2 = new QFrame(frame_11);
        frame_ch1_freq_2->setObjectName("frame_ch1_freq_2");
        frame_ch1_freq_2->setFrameShape(QFrame::Shape::Box);
        frame_ch1_freq_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_24 = new QHBoxLayout(frame_ch1_freq_2);
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        label_ch1_freq_2 = new QLabel(frame_ch1_freq_2);
        label_ch1_freq_2->setObjectName("label_ch1_freq_2");
        label_ch1_freq_2->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_24->addWidget(label_ch1_freq_2);

        spinDuracaoMs = new QSpinBox(frame_ch1_freq_2);
        spinDuracaoMs->setObjectName("spinDuracaoMs");
        sizePolicy2.setHeightForWidth(spinDuracaoMs->sizePolicy().hasHeightForWidth());
        spinDuracaoMs->setSizePolicy(sizePolicy2);
        spinDuracaoMs->setMinimumSize(QSize(110, 0));
        spinDuracaoMs->setMaximumSize(QSize(90, 16777215));
        spinDuracaoMs->setMaximum(64000);
        spinDuracaoMs->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        spinDuracaoMs->setValue(3200);

        horizontalLayout_24->addWidget(spinDuracaoMs);


        verticalLayout_11->addWidget(frame_ch1_freq_2);

        frame_ch1_ampl_2 = new QFrame(frame_11);
        frame_ch1_ampl_2->setObjectName("frame_ch1_ampl_2");
        frame_ch1_ampl_2->setFrameShape(QFrame::Shape::Box);
        frame_ch1_ampl_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_25 = new QHBoxLayout(frame_ch1_ampl_2);
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        label_ch1_ampl_2 = new QLabel(frame_ch1_ampl_2);
        label_ch1_ampl_2->setObjectName("label_ch1_ampl_2");
        label_ch1_ampl_2->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_25->addWidget(label_ch1_ampl_2);

        spinAmplitude = new QSpinBox(frame_ch1_ampl_2);
        spinAmplitude->setObjectName("spinAmplitude");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinAmplitude->sizePolicy().hasHeightForWidth());
        spinAmplitude->setSizePolicy(sizePolicy3);
        spinAmplitude->setMinimumSize(QSize(90, 0));
        spinAmplitude->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_25->addWidget(spinAmplitude);


        verticalLayout_11->addWidget(frame_ch1_ampl_2);

        frame_20 = new QFrame(frame_11);
        frame_20->setObjectName("frame_20");
        frame_20->setFrameShape(QFrame::Shape::Box);
        frame_20->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_30 = new QHBoxLayout(frame_20);
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        label_38 = new QLabel(frame_20);
        label_38->setObjectName("label_38");
        label_38->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_30->addWidget(label_38);

        spinFreqPortadora = new QSpinBox(frame_20);
        spinFreqPortadora->setObjectName("spinFreqPortadora");
        sizePolicy2.setHeightForWidth(spinFreqPortadora->sizePolicy().hasHeightForWidth());
        spinFreqPortadora->setSizePolicy(sizePolicy2);
        spinFreqPortadora->setMinimumSize(QSize(110, 0));
        spinFreqPortadora->setMaximumSize(QSize(90, 16777215));
        spinFreqPortadora->setMaximum(64000);
        spinFreqPortadora->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        spinFreqPortadora->setValue(1000);

        horizontalLayout_30->addWidget(spinFreqPortadora);


        verticalLayout_11->addWidget(frame_20);

        frame_21 = new QFrame(frame_11);
        frame_21->setObjectName("frame_21");
        frame_21->setFrameShape(QFrame::Shape::Box);
        frame_21->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_31 = new QHBoxLayout(frame_21);
        horizontalLayout_31->setObjectName("horizontalLayout_31");
        label_39 = new QLabel(frame_21);
        label_39->setObjectName("label_39");
        label_39->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_31->addWidget(label_39);

        spinFreqModulacao = new QSpinBox(frame_21);
        spinFreqModulacao->setObjectName("spinFreqModulacao");
        sizePolicy2.setHeightForWidth(spinFreqModulacao->sizePolicy().hasHeightForWidth());
        spinFreqModulacao->setSizePolicy(sizePolicy2);
        spinFreqModulacao->setMinimumSize(QSize(110, 0));
        spinFreqModulacao->setMaximumSize(QSize(90, 16777215));
        spinFreqModulacao->setMaximum(64000);
        spinFreqModulacao->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        spinFreqModulacao->setValue(1000);

        horizontalLayout_31->addWidget(spinFreqModulacao);


        verticalLayout_11->addWidget(frame_21);

        frame_16 = new QFrame(frame_11);
        frame_16->setObjectName("frame_16");
        frame_16->setFrameShape(QFrame::Shape::Box);
        frame_16->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_26 = new QHBoxLayout(frame_16);
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        label_34 = new QLabel(frame_16);
        label_34->setObjectName("label_34");
        label_34->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_26->addWidget(label_34);

        spinFatorAM = new QSpinBox(frame_16);
        spinFatorAM->setObjectName("spinFatorAM");
        sizePolicy2.setHeightForWidth(spinFatorAM->sizePolicy().hasHeightForWidth());
        spinFatorAM->setSizePolicy(sizePolicy2);
        spinFatorAM->setMinimumSize(QSize(110, 0));
        spinFatorAM->setMaximumSize(QSize(90, 16777215));
        spinFatorAM->setMaximum(64000);
        spinFatorAM->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        spinFatorAM->setValue(1000);

        horizontalLayout_26->addWidget(spinFatorAM);


        verticalLayout_11->addWidget(frame_16);

        frame_17 = new QFrame(frame_11);
        frame_17->setObjectName("frame_17");
        frame_17->setFrameShape(QFrame::Shape::Box);
        frame_17->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_27 = new QHBoxLayout(frame_17);
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        label_35 = new QLabel(frame_17);
        label_35->setObjectName("label_35");
        label_35->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_27->addWidget(label_35);

        spinExponencialMod = new QSpinBox(frame_17);
        spinExponencialMod->setObjectName("spinExponencialMod");
        sizePolicy2.setHeightForWidth(spinExponencialMod->sizePolicy().hasHeightForWidth());
        spinExponencialMod->setSizePolicy(sizePolicy2);
        spinExponencialMod->setMinimumSize(QSize(110, 0));
        spinExponencialMod->setMaximumSize(QSize(90, 16777215));
        spinExponencialMod->setMaximum(64000);
        spinExponencialMod->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        spinExponencialMod->setValue(1000);

        horizontalLayout_27->addWidget(spinExponencialMod);


        verticalLayout_11->addWidget(frame_17);

        frame_18 = new QFrame(frame_11);
        frame_18->setObjectName("frame_18");
        frame_18->setFrameShape(QFrame::Shape::Box);
        frame_18->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_28 = new QHBoxLayout(frame_18);
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        label_36 = new QLabel(frame_18);
        label_36->setObjectName("label_36");
        label_36->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_28->addWidget(label_36);

        spinFaseFM = new QSpinBox(frame_18);
        spinFaseFM->setObjectName("spinFaseFM");
        sizePolicy2.setHeightForWidth(spinFaseFM->sizePolicy().hasHeightForWidth());
        spinFaseFM->setSizePolicy(sizePolicy2);
        spinFaseFM->setMinimumSize(QSize(110, 0));
        spinFaseFM->setMaximumSize(QSize(90, 16777215));
        spinFaseFM->setMaximum(64000);
        spinFaseFM->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        spinFaseFM->setValue(1000);

        horizontalLayout_28->addWidget(spinFaseFM);


        verticalLayout_11->addWidget(frame_18);

        frame_19 = new QFrame(frame_11);
        frame_19->setObjectName("frame_19");
        frame_19->setFrameShape(QFrame::Shape::Box);
        frame_19->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_29 = new QHBoxLayout(frame_19);
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        label_37 = new QLabel(frame_19);
        label_37->setObjectName("label_37");
        label_37->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_29->addWidget(label_37);

        spinFatorFM = new QSpinBox(frame_19);
        spinFatorFM->setObjectName("spinFatorFM");
        sizePolicy2.setHeightForWidth(spinFatorFM->sizePolicy().hasHeightForWidth());
        spinFatorFM->setSizePolicy(sizePolicy2);
        spinFatorFM->setMinimumSize(QSize(110, 0));
        spinFatorFM->setMaximumSize(QSize(90, 16777215));
        spinFatorFM->setMaximum(64000);
        spinFatorFM->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        spinFatorFM->setValue(1000);

        horizontalLayout_29->addWidget(spinFatorFM);


        verticalLayout_11->addWidget(frame_19);


        verticalLayout_2->addWidget(frame_11);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(sidePanel);

        QMetaObject::connectSlotsByName(sidePanel);
    } // setupUi

    void retranslateUi(QWidget *sidePanel)
    {
        stimulusGroupBox->setTitle(QCoreApplication::translate("sidePanel", "Par\303\242metros do est\303\255mulo", nullptr));
        aud_selecionar_audio->setText(QCoreApplication::translate("sidePanel", "Selecionar Audio", nullptr));
        aud_iniciar_estimulo->setText(QCoreApplication::translate("sidePanel", "Iniciar", nullptr));
        aud_parar_estimulo->setText(QCoreApplication::translate("sidePanel", "Parar", nullptr));
        waveformLabel->setText(QCoreApplication::translate("sidePanel", "Canal de est\303\255mulo", nullptr));
        comboCanalEstimulo->setItemText(0, QCoreApplication::translate("sidePanel", "Esquerdo", nullptr));
        comboCanalEstimulo->setItemText(1, QCoreApplication::translate("sidePanel", "Direito", nullptr));

        waveformLabel_2->setText(QCoreApplication::translate("sidePanel", "Tipo de est\303\255mulo ", nullptr));
        comboTipoEstimulo->setItemText(0, QCoreApplication::translate("sidePanel", "Tipos...", nullptr));

        frequencyLabel->setText(QCoreApplication::translate("sidePanel", "Dura\303\247\303\243o do est\303\255mulo", nullptr));
        amplitudeLabel->setText(QCoreApplication::translate("sidePanel", "Reprodu\303\247\303\243o c\303\255clica", nullptr));
        checkReproducaoCiclica->setText(QString());
        label_61->setText(QCoreApplication::translate("sidePanel", "Volume (%)", nullptr));
        label_31->setText(QCoreApplication::translate("sidePanel", "Frequ\303\252ncia (Hz) audio", nullptr));
        label_ch1_freq_2->setText(QCoreApplication::translate("sidePanel", "Dura\303\247\303\243o est\303\255mulo (ms)", nullptr));
        label_ch1_ampl_2->setText(QCoreApplication::translate("sidePanel", "Amplitude (%)", nullptr));
        label_38->setText(QCoreApplication::translate("sidePanel", "Frequ\303\252ncia portadora (Hz)", nullptr));
        label_39->setText(QCoreApplication::translate("sidePanel", "Frequ\303\252ncia de modula\303\247\303\243o (Hz)", nullptr));
        label_34->setText(QCoreApplication::translate("sidePanel", "Fator de modula\303\247\303\243o AM (%)", nullptr));
        label_35->setText(QCoreApplication::translate("sidePanel", "Exponencial do modulador", nullptr));
        label_36->setText(QCoreApplication::translate("sidePanel", "Fase FM", nullptr));
        label_37->setText(QCoreApplication::translate("sidePanel", "Fator de modula\303\247\303\243o FM (%)", nullptr));
        (void)sidePanel;
    } // retranslateUi

};

namespace Ui {
    class sidePanel: public Ui_sidePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEPANEL_H
