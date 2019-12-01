//
// Created by mikael on 2019-11-24.
//

#include <map>
#include <sstream>
#include "Camion.h"
#include "ContratException.h"
#include "validationFormat.h"

using namespace std;

/**
 * \brief Constructeur de la classe. Camion
 * \param p_niv Une chaîne de caractères représentant le niv (numéro d'identification du véhicule) du camion.
 * \param p_immatriculation Une chaîne de caractères représentant le numéro d'immatriculation du camion.
 * \param p_poids Un entier représentant le poids du camion.
 * \param p_nbEssieux En entier représentant le nombre d'essieux du camion.
 * \pre p_poids > 3000 kg
 * \pre p_nbEssieux >= 2
 * \post m_nbEssieux prend la valeur de p_nbEssieux.
 * \post m_poids prend la valeur de p_poids.
 */
saaq::Camion::Camion(const std::string &p_niv, const std::string &p_immatriculation, const unsigned int p_poids,
                     const unsigned short p_nbEssieux) : Vehicule(p_niv, p_immatriculation), m_poids(p_poids),
                                                         m_nbEssieux(p_nbEssieux)
{
    PRECONDITION(p_poids > 3000);
    PRECONDITION(p_nbEssieux >= 2);
    PRECONDITION(util::validerImmatriculationCamion(p_immatriculation))

    POSTCONDITION(m_nbEssieux == p_nbEssieux);
    POSTCONDITION(m_poids == p_poids);
    INVARIANTS();
}

/**
 * \brief Opérateur d'égalité surchargé
 * \return une valeur booléenne vraie si les deux objets sont égaux.
 */
const bool saaq::Camion::operator==(const saaq::Camion &p_autre) const {
	return saaq::Vehicule::operator==(p_autre)
			&& reqNbEssieux() == p_autre.reqNbEssieux()
			&& reqPoids() == p_autre.reqPoids();
}

/**
 * \brief Vérifier les invariants de la classe:
 * m_poids > 3000
 * m_nbEssieux >= 2
 * immatriculation valide
 */
void saaq::Camion::verifieInvariant() const
{
    INVARIANT(m_poids > 3000);
    INVARIANT(m_nbEssieux >= 2);
    INVARIANT(util::validerImmatriculationCamion(reqImmatriculation()));
}

/**
 * \brief Retourne le poids du camion.
 * \return un entier représentant le poids du camion.
 */
const unsigned int saaq::Camion::reqPoids() const
{
    return m_poids;
}

/**
 * \brief retourne le nombre d'essieux du camion.
 * \return un entier représentant le nombre d'essieux
 */
const unsigned short saaq::Camion::reqNbEssieux() const
{
    return m_nbEssieux;
}

/**
 * Assigne un numéro d'immatriculation à l'objet courant.
 * \pre p_immatriculation est un numéro d'immatriculation de camion valide
 * \post reqImmatriculation retourne la valeur de p_immatriculation
 * \param[in] p_immatriculation Une chaîne de caractères à assigner au numéro d'immatriculation de l'objet courant.
 */
void saaq::Camion::asgImmatriculation(const std::string &p_immatriculation)
{
    PRECONDITION(util::validerImmatriculationCamion(p_immatriculation));
    Vehicule::asgImmatriculation(p_immatriculation);
    POSTCONDITION(reqImmatriculation() == p_immatriculation);
    INVARIANTS();
}
/**
 * \brief retourne la tarification annuelle de la plaque d'immatriculation de ce camion selon les
 * grilles de calcul de la SAAQ (https://saaq.gouv.qc.ca/saaq/tarifs-amendes/immatriculation/cout-renouvellement-immatriculation/camions-ensembles-vehicules-routiers-vehicules-ferme-plus-3000kg/).
 * \return la tarification annuelle de l'immatriculation de ce camion.
 */
const double saaq::Camion::tarificationAnnuelle() const
{
    double tarification = 0;
    switch (m_nbEssieux)
    {
        case 2:
            if (m_poids <= 4000)
            {
                tarification = 570.28;
            }
            else
            {
                tarification = 905.28;
            }
            break;
        case 3:
            tarification = 1566.19;
            break;
        case 4:
            tarification = 2206.19;
            break;
        case 5:
            tarification = 2821.76;
            break;
        default:
            //6 et plus
            tarification = 3729.76;
    }
    return tarification;
}

/**
 * \brief Constructeur copie de la classe
 */
saaq::Vehicule *saaq::Camion::clone() const
{
    return new Camion(*this);
}

/**
 * \brief retourne les informations de ce camion sous la forme d'une chaîne de caractères formatée.
 * \return une chaîne de caractères formatée contenant les informations de ce camion.
 */
const string saaq::Camion::reqVehiculeFormate() const
{
    ostringstream os;
    os << Vehicule::reqVehiculeFormate()
       << "nombre d'essieux : " << reqNbEssieux() << endl
       << "poids : " << reqPoids() << endl
       << "tarif : " << tarificationAnnuelle() << "$" << endl;
    return os.str();
}
/**
 * \brief 	valide un numéro d'immatriculation de camion
 * \param 	p_immatriculation Une chaîne de caractères représentant un numéro d'immatriculation
 * \return 	une valeur booléenne vraie si p_immatriculation est un numéro d'immatriculation
 * 			de camion valide
 */
const bool saaq::Camion::validerImmatriculation(const std::string& p_immatriculation) const {
	return util::validerImmatriculationCamion(p_immatriculation);
}
