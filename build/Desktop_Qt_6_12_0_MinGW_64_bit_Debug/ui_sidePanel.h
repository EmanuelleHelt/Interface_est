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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelPanel
{
public:
    QGroupBox *stimulusGroupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *waveformLabel;
    QComboBox *waveformComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *waveformLabel_2;
    QComboBox *waveformComboBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *frequencyLabel;
    QLineEdit *frequencyValueEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *amplitudeLabel;
    QCheckBox *checkBox;
    QLineEdit *amplitudeValueEdit;
    QFrame *frame_ch1_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_11;
    QFrame *frame_ch1_ciclos_4;
    QHBoxLayout *horizontalLayout_49;
    QLabel *label_61;
    QSpinBox *esq_spinBox_vol;
    QFrame *frame_ch1_ciclos_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_31;
    QSpinBox *esq_spinBox_freqhz;
    QFrame *frame_ch1_freq_2;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_ch1_freq_2;
    QSpinBox *esq_spinBox_ms;
    QFrame *frame_ch1_ampl_2;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_ch1_ampl_2;
    QDoubleSpinBox *esq_spinBox_amplitude;
    QFrame *frame_20;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_38;
    QSpinBox *esq_spinBox_freqhzport;
    QFrame *frame_21;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_39;
    QSpinBox *esq_spinBox_freqhzmod;
    QFrame *frame_16;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_34;
    QSpinBox *esq_spinBox_fatorammod;
    QFrame *frame_17;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_35;
    QSpinBox *esq_spinBox_expomod;
    QFrame *frame_18;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_36;
    QSpinBox *esq_spinBox_fasefm;
    QFrame *frame_19;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_37;
    QSpinBox *esq_spinBox_fatorfmmod;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QFrame *frame_2;

    void setupUi(QWidget *ChannelPanel)
    {
        if (ChannelPanel->objectName().isEmpty())
            ChannelPanel->setObjectName("ChannelPanel");
        ChannelPanel->resize(570, 677);
        stimulusGroupBox = new QGroupBox(ChannelPanel);
        stimulusGroupBox->setObjectName("stimulusGroupBox");
        stimulusGroupBox->setGeometry(QRect(9, 9, 551, 161));
        widget = new QWidget(stimulusGroupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(11, 31, 531, 124));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        waveformLabel = new QLabel(widget);
        waveformLabel->setObjectName("waveformLabel");

        horizontalLayout->addWidget(waveformLabel);

        waveformComboBox = new QComboBox(widget);
        waveformComboBox->addItem(QString());
        waveformComboBox->addItem(QString());
        waveformComboBox->setObjectName("waveformComboBox");

        horizontalLayout->addWidget(waveformComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        waveformLabel_2 = new QLabel(widget);
        waveformLabel_2->setObjectName("waveformLabel_2");

        horizontalLayout_2->addWidget(waveformLabel_2);

        waveformComboBox_2 = new QComboBox(widget);
        waveformComboBox_2->addItem(QString());
        waveformComboBox_2->setObjectName("waveformComboBox_2");

        horizontalLayout_2->addWidget(waveformComboBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        frequencyLabel = new QLabel(widget);
        frequencyLabel->setObjectName("frequencyLabel");

        horizontalLayout_3->addWidget(frequencyLabel);

        frequencyValueEdit = new QLineEdit(widget);
        frequencyValueEdit->setObjectName("frequencyValueEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frequencyValueEdit->sizePolicy().hasHeightForWidth());
        frequencyValueEdit->setSizePolicy(sizePolicy);
        frequencyValueEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(frequencyValueEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        amplitudeLabel = new QLabel(widget);
        amplitudeLabel->setObjectName("amplitudeLabel");

        horizontalLayout_4->addWidget(amplitudeLabel);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName("checkBox");

        horizontalLayout_4->addWidget(checkBox);

        amplitudeValueEdit = new QLineEdit(widget);
        amplitudeValueEdit->setObjectName("amplitudeValueEdit");
        sizePolicy.setHeightForWidth(amplitudeValueEdit->sizePolicy().hasHeightForWidth());
        amplitudeValueEdit->setSizePolicy(sizePolicy);
        amplitudeValueEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(amplitudeValueEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        frame_ch1_2 = new QFrame(ChannelPanel);
        frame_ch1_2->setObjectName("frame_ch1_2");
        frame_ch1_2->setGeometry(QRect(10, 170, 551, 501));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_ch1_2->sizePolicy().hasHeightForWidth());
        frame_ch1_2->setSizePolicy(sizePolicy1);
        frame_ch1_2->setFrameShape(QFrame::Shape::Box);
        frame_ch1_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_ch1_2->setLineWidth(1);
        frame_ch1_2->setMidLineWidth(0);
        widget1 = new QWidget(frame_ch1_2);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(11, 10, 531, 548));
        horizontalLayout_5 = new QHBoxLayout(widget1);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_11 = new QFrame(widget1);
        frame_11->setObjectName("frame_11");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(4);
        sizePolicy2.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy2);
        frame_11->setFrameShape(QFrame::Shape::Box);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
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

        esq_spinBox_vol = new QSpinBox(frame_ch1_ciclos_4);
        esq_spinBox_vol->setObjectName("esq_spinBox_vol");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(esq_spinBox_vol->sizePolicy().hasHeightForWidth());
        esq_spinBox_vol->setSizePolicy(sizePolicy3);
        esq_spinBox_vol->setMaximumSize(QSize(90, 16777215));
        esq_spinBox_vol->setMaximum(100);
        esq_spinBox_vol->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        esq_spinBox_vol->setValue(100);

        horizontalLayout_49->addWidget(esq_spinBox_vol);


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

        esq_spinBox_freqhz = new QSpinBox(frame_ch1_ciclos_2);
        esq_spinBox_freqhz->setObjectName("esq_spinBox_freqhz");
        sizePolicy3.setHeightForWidth(esq_spinBox_freqhz->sizePolicy().hasHeightForWidth());
        esq_spinBox_freqhz->setSizePolicy(sizePolicy3);
        esq_spinBox_freqhz->setMaximumSize(QSize(90, 16777215));
        esq_spinBox_freqhz->setMaximum(10000);
        esq_spinBox_freqhz->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        esq_spinBox_freqhz->setValue(100);

        horizontalLayout_22->addWidget(esq_spinBox_freqhz);


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

        esq_spinBox_ms = new QSpinBox(frame_ch1_freq_2);
        esq_spinBox_ms->setObjectName("esq_spinBox_ms");
        sizePolicy3.setHeightForWidth(esq_spinBox_ms->sizePolicy().hasHeightForWidth());
        esq_spinBox_ms->setSizePolicy(sizePolicy3);
        esq_spinBox_ms->setMaximumSize(QSize(90, 16777215));
        esq_spinBox_ms->setMaximum(64000);
        esq_spinBox_ms->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        esq_spinBox_ms->setValue(3200);

        horizontalLayout_24->addWidget(esq_spinBox_ms);


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

        esq_spinBox_amplitude = new QDoubleSpinBox(frame_ch1_ampl_2);
        esq_spinBox_amplitude->setObjectName("esq_spinBox_amplitude");
        esq_spinBox_amplitude->setMinimumSize(QSize(50, 0));
        esq_spinBox_amplitude->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_25->addWidget(esq_spinBox_amplitude);


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

        esq_spinBox_freqhzport = new QSpinBox(frame_20);
        esq_spinBox_freqhzport->setObjectName("esq_spinBox_freqhzport");
        sizePolicy3.setHeightForWidth(esq_spinBox_freqhzport->sizePolicy().hasHeightForWidth());
        esq_spinBox_freqhzport->setSizePolicy(sizePolicy3);
        esq_spinBox_freqhzport->setMaximumSize(QSize(90, 16777215));
        esq_spinBox_freqhzport->setMaximum(64000);
        esq_spinBox_freqhzport->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        esq_spinBox_freqhzport->setValue(1000);

        horizontalLayout_30->addWidget(esq_spinBox_freqhzport);


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

        esq_spinBox_freqhzmod = new QSpinBox(frame_21);
        esq_spinBox_freqhzmod->setObjectName("esq_spinBox_freqhzmod");
        sizePolicy3.setHeightForWidth(esq_spinBox_freqhzmod->sizePolicy().hasHeightForWidth());
        esq_spinBox_freqhzmod->setSizePolicy(sizePolicy3);
        esq_spinBox_freqhzmod->setMaximumSize(QSize(90, 16777215));
        esq_spinBox_freqhzmod->setMaximum(64000);
        esq_spinBox_freqhzmod->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        esq_spinBox_freqhzmod->setValue(1000);

        horizontalLayout_31->addWidget(esq_spinBox_freqhzmod);


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

        esq_spinBox_fatorammod = new QSpinBox(frame_16);
        esq_spinBox_fatorammod->setObjectName("esq_spinBox_fatorammod");
        sizePolicy3.setHeightForWidth(esq_spinBox_fatorammod->sizePolicy().hasHeightForWidth());
        esq_spinBox_fatorammod->setSizePolicy(sizePolicy3);
        esq_spinBox_fatorammod->setMaximumSize(QSize(90, 16777215));
        esq_spinBox_fatorammod->setMaximum(64000);
        esq_spinBox_fatorammod->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        esq_spinBox_fatorammod->setValue(1000);

        horizontalLayout_26->addWidget(esq_spinBox_fatorammod);


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

        esq_spinBox_expomod = new QSpinBox(frame_17);
        esq_spinBox_expomod->setObjectName("esq_spinBox_expomod");
        sizePolicy3.setHeightForWidth(esq_spinBox_expomod->sizePolicy().hasHeightForWidth());
        esq_spinBox_expomod->setSizePolicy(sizePolicy3);
        esq_spinBox_expomod->setMaximumSize(QSize(90, 16777215));
        esq_spinBox_expomod->setMaximum(64000);
        esq_spinBox_expomod->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        esq_spinBox_expomod->setValue(1000);

        horizontalLayout_27->addWidget(esq_spinBox_expomod);


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

        esq_spinBox_fasefm = new QSpinBox(frame_18);
        esq_spinBox_fasefm->setObjectName("esq_spinBox_fasefm");
        sizePolicy3.setHeightForWidth(esq_spinBox_fasefm->sizePolicy().hasHeightForWidth());
        esq_spinBox_fasefm->setSizePolicy(sizePolicy3);
        esq_spinBox_fasefm->setMaximumSize(QSize(90, 16777215));
        esq_spinBox_fasefm->setMaximum(64000);
        esq_spinBox_fasefm->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        esq_spinBox_fasefm->setValue(1000);

        horizontalLayout_28->addWidget(esq_spinBox_fasefm);


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

        esq_spinBox_fatorfmmod = new QSpinBox(frame_19);
        esq_spinBox_fatorfmmod->setObjectName("esq_spinBox_fatorfmmod");
        sizePolicy3.setHeightForWidth(esq_spinBox_fatorfmmod->sizePolicy().hasHeightForWidth());
        esq_spinBox_fatorfmmod->setSizePolicy(sizePolicy3);
        esq_spinBox_fatorfmmod->setMaximumSize(QSize(90, 16777215));
        esq_spinBox_fatorfmmod->setMaximum(64000);
        esq_spinBox_fatorfmmod->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        esq_spinBox_fatorfmmod->setValue(1000);

        horizontalLayout_29->addWidget(esq_spinBox_fatorfmmod);


        verticalLayout_11->addWidget(frame_19);


        horizontalLayout_5->addWidget(frame_11);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame = new QFrame(widget1);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_2->addWidget(frame);

        frame_2 = new QFrame(widget1);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_2->addWidget(frame_2);


        horizontalLayout_5->addLayout(verticalLayout_2);


        retranslateUi(ChannelPanel);

        QMetaObject::connectSlotsByName(ChannelPanel);
    } // setupUi

    void retranslateUi(QWidget *ChannelPanel)
    {
        stimulusGroupBox->setTitle(QCoreApplication::translate("ChannelPanel", "Par\303\242metros do est\303\255mulo", nullptr));
        waveformLabel->setText(QCoreApplication::translate("ChannelPanel", "Canal de est\303\255mulo", nullptr));
        waveformComboBox->setItemText(0, QCoreApplication::translate("ChannelPanel", "Esquerdo", nullptr));
        waveformComboBox->setItemText(1, QCoreApplication::translate("ChannelPanel", "Direito", nullptr));

        waveformLabel_2->setText(QCoreApplication::translate("ChannelPanel", "Tipo de est\303\255mulo ", nullptr));
        waveformComboBox_2->setItemText(0, QCoreApplication::translate("ChannelPanel", "Tipos...", nullptr));

        frequencyLabel->setText(QCoreApplication::translate("ChannelPanel", "Dura\303\247\303\243o do est\303\255mulo", nullptr));
        frequencyValueEdit->setText(QCoreApplication::translate("ChannelPanel", "1024", nullptr));
        amplitudeLabel->setText(QCoreApplication::translate("ChannelPanel", "Reprodu\303\247\303\243o c\303\255clica", nullptr));
        checkBox->setText(QString());
        amplitudeValueEdit->setText(QCoreApplication::translate("ChannelPanel", "00:00:00", nullptr));
        label_61->setText(QCoreApplication::translate("ChannelPanel", "Volume (%)", nullptr));
        label_31->setText(QCoreApplication::translate("ChannelPanel", "Frequ\303\252ncia (Hz) audio", nullptr));
        label_ch1_freq_2->setText(QCoreApplication::translate("ChannelPanel", "Dura\303\247\303\243o est\303\255mulo (ms)", nullptr));
        label_ch1_ampl_2->setText(QCoreApplication::translate("ChannelPanel", "Amplitude (%)", nullptr));
        label_38->setText(QCoreApplication::translate("ChannelPanel", "Frequ\303\252ncia portadora (Hz)", nullptr));
        label_39->setText(QCoreApplication::translate("ChannelPanel", "Frequ\303\252ncia de modula\303\247\303\243o (Hz)", nullptr));
        label_34->setText(QCoreApplication::translate("ChannelPanel", "Fator de modula\303\247\303\243o AM (%)", nullptr));
        label_35->setText(QCoreApplication::translate("ChannelPanel", "Exponencial do modulador", nullptr));
        label_36->setText(QCoreApplication::translate("ChannelPanel", "Fase FM", nullptr));
        label_37->setText(QCoreApplication::translate("ChannelPanel", "Fator de modula\303\247\303\243o FM (%)", nullptr));
        (void)ChannelPanel;
    } // retranslateUi

};

namespace Ui {
    class ChannelPanel: public Ui_ChannelPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEPANEL_H
