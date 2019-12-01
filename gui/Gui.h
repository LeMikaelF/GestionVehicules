#ifndef GUI_H
#define GUI_H

#include <QtGui/QMainWindow>
#include "ui_Gui.h"
#include "Proprietaire.h"
#include "Vehicule.h"
#include "VehiculePromenade.h"
#include "Camion.h"

class Gui : public QMainWindow
{
    Q_OBJECT

public:
    Gui(QWidget *parent = 0);
    ~Gui();

private:
    Ui::GuiClass ui;
    saaq::Proprietaire proprietaire;

private slots:
	void ajouterCamion(const saaq::Camion& camion);
	void ajouterVehiculePromenade(const saaq::VehiculePromenade& vehiculePromenade);
	void supprimerVehicule(const saaq::Vehicule& vehicule);
};

#endif // GUI_H