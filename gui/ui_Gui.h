/********************************************************************************
** Form generated from reading UI file 'Gui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiClass
{
public:
    QAction *actionSupprimerVehicule;
    QAction *actionQuitter;
    QAction *actionAjouterCamion;
    QAction *actionAjouterVehiculePromenade;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEditProprietaire;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *actionAjouterVehicule;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GuiClass)
    {
        if (GuiClass->objectName().isEmpty())
            GuiClass->setObjectName(QString::fromUtf8("GuiClass"));
        GuiClass->resize(800, 600);
        actionSupprimerVehicule = new QAction(GuiClass);
        actionSupprimerVehicule->setObjectName(QString::fromUtf8("actionSupprimerVehicule"));
        actionQuitter = new QAction(GuiClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAjouterCamion = new QAction(GuiClass);
        actionAjouterCamion->setObjectName(QString::fromUtf8("actionAjouterCamion"));
        actionAjouterVehiculePromenade = new QAction(GuiClass);
        actionAjouterVehiculePromenade->setObjectName(QString::fromUtf8("actionAjouterVehiculePromenade"));
        centralwidget = new QWidget(GuiClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plainTextEditProprietaire = new QPlainTextEdit(centralwidget);
        plainTextEditProprietaire->setObjectName(QString::fromUtf8("plainTextEditProprietaire"));
        plainTextEditProprietaire->setReadOnly(true);

        gridLayout->addWidget(plainTextEditProprietaire, 0, 0, 1, 1);

        GuiClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GuiClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 35));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        actionAjouterVehicule = new QMenu(menuMenu);
        actionAjouterVehicule->setObjectName(QString::fromUtf8("actionAjouterVehicule"));
        GuiClass->setMenuBar(menubar);
        statusbar = new QStatusBar(GuiClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GuiClass->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionAjouterVehicule->menuAction());
        menuMenu->addAction(actionSupprimerVehicule);
        menuMenu->addAction(actionQuitter);
        actionAjouterVehicule->addAction(actionAjouterCamion);
        actionAjouterVehicule->addAction(actionAjouterVehiculePromenade);

        retranslateUi(GuiClass);
        QObject::connect(actionAjouterCamion, SIGNAL(triggered()), GuiClass, SLOT(ajouterCamion()));
        QObject::connect(actionSupprimerVehicule, SIGNAL(triggered()), GuiClass, SLOT(supprimerVehicule()));
        QObject::connect(actionQuitter, SIGNAL(triggered()), GuiClass, SLOT(close()));
        QObject::connect(actionAjouterVehiculePromenade, SIGNAL(triggered()), GuiClass, SLOT(ajouterVehiculePromenade()));

        QMetaObject::connectSlotsByName(GuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *GuiClass)
    {
        GuiClass->setWindowTitle(QApplication::translate("GuiClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSupprimerVehicule->setText(QApplication::translate("GuiClass", "Supprimer v\303\251hicule", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("GuiClass", "Quitter", 0, QApplication::UnicodeUTF8));
        actionAjouterCamion->setText(QApplication::translate("GuiClass", "Camion", 0, QApplication::UnicodeUTF8));
        actionAjouterVehiculePromenade->setText(QApplication::translate("GuiClass", "V\303\251hicule de promenade", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("GuiClass", "Menu", 0, QApplication::UnicodeUTF8));
        actionAjouterVehicule->setTitle(QApplication::translate("GuiClass", "Ajouter v\303\251hicule", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
