#include "DialogueVehicule.h"
#include <string>
#include <iostream>
#include <QMessageBox>
#include "validationFormat.h"

using namespace std;

DialogueVehicule::DialogueVehicule(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

DialogueVehicule::~DialogueVehicule()
{

}
string DialogueVehicule::reqNiv() const {
	return ui.lineEditNiv->text().toStdString();
}

string DialogueVehicule::reqImmatriculation() const {
	return ui.lineEditImmatriculation->text().toStdString();
}


int DialogueVehicule::reqNbSieges() const{

	try{
		return stoi(ui.lineEditSiege->text().toStdString());
	}catch(invalid_argument&){
		return 0;
	}

}
void DialogueVehicule::validerVehicule()
{
	string niv = ui.lineEditNiv->text().toStdString();
	string immatriculation = ui.lineEditImmatriculation->text().toStdString();

	int  nbSieges = 0;

	try {
		nbSieges = stoi(ui.lineEditSiege->text().toStdString());
	} catch (invalid_argument&) {}

	bool valide = true;

	if(!util::validerNiv(niv)) {
		valide = false;
		QString msg("Le niv est invalide.");
		QMessageBox::information(this, "Erreur", msg);
	} else if (!util::validerImmatriculationPromenade(immatriculation)){
		valide = false;
		QString msg("L'immatriculation est invalide.");
		QMessageBox::information(this, "Erreur", msg);
	} else if (!(nbSieges > 0)) {
		valide = false;
		QString msg("Le nombre de sieges doit être supérieur à 0.");
		QMessageBox::information(this, "Erreur", msg);
	}

	if(valide){
		accept();
	}
}
