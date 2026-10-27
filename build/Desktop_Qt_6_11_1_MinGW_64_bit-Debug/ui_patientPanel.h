/********************************************************************************
** Form generated from reading UI file 'patientPanel.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTPANEL_H
#define UI_PATIENTPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientPanel
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *okpushButton;
    QPushButton *closeButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *identifierLineEdit;
    QLabel *label_3;
    QDateEdit *birthDateEdit;
    QLabel *label_5;
    QComboBox *genderComboBox;
    QLabel *label_4;
    QLineEdit *examinerLineEdit;
    QLabel *label_6;
    QPlainTextEdit *observationsPlainTextEdit;

    void setupUi(QDialog *PatientPanel)
    {
        if (PatientPanel->objectName().isEmpty())
            PatientPanel->setObjectName("PatientPanel");
        PatientPanel->resize(626, 769);
        layoutWidget = new QWidget(PatientPanel);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(350, 600, 231, 91));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        okpushButton = new QPushButton(layoutWidget);
        okpushButton->setObjectName("okpushButton");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font.setPointSize(12);
        okpushButton->setFont(font);

        horizontalLayout->addWidget(okpushButton);

        closeButton = new QPushButton(layoutWidget);
        closeButton->setObjectName("closeButton");
        closeButton->setFont(font);

        horizontalLayout->addWidget(closeButton);

        layoutWidget1 = new QWidget(PatientPanel);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(60, 41, 411, 511));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font1.setPointSize(14);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(layoutWidget1);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setFont(font);

        verticalLayout->addWidget(nameLineEdit);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        identifierLineEdit = new QLineEdit(layoutWidget1);
        identifierLineEdit->setObjectName("identifierLineEdit");
        identifierLineEdit->setFont(font);

        verticalLayout->addWidget(identifierLineEdit);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        birthDateEdit = new QDateEdit(layoutWidget1);
        birthDateEdit->setObjectName("birthDateEdit");
        birthDateEdit->setFont(font);

        verticalLayout->addWidget(birthDateEdit);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        genderComboBox = new QComboBox(layoutWidget1);
        genderComboBox->addItem(QString());
        genderComboBox->addItem(QString());
        genderComboBox->setObjectName("genderComboBox");
        genderComboBox->setFont(font);

        verticalLayout->addWidget(genderComboBox);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        examinerLineEdit = new QLineEdit(layoutWidget1);
        examinerLineEdit->setObjectName("examinerLineEdit");
        examinerLineEdit->setFont(font);

        verticalLayout->addWidget(examinerLineEdit);


        verticalLayout_2->addLayout(verticalLayout);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);

        verticalLayout_2->addWidget(label_6);

        observationsPlainTextEdit = new QPlainTextEdit(layoutWidget1);
        observationsPlainTextEdit->setObjectName("observationsPlainTextEdit");
        observationsPlainTextEdit->setFont(font);

        verticalLayout_2->addWidget(observationsPlainTextEdit);


        retranslateUi(PatientPanel);

        QMetaObject::connectSlotsByName(PatientPanel);
    } // setupUi

    void retranslateUi(QDialog *PatientPanel)
    {
        PatientPanel->setWindowTitle(QCoreApplication::translate("PatientPanel", "Registro do paciente", nullptr));
        okpushButton->setText(QCoreApplication::translate("PatientPanel", "Salvar", nullptr));
        closeButton->setText(QCoreApplication::translate("PatientPanel", "Close", nullptr));
        label->setText(QCoreApplication::translate("PatientPanel", "Nome:", nullptr));
        label_2->setText(QCoreApplication::translate("PatientPanel", "CPF:", nullptr));
        label_3->setText(QCoreApplication::translate("PatientPanel", "Data de nacimento:", nullptr));
        label_5->setText(QCoreApplication::translate("PatientPanel", "Sexo:", nullptr));
        genderComboBox->setItemText(0, QCoreApplication::translate("PatientPanel", "Feminino", nullptr));
        genderComboBox->setItemText(1, QCoreApplication::translate("PatientPanel", "Maculino", nullptr));

        label_4->setText(QCoreApplication::translate("PatientPanel", "Examinador:", nullptr));
        label_6->setText(QCoreApplication::translate("PatientPanel", "Observa\303\247\303\265es:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientPanel: public Ui_PatientPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTPANEL_H
