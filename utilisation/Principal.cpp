/*
 * Principal.cpp
 *
 *  Created on: 2019-11-28
 *      Author: etudiant
 */

#include <iostream>
#include "validationFormat.h"
#include "Vehicule.h"
#include "Camion.h"
#include "VehiculePromenade.h"
#include "Proprietaire.h"

using namespace std;

enum VehiculeType {
	VehiculePromenade,
	Camion
};

string demandeNivAvecValidation();
string demandeImmatriculationAvecValidation(VehiculeType type);
int demandeNbPlacesAvecValidation();
saaq::Vehicule* demandeAjouterVehicule(VehiculeType type);
int demandePoidsAvecValidation();
int demandeNbEssieuxAvecValidation();

int main() {
	cout 	<< "*******************************************************" << endl << endl
			<< "Bienvenue a l'outil d'ajout de gestion de vehicules" << endl << endl
			<< "*******************************************************" << endl << endl;
	saaq::Vehicule* vehicule1 = demandeAjouterVehicule(VehiculePromenade);
	saaq::Vehicule* vehicule2 = demandeAjouterVehicule(Camion);
	saaq::Proprietaire proprietaire("Tremblay", "Louis");
	proprietaire.ajouterVehicule(*vehicule1);
	proprietaire.ajouterVehicule(*vehicule2);
	delete vehicule1;
	delete vehicule2;
	cout << endl << proprietaire.reqProprietaireFormate();
}

saaq::Vehicule* demandeAjouterVehicule(VehiculeType type) {
	string nomType = type == VehiculePromenade ? "vehicule de promenade" : "camion";

	cout	<< "-------------------------------------------------------" << endl
			<< "Ajoutez un " << nomType << endl
			<< "-------------------------------------------------------" << endl << endl;
	string niv = demandeNivAvecValidation();
	string immatriculation = demandeImmatriculationAvecValidation(type);
	saaq::Vehicule* vehicule;
	switch (type) {
	case(VehiculePromenade) : {
		int nbPlaces = demandeNbPlacesAvecValidation();
		vehicule = new saaq::VehiculePromenade(niv, immatriculation, nbPlaces);
		break;
	}
	case(Camion) : {
		int poids = demandePoidsAvecValidation();
		int nbEssieux = demandeNbEssieuxAvecValidation();
		vehicule = new saaq::Camion(niv, immatriculation, poids, nbEssieux);
		break;
	}
	default :
		return nullptr;
		break;
	}
	return vehicule;
}

int demandePoidsAvecValidation() {
	int poids = 0;
	bool valide = false;
	do {
		cout << "Entrez le poids du camion > 3000 kg" << endl;
		cin >> poids;
		valide = poids > 3000;
		if(!valide) {
			cout << "Nombre de places invalides." << endl;
			poids = 0;
			}
		cin.clear();
		cin.ignore(10000, '\n');
	} while (!valide);
	return poids;
}

int demandeNbEssieuxAvecValidation() {
	int nbEssieux = 0;
	bool valide = false;
	do {
		cout << "Entrez le nombre d'essieux >= 2" << endl;
		cin >> nbEssieux;
		valide = nbEssieux >= 2;
		if(!valide) {
				cout << "Nombre d'essieux invalides." << endl;
				nbEssieux = 0;
			}
		cin.clear();
		cin.ignore(10000, '\n');
	} while (!valide);
	return nbEssieux;
}

int demandeNbPlacesAvecValidation() {
	int nbPlaces = 0;
	bool valide = false;
	do {
		cout << "Entrez le nombre de places > 0 : " << endl;
		cin >> nbPlaces;
		valide = nbPlaces > 0;
		if(!valide) {
			cout << "Nombre de places invalides." << endl;
			nbPlaces = 0;
		}
		cin.clear();
		cin.ignore(10000, '\n');
	} while (!valide);
	return nbPlaces;
}

string demandeImmatriculationAvecValidation(VehiculeType type)
{
	string immatriculation;
	bool valide = false;
	do
	{
		cout << "Entrez le numéro d'immatriculation du véhicule : ";
		getline(cin, immatriculation);

		switch (type) {
		case VehiculePromenade:
			valide = util::validerImmatriculationPromenade(immatriculation);
			break;
		case Camion:
			valide = util::validerImmatriculationCamion(immatriculation);
			break;
		default:
			break;
		}

		if (!valide)
		{
			cout << "Immatriculation invalide." << endl;
		}
	}
	while (!valide);
	return immatriculation;
}

string demandeNivAvecValidation()
{
	string niv;
	bool valide = false;
	do
	{
		cout << "Entrez le numero de serie : ";
		getline(cin, niv);
		valide = util::validerNiv(niv);
		if (!valide)
		{
			cout << "Niv invalide." << endl;
		}
	}
	while (!valide);
	return niv;
}
