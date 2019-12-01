#include "Gui.h"

Gui::Gui(QWidget *parent)
    : QMainWindow(parent), proprietaire("Desroches", "Giovanni")
{
	ui.setupUi(this);
}

Gui::~Gui()
{

}

void Gui::ajouterCamion(const saaq::Camion& camion) {
}

void Gui::ajouterVehiculePromenade(
		const saaq::VehiculePromenade& vehiculePromenade) {
}

void Gui::supprimerVehicule(const saaq::Vehicule& vehicule) {
}
