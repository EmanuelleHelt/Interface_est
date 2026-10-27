/********************************************************************************
** Form generated from reading UI file 'sidebar.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEBAR_H
#define UI_SIDEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logoLabel
{
public:

    void setupUi(QWidget *logoLabel)
    {
        if (logoLabel->objectName().isEmpty())
            logoLabel->setObjectName("logoLabel");
        logoLabel->resize(400, 300);

        retranslateUi(logoLabel);

        QMetaObject::connectSlotsByName(logoLabel);
    } // setupUi

    void retranslateUi(QWidget *logoLabel)
    {
        logoLabel->setWindowTitle(QCoreApplication::translate("logoLabel", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class logoLabel: public Ui_logoLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEBAR_H
