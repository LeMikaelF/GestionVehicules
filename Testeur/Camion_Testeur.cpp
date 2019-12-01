#include <gtest/gtest.h>
#include "Camion.h"
#include "ContratException.h"
#include "sstream"

using namespace saaq;
using namespace std;

/**
 * \brief 	Test du constructeur
 * 			Cas valide: création d'un objet et vérification de l'assignation de tous les attributs.
 * 			Cas invalides:
 * 				- !(p_poids > 3000)
 * 				- !(p_nbEssieux >= 2)
 */
TEST(Camion, ConstructeurValide) {
	Camion camion("JHMFA16586S014014", "L000000", 4000, 7);
	ASSERT_EQ(camion.reqImmatriculation(), "L000000");
	ASSERT_EQ(camion.reqPoids(), 4000);
	ASSERT_EQ(camion.reqNbEssieux(), 7);
}

//cas invalides
TEST(Camion, PoidsInvalide) {
	ASSERT_THROW(Camion camion("JHMFA16586S014014", "L000000", 1000, 7),
		PreconditionException);
}

TEST(Camion, NbEssieuxInvalide) {
	ASSERT_THROW(Camion camion("JHMFA16586S014014", "L000000", 1000, 1),
		PreconditionException);
}

/**
 * \brief Création d'une fixture de test à utiliser pour les méthodes publiques de la classe Camion.
 */
class UnCamion : public ::testing::Test {
public:
	UnCamion() : camion("JHMFA16586S014014", "L000000", 4000, 7) {};
	Camion camion;
};

/**
 * \brief 	Test de la méthode reqPoids()
 * 			Cas valide: vérifier que la méthoderetourne le poids du camion
 * 			Cas invalide: aucun
 */
TEST_F(UnCamion, ReqPoids) {
	ASSERT_EQ(camion.reqPoids(), 4000);
}

/**
 * \brief 	Test de la méthode reqNbEssieux()
 * 			Cas valide: vérifier que la méthode retourne le nombre d'essieux du camion
 * 			Cas invalide: aucun
 */
TEST_F(UnCamion, ReqNbEssieux) {
	ASSERT_EQ(camion.reqNbEssieux(), 7);
}

/**
 * \brief	Test de la méthode reqVehiculeFormate()
 * 			Cas valide: vérifier que la méthode retourne une chaîne de caractères formatée
 */
TEST_F(UnCamion, ReqVehiculeFormate) {
	ostringstream os;
	os 		<< "Numero de serie : JHMFA16586S014014" << endl
			<< "Numero d'immatriculation : L000000" << endl
			<< "Date d'enregistrement : " << camion.reqDateEnregistrement().reqDateFormatee() << endl
			<< "nombre d'essieux : " << camion.reqNbEssieux() << endl
			<< "poids : " << camion.reqPoids() << endl
			<< "tarif : 3729.76$" << endl;
	ASSERT_EQ(camion.reqVehiculeFormate(), os.str());
}

/**
 * \brief	Test de la méthode tarificationAnnuelle()
 * 			Cas valide: vérifier que la méthode retourne la bonne tarification annuelle.
 * 			Cas invalide: aucun
 */
TEST_F(UnCamion, TarificationAnnuelle) {
	ASSERT_EQ(camion.tarificationAnnuelle(), 3729.76);
}

/**
 * \brief	Test de la méthode asgImmatriculation()
 * 			Cas valide: vérifier que la méhode assigne un numéro d'immatriculation valide.
 * 			Cas invalide: vérifier que la méthode n'assigne pas un numéro d'immatriculation invalide.
 */
TEST_F(UnCamion, AsgImmatriculationValide) {
	camion.asgImmatriculation("L032006");
	ASSERT_EQ(camion.reqImmatriculation(), "L032006");
}

// Cas invalide
TEST_F(UnCamion, AsgImmatriculationInvalide) {
	ASSERT_THROW(camion.asgImmatriculation("0"), PreconditionException);
}



