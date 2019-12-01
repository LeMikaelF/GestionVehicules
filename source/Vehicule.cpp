/*
 * Vehicule.cpp
 *
 *  Created on: 2019-10-17
 *      Author: etudiant
 */


#include "Vehicule.h"
#include <sstream>
#include <iostream>
#include "ContratException.h"
#include "validationFormat.h"

using namespace std;
using saaq::Vehicule;
/**
 * \brief Constructeur par défaut. La date d'enregistrement du véhicule est la date de création de l'objet,
 *        selon la classe `util::Date`.
 * \param p_niv Une chaîne de caractères représentant le niv (numéro d'identification du véhicule) du véhicule.
 * \param p_immatriculation Une chaîne de caractères représentant le numéro d'immatriculation du véhicule.
 * \pre niv valide
 * \post m_immatriculation prend la valeur de p_immatriculation
 * \post m_mateEnregistrement est une date valide.
 */
Vehicule::Vehicule(const string &p_niv, const string &p_immatriculation)
        : m_niv(p_niv),
          m_immatriculation(p_immatriculation)
{
    PRECONDITION(util::validerNiv(p_niv));

    POSTCONDITION(m_niv == p_niv);
    POSTCONDITION(m_immatriculation == p_immatriculation);
    POSTCONDITION(util::Date().validerDate(m_dateEnregistrement.reqJour(), m_dateEnregistrement.reqMois(),
                                           m_dateEnregistrement.reqAnnee()))
    INVARIANTS();
}

/**
 * \brief Retourne les informations du véhicule formatées dans une chaîne de caractères
 * \return Le véhicule formaté dans une chaîne de caractères
 */
const string Vehicule::reqVehiculeFormate() const
{
    ostringstream tampon;
    tampon << "Numero de serie : " << reqNiv() << endl
           << "Numero d'immatriculation : " << reqImmatriculation() << endl
           << "Date d'enregistrement : " << reqDateEnregistrement().reqDateFormatee() << endl;
    return tampon.str();
}

/**
 * Assigne un numéro d'immatriculation à l'objet courant. Les classes dérivées sont responsables d'assurer
 * la validité du numéro d'immatriculation.
 * \param[in] p_immatriculation Une chaîne de caractères à assigner au numéro d'immatriculation de l'objet courant.
 */
void Vehicule::asgImmatriculation(const string &p_immatriculation)
{
	PRECONDITION(validerImmatriculation(p_immatriculation));
    m_immatriculation = p_immatriculation;
    INVARIANTS();
}

/**
 * Retourne le niv (numéro d'identification du véhicule) de l'objet courant.
 * @return Une chaîne de caractères représentant le niv (numéro d'identification du véhicule) de l'objet courant.
 */
const string &Vehicule::reqNiv() const
{
    return m_niv;
}

/**
 * Retourne le numéro d'immatriculation de l'objet courant.
 * @return Une chaîne de caractères représentant le numéro d'immatriculation de l'objet courant.
 */
const string &Vehicule::reqImmatriculation() const
{
    return m_immatriculation;
}

/**
 * Retourne la date d'enregistrement de l'objet courant.
 * @return Un objet `util::Date` représentant la date d'enregistrement de l'objet courant.
 */
const util::Date Vehicule::reqDateEnregistrement() const
{
    return m_dateEnregistrement;
}

/**
 * Surcharge de l'opérateur == \n
 * Cette méthode compare tous les attributs des deux objets pour détermineur leur égalité.
 * @param[in] p_autre Un objet `saaq::Vehicule` à comparer à l'objet courant.
 * @return Un booléen indiquant si tous les attributs de l'objet passé en paramètre sont égaux aux
 *         attributs de l'objet courant.
 */
const bool Vehicule::operator==(const Vehicule &p_autre) const
{
    return m_niv == p_autre.m_niv
           && m_immatriculation == p_autre.m_immatriculation
           && m_dateEnregistrement == p_autre.m_dateEnregistrement;
}

/**
 * \brief Vérifier les invariants de classe
 */
void saaq::Vehicule::verifieInvariant() const
{
    INVARIANT(util::validerNiv(m_niv));
    INVARIANT(util::Date().validerDate(m_dateEnregistrement.reqJour(), m_dateEnregistrement.reqMois(),
                                           m_dateEnregistrement.reqAnnee()))}
/**
 * \brief destructeur de la classe (no-op)
 */
saaq::Vehicule::~Vehicule()
{
}

