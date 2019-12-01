//
// Created by mikael on 2019-11-26.
//
#include "Camion.h"
#include <gtest/gtest.h>
#include <string>
#include "Vehicule.h"
#include "ContratException.h"
#include "Date.h"

using namespace std;
using namespace saaq;

/**
 * \brief 	Création d'une classe dérivée de la classe Vehicule à des fins de test.
 * 			Les méthodes purement virtuelles sont des no-op.
 */
class VehiculeTest : public Vehicule {
public:
	VehiculeTest(const string& p_niv, const string& p_immatriculation) :
		Vehicule(p_niv, p_immatriculation) {}
	void asgImmatriculation(const string& p_immatriculation) override {
		Vehicule::asgImmatriculation(p_immatriculation);
	}
	Vehicule* clone() const {
		return nullptr;
	}
	const double tarificationAnnuelle() const {
		return 0;
	}
	const bool validerImmatriculation(const std::string& p_immatriculation) const {
		return true;
	}
};

/**
 * \brief	Création d'une fixture de test pour les méthodes publiques de la classe VehiculeTest.
 */
class UnVehicule : public ::testing::Test {
public:
	UnVehicule() : vehiculeTest("5LMJJ2J57CEL03980", "SAAQ") {};
	VehiculeTest vehiculeTest;
};

/**
 * \brief	Test du constructeur de VehiculeTest. Le constructeur délègue la construction de l'objet
 * 				au constructeur de la classe Vehicule.
 * 			Cas valide: Création de l'objet et vérification de l'assignation de tous les attributs de Vehicule.
 * 			Cas invalide: niv invalide
 */
TEST(Vehicule, ParametresValides) {
	VehiculeTest vehiculeTest("5LMJJ2J57CEL03980", "SAAQ");
	ASSERT_EQ(vehiculeTest.reqNiv(), "5LMJJ2J57CEL03980");
	ASSERT_EQ(vehiculeTest.reqImmatriculation(), "SAAQ");
}

//Cas invalide
TEST(Vehicule, NivInvalide) {
	ASSERT_THROW(VehiculeTest vehiculeTest("5LMJJ2J57CEL0auie", "SAAQ"),
			PreconditionException);
}

/**
 * \brief 	Test de l'opérateur ==
 * 			Cas valide: retourne true sur deux objets dont l'immatriculation et le niv sont identique.
 * 			Cas invalides: retourne false
 * 				- niv non identique
 * 				- immatriculation non identique
 */
TEST(Vehicule, estEgal) {
	VehiculeTest vehiculeTest("5LMJJ2J57CEL03980", "SAAQ");
	VehiculeTest vehiculeTest2("5LMJJ2J57CEL03980", "SAAQ");
	ASSERT_EQ(vehiculeTest, vehiculeTest2);
}

//Cas invalides
TEST(Vehicule, pasEgalNiv) {
	VehiculeTest vehiculeTest("5LMJJ2J57CEL03980", "SAAQ");
	VehiculeTest vehiculeTest2("JHMFA16586S014014", "SAAQ");
	ASSERT_FALSE(vehiculeTest == vehiculeTest2);
}

TEST(Vehicule, pasEgalImmatriculation) {
	VehiculeTest vehiculeTest("5LMJJ2J57CEL03980", "SAAQ");
	VehiculeTest vehiculeTest2("5LMJJ2J57CEL03980", "SAAA");
	ASSERT_FALSE(vehiculeTest == vehiculeTest2);
}

/**
 * \brief	Test de la méthode reqNiv()
 * 			Cas valide: retourne le numéro de série du véhicule
 * 			Cas invalide: aucun
 */
TEST_F(UnVehicule, reqNiv) {
	ASSERT_EQ(vehiculeTest.reqNiv(), "5LMJJ2J57CEL03980");
}

/**
 * \brief	Test de la méthode reqImmatriculation()
 * 			Cas valide: retourne le numéro d'immatriculation du véhicule
 * 			Cas invalide: aucun
 */
TEST_F(UnVehicule, reqImmatriculation) {
	ASSERT_EQ(vehiculeTest.reqImmatriculation(), "SAAQ");
}

TEST_F(UnVehicule, reqDateEnregistrement) {
	ASSERT_TRUE(util::Date().validerDate(vehiculeTest.reqDateEnregistrement().reqJour(),
			vehiculeTest.reqDateEnregistrement().reqMois(),
			vehiculeTest.reqDateEnregistrement().reqAnnee()));
}

/**
 * \brief	Test de la méthode reqVehiculeFormate().
 * 			Cas valide: la méthode retourne une chaîne de caractères formatée selon les spécifications.
 * 			Cas invalide: aucun
 */
TEST_F(UnVehicule, ReqVehiculeFormate) {
	ostringstream os;
	os		<< "Numero de serie : 5LMJJ2J57CEL03980" << endl
			<< "Numero d'immatriculation : SAAQ" << endl
			<< "Date d'enregistrement : " << vehiculeTest.reqDateEnregistrement().reqDateFormatee() << endl;
	ASSERT_EQ(vehiculeTest.reqVehiculeFormate(), os.str());
}



