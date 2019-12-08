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
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogueVehiculeClass
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *labelImmatriculation;
    QLabel *labelNiv;
    QLineEdit *lineEditNiv;
    QLineEdit *lineEditImmatriculation;
    QLabel *labelNbSiege;
    QLineEdit *lineEditSiege;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonAjouter;
    QPushButton *buttonAnnuler;

    void setupUi(QDialog *DialogueVehiculeClass)
    {
        if (DialogueVehiculeClass->objectName().isEmpty())
            DialogueVehiculeClass->setObjectName(QString::fromUtf8("DialogueVehiculeClass"));
        DialogueVehiculeClass->resize(367, 232);
        DialogueVehiculeClass->setLayoutDirection(Qt::LeftToRight);
        DialogueVehiculeClass->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(DialogueVehiculeClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        labelImmatriculation = new QLabel(DialogueVehiculeClass);
        labelImmatriculation->setObjectName(QString::fromUtf8("labelImmatriculation"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelImmatriculation);

        labelNiv = new QLabel(DialogueVehiculeClass);
        labelNiv->setObjectName(QString::fromUtf8("labelNiv"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelNiv);

        lineEditNiv = new QLineEdit(DialogueVehiculeClass);
        lineEditNiv->setObjectName(QString::fromUtf8("lineEditNiv"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditNiv);

        lineEditImmatriculation = new QLineEdit(DialogueVehiculeClass);
        lineEditImmatriculation->setObjectName(QString::fromUtf8("lineEditImmatriculation"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEditImmatriculation);

        labelNbSiege = new QLabel(DialogueVehiculeClass);
        labelNbSiege->setObjectName(QString::fromUtf8("labelNbSiege"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelNbSiege);

        lineEditSiege = new QLineEdit(DialogueVehiculeClass);
        lineEditSiege->setObjectName(QString::fromUtf8("lineEditSiege"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEditSiege);


        verticalLayout_2->addLayout(formLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonAjouter = new QPushButton(DialogueVehiculeClass);
        buttonAjouter->setObjectName(QString::fromUtf8("buttonAjouter"));

        horizontalLayout->addWidget(buttonAjouter);

        buttonAnnuler = new QPushButton(DialogueVehiculeClass);
        buttonAnnuler->setObjectName(QString::fromUtf8("buttonAnnuler"));

        horizontalLayout->addWidget(buttonAnnuler);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(DialogueVehiculeClass);
        QObject::connect(buttonAjouter, SIGNAL(clicked()), DialogueVehiculeClass, SLOT(validerVehicule()));
        QObject::connect(buttonAnnuler, SIGNAL(clicked()), DialogueVehiculeClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogueVehiculeClass);
    } // setupUi

    void retranslateUi(QDialog *DialogueVehiculeClass)
    {
        DialogueVehiculeClass->setWindowTitle(QApplication::translate("DialogueVehiculeClass", "DialogueVehicule", 0, QApplication::UnicodeUTF8));
        labelImmatriculation->setText(QApplication::translate("DialogueVehiculeClass", "Immatriculation", 0, QApplication::UnicodeUTF8));
        labelNiv->setText(QApplication::translate("DialogueVehiculeClass", "Num\303\251ro de s\303\251rie", 0, QApplication::UnicodeUTF8));
        labelNbSiege->setText(QApplication::translate("DialogueVehiculeClass", "Nombre de sieges", 0, QApplication::UnicodeUTF8));
        buttonAjouter->setText(QApplication::translate("DialogueVehiculeClass", "Ajouter", 0, QApplication::UnicodeUTF8));
        buttonAnnuler->setText(QApplication::translate("DialogueVehiculeClass", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogueVehiculeClass: public Ui_DialogueVehiculeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUEVEHICULE_H
