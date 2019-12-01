/********************************************************************************
** Form generated from reading UI file 'DialogueSupprimer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUESUPPRIMER_H
#define UI_DIALOGUESUPPRIMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogueSupprimerClass
{
public:

    void setupUi(QDialog *DialogueSupprimerClass)
    {
        if (DialogueSupprimerClass->objectName().isEmpty())
            DialogueSupprimerClass->setObjectName(QString::fromUtf8("DialogueSupprimerClass"));
        DialogueSupprimerClass->resize(400, 300);

        retranslateUi(DialogueSupprimerClass);

        QMetaObject::connectSlotsByName(DialogueSupprimerClass);
    } // setupUi

    void retranslateUi(QDialog *DialogueSupprimerClass)
    {
        DialogueSupprimerClass->setWindowTitle(QApplication::translate("DialogueSupprimerClass", "DialogueSupprimer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogueSupprimerClass: public Ui_DialogueSupprimerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUESUPPRIMER_H
