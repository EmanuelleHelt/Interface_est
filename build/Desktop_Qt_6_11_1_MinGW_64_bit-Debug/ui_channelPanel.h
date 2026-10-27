/********************************************************************************
** Form generated from reading UI file 'channelPanel.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELPANEL_H
#define UI_CHANNELPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelPanel
{
public:
    QVBoxLayout *channelVerticalLayout;
    QLabel *channelTitleLabel;
    QGroupBox *stimulusGroupBox;
    QGridLayout *stimulusGridLayout;
    QCheckBox *channelEnabledCheckBox;
    QLabel *waveformLabel;
    QComboBox *waveformComboBox;
    QLabel *frequencyLabel;
    QPushButton *frequencyMinusButton;
    QLineEdit *frequencyValueEdit;
    QPushButton *frequencyPlusButton;
    QLabel *amplitudeLabel;
    QPushButton *amplitudeMinusButton;
    QLineEdit *amplitudeValueEdit;
    QPushButton *amplitudePlusButton;
    QStackedWidget *protocolSettingsStack;
    QWidget *emptyProtocolPage;
    QTabWidget *channelGraphsTabWidget;
    QWidget *tab_1;
    QWidget *tab_2;

    void setupUi(QWidget *ChannelPanel)
    {
        if (ChannelPanel->objectName().isEmpty())
            ChannelPanel->setObjectName("ChannelPanel");
        ChannelPanel->resize(369, 436);
        channelVerticalLayout = new QVBoxLayout(ChannelPanel);
        channelVerticalLayout->setObjectName("channelVerticalLayout");
        channelTitleLabel = new QLabel(ChannelPanel);
        channelTitleLabel->setObjectName("channelTitleLabel");

        channelVerticalLayout->addWidget(channelTitleLabel);

        stimulusGroupBox = new QGroupBox(ChannelPanel);
        stimulusGroupBox->setObjectName("stimulusGroupBox");
        stimulusGridLayout = new QGridLayout(stimulusGroupBox);
        stimulusGridLayout->setObjectName("stimulusGridLayout");
        channelEnabledCheckBox = new QCheckBox(stimulusGroupBox);
        channelEnabledCheckBox->setObjectName("channelEnabledCheckBox");

        stimulusGridLayout->addWidget(channelEnabledCheckBox, 0, 0, 1, 4);

        waveformLabel = new QLabel(stimulusGroupBox);
        waveformLabel->setObjectName("waveformLabel");

        stimulusGridLayout->addWidget(waveformLabel, 1, 0, 1, 1);

        waveformComboBox = new QComboBox(stimulusGroupBox);
        waveformComboBox->addItem(QString());
        waveformComboBox->addItem(QString());
        waveformComboBox->addItem(QString());
        waveformComboBox->addItem(QString());
        waveformComboBox->addItem(QString());
        waveformComboBox->addItem(QString());
        waveformComboBox->setObjectName("waveformComboBox");

        stimulusGridLayout->addWidget(waveformComboBox, 1, 1, 1, 3);

        frequencyLabel = new QLabel(stimulusGroupBox);
        frequencyLabel->setObjectName("frequencyLabel");

        stimulusGridLayout->addWidget(frequencyLabel, 2, 0, 1, 1);

        frequencyMinusButton = new QPushButton(stimulusGroupBox);
        frequencyMinusButton->setObjectName("frequencyMinusButton");

        stimulusGridLayout->addWidget(frequencyMinusButton, 2, 1, 1, 1);

        frequencyValueEdit = new QLineEdit(stimulusGroupBox);
        frequencyValueEdit->setObjectName("frequencyValueEdit");
        frequencyValueEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        stimulusGridLayout->addWidget(frequencyValueEdit, 2, 2, 1, 1);

        frequencyPlusButton = new QPushButton(stimulusGroupBox);
        frequencyPlusButton->setObjectName("frequencyPlusButton");

        stimulusGridLayout->addWidget(frequencyPlusButton, 2, 3, 1, 1);

        amplitudeLabel = new QLabel(stimulusGroupBox);
        amplitudeLabel->setObjectName("amplitudeLabel");

        stimulusGridLayout->addWidget(amplitudeLabel, 3, 0, 1, 1);

        amplitudeMinusButton = new QPushButton(stimulusGroupBox);
        amplitudeMinusButton->setObjectName("amplitudeMinusButton");

        stimulusGridLayout->addWidget(amplitudeMinusButton, 3, 1, 1, 1);

        amplitudeValueEdit = new QLineEdit(stimulusGroupBox);
        amplitudeValueEdit->setObjectName("amplitudeValueEdit");
        amplitudeValueEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        stimulusGridLayout->addWidget(amplitudeValueEdit, 3, 2, 1, 1);

        amplitudePlusButton = new QPushButton(stimulusGroupBox);
        amplitudePlusButton->setObjectName("amplitudePlusButton");

        stimulusGridLayout->addWidget(amplitudePlusButton, 3, 3, 1, 1);


        channelVerticalLayout->addWidget(stimulusGroupBox);

        protocolSettingsStack = new QStackedWidget(ChannelPanel);
        protocolSettingsStack->setObjectName("protocolSettingsStack");
        emptyProtocolPage = new QWidget();
        emptyProtocolPage->setObjectName("emptyProtocolPage");
        protocolSettingsStack->addWidget(emptyProtocolPage);

        channelVerticalLayout->addWidget(protocolSettingsStack);

        channelGraphsTabWidget = new QTabWidget(ChannelPanel);
        channelGraphsTabWidget->setObjectName("channelGraphsTabWidget");
        tab_1 = new QWidget();
        tab_1->setObjectName("tab_1");
        channelGraphsTabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        channelGraphsTabWidget->addTab(tab_2, QString());

        channelVerticalLayout->addWidget(channelGraphsTabWidget);

        channelVerticalLayout->setStretch(3, 1);

        retranslateUi(ChannelPanel);

        protocolSettingsStack->setCurrentIndex(0);
        channelGraphsTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ChannelPanel);
    } // setupUi

    void retranslateUi(QWidget *ChannelPanel)
    {
        channelTitleLabel->setText(QCoreApplication::translate("ChannelPanel", "Canal", nullptr));
        stimulusGroupBox->setTitle(QCoreApplication::translate("ChannelPanel", "Par\303\242metros do est\303\255mulo", nullptr));
        channelEnabledCheckBox->setText(QCoreApplication::translate("ChannelPanel", "OFF", nullptr));
        waveformLabel->setText(QCoreApplication::translate("ChannelPanel", "Tipo de est\303\255mulo ", nullptr));
        waveformComboBox->setItemText(0, QCoreApplication::translate("ChannelPanel", "Senoidal", nullptr));
        waveformComboBox->setItemText(1, QCoreApplication::translate("ChannelPanel", "Onda Quadrada", nullptr));
        waveformComboBox->setItemText(2, QCoreApplication::translate("ChannelPanel", "Triangular", nullptr));
        waveformComboBox->setItemText(3, QCoreApplication::translate("ChannelPanel", "Dente de Serra", nullptr));
        waveformComboBox->setItemText(4, QCoreApplication::translate("ChannelPanel", "Trem de pulso", nullptr));
        waveformComboBox->setItemText(5, QCoreApplication::translate("ChannelPanel", "Personalizado", nullptr));

        frequencyLabel->setText(QCoreApplication::translate("ChannelPanel", "Frequ\303\252ncia (Hz)", nullptr));
        frequencyMinusButton->setText(QCoreApplication::translate("ChannelPanel", "-", nullptr));
        frequencyValueEdit->setText(QCoreApplication::translate("ChannelPanel", "0", nullptr));
        frequencyPlusButton->setText(QCoreApplication::translate("ChannelPanel", "+", nullptr));
        amplitudeLabel->setText(QCoreApplication::translate("ChannelPanel", "Amplitude (\302\265A)", nullptr));
        amplitudeMinusButton->setText(QCoreApplication::translate("ChannelPanel", "-", nullptr));
        amplitudeValueEdit->setText(QCoreApplication::translate("ChannelPanel", "0", nullptr));
        amplitudePlusButton->setText(QCoreApplication::translate("ChannelPanel", "+", nullptr));
        channelGraphsTabWidget->setTabText(channelGraphsTabWidget->indexOf(tab_1), QCoreApplication::translate("ChannelPanel", "Forma de onda", nullptr));
        channelGraphsTabWidget->setTabText(channelGraphsTabWidget->indexOf(tab_2), QCoreApplication::translate("ChannelPanel", "Evolu\303\247\303\243o do protocolo", nullptr));
        (void)ChannelPanel;
    } // retranslateUi

};

namespace Ui {
    class ChannelPanel: public Ui_ChannelPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELPANEL_H
