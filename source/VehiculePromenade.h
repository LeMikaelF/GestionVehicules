//
// Created by mikael on 2019-11-24.
//

#ifndef SRC_VEHICULEPROMENADE_H
#define SRC_VEHICULEPROMENADE_H

#include <string>
#include "Vehicule.h"

namespace saaq
{
/**
 * \brief Cette classe sert à l'enregistrement d'un véhicule de promenade.
 * La validation de ses attributs est la responsabilité du programme qui l'utilise.
 * La date d'enregistrement est la date de création de l'objet.
 * Le niv ne peut pas être modifié.
 */
    class VehiculePromenade : public Vehicule
    {
    public:
        VehiculePromenade(const std::string &p_niv, const std::string &p_immatriculation,
                          const int p_nbPlaces);

        const bool operator==(const VehiculePromenade &p_autre) const;

        const int reqNbPlaces() const;

        const double tarificationAnnuelle() const override;

        virtual Vehicule *clone() const override;

        const std::string reqVehiculeFormate() const override;

        void asgImmatriculation(const std::string &p_immatriculation) override;

        virtual const bool validerImmatriculation(const std::string& p_immatriculation) const;

    private:
        const int m_nbPlaces;
        void verifieInvariant() const;
    };

}


#endif //SRC_VEHICULEPROMENADE_H
