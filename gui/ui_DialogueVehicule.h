/********************************************************************************
** Form generated from reading UI file 'DialogueVehicule.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUEVEHICULE_H
#define UI_DIALOGUEVEHICULE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogueVehiculeClass
{
public:

    void setupUi(QDialog *DialogueVehiculeClass)
    {
        if (DialogueVehiculeClass->objectName().isEmpty())
            DialogueVehiculeClass->setObjectName(QString::fromUtf8("DialogueVehiculeClass"));
        DialogueVehiculeClass->resize(400, 300);

        retranslateUi(DialogueVehiculeClass);

        QMetaObject::connectSlotsByName(DialogueVehiculeClass);
    } // setupUi

    void retranslateUi(QDialog *DialogueVehiculeClass)
    {
        DialogueVehiculeClass->setWindowTitle(QApplication::translate("DialogueVehiculeClass", "DialogueVehicule", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogueVehiculeClass: public Ui_DialogueVehiculeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUEVEHICULE_H
