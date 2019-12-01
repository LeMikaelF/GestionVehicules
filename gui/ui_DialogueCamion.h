/********************************************************************************
** Form generated from reading UI file 'DialogueCamion.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUECAMION_H
#define UI_DIALOGUECAMION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogueCamionClass
{
public:

    void setupUi(QDialog *DialogueCamionClass)
    {
        if (DialogueCamionClass->objectName().isEmpty())
            DialogueCamionClass->setObjectName(QString::fromUtf8("DialogueCamionClass"));
        DialogueCamionClass->resize(400, 300);

        retranslateUi(DialogueCamionClass);

        QMetaObject::connectSlotsByName(DialogueCamionClass);
    } // setupUi

    void retranslateUi(QDialog *DialogueCamionClass)
    {
        DialogueCamionClass->setWindowTitle(QApplication::translate("DialogueCamionClass", "DialogueCamion", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogueCamionClass: public Ui_DialogueCamionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUECAMION_H
