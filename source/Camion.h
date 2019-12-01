//
// Created by mikael on 2019-11-24.
//

#ifndef SRC_CAMION_H
#define SRC_CAMION_H

#include "Vehicule.h"

namespace saaq
{
	/**
     * \brief Cette classe sert à l'enregistrement d'un camion.
     * La validation de ses attributs est la responsabilité du programme qui l'utilise.
     * La date d'enregistrement est la date de création de l'objet.
     * Le niv ne peut pas être modifié.
     */
    class Camion : public Vehicule
    {
    public:
        Camion(const std::string &p_niv, const std::string &p_immatriculation, const unsigned int p_poids,
               const unsigned short p_nbEssieux);
        const bool operator==(const Camion &p_autre) const;

        const unsigned int reqPoids() const;

        const unsigned short reqNbEssieux() const;

        const std::string reqVehiculeFormate() const override;

        Vehicule *clone() const override;

        const double tarificationAnnuelle() const override;

        void asgImmatriculation(const std::string &p_immatriculation) override;

        virtual const bool validerImmatriculation(const std::string& p_immatriculation) const;

    private:
        const unsigned int m_poids;

        const unsigned short int m_nbEssieux;

        void verifieInvariant() const;

    };
}


#endif //SRC_CAMION_H
