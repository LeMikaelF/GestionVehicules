#include "DialogueCamion.h"
#include <iostream>
#include <string>
#include <QMessageBox>
#include "validationFormat.h"

using namespace std;

DialogueCamion::DialogueCamion(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);
}

DialogueCamion::~DialogueCamion()
{

}

const string DialogueCamion::reqNiv() const {
	return ui.lineEditNiv->text().toStdString();
}

const string DialogueCamion::reqImmatriculation() const {
	return ui.lineEditImmatriculation->text().toStdString();
}

int DialogueCamion::reqPoids() const {
	try {
		return stoi(ui.lineEditPoids->text().toStdString());
	} catch (invalid_argument&) {
		return 0;
	}
}

int DialogueCamion::reqNbEssieux() const {
	try {
		return stoi(ui.lineEditNbEssieux->text().toStdString());
	} catch (invalid_argument&) {
		return 0;
	}
}

void DialogueCamion::validerCamion() {
	string niv = ui.lineEditNiv->text().toStdString();
	string immatriculation = ui.lineEditImmatriculation->text().toStdString();

	int poids = 0;
	try {
		poids = stoi(ui.lineEditPoids->text().toStdString());
	} catch (invalid_argument&) {}

	int nbEssieux = 0;
	try {
		nbEssieux = stoi(ui.lineEditNbEssieux->text().toStdString());
	} catch (invalid_argument&) {}

	bool valide = true;

	if(!util::validerNiv(niv)) {
		valide = false;
		QString msg("Le niv est invalide.");
		QMessageBox::information(this, "Erreur", msg);
	} else if (!util::validerImmatriculationCamion(immatriculation)){
		valide = false;
		QString msg("L'immatriculation est invalide.");
		QMessageBox::information(this, "Erreur", msg);
	} else if (!(poids > 3000)) {
		valide = false;
		QString msg("Le poids doit être supérieur à 3000 kg.");
		QMessageBox::information(this, "Erreur", msg);
	} else if (!(nbEssieux >= 2)) {
		valide = false;
		QString msg("Le nombre d'essieux doit être supérieur ou égal à 2.");
		QMessageBox::information(this, "Erreur", msg);
	}

	if(valide) {
		accept();
	}
}
