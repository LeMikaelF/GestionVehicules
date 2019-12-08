/*
 * Proprietaire_Testeur.cpp
 *
 *  Created on: 2019-11-28
 *      Author: etudiant
 */
#include <gtest/gtest.h>
#include <string>
#include "ContratException.h"
#include "Proprietaire.h"
#include "VehiculePromenade.h"
#include "VehiculeException.h"

using namespace saaq;
using namespace std;

/**
 * \brief	Test du constructeur de Proprietaire
 * 			Cas valide: création d'un objet et vérification de tous ses attributs.
 * 			Cas invalides:
 * 				- Nom vide
 * 				- Prénom vide
 */
TEST(Proprietaire, ConstructeurValide) {
	Proprietaire proprietaire("Francoeur", "Mikaël");
	ASSERT_EQ(proprietaire.reqNom(), "Francoeur");
	ASSERT_EQ(proprietaire.reqPrenom(), "Mikaël");
}

//Cas invalides
TEST(Proprietaire, NomInvalide) {
	ASSERT_THROW(Proprietaire proprietaire("", "Mikaël"), PreconditionException);
}

TEST(Proprietaire, PrenomInvalide) {
	ASSERT_THROW(Proprietaire proprietaire("Francoeur", ""), PreconditionException);
}

/**
 * \brief 	Test de la méthode ajouterVehicule(const Vehicule& p_vehicule)
 * 			Cas valide: Vérifier que le véhicule apparaît
 * 						dans la chaîne de caractères retournée par reqProprietaireFormate()
 * 			Cas invalide: Véhicule déjà présent
 */
TEST(Proprietaire, AjouterVehiculeValide) {
	Proprietaire proprietaire("Francoeur", "Mikaël");
	VehiculePromenade vehiculePromenade("JHMFA16586S014014", "000 ABC", 3);
	proprietaire.ajouterVehicule(vehiculePromenade);
	ASSERT_PRED_FORMAT2(testing::IsSubstring, vehiculePromenade.reqVehiculeFormate(), proprietaire.reqProprietaireFormate());
}

//Cas invalide
TEST(Proprietaire, AjouterVehiculeVehiculeDejaPresent) {
	Proprietaire proprietaire("Francoeur", "Mikaël");
	VehiculePromenade vehiculePromenade("JHMFA16586S014014", "000 ABC", 3);
	proprietaire.ajouterVehicule(vehiculePromenade);
	ASSERT_THROW(proprietaire.ajouterVehicule(vehiculePromenade), VehiculeDejaPresentException);
}

/**
 * \brief	Test de la méthode supprimerVehicule()
 * 			Cas valide: supprimer un véhicule présent
 * 			Cas invalide: supprimer un véhicule absent
 */
TEST(Proprietaire, SupprimerVehiculeValide) {
	Proprietaire proprietaire("Francoeur", "Mikaël");
	VehiculePromenade vehiculePromenade("JHMFA16586S014014", "000 ABC", 3);
	proprietaire.ajouterVehicule(vehiculePromenade);
	proprietaire.supprimerVehicule("JHMFA16586S014014");
	ASSERT_PRED_FORMAT2(testing::IsNotSubstring, vehiculePromenade.reqVehiculeFormate(), proprietaire.reqProprietaireFormate());
}

//Cas invalide
TEST(Proprietaire, SupprimerVehiculeAbsent) {
	Proprietaire proprietaire("Francoeur", "Mikaël");
	ASSERT_THROW(proprietaire.supprimerVehicule("JHMFA16586S014014"), VehiculeAbsentException);
}

/**
 * \brief	Test de la méthode reqProprietaireFormate()
 * 			Vérifier que la chaîne de caractères est correctement formatée.
 * 			Cas valides:
 * 				- Aucun véhicule
 * 				- Deux véhicules
 */
TEST(Proprietaire, ReqProprietaireFormateAucunVehicule) {
	Proprietaire proprietaire("Francoeur", "Mikaël");

	ostringstream os;
	os 	<< "Proprietaire" << endl
			<< "-------------------" << endl
			<< "Nom     : Francoeur" << endl
			<< "Prenom  : Mikaël" << endl;
	ASSERT_EQ(proprietaire.reqProprietaireFormate(), os.str());
}

TEST(Proprietaire, ReqProprietaireFormateDeuxVehicules) {
	Proprietaire proprietaire("Francoeur", "Mikaël");
	VehiculePromenade vehicule1("JHMFA16586S014014", "000 ABC", 3);
	VehiculePromenade vehicule2("WP1AC29P65LA91996", "SAAQ", 5);
	proprietaire.ajouterVehicule(vehicule1);
	proprietaire.ajouterVehicule(vehicule2);

	ostringstream os;
	os 	<< "Proprietaire" << endl
			<< "-------------------" << endl
			<< "Nom     : Francoeur" << endl
			<< "Prenom  : Mikaël" << endl
			<< "-------------------" << endl
			<< vehicule1.reqVehiculeFormate()
			<< "-------------------" << endl
			<< vehicule2.reqVehiculeFormate();
	ASSERT_EQ(proprietaire.reqProprietaireFormate(), os.str());}

/**
 * \brief 	Test de la méthode vehiculeDejaPresent()
 * 			Cas valides:
 * 				- Véhicule déjà présent, retourne true
 * 				- Véhicule pas déjà présent, retourne false
 */
TEST(Proprietaire, EstDejaPresentVrai) {
	Proprietaire proprietaire("Francoeur", "Mikaël");
	VehiculePromenade vehicule("JHMFA16586S014014", "000 ABC", 3);
proprietaire.ajouterVehicule(vehicule);
	ASSERT_TRUE(proprietaire.vehiculeEstDejaPresent("JHMFA16586S014014"));
}

TEST(Proprietaire, EstDejaPresentFaux) {
	Proprietaire proprietaire("Francoeur", "Mikaël");
	VehiculePromenade vehicule("JHMFA16586S014014", "000 ABC", 3);
	proprietaire.ajouterVehicule(vehicule);
	ASSERT_FALSE(proprietaire.vehiculeEstDejaPresent("SAAQ"));
}

/**
 * \brief Création d'une fixture de test pour les méthodes publiques de la classe Proprietaire.
 */
class UnProprietaire : public ::testing::Test {
public:
	UnProprietaire() : proprietaire("Francoeur", "Mikaël") {};
	Proprietaire proprietaire;
};

/**
 * \brief	Test de la méthode reqNom()
 * 			Cas valide: vérifier le retour du nom du propriétaire
 * 			Cas invalide: aucun
 */
TEST_F(UnProprietaire, ReqNom) {
	ASSERT_EQ(proprietaire.reqNom(), "Francoeur");
}

/**
 * \brief	Test de la méthode reqPrenom()
 * 			Cas valide: vérifier le retour du prénom du propriétaire
 * 			Cas invalide: aucun
 */
TEST_F(UnProprietaire, ReqPrenom) {
	ASSERT_EQ(proprietaire.reqPrenom(), "Mikaël");
}
