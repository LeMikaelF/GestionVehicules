//
// Created by mikael on 2019-11-24.
//

#include <sstream>
#include "VehiculePromenade.h"
#include "ContratException.h"
#include "validationFormat.h"
#include "Vehicule.h"
using namespace std;
/**
 * \brief Constructeur de VehiculePromenade.
 * \param p_niv Une chaîne de caractères représentant le niv (numéro d'identification du véhicule) du véhicule.
 * \param p_immatriculation Une chaîne de caractères représentant le numéro d'immatriculation du véhicule.
 * \param p_nbPlaces un entier représentant le nombre de places du véhicule
 * \pre p_nbPlaces > 0
 * \post m_nbPlaces prend la valeur de p_nbPlaces
 */
saaq::VehiculePromenade::VehiculePromenade(const std::string &p_niv, const std::string &p_immatriculation,
                                           const int p_nbPlaces) : Vehicule(p_niv, p_immatriculation),
                                                                   m_nbPlaces(p_nbPlaces)
{
    PRECONDITION(m_nbPlaces > 0);
    PRECONDITION(util::validerImmatriculationPromenade(p_immatriculation));
    POSTCONDITION(m_nbPlaces == p_nbPlaces);
    INVARIANTS();
}

/**
 * \brief Opérateur d'égalité surchargé
 * \return une valeur booléenne vraie si les deux objets sont égaux.
 */
const bool saaq::VehiculePromenade::operator==(const saaq::VehiculePromenade &p_autre) const {
	return saaq::Vehicule::operator==(p_autre) && reqNbPlaces() == p_autre.reqNbPlaces();
}

/**
 * \brief Assigne un numéro d'immatriculation à l'objet courant.
 * \pre p_immatriculation est un numéro d'immatriculation de véhicule de promenade valide.
 * \post reqImmatriculation retourne la valeur de p_immatriculation.
 * \param[in] p_immatriculation Une chaîne de caractères à assigner au numéro d'immatriculation de l'objet courant.
 */
void saaq::VehiculePromenade::asgImmatriculation(const std::string &p_immatriculation)
{
    PRECONDITION(util::validerImmatriculationPromenade(p_immatriculation));
    Vehicule::asgImmatriculation(p_immatriculation);
    POSTCONDITION(p_immatriculation == reqImmatriculation());
    INVARIANTS();
}

/**
 * \brief Vérifier les invariants de la classe.
 */
void saaq::VehiculePromenade::verifieInvariant() const
{
    INVARIANT(util::validerImmatriculationPromenade(reqImmatriculation()));
}

/**
 * \brief retourne le nombre de places du véhicule
 * \return un entier représentant le nombre de places du véhicule.
 */
const int saaq::VehiculePromenade::reqNbPlaces() const
{
    return m_nbPlaces;
}
/**
 * \brief retourne la tarification annuelle de la plaque d'immatriculation de ce véhicule de promenade.
 * Gère seulement les propriétaires domiciliés au Québec.
 * \return la tarification annuelle de l'immatriculation de ce véhicule de promenade.
 */
const double saaq::VehiculePromenade::tarificationAnnuelle() const
{
    return 224.04;
}

/**
 * \brief constructeur copie de la classe
 */
saaq::Vehicule *saaq::VehiculePromenade::clone() const
{
    return new VehiculePromenade(*this);
}

/**
 * \brief retourne les informations de ce véhicule de promenade sous la forme d'une chaîne de caractères formatée.
 * \return une chaîne de caractères formatée contenant les informations de ce véhicule de promenade.
 */
const std::string saaq::VehiculePromenade::reqVehiculeFormate() const
{
    ostringstream os;
    os << Vehicule::reqVehiculeFormate()
       << "nombre de places : " << reqNbPlaces() << endl
       << "tarif : " << tarificationAnnuelle() << "$" << endl;
    return os.str();
}

/**
 * \brief 	valide un numéro d'immatriculation de véhicule de promenade
 * \param 	p_immatriculation Une chaîne de caractères représentant un numéro d'immatriculation
 * \return 	une valeur booléenne vraie si p_immatriculation est un numéro d'immatriculation
 * 			de véhicule de promenae valide
 */
const bool saaq::VehiculePromenade::validerImmatriculation(const std::string& p_immatriculation) const {
	return util::validerImmatriculationPromenade(p_immatriculation);
}
