/********************************************************************************
** Form generated from reading UI file 'rampSettingsPanel.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAMPSETTINGSPANEL_H
#define UI_RAMPSETTINGSPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RampSettingsPanel
{
public:
    QGridLayout *rampSettingsGridLayout;
    QLabel *stepAmplitudeLabel;
    QPushButton *stimulationTimeMinusButton;
    QLineEdit *stimulationTimeValueEdit;
    QPushButton *feltButton;
    QLabel *resultLabel;
    QLabel *currentAmplitudeLabel;
    QLabel *statusLabel;
    QLabel *stimulationTimeLabel;
    QPushButton *restTimePlusButton;
    QLineEdit *restTimeValueEdit;
    QPushButton *stepAmplitudeMinusButton;
    QLineEdit *stepAmplitudeValueEdit;
    QLabel *restTimeLabel;
    QPushButton *stimulationTimePlusButton;
    QPushButton *restTimeMinusButton;
    QPushButton *stepAmplitudePlusButton;

    void setupUi(QWidget *RampSettingsPanel)
    {
        if (RampSettingsPanel->objectName().isEmpty())
            RampSettingsPanel->setObjectName("RampSettingsPanel");
        RampSettingsPanel->resize(500, 320);
        rampSettingsGridLayout = new QGridLayout(RampSettingsPanel);
        rampSettingsGridLayout->setObjectName("rampSettingsGridLayout");
        stepAmplitudeLabel = new QLabel(RampSettingsPanel);
        stepAmplitudeLabel->setObjectName("stepAmplitudeLabel");

        rampSettingsGridLayout->addWidget(stepAmplitudeLabel, 0, 0, 1, 1);

        stimulationTimeMinusButton = new QPushButton(RampSettingsPanel);
        stimulationTimeMinusButton->setObjectName("stimulationTimeMinusButton");

        rampSettingsGridLayout->addWidget(stimulationTimeMinusButton, 1, 1, 1, 1);

        stimulationTimeValueEdit = new QLineEdit(RampSettingsPanel);
        stimulationTimeValueEdit->setObjectName("stimulationTimeValueEdit");
        stimulationTimeValueEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        rampSettingsGridLayout->addWidget(stimulationTimeValueEdit, 1, 2, 1, 1);

        feltButton = new QPushButton(RampSettingsPanel);
        feltButton->setObjectName("feltButton");
        feltButton->setEnabled(false);

        rampSettingsGridLayout->addWidget(feltButton, 3, 0, 1, 4);

        resultLabel = new QLabel(RampSettingsPanel);
        resultLabel->setObjectName("resultLabel");

        rampSettingsGridLayout->addWidget(resultLabel, 5, 0, 1, 4);

        currentAmplitudeLabel = new QLabel(RampSettingsPanel);
        currentAmplitudeLabel->setObjectName("currentAmplitudeLabel");

        rampSettingsGridLayout->addWidget(currentAmplitudeLabel, 4, 0, 1, 4);

        statusLabel = new QLabel(RampSettingsPanel);
        statusLabel->setObjectName("statusLabel");

        rampSettingsGridLayout->addWidget(statusLabel, 6, 0, 1, 4);

        stimulationTimeLabel = new QLabel(RampSettingsPanel);
        stimulationTimeLabel->setObjectName("stimulationTimeLabel");

        rampSettingsGridLayout->addWidget(stimulationTimeLabel, 1, 0, 1, 1);

        restTimePlusButton = new QPushButton(RampSettingsPanel);
        restTimePlusButton->setObjectName("restTimePlusButton");

        rampSettingsGridLayout->addWidget(restTimePlusButton, 2, 3, 1, 1);

        restTimeValueEdit = new QLineEdit(RampSettingsPanel);
        restTimeValueEdit->setObjectName("restTimeValueEdit");
        restTimeValueEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        rampSettingsGridLayout->addWidget(restTimeValueEdit, 2, 2, 1, 1);

        stepAmplitudeMinusButton = new QPushButton(RampSettingsPanel);
        stepAmplitudeMinusButton->setObjectName("stepAmplitudeMinusButton");

        rampSettingsGridLayout->addWidget(stepAmplitudeMinusButton, 0, 1, 1, 1);

        stepAmplitudeValueEdit = new QLineEdit(RampSettingsPanel);
        stepAmplitudeValueEdit->setObjectName("stepAmplitudeValueEdit");
        stepAmplitudeValueEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        rampSettingsGridLayout->addWidget(stepAmplitudeValueEdit, 0, 2, 1, 1);

        restTimeLabel = new QLabel(RampSettingsPanel);
        restTimeLabel->setObjectName("restTimeLabel");

        rampSettingsGridLayout->addWidget(restTimeLabel, 2, 0, 1, 1);

        stimulationTimePlusButton = new QPushButton(RampSettingsPanel);
        stimulationTimePlusButton->setObjectName("stimulationTimePlusButton");

        rampSettingsGridLayout->addWidget(stimulationTimePlusButton, 1, 3, 1, 1);

        restTimeMinusButton = new QPushButton(RampSettingsPanel);
        restTimeMinusButton->setObjectName("restTimeMinusButton");

        rampSettingsGridLayout->addWidget(restTimeMinusButton, 2, 1, 1, 1);

        stepAmplitudePlusButton = new QPushButton(RampSettingsPanel);
        stepAmplitudePlusButton->setObjectName("stepAmplitudePlusButton");

        rampSettingsGridLayout->addWidget(stepAmplitudePlusButton, 0, 3, 1, 1);

#if QT_CONFIG(shortcut)
        stepAmplitudeLabel->setBuddy(stepAmplitudeValueEdit);
        stimulationTimeLabel->setBuddy(stimulationTimeValueEdit);
        restTimeLabel->setBuddy(restTimeValueEdit);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(stepAmplitudeMinusButton, stepAmplitudeValueEdit);
        QWidget::setTabOrder(stepAmplitudeValueEdit, stepAmplitudePlusButton);
        QWidget::setTabOrder(stepAmplitudePlusButton, stimulationTimeMinusButton);
        QWidget::setTabOrder(stimulationTimeMinusButton, stimulationTimeValueEdit);
        QWidget::setTabOrder(stimulationTimeValueEdit, stimulationTimePlusButton);
        QWidget::setTabOrder(stimulationTimePlusButton, restTimeMinusButton);
        QWidget::setTabOrder(restTimeMinusButton, restTimeValueEdit);
        QWidget::setTabOrder(restTimeValueEdit, restTimePlusButton);
        QWidget::setTabOrder(restTimePlusButton, feltButton);

        retranslateUi(RampSettingsPanel);

        QMetaObject::connectSlotsByName(RampSettingsPanel);
    } // setupUi

    void retranslateUi(QWidget *RampSettingsPanel)
    {
        RampSettingsPanel->setWindowTitle(QCoreApplication::translate("RampSettingsPanel", "Configura\303\247\303\243o da rampa", nullptr));
        stepAmplitudeLabel->setText(QCoreApplication::translate("RampSettingsPanel", "Passo de amplitude (\302\265A)", nullptr));
        stimulationTimeMinusButton->setText(QCoreApplication::translate("RampSettingsPanel", "\342\210\222", nullptr));
        stimulationTimeValueEdit->setText(QString());
        feltButton->setText(QCoreApplication::translate("RampSettingsPanel", "Percep\303\247\303\243o de est\303\255mulo", nullptr));
        resultLabel->setText(QCoreApplication::translate("RampSettingsPanel", "Resultado: \342\200\224 \302\265A", nullptr));
        currentAmplitudeLabel->setText(QCoreApplication::translate("RampSettingsPanel", "Amplitude atual: \342\200\224 \302\265A", nullptr));
        statusLabel->setText(QCoreApplication::translate("RampSettingsPanel", "Estado: Aguardando in\303\255cio", nullptr));
        stimulationTimeLabel->setText(QCoreApplication::translate("RampSettingsPanel", "Tempo de estimula\303\247\303\243o (s)", nullptr));
        restTimePlusButton->setText(QCoreApplication::translate("RampSettingsPanel", "+", nullptr));
        restTimeValueEdit->setText(QString());
        stepAmplitudeMinusButton->setText(QCoreApplication::translate("RampSettingsPanel", "\342\210\222", nullptr));
        stepAmplitudeValueEdit->setText(QString());
        restTimeLabel->setText(QCoreApplication::translate("RampSettingsPanel", "Tempo de repouso (s)", nullptr));
        stimulationTimePlusButton->setText(QCoreApplication::translate("RampSettingsPanel", "+", nullptr));
        restTimeMinusButton->setText(QCoreApplication::translate("RampSettingsPanel", "\342\210\222", nullptr));
        stepAmplitudePlusButton->setText(QCoreApplication::translate("RampSettingsPanel", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RampSettingsPanel: public Ui_RampSettingsPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAMPSETTINGSPANEL_H
