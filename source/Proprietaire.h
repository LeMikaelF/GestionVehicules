//
// Created by mikael on 2019-11-24.
//

#ifndef SRC_PROPRIETAIRE_H
#define SRC_PROPRIETAIRE_H

#include <string>
#include <vector>
#include "Vehicule.h"

namespace saaq
{

	/**
	 * \brief 	Une classe représentant un propriétaire de véhicules.
	 * 			Le programme utilisant la classe est responsable de la
	 * 			validité des attributs.
	 */
    class Proprietaire
    {
    public:
        Proprietaire(const std::string &p_nom, const std::string &p_prenom);
        Proprietaire(const Proprietaire& p_proprietaire);
        const std::string &reqNom() const;
        const std::string &reqPrenom() const;
        const std::string reqProprietaireFormate() const;
        void ajouterVehicule(const Vehicule& p_nouveauVehicule);
        const Proprietaire & operator=(const Proprietaire p_proprietaire);
        bool vehiculeEstDejaPresent (const std::string& p_niv) const;
        void supprimerVehicule(const std::string& p_niv);
        virtual ~Proprietaire();

    private:
        std::string m_nom;
        std::string m_prenom;
        std::vector<Vehicule *> m_vVehicules;

        void verifieInvariant() const;

    };

}


#endif //SRC_PROPRIETAIRE_H
