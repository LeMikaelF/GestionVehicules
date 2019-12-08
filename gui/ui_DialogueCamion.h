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
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogueCamionClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *numRoDeSRieLabel;
    QLineEdit *lineEditNiv;
    QLabel *labelImmatriculation;
    QLineEdit *lineEditImmatriculation;
    QLabel *labelPoids;
    QLineEdit *lineEditPoids;
    QLabel *labelNbEssieux;
    QLineEdit *lineEditNbEssieux;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonAjouter;
    QPushButton *buttonAnnuler;

    void setupUi(QDialog *DialogueCamionClass)
    {
        if (DialogueCamionClass->objectName().isEmpty())
            DialogueCamionClass->setObjectName(QString::fromUtf8("DialogueCamionClass"));
        DialogueCamionClass->setWindowModality(Qt::ApplicationModal);
        DialogueCamionClass->resize(372, 249);
        DialogueCamionClass->setModal(true);
        verticalLayout_3 = new QVBoxLayout(DialogueCamionClass);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        numRoDeSRieLabel = new QLabel(DialogueCamionClass);
        numRoDeSRieLabel->setObjectName(QString::fromUtf8("numRoDeSRieLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, numRoDeSRieLabel);

        lineEditNiv = new QLineEdit(DialogueCamionClass);
        lineEditNiv->setObjectName(QString::fromUtf8("lineEditNiv"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditNiv);

        labelImmatriculation = new QLabel(DialogueCamionClass);
        labelImmatriculation->setObjectName(QString::fromUtf8("labelImmatriculation"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelImmatriculation);

        lineEditImmatriculation = new QLineEdit(DialogueCamionClass);
        lineEditImmatriculation->setObjectName(QString::fromUtf8("lineEditImmatriculation"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditImmatriculation);

        labelPoids = new QLabel(DialogueCamionClass);
        labelPoids->setObjectName(QString::fromUtf8("labelPoids"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelPoids);

        lineEditPoids = new QLineEdit(DialogueCamionClass);
        lineEditPoids->setObjectName(QString::fromUtf8("lineEditPoids"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditPoids);

        labelNbEssieux = new QLabel(DialogueCamionClass);
        labelNbEssieux->setObjectName(QString::fromUtf8("labelNbEssieux"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelNbEssieux);

        lineEditNbEssieux = new QLineEdit(DialogueCamionClass);
        lineEditNbEssieux->setObjectName(QString::fromUtf8("lineEditNbEssieux"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditNbEssieux);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonAjouter = new QPushButton(DialogueCamionClass);
        buttonAjouter->setObjectName(QString::fromUtf8("buttonAjouter"));

        horizontalLayout->addWidget(buttonAjouter);

        buttonAnnuler = new QPushButton(DialogueCamionClass);
        buttonAnnuler->setObjectName(QString::fromUtf8("buttonAnnuler"));

        horizontalLayout->addWidget(buttonAnnuler);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(DialogueCamionClass);
        QObject::connect(buttonAjouter, SIGNAL(clicked()), DialogueCamionClass, SLOT(validerCamion()));
        QObject::connect(buttonAnnuler, SIGNAL(clicked()), DialogueCamionClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogueCamionClass);
    } // setupUi

    void retranslateUi(QDialog *DialogueCamionClass)
    {
        DialogueCamionClass->setWindowTitle(QApplication::translate("DialogueCamionClass", "Ajout d'un camion", 0, QApplication::UnicodeUTF8));
        numRoDeSRieLabel->setText(QApplication::translate("DialogueCamionClass", "Num\303\251ro de s\303\251rie", 0, QApplication::UnicodeUTF8));
        labelImmatriculation->setText(QApplication::translate("DialogueCamionClass", "Immatriculation", 0, QApplication::UnicodeUTF8));
        labelPoids->setText(QApplication::translate("DialogueCamionClass", "Poids (kg)", 0, QApplication::UnicodeUTF8));
        labelNbEssieux->setText(QApplication::translate("DialogueCamionClass", "Nombre d'essieux", 0, QApplication::UnicodeUTF8));
        buttonAjouter->setText(QApplication::translate("DialogueCamionClass", "Ajouter", 0, QApplication::UnicodeUTF8));
        buttonAnnuler->setText(QApplication::translate("DialogueCamionClass", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogueCamionClass: public Ui_DialogueCamionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUECAMION_H
