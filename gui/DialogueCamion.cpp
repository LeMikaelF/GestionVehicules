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
	return stoi(ui.lineEditPoids->text().toStdString());
}

int DialogueCamion::reqNbEssieux() const {
	return stoi(ui.lineEditNbEssieux->text().toStdString());
}

void DialogueCamion::validerCamion() {
	//TODO stub
	string niv = ui.lineEditNiv->text().toStdString();
	string immatriculation = ui.lineEditImmatriculation->text().toStdString();
	int poids = stoi(ui.lineEditPoids->text().toStdString());
	int nbEssieux = stoi(ui.lineEditNbEssieux->text().toStdString());

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
	} else {
		reject();
	}
}
