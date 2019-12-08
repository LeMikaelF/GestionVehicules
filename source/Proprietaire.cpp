//
// Created by mikael on 2019-11-24.
//

#include <sstream>
#include <numeric>
#include <algorithm>
#include "Proprietaire.h"
#include "ContratException.h"
#include "VehiculeException.h"
#include "validationFormat.h"

using namespace std;
using namespace saaq;

/**
 * Constructeur de la classe Proprietaire
 * \param p_nom		Nom de famille du propriétaire
 * \param p_prenom	Prénom du propriétaire
 * \pre				p_nom non vide
 * \pre				p_prenom non vide
 * \post			m_nom prend la valeur de p_nom
 * \post			m_prenom prend la valeur de p_prenom
 */
Proprietaire::Proprietaire(const std::string &p_nom, const std::string &p_prenom) : m_nom(p_nom),
		m_prenom(p_prenom)
{
	PRECONDITION(!p_nom.empty());
	PRECONDITION(!p_prenom.empty());

	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);
	INVARIANTS();
}

/**
 * \brief Vérifier les invariants de la classe
 */
void Proprietaire::verifieInvariant() const
{
	INVARIANT(!m_nom.empty());
	INVARIANT(!m_prenom.empty());
}

/**
 * \brief Retourne le nom du propriétaire
 * \return une chaîne de caractères représentant le nom du propriétaire
 */
const std::string &Proprietaire::reqNom() const
{
	return m_nom;
}

/**
 * \brief Retourne le prénom du propriétaire
 * \return une chaîne de caractères représentant le prénom du propriétaire.
 */
const std::string &Proprietaire::reqPrenom() const
{
	return m_prenom;
}

/**
 * \brief Retourne les informations formatées du propriétaire.
 * \return 	une chaîne de caractères contenant les informations du propriétaire
 * 			formatées selon les spécifications.
 */
const std::string Proprietaire::reqProprietaireFormate() const
{
	const string separateur = "-------------------";

	ostringstream os;
	os << "Proprietaire" << endl
			<< separateur << endl
			<< "Nom     : " << reqNom() << endl
			<< "Prenom  : " << reqPrenom() << endl
			<< accumulate(m_vVehicules.begin(), m_vVehicules.end(), string(),
					[separateur](string a, Vehicule* b)
					{ return a + separateur + "\n" + b->reqVehiculeFormate();});
	return os.str();
}

/**
 * \brief 	Ajoute un véhicule au propriétaire.
 * \param 	p_nouveauVehicule
 * 				Une référence constante vers un objet Vehicule à ajouter au propriétaire.
 * \throw	VehiculeDejaPresentException si le véhicule à ajouter est déjà présent dans
 * 			le vecteur de l'objet.
 * \post 	Le vecteur m_vVehicules du Proprietaire contient une copie du nouveau véhicule.
 */
void Proprietaire::ajouterVehicule(const Vehicule &p_nouveauVehicule)
{
	if(vehiculeEstDejaPresent(p_nouveauVehicule.reqNiv())) {
		throw VehiculeDejaPresentException(p_nouveauVehicule.reqVehiculeFormate());
	}
	m_vVehicules.push_back(p_nouveauVehicule.clone());
	const Vehicule* vehiculeP = &p_nouveauVehicule;
	POSTCONDITION(any_of(m_vVehicules.begin(), m_vVehicules.end(),
			[vehiculeP](Vehicule* v) {return *v == *vehiculeP;}));
}

/**
 * \brief Destructeur de la classe Propiretaire
 */
Proprietaire::~Proprietaire()
{
	for(std::vector<Vehicule*>::iterator it = m_vVehicules.begin(); it != m_vVehicules.end(); it++) {
			delete(*it);
			it = m_vVehicules.erase(it);
	}
}

/**
 * \brief Constructeur copie de la classe Proprietaire.
 */
Proprietaire::Proprietaire(const Proprietaire &p_proprietaire)
: Proprietaire(p_proprietaire.reqNom(), p_proprietaire.reqPrenom())
{
	for_each(p_proprietaire.m_vVehicules.begin(), p_proprietaire.m_vVehicules.end(), [this](Vehicule *v)
			{ ajouterVehicule(*v); });
}

/**
 * \brief 	Opérateur d'assignation surchargé de Proprietaire.
 * \return	L'objet courant.
 */
const Proprietaire &Proprietaire::operator=(const Proprietaire p_proprietaire)
{
	if (this != &p_proprietaire)
	{
		for_each(m_vVehicules.begin(), m_vVehicules.end(), [](Vehicule *v)
				{ delete (v); });
		m_vVehicules.shrink_to_fit();
		for_each(p_proprietaire.m_vVehicules.begin(), p_proprietaire.m_vVehicules.end(), [this](Vehicule *v)
				{ ajouterVehicule(*v); });
	}
	return *this;
}

/**
 * \brief 		Vérifie si un véhicule (identifié par son niv) est déjà présent dans
 * 				le vecteur de l'objet Propriétaire.
 * \param[in] 	Une chaîne de caractères représentant le niv du véhicule à vérifier
 * \return		Une valeur booléenne vraie si le véhicule est déjà présent
 * 				dans le vecteur de l'objet.
 */
bool Proprietaire::vehiculeEstDejaPresent(const std::string& p_niv) const {
	return any_of(m_vVehicules.begin(), m_vVehicules.end(),
			[p_niv](Vehicule* v) {return v->reqNiv() == p_niv;});
}

/**
 * \brief	Supprime un véhicule de l'objet Propriétaire.
 * \throw	VehiculeAbsentException si le véhicule à supprimer est absent du
 * 			vecteur de l'objet.
 * \pre		Le niv est valide
 * \post	Le véhicule est retiré du vecteur de l'objet.
 */
void Proprietaire::supprimerVehicule(const std::string& p_niv) {
	PRECONDITION(util::validerNiv(p_niv));
	bool trouve = false;
	for(std::vector<Vehicule*>::iterator it = m_vVehicules.begin();
			it != m_vVehicules.end() && !trouve; it++) {
		if((*it)->reqNiv() == p_niv) {
			delete(*it);
			it = m_vVehicules.erase(it);
			trouve = true;
		}
	}
	if(!trouve) {
		throw VehiculeAbsentException("Erreur: véhicule # "
				+ string(p_niv) + "absent.");
	}
	INVARIANTS();
}
