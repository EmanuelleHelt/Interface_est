/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame_2_Canais;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_ch1;
    QVBoxLayout *verticalLayout;
    QFrame *frame_Titulo_ch1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_ch1_titulo;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *ch1_checkBox_ON;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_ch1_ciclos;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_8;
    QComboBox *ch1_comboBox_tipoEstimulo;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_21;
    QDoubleSpinBox *ch1_doubleSpinBox_trigger;
    QFrame *frame_ch1_freq;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_ch1_freq;
    QSpinBox *ch1_spinBox_freq;
    QFrame *frame_ch1_ampl;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_ch1_ampl;
    QSpinBox *ch1_spinBox_ampl;
    QLabel *label_23;
    QDoubleSpinBox *ch1_doubleSpinBox_I1i;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QSpinBox *ch1_spinBox_ciclos;
    QLabel *label_ch1_180phase;
    QCheckBox *ch1_checkBox_180phase;
    QGraphicsView *ch1_graphicsView;
    QFrame *frame_ch2;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_Titulo_ch2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *ch2_checkBox_ON;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_10;
    QComboBox *ch2_comboBox_tipoEstimulo;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_2;
    QFrame *frame_14;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QSpinBox *ch2_spinBox_freq;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QSpinBox *ch2_spinBox_ampl;
    QLabel *label_24;
    QDoubleSpinBox *ch2_doubleSpinBox_I2i;
    QFrame *frame_15;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QSpinBox *ch2_spinBox_ciclos;
    QLabel *label_15;
    QCheckBox *checkBox_4;
    QGraphicsView *graphicsView_2;
    QFrame *frame_1_Titulo;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *testeCanais_pushButton;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QLabel *label_16;
    QLabel *label_17;
    QFrame *frame_3_Config_Estimulo;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *protocoloEstimulacao_comboBox;
    QCheckBox *ciclicoCheckBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QTimeEdit *timeEdit;
    QFrame *frame_3;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_18;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_toff;
    QDoubleSpinBox *doubleSpinBox_ton;
    QFrame *frame_4;
    QLabel *label_20;
    QPushButton *pushButton;
    QSpinBox *spinBox_protocol;
    QPushButton *iniciarEstimulo_pushButton;
    QPushButton *pararEstimulo_pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1118, 920);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/LAPIS_UFRJ.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame_2_Canais = new QFrame(centralwidget);
        frame_2_Canais->setObjectName("frame_2_Canais");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2_Canais->sizePolicy().hasHeightForWidth());
        frame_2_Canais->setSizePolicy(sizePolicy);
        frame_2_Canais->setMinimumSize(QSize(0, 400));
        frame_2_Canais->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2_Canais->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2_Canais);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        frame_ch1 = new QFrame(frame_2_Canais);
        frame_ch1->setObjectName("frame_ch1");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_ch1->sizePolicy().hasHeightForWidth());
        frame_ch1->setSizePolicy(sizePolicy1);
        frame_ch1->setFrameShape(QFrame::Shape::StyledPanel);
        frame_ch1->setFrameShadow(QFrame::Shadow::Plain);
        frame_ch1->setLineWidth(0);
        frame_ch1->setMidLineWidth(0);
        verticalLayout = new QVBoxLayout(frame_ch1);
        verticalLayout->setObjectName("verticalLayout");
        frame_Titulo_ch1 = new QFrame(frame_ch1);
        frame_Titulo_ch1->setObjectName("frame_Titulo_ch1");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(frame_Titulo_ch1->sizePolicy().hasHeightForWidth());
        frame_Titulo_ch1->setSizePolicy(sizePolicy2);
        frame_Titulo_ch1->setFrameShape(QFrame::Shape::StyledPanel);
        frame_Titulo_ch1->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_Titulo_ch1);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_ch1_titulo = new QLabel(frame_Titulo_ch1);
        label_ch1_titulo->setObjectName("label_ch1_titulo");
        QFont font;
        font.setFamilies({QString::fromUtf8("Malgun Gothic")});
        font.setPointSize(13);
        font.setBold(true);
        label_ch1_titulo->setFont(font);

        horizontalLayout_6->addWidget(label_ch1_titulo);

        horizontalSpacer_3 = new QSpacerItem(187, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        ch1_checkBox_ON = new QCheckBox(frame_Titulo_ch1);
        ch1_checkBox_ON->setObjectName("ch1_checkBox_ON");
        ch1_checkBox_ON->setMaximumSize(QSize(52, 44));
        ch1_checkBox_ON->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(ch1_checkBox_ON);


        verticalLayout->addWidget(frame_Titulo_ch1);

        frame_5 = new QFrame(frame_ch1);
        frame_5->setObjectName("frame_5");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(4);
        sizePolicy3.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy3);
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame_ch1_ciclos = new QFrame(frame_5);
        frame_ch1_ciclos->setObjectName("frame_ch1_ciclos");
        frame_ch1_ciclos->setFrameShape(QFrame::Shape::StyledPanel);
        frame_ch1_ciclos->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_14 = new QHBoxLayout(frame_ch1_ciclos);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_8 = new QLabel(frame_ch1_ciclos);
        label_8->setObjectName("label_8");

        horizontalLayout_14->addWidget(label_8);

        ch1_comboBox_tipoEstimulo = new QComboBox(frame_ch1_ciclos);
        ch1_comboBox_tipoEstimulo->addItem(QString());
        ch1_comboBox_tipoEstimulo->addItem(QString());
        ch1_comboBox_tipoEstimulo->addItem(QString());
        ch1_comboBox_tipoEstimulo->addItem(QString());
        ch1_comboBox_tipoEstimulo->addItem(QString());
        ch1_comboBox_tipoEstimulo->addItem(QString());
        ch1_comboBox_tipoEstimulo->setObjectName("ch1_comboBox_tipoEstimulo");

        horizontalLayout_14->addWidget(ch1_comboBox_tipoEstimulo);

        frame_6 = new QFrame(frame_ch1_ciclos);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_16 = new QHBoxLayout(frame_6);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_21 = new QLabel(frame_6);
        label_21->setObjectName("label_21");

        horizontalLayout_16->addWidget(label_21);

        ch1_doubleSpinBox_trigger = new QDoubleSpinBox(frame_6);
        ch1_doubleSpinBox_trigger->setObjectName("ch1_doubleSpinBox_trigger");

        horizontalLayout_16->addWidget(ch1_doubleSpinBox_trigger);


        horizontalLayout_14->addWidget(frame_6);


        verticalLayout_2->addWidget(frame_ch1_ciclos);

        frame_ch1_freq = new QFrame(frame_5);
        frame_ch1_freq->setObjectName("frame_ch1_freq");
        frame_ch1_freq->setFrameShape(QFrame::Shape::StyledPanel);
        frame_ch1_freq->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame_ch1_freq);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_ch1_freq = new QLabel(frame_ch1_freq);
        label_ch1_freq->setObjectName("label_ch1_freq");

        horizontalLayout_13->addWidget(label_ch1_freq);

        ch1_spinBox_freq = new QSpinBox(frame_ch1_freq);
        ch1_spinBox_freq->setObjectName("ch1_spinBox_freq");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ch1_spinBox_freq->sizePolicy().hasHeightForWidth());
        ch1_spinBox_freq->setSizePolicy(sizePolicy4);
        ch1_spinBox_freq->setMaximumSize(QSize(90, 16777215));
        ch1_spinBox_freq->setMaximum(64000);
        ch1_spinBox_freq->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        ch1_spinBox_freq->setValue(3200);

        horizontalLayout_13->addWidget(ch1_spinBox_freq);


        verticalLayout_2->addWidget(frame_ch1_freq);

        frame_ch1_ampl = new QFrame(frame_5);
        frame_ch1_ampl->setObjectName("frame_ch1_ampl");
        frame_ch1_ampl->setFrameShape(QFrame::Shape::StyledPanel);
        frame_ch1_ampl->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_ch1_ampl);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_ch1_ampl = new QLabel(frame_ch1_ampl);
        label_ch1_ampl->setObjectName("label_ch1_ampl");

        horizontalLayout_9->addWidget(label_ch1_ampl);

        ch1_spinBox_ampl = new QSpinBox(frame_ch1_ampl);
        ch1_spinBox_ampl->setObjectName("ch1_spinBox_ampl");
        sizePolicy4.setHeightForWidth(ch1_spinBox_ampl->sizePolicy().hasHeightForWidth());
        ch1_spinBox_ampl->setSizePolicy(sizePolicy4);
        ch1_spinBox_ampl->setMaximumSize(QSize(90, 16777215));
        ch1_spinBox_ampl->setMaximum(10000);
        ch1_spinBox_ampl->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        ch1_spinBox_ampl->setValue(100);

        horizontalLayout_9->addWidget(ch1_spinBox_ampl);

        label_23 = new QLabel(frame_ch1_ampl);
        label_23->setObjectName("label_23");

        horizontalLayout_9->addWidget(label_23);

        ch1_doubleSpinBox_I1i = new QDoubleSpinBox(frame_ch1_ampl);
        ch1_doubleSpinBox_I1i->setObjectName("ch1_doubleSpinBox_I1i");
        ch1_doubleSpinBox_I1i->setMinimumSize(QSize(50, 0));
        ch1_doubleSpinBox_I1i->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_9->addWidget(ch1_doubleSpinBox_I1i);


        verticalLayout_2->addWidget(frame_ch1_ampl);

        frame_10 = new QFrame(frame_5);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_10);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_11 = new QLabel(frame_10);
        label_11->setObjectName("label_11");

        horizontalLayout_8->addWidget(label_11);

        ch1_spinBox_ciclos = new QSpinBox(frame_10);
        ch1_spinBox_ciclos->setObjectName("ch1_spinBox_ciclos");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(ch1_spinBox_ciclos->sizePolicy().hasHeightForWidth());
        ch1_spinBox_ciclos->setSizePolicy(sizePolicy5);
        ch1_spinBox_ciclos->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(ch1_spinBox_ciclos);

        label_ch1_180phase = new QLabel(frame_10);
        label_ch1_180phase->setObjectName("label_ch1_180phase");

        horizontalLayout_8->addWidget(label_ch1_180phase);

        ch1_checkBox_180phase = new QCheckBox(frame_10);
        ch1_checkBox_180phase->setObjectName("ch1_checkBox_180phase");
        ch1_checkBox_180phase->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_8->addWidget(ch1_checkBox_180phase);


        verticalLayout_2->addWidget(frame_10);


        verticalLayout->addWidget(frame_5);

        ch1_graphicsView = new QGraphicsView(frame_ch1);
        ch1_graphicsView->setObjectName("ch1_graphicsView");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(ch1_graphicsView->sizePolicy().hasHeightForWidth());
        ch1_graphicsView->setSizePolicy(sizePolicy6);

        verticalLayout->addWidget(ch1_graphicsView);


        horizontalLayout_3->addWidget(frame_ch1);

        frame_ch2 = new QFrame(frame_2_Canais);
        frame_ch2->setObjectName("frame_ch2");
        sizePolicy1.setHeightForWidth(frame_ch2->sizePolicy().hasHeightForWidth());
        frame_ch2->setSizePolicy(sizePolicy1);
        frame_ch2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_ch2->setFrameShadow(QFrame::Shadow::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame_ch2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_Titulo_ch2 = new QFrame(frame_ch2);
        frame_Titulo_ch2->setObjectName("frame_Titulo_ch2");
        sizePolicy2.setHeightForWidth(frame_Titulo_ch2->sizePolicy().hasHeightForWidth());
        frame_Titulo_ch2->setSizePolicy(sizePolicy2);
        frame_Titulo_ch2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_Titulo_ch2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_Titulo_ch2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_9 = new QLabel(frame_Titulo_ch2);
        label_9->setObjectName("label_9");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Malgun Gothic")});
        font1.setPointSize(14);
        font1.setBold(true);
        label_9->setFont(font1);

        horizontalLayout_7->addWidget(label_9);

        horizontalSpacer_4 = new QSpacerItem(185, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        ch2_checkBox_ON = new QCheckBox(frame_Titulo_ch2);
        ch2_checkBox_ON->setObjectName("ch2_checkBox_ON");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(ch2_checkBox_ON->sizePolicy().hasHeightForWidth());
        ch2_checkBox_ON->setSizePolicy(sizePolicy7);
        ch2_checkBox_ON->setMaximumSize(QSize(52, 44));
        ch2_checkBox_ON->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(ch2_checkBox_ON);


        verticalLayout_3->addWidget(frame_Titulo_ch2);

        frame_7 = new QFrame(frame_ch2);
        frame_7->setObjectName("frame_7");
        sizePolicy3.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy3);
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_7);
        verticalLayout_6->setObjectName("verticalLayout_6");
        frame = new QFrame(frame_7);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_15 = new QHBoxLayout(frame);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");

        horizontalLayout_15->addWidget(label_10);

        ch2_comboBox_tipoEstimulo = new QComboBox(frame);
        ch2_comboBox_tipoEstimulo->addItem(QString());
        ch2_comboBox_tipoEstimulo->addItem(QString());
        ch2_comboBox_tipoEstimulo->addItem(QString());
        ch2_comboBox_tipoEstimulo->addItem(QString());
        ch2_comboBox_tipoEstimulo->addItem(QString());
        ch2_comboBox_tipoEstimulo->addItem(QString());
        ch2_comboBox_tipoEstimulo->setObjectName("ch2_comboBox_tipoEstimulo");

        horizontalLayout_15->addWidget(ch2_comboBox_tipoEstimulo);

        frame_8 = new QFrame(frame);
        frame_8->setObjectName("frame_8");
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_17 = new QHBoxLayout(frame_8);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_22 = new QLabel(frame_8);
        label_22->setObjectName("label_22");

        horizontalLayout_17->addWidget(label_22);

        doubleSpinBox_2 = new QDoubleSpinBox(frame_8);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");

        horizontalLayout_17->addWidget(doubleSpinBox_2);


        horizontalLayout_15->addWidget(frame_8);


        verticalLayout_6->addWidget(frame);

        frame_14 = new QFrame(frame_7);
        frame_14->setObjectName("frame_14");
        frame_14->setFrameShape(QFrame::Shape::StyledPanel);
        frame_14->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_14);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_13 = new QLabel(frame_14);
        label_13->setObjectName("label_13");

        horizontalLayout_10->addWidget(label_13);

        ch2_spinBox_freq = new QSpinBox(frame_14);
        ch2_spinBox_freq->setObjectName("ch2_spinBox_freq");
        sizePolicy4.setHeightForWidth(ch2_spinBox_freq->sizePolicy().hasHeightForWidth());
        ch2_spinBox_freq->setSizePolicy(sizePolicy4);
        ch2_spinBox_freq->setMaximumSize(QSize(90, 16777215));
        ch2_spinBox_freq->setMaximum(64000);
        ch2_spinBox_freq->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        ch2_spinBox_freq->setValue(1000);

        horizontalLayout_10->addWidget(ch2_spinBox_freq);


        verticalLayout_6->addWidget(frame_14);

        frame_13 = new QFrame(frame_7);
        frame_13->setObjectName("frame_13");
        frame_13->setFrameShape(QFrame::Shape::StyledPanel);
        frame_13->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_11 = new QHBoxLayout(frame_13);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_14 = new QLabel(frame_13);
        label_14->setObjectName("label_14");

        horizontalLayout_11->addWidget(label_14);

        ch2_spinBox_ampl = new QSpinBox(frame_13);
        ch2_spinBox_ampl->setObjectName("ch2_spinBox_ampl");
        sizePolicy4.setHeightForWidth(ch2_spinBox_ampl->sizePolicy().hasHeightForWidth());
        ch2_spinBox_ampl->setSizePolicy(sizePolicy4);
        ch2_spinBox_ampl->setMaximumSize(QSize(90, 16777215));
        ch2_spinBox_ampl->setMaximum(10000);
        ch2_spinBox_ampl->setStepType(QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
        ch2_spinBox_ampl->setValue(100);

        horizontalLayout_11->addWidget(ch2_spinBox_ampl);

        label_24 = new QLabel(frame_13);
        label_24->setObjectName("label_24");

        horizontalLayout_11->addWidget(label_24);

        ch2_doubleSpinBox_I2i = new QDoubleSpinBox(frame_13);
        ch2_doubleSpinBox_I2i->setObjectName("ch2_doubleSpinBox_I2i");
        ch2_doubleSpinBox_I2i->setMinimumSize(QSize(50, 0));
        ch2_doubleSpinBox_I2i->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_11->addWidget(ch2_doubleSpinBox_I2i);


        verticalLayout_6->addWidget(frame_13);

        frame_15 = new QFrame(frame_7);
        frame_15->setObjectName("frame_15");
        frame_15->setFrameShape(QFrame::Shape::StyledPanel);
        frame_15->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_15);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_12 = new QLabel(frame_15);
        label_12->setObjectName("label_12");

        horizontalLayout_12->addWidget(label_12);

        ch2_spinBox_ciclos = new QSpinBox(frame_15);
        ch2_spinBox_ciclos->setObjectName("ch2_spinBox_ciclos");
        sizePolicy4.setHeightForWidth(ch2_spinBox_ciclos->sizePolicy().hasHeightForWidth());
        ch2_spinBox_ciclos->setSizePolicy(sizePolicy4);
        ch2_spinBox_ciclos->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_12->addWidget(ch2_spinBox_ciclos);

        label_15 = new QLabel(frame_15);
        label_15->setObjectName("label_15");

        horizontalLayout_12->addWidget(label_15);

        checkBox_4 = new QCheckBox(frame_15);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_12->addWidget(checkBox_4);


        verticalLayout_6->addWidget(frame_15);


        verticalLayout_3->addWidget(frame_7);

        graphicsView_2 = new QGraphicsView(frame_ch2);
        graphicsView_2->setObjectName("graphicsView_2");
        sizePolicy6.setHeightForWidth(graphicsView_2->sizePolicy().hasHeightForWidth());
        graphicsView_2->setSizePolicy(sizePolicy6);

        verticalLayout_3->addWidget(graphicsView_2);


        horizontalLayout_3->addWidget(frame_ch2);


        gridLayout->addWidget(frame_2_Canais, 3, 0, 1, 1);

        frame_1_Titulo = new QFrame(centralwidget);
        frame_1_Titulo->setObjectName("frame_1_Titulo");
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy8.setHorizontalStretch(11);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(frame_1_Titulo->sizePolicy().hasHeightForWidth());
        frame_1_Titulo->setSizePolicy(sizePolicy8);
        frame_1_Titulo->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 255);"));
        frame_1_Titulo->setFrameShape(QFrame::Shape::StyledPanel);
        frame_1_Titulo->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_1_Titulo);
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(frame_1_Titulo);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(124, 100));
        label_3->setTextFormat(Qt::TextFormat::AutoText);
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/UPS_logo.png")));
        label_3->setScaledContents(true);
        label_3->setMargin(0);
        label_3->setIndent(0);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(frame_1_Titulo);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy9(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy9);
        label_4->setMaximumSize(QSize(224, 100));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Images/PEB_logo.png")));
        label_4->setScaledContents(true);
        label_4->setWordWrap(false);

        horizontalLayout->addWidget(label_4);

        label_2 = new QLabel(frame_1_Titulo);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Malgun Gothic")});
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        frame_2 = new QFrame(frame_1_Titulo);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        testeCanais_pushButton = new QPushButton(frame_2);
        testeCanais_pushButton->setObjectName("testeCanais_pushButton");
        testeCanais_pushButton->setEnabled(true);
        QSizePolicy sizePolicy10(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(testeCanais_pushButton->sizePolicy().hasHeightForWidth());
        testeCanais_pushButton->setSizePolicy(sizePolicy10);
        testeCanais_pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qradialgradient(cx: 0.5, cy: 0.5, fx: 0.5, fy: 0.5, radius: 0.5, stop: 0 #FF0000, stop: 1 transparent);\n"
"    border: 2px solid #FF0000;\n"
"    border-radius: 7px;\n"
"    width: 14px;\n"
"    height: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #FF0000;  /* Define a cor de fundo como vermelho (cor do LED) */\n"
"    border: 2px solid #FF0000;  /* Define uma borda vermelha de 2 pixels */\n"
"    border-radius: 7px;         /* Ajuste o valor do raio para criar um bot\303\243o redondo */\n"
"    width: 14px;                /* Defina o tamanho do bot\303\243o (o dobro do raio) */\n"
"    height: 14px;               /* Defina o tamanho do bot\303\243o (o dobro do raio) */\n"
"\n"
"}\n"
""));
        testeCanais_pushButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(testeCanais_pushButton);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label = new QLabel(frame_2);
        label->setObjectName("label");

        verticalLayout_7->addWidget(label);

        label_16 = new QLabel(frame_2);
        label_16->setObjectName("label_16");

        verticalLayout_7->addWidget(label_16);

        label_17 = new QLabel(frame_2);
        label_17->setObjectName("label_17");

        verticalLayout_7->addWidget(label_17);


        horizontalLayout_2->addLayout(verticalLayout_7);


        horizontalLayout->addWidget(frame_2);


        gridLayout->addWidget(frame_1_Titulo, 0, 0, 1, 1);

        frame_3_Config_Estimulo = new QFrame(centralwidget);
        frame_3_Config_Estimulo->setObjectName("frame_3_Config_Estimulo");
        QSizePolicy sizePolicy11(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(1);
        sizePolicy11.setHeightForWidth(frame_3_Config_Estimulo->sizePolicy().hasHeightForWidth());
        frame_3_Config_Estimulo->setSizePolicy(sizePolicy11);
        frame_3_Config_Estimulo->setMaximumSize(QSize(16777215, 75));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        frame_3_Config_Estimulo->setFont(font3);
        frame_3_Config_Estimulo->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3_Config_Estimulo->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_3_Config_Estimulo);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(frame_3_Config_Estimulo);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        protocoloEstimulacao_comboBox = new QComboBox(frame_3_Config_Estimulo);
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->addItem(QString());
        protocoloEstimulacao_comboBox->setObjectName("protocoloEstimulacao_comboBox");

        horizontalLayout_5->addWidget(protocoloEstimulacao_comboBox);

        ciclicoCheckBox = new QCheckBox(frame_3_Config_Estimulo);
        ciclicoCheckBox->setObjectName("ciclicoCheckBox");

        horizontalLayout_5->addWidget(ciclicoCheckBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_6 = new QLabel(frame_3_Config_Estimulo);
        label_6->setObjectName("label_6");

        horizontalLayout_4->addWidget(label_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_7 = new QLabel(frame_3_Config_Estimulo);
        label_7->setObjectName("label_7");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(6);
        label_7->setFont(font4);

        verticalLayout_4->addWidget(label_7);

        timeEdit = new QTimeEdit(frame_3_Config_Estimulo);
        timeEdit->setObjectName("timeEdit");

        verticalLayout_4->addWidget(timeEdit);


        horizontalLayout_4->addLayout(verticalLayout_4);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        frame_3 = new QFrame(frame_3_Config_Estimulo);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget = new QWidget(frame_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 121, 74));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName("label_18");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_18);

        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName("label_19");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_19);

        doubleSpinBox_toff = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_toff->setObjectName("doubleSpinBox_toff");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, doubleSpinBox_toff);

        doubleSpinBox_ton = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_ton->setObjectName("doubleSpinBox_ton");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, doubleSpinBox_ton);


        horizontalLayout_5->addWidget(frame_3);

        frame_4 = new QFrame(frame_3_Config_Estimulo);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        frame_4->setLineWidth(0);
        label_20 = new QLabel(frame_4);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(2, 0, 71, 21));
        pushButton = new QPushButton(frame_4);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 20, 61, 29));
        spinBox_protocol = new QSpinBox(frame_4);
        spinBox_protocol->setObjectName("spinBox_protocol");
        spinBox_protocol->setGeometry(QRect(70, 10, 42, 26));

        horizontalLayout_5->addWidget(frame_4);

        iniciarEstimulo_pushButton = new QPushButton(frame_3_Config_Estimulo);
        iniciarEstimulo_pushButton->setObjectName("iniciarEstimulo_pushButton");
        sizePolicy5.setHeightForWidth(iniciarEstimulo_pushButton->sizePolicy().hasHeightForWidth());
        iniciarEstimulo_pushButton->setSizePolicy(sizePolicy5);
        iniciarEstimulo_pushButton->setMaximumSize(QSize(150, 80));

        horizontalLayout_5->addWidget(iniciarEstimulo_pushButton);

        pararEstimulo_pushButton = new QPushButton(frame_3_Config_Estimulo);
        pararEstimulo_pushButton->setObjectName("pararEstimulo_pushButton");

        horizontalLayout_5->addWidget(pararEstimulo_pushButton);


        gridLayout->addWidget(frame_3_Config_Estimulo, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1118, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Estimulador El\303\251trico v0.6 - LAPIS/UFRJ", nullptr));
        label_ch1_titulo->setText(QCoreApplication::translate("MainWindow", "Canal 1", nullptr));
        ch1_checkBox_ON->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Tipo de Est\303\255mulo", nullptr));
        ch1_comboBox_tipoEstimulo->setItemText(0, QCoreApplication::translate("MainWindow", "Senoidal", nullptr));
        ch1_comboBox_tipoEstimulo->setItemText(1, QCoreApplication::translate("MainWindow", "Onda Quadrada", nullptr));
        ch1_comboBox_tipoEstimulo->setItemText(2, QCoreApplication::translate("MainWindow", "Triangular", nullptr));
        ch1_comboBox_tipoEstimulo->setItemText(3, QCoreApplication::translate("MainWindow", "Dente de serra", nullptr));
        ch1_comboBox_tipoEstimulo->setItemText(4, QCoreApplication::translate("MainWindow", "Trem de pulso", nullptr));
        ch1_comboBox_tipoEstimulo->setItemText(5, QCoreApplication::translate("MainWindow", "Personalizado", nullptr));

        label_21->setText(QCoreApplication::translate("MainWindow", "Trigger(s)", nullptr));
        label_ch1_freq->setText(QCoreApplication::translate("MainWindow", "Frequ\303\252ncia (Hz)", nullptr));
        label_ch1_ampl->setText(QCoreApplication::translate("MainWindow", "Amplitude (\302\265A)", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "I1i (\302\265A)", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Ciclos", nullptr));
        label_ch1_180phase->setText(QCoreApplication::translate("MainWindow", "Deslocamento 180\302\260", nullptr));
        ch1_checkBox_180phase->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Canal 2", nullptr));
        ch2_checkBox_ON->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Tipo de Est\303\255mulo", nullptr));
        ch2_comboBox_tipoEstimulo->setItemText(0, QCoreApplication::translate("MainWindow", "Senoidal", nullptr));
        ch2_comboBox_tipoEstimulo->setItemText(1, QCoreApplication::translate("MainWindow", "Onda Quadrada", nullptr));
        ch2_comboBox_tipoEstimulo->setItemText(2, QCoreApplication::translate("MainWindow", "Triangular", nullptr));
        ch2_comboBox_tipoEstimulo->setItemText(3, QCoreApplication::translate("MainWindow", "Dente de serra", nullptr));
        ch2_comboBox_tipoEstimulo->setItemText(4, QCoreApplication::translate("MainWindow", "Trem de pulso", nullptr));
        ch2_comboBox_tipoEstimulo->setItemText(5, QCoreApplication::translate("MainWindow", "Personalizado", nullptr));

        label_22->setText(QCoreApplication::translate("MainWindow", "Trigger(s)", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Frequ\303\252ncia (Hz)", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Amplitude (\302\265A)", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "I2i(\302\265A)", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Ciclos", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Deslocamento 180\302\260", nullptr));
        checkBox_4->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", " Estimulador El\303\251trico", nullptr));
        testeCanais_pushButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "                    Version: 0.6", nullptr));
        label_16->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "                   31/10/2024", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Protocolo de estimula\303\247\303\243o", nullptr));
        protocoloEstimulacao_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Cont\303\255nuo", nullptr));
        protocoloEstimulacao_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Personalizado", nullptr));
        protocoloEstimulacao_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Limiar de sensibilidade", nullptr));
        protocoloEstimulacao_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Rampa", nullptr));
        protocoloEstimulacao_comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Limitado", nullptr));

        ciclicoCheckBox->setText(QCoreApplication::translate("MainWindow", "C\303\255clico", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Dura\303\247\303\243o do est\303\255mulo", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "    MM:SS", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "T.on(s)", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "T.off(s)", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "#Protocolo", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Enviar", nullptr));
        iniciarEstimulo_pushButton->setText(QCoreApplication::translate("MainWindow", "Iniciar", nullptr));
        pararEstimulo_pushButton->setText(QCoreApplication::translate("MainWindow", "parar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
