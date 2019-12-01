/*
 * Vehicule.h
 *
 *  Created on: 2019-10-17
 *      Author: etudiant
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_


#include "Date.h"

/**
 * \namespace saaq Le namespace saaq contient seulement la classe Vehicule.
 */
namespace saaq
{
    /**
     * \brief Cette classe sert à l'enregistrement d'un véhicule.
     * La validation de ses attributs est la responsabilité du programme qui l'utilise.
     * La date d'enregistrement est la date de création de l'objet.
     * Le niv ne peut pas être modifié.
     */
    class Vehicule
    {
    public:
        Vehicule(const std::string &p_niv, const std::string &p_immatriculation);

        virtual ~Vehicule();

        virtual Vehicule *clone() const = 0;

        virtual const bool operator==(const Vehicule &p_autre) const;

        const std::string &reqNiv() const;

        const std::string &reqImmatriculation() const;

        const util::Date reqDateEnregistrement() const;

        virtual const std::string reqVehiculeFormate() const;

        virtual const double tarificationAnnuelle() const = 0;

        virtual const bool validerImmatriculation(const std::string& p_immatriculation) const = 0;

    protected:
        virtual void asgImmatriculation(const std::string &p_immatriculation) = 0;

    private:
        void verifieInvariant() const;

        const std::string m_niv;

        const util::Date m_dateEnregistrement;

        std::string m_immatriculation;
    };
}

#endif /* VEHICULE_H_ */
