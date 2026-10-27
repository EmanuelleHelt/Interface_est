/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRegistrar_paciente;
    QAction *actionSalvar_sessao;
    QAction *actionSobre;
    QWidget *centralwidget;
    QPushButton *testeCanais_pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QSpinBox *ch1_spinBox_ciclos;
    QSpinBox *spinBox_protocol;
    QDoubleSpinBox *ch2_doubleSpinBox_I2i;
    QDoubleSpinBox *ch1_doubleSpinBox_I1i;
    QVBoxLayout *verticalLayout_6;
    QDoubleSpinBox *doubleSpinBox_toff;
    QSpinBox *ch2_spinBox_ciclos;
    QDoubleSpinBox *doubleSpinBox_ton;
    QDoubleSpinBox *ch1_doubleSpinBox_trigger;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *ciclicoCheckBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *iniciarEstimulo_pushButton;
    QPushButton *pararEstimulo_pushButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_15;
    QToolButton *loadProtocol;
    QToolButton *continuousProtocol;
    QToolButton *rampProtocol;
    QToolButton *thresholdProtocol;
    QToolButton *limitedProtocol;
    QToolButton *customProtocol;
    QComboBox *protocoloEstimulacao_comboBox;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(938, 552);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(32);
        sizePolicy.setVerticalStretch(32);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setIconSize(QSize(25, 25));
        MainWindow->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        actionRegistrar_paciente = new QAction(MainWindow);
        actionRegistrar_paciente->setObjectName("actionRegistrar_paciente");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font.setPointSize(14);
        actionRegistrar_paciente->setFont(font);
        actionSalvar_sessao = new QAction(MainWindow);
        actionSalvar_sessao->setObjectName("actionSalvar_sessao");
        actionSalvar_sessao->setFont(font);
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName("actionSobre");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font1.setPointSize(18);
        actionSobre->setFont(font1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        testeCanais_pushButton = new QPushButton(centralwidget);
        testeCanais_pushButton->setObjectName("testeCanais_pushButton");
        testeCanais_pushButton->setGeometry(QRect(550, 50, 20, 18));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(560, 110, 68, 358));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        ch1_spinBox_ciclos = new QSpinBox(layoutWidget);
        ch1_spinBox_ciclos->setObjectName("ch1_spinBox_ciclos");
        ch1_spinBox_ciclos->setEnabled(true);

        verticalLayout_7->addWidget(ch1_spinBox_ciclos);

        spinBox_protocol = new QSpinBox(layoutWidget);
        spinBox_protocol->setObjectName("spinBox_protocol");
        spinBox_protocol->setEnabled(true);

        verticalLayout_7->addWidget(spinBox_protocol);

        ch2_doubleSpinBox_I2i = new QDoubleSpinBox(layoutWidget);
        ch2_doubleSpinBox_I2i->setObjectName("ch2_doubleSpinBox_I2i");
        ch2_doubleSpinBox_I2i->setEnabled(true);

        verticalLayout_7->addWidget(ch2_doubleSpinBox_I2i);

        ch1_doubleSpinBox_I1i = new QDoubleSpinBox(layoutWidget);
        ch1_doubleSpinBox_I1i->setObjectName("ch1_doubleSpinBox_I1i");
        ch1_doubleSpinBox_I1i->setEnabled(true);

        verticalLayout_7->addWidget(ch1_doubleSpinBox_I1i);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        doubleSpinBox_toff = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_toff->setObjectName("doubleSpinBox_toff");
        doubleSpinBox_toff->setEnabled(true);

        verticalLayout_6->addWidget(doubleSpinBox_toff);

        ch2_spinBox_ciclos = new QSpinBox(layoutWidget);
        ch2_spinBox_ciclos->setObjectName("ch2_spinBox_ciclos");
        ch2_spinBox_ciclos->setEnabled(true);

        verticalLayout_6->addWidget(ch2_spinBox_ciclos);

        doubleSpinBox_ton = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_ton->setObjectName("doubleSpinBox_ton");
        doubleSpinBox_ton->setEnabled(true);

        verticalLayout_6->addWidget(doubleSpinBox_ton);

        ch1_doubleSpinBox_trigger = new QDoubleSpinBox(layoutWidget);
        ch1_doubleSpinBox_trigger->setObjectName("ch1_doubleSpinBox_trigger");
        ch1_doubleSpinBox_trigger->setEnabled(true);

        verticalLayout_6->addWidget(ch1_doubleSpinBox_trigger);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        ciclicoCheckBox = new QCheckBox(layoutWidget);
        ciclicoCheckBox->setObjectName("ciclicoCheckBox");

        verticalLayout_5->addWidget(ciclicoCheckBox);


        verticalLayout_7->addLayout(verticalLayout_5);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(590, 30, 321, 53));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_11->setSpacing(30);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        iniciarEstimulo_pushButton = new QPushButton(layoutWidget1);
        iniciarEstimulo_pushButton->setObjectName("iniciarEstimulo_pushButton");

        horizontalLayout_11->addWidget(iniciarEstimulo_pushButton);

        pararEstimulo_pushButton = new QPushButton(layoutWidget1);
        pararEstimulo_pushButton->setObjectName("pararEstimulo_pushButton");

        horizontalLayout_11->addWidget(pararEstimulo_pushButton);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 30, 496, 144));
        verticalLayout_8 = new QVBoxLayout(layoutWidget2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        loadProtocol = new QToolButton(layoutWidget2);
        loadProtocol->setObjectName("loadProtocol");
        loadProtocol->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/loag.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        loadProtocol->setIcon(icon);
        loadProtocol->setIconSize(QSize(30, 30));
        loadProtocol->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout_15->addWidget(loadProtocol);

        continuousProtocol = new QToolButton(layoutWidget2);
        continuousProtocol->setObjectName("continuousProtocol");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cont.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        continuousProtocol->setIcon(icon1);
        continuousProtocol->setIconSize(QSize(60, 60));
        continuousProtocol->setCheckable(true);
        continuousProtocol->setChecked(false);
        continuousProtocol->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout_15->addWidget(continuousProtocol);

        rampProtocol = new QToolButton(layoutWidget2);
        rampProtocol->setObjectName("rampProtocol");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/ramp.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        rampProtocol->setIcon(icon2);
        rampProtocol->setIconSize(QSize(60, 60));
        rampProtocol->setCheckable(true);
        rampProtocol->setChecked(false);
        rampProtocol->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout_15->addWidget(rampProtocol);

        thresholdProtocol = new QToolButton(layoutWidget2);
        thresholdProtocol->setObjectName("thresholdProtocol");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/limiar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        thresholdProtocol->setIcon(icon3);
        thresholdProtocol->setIconSize(QSize(60, 60));
        thresholdProtocol->setCheckable(true);
        thresholdProtocol->setChecked(false);
        thresholdProtocol->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout_15->addWidget(thresholdProtocol);

        limitedProtocol = new QToolButton(layoutWidget2);
        limitedProtocol->setObjectName("limitedProtocol");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/lim.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        limitedProtocol->setIcon(icon4);
        limitedProtocol->setIconSize(QSize(60, 60));
        limitedProtocol->setCheckable(true);
        limitedProtocol->setChecked(false);
        limitedProtocol->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout_15->addWidget(limitedProtocol);

        customProtocol = new QToolButton(layoutWidget2);
        customProtocol->setObjectName("customProtocol");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/perz.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        customProtocol->setIcon(icon5);
        customProtocol->setIconSize(QSize(60, 60));
        customProtocol->setCheckable(true);
        customProtocol->setChecked(false);
        customProtocol->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout_15->addWidget(customProtocol);


        verticalLayout_8->addLayout(horizontalLayout_15);

        protocoloEstimulacao_comboBox = new QComboBox(centralwidget);
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->setObjectName("protocoloEstimulacao_comboBox");
        protocoloEstimulacao_comboBox->setGeometry(QRect(40, 280, 300, 50));
        protocoloEstimulacao_comboBox->setMinimumSize(QSize(300, 50));
        protocoloEstimulacao_comboBox->setMaximumSize(QSize(500, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font2.setPointSize(16);
        protocoloEstimulacao_comboBox->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRegistrar_paciente->setText(QCoreApplication::translate("MainWindow", "Registrar paciente", nullptr));
        actionSalvar_sessao->setText(QCoreApplication::translate("MainWindow", "Salvar sessao", nullptr));
        actionSobre->setText(QCoreApplication::translate("MainWindow", "Sobre", nullptr));
        testeCanais_pushButton->setText(QString());
        ciclicoCheckBox->setText(QCoreApplication::translate("MainWindow", "Cicl\303\255co", nullptr));
        iniciarEstimulo_pushButton->setText(QCoreApplication::translate("MainWindow", "Iniciar", nullptr));
        pararEstimulo_pushButton->setText(QCoreApplication::translate("MainWindow", "Parar", nullptr));
        loadProtocol->setText(QCoreApplication::translate("MainWindow", "Carregar", nullptr));
        continuousProtocol->setText(QCoreApplication::translate("MainWindow", "Cont\303\255nuo", nullptr));
        rampProtocol->setText(QCoreApplication::translate("MainWindow", "Rampa", nullptr));
        thresholdProtocol->setText(QCoreApplication::translate("MainWindow", "Limiar", nullptr));
        limitedProtocol->setText(QCoreApplication::translate("MainWindow", "Limitado", nullptr));
        customProtocol->setText(QCoreApplication::translate("MainWindow", "Personalizado", nullptr));
        protocoloEstimulacao_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Cont\303\255nuo", nullptr));
        protocoloEstimulacao_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Personalizado ", nullptr));
        protocoloEstimulacao_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Limiar de sensibilidade", nullptr));
        protocoloEstimulacao_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Rampa ", nullptr));
        protocoloEstimulacao_comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Limitado ", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
