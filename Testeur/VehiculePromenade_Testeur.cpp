#include <gtest/gtest.h>
#include "VehiculePromenade.h"
#include "ContratException.h"
#include <string>
#include <sstream>

using namespace std;
using namespace saaq;

/**
 * \brief	Test du constructeur de VehiculePromenade.
 * 			Cas valide: création de l'objet et vérification de l'assignation des attributs.
 * 			Cas invalides:
 * 				- p_immatriculation invalide
 * 				- (p_nbPlaces > 0)
 */
TEST(VehiculePromenade, ConstructeurValide) {
	VehiculePromenade vehiculePromenade("JHMFA16586S014014", "000 ABC", 3);
	ASSERT_EQ(vehiculePromenade.reqImmatriculation(), "000 ABC");
	ASSERT_EQ(vehiculePromenade.reqNbPlaces(), 3);
}

//Cas invalides
TEST(VehiculePromenade, ImmatriculationInvalide) {
	ASSERT_THROW(VehiculePromenade vehiculePromenade("JHMFA16586S014014", "0", 3),
			PreconditionException);
}

TEST(VehiculePromenade, NbPlacesInvalide) {
	ASSERT_THROW(VehiculePromenade vehiculePromenade("JHMFA16586S014014", "000 ABC", 0),
				PreconditionException);
}

/**
 * \brief Création d'une fixture de test pour les méthodes publiques de la classe VehiculePromenade.
 */
class UnVehiculePromenade : public ::testing::Test {
public:
	UnVehiculePromenade() : vehiculePromenade("JHMFA16586S014014", "000 ABC", 3) {}
	VehiculePromenade vehiculePromenade;
};

/**
 * \brief	Test de la méthode reqNbPlaces()
 * 		Cas valide: retourne le nombre de places du véhicule
 * 		Cas invalide: aucun
 */
TEST_F(UnVehiculePromenade, ReqNbPlaces) {
	int attendu = vehiculePromenade.reqNbPlaces();
	ASSERT_EQ(attendu, 3);
}

/**
 * \brief	Test de la méthode tarificationAnnuelle()
 * 			Cas valide: retourne la tarification annuelle d'un véhicule de promenade pour un
 * 						propriétaire domicilié au Québec.
 * 			Cas invalide: aucun
 */
TEST_F(UnVehiculePromenade, ReqTarificationAnnuelle) {
	ASSERT_EQ(vehiculePromenade.tarificationAnnuelle(), 224.04);
}

/**
 * \brief	Test de la méthode reqVehiculeFormate()
 * 			Cas valide: retourne une chaîne de caractères formatée selon les spécifications.
 * 			Cas invalide: aucun
 */
TEST_F(UnVehiculePromenade, ReqVehiculeFormate) {
	ostringstream os;
	os  << "Numero de serie : JHMFA16586S014014" << endl
		<< "Numero d'immatriculation : 000 ABC" << endl
		<< "Date d'enregistrement : " << vehiculePromenade.reqDateEnregistrement().reqDateFormatee() << endl
		<< "nombre de places : 3" << endl
		<< "tarif : 224.04$" << endl;
	string attendu = vehiculePromenade.reqVehiculeFormate();
	ASSERT_EQ(attendu, os.str());
}

/**
 * \brief	Test de la méthode asgImmatriculation()
 * 			Cas valide: vérifier que la méhode assigne un numéro d'immatriculation valide.
 * 			Cas invalide: vérifier que la méthode n'assigne pas un numéro d'immatriculation invalide.
 */
TEST_F(UnVehiculePromenade, AsgImmatriculationValide) {
	vehiculePromenade.asgImmatriculation("000 CBA");
	ASSERT_EQ(vehiculePromenade.reqImmatriculation(), "000 CBA");
}

//Cas invalide
TEST_F(UnVehiculePromenade, AsgImmatriculationInvalide) {
	ASSERT_THROW(vehiculePromenade.asgImmatriculation("0"), PreconditionException);
}
