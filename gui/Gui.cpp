#include <QMessageBox>
#include "Gui.h"
#include "VehiculeException.h"
#include "Camion.h"
#include "DialogueCamion.h"
#include "DialogueSupprimer.h"
#include "DialogueVehicule.h"
#include "VehiculePromenade.h"

using namespace std;

Gui::Gui(QWidget *parent)
    : QMainWindow(parent), proprietaire("Desroches", "Giovanni")
{
	ui.setupUi(this);
	//FIXME changer ceci pour un richText, mes espaces insécables ne s'affichent pas correctement.
	ui.plainTextEditProprietaire->setPlainText(
			QString::fromStdString(proprietaire.reqProprietaireFormate()));
}

Gui::~Gui()
{

}

void Gui::ajouterCamion() {
	DialogueCamion dialogueCamion(this);
	if(dialogueCamion.exec()) {
		try{
			proprietaire.ajouterVehicule(saaq::Camion(
					dialogueCamion.reqNiv(),
					dialogueCamion.reqImmatriculation(),
					dialogueCamion.reqPoids(),
					dialogueCamion.reqNbEssieux()
					));
			ui.plainTextEditProprietaire->setPlainText(
					QString::fromStdString(proprietaire.reqProprietaireFormate()));
		} catch (VehiculeDejaPresentException& exception){
			QString message(exception.what());
			QMessageBox::information(this, "Erreur", message);
		}
	}
}

void Gui::ajouterVehiculePromenade() {
	DialogueVehicule dialogueVehicule(this);
	if(dialogueVehicule.exec()) {
		try{
			proprietaire.ajouterVehicule(saaq::VehiculePromenade(
					dialogueVehicule.reqNiv(),
					dialogueVehicule.reqImmatriculation(),
					dialogueVehicule.reqNbSieges()
					));
			ui.plainTextEditProprietaire->setPlainText(
					QString::fromStdString(proprietaire.reqProprietaireFormate()));
		} catch (VehiculeDejaPresentException& exception){
			QString message(exception.what());
			QMessageBox::information(this, "Erreur", message);
		}
	}
}

void Gui::supprimerVehicule() {
	DialogueSupprimer dialogueSupprimer(this);
	if(dialogueSupprimer.exec()) {
		try {
			const string niv = dialogueSupprimer.reqNiv();
			proprietaire.supprimerVehicule(niv);
			ui.plainTextEditProprietaire->setPlainText(
					QString::fromStdString(proprietaire.reqProprietaireFormate()));
		} catch (VehiculeAbsentException& exception) {
			QString message(exception.what());
			QMessageBox::information(this, "Erreur", message);
		}
	}
}
