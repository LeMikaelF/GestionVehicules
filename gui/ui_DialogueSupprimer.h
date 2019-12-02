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
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogueSupprimerClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelNiv;
    QLineEdit *lineEditNiv;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonSupprimer;
    QPushButton *buttonAnnuler;

    void setupUi(QDialog *DialogueSupprimerClass)
    {
        if (DialogueSupprimerClass->objectName().isEmpty())
            DialogueSupprimerClass->setObjectName(QString::fromUtf8("DialogueSupprimerClass"));
        DialogueSupprimerClass->resize(228, 85);
        verticalLayout_2 = new QVBoxLayout(DialogueSupprimerClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelNiv = new QLabel(DialogueSupprimerClass);
        labelNiv->setObjectName(QString::fromUtf8("labelNiv"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNiv);

        lineEditNiv = new QLineEdit(DialogueSupprimerClass);
        lineEditNiv->setObjectName(QString::fromUtf8("lineEditNiv"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditNiv);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonSupprimer = new QPushButton(DialogueSupprimerClass);
        buttonSupprimer->setObjectName(QString::fromUtf8("buttonSupprimer"));

        horizontalLayout->addWidget(buttonSupprimer);

        buttonAnnuler = new QPushButton(DialogueSupprimerClass);
        buttonAnnuler->setObjectName(QString::fromUtf8("buttonAnnuler"));

        horizontalLayout->addWidget(buttonAnnuler);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DialogueSupprimerClass);
        QObject::connect(buttonSupprimer, SIGNAL(clicked()), DialogueSupprimerClass, SLOT(validerNiv()));
        QObject::connect(buttonAnnuler, SIGNAL(clicked()), DialogueSupprimerClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogueSupprimerClass);
    } // setupUi

    void retranslateUi(QDialog *DialogueSupprimerClass)
    {
        DialogueSupprimerClass->setWindowTitle(QApplication::translate("DialogueSupprimerClass", "Supprimer un v\303\251hicule", 0, QApplication::UnicodeUTF8));
        labelNiv->setText(QApplication::translate("DialogueSupprimerClass", "Niv \303\240 supprimer", 0, QApplication::UnicodeUTF8));
        buttonSupprimer->setText(QApplication::translate("DialogueSupprimerClass", "Supprimer", 0, QApplication::UnicodeUTF8));
        buttonAnnuler->setText(QApplication::translate("DialogueSupprimerClass", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogueSupprimerClass: public Ui_DialogueSupprimerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUESUPPRIMER_H
