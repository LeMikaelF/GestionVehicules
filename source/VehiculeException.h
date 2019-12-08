/*
 * VehiculeException.h
 *
 *  Created on: 2019-11-30
 *      Author: etudiant
 */

#ifndef VEHICULEEXCEPTION_H_
#define VEHICULEEXCEPTION_H_

#include <stdexcept>

/**
 * \brief Exception générale représentantant une erreur de programme de véhicule.
 */
class VehiculeException: public std::runtime_error {
public:
	VehiculeException(const std::string& p_raison);
};

/**
 * \brief	Exception d'exécution générée quand un véhicule est déjà présent dans un objet Propriétaire.
 */
class VehiculeDejaPresentException : public VehiculeException {
public:
	VehiculeDejaPresentException(const std::string& p_raison);
};

/**
 * \brief	Exception d'exécution générée quand un véhicule est absent dans un objet Propriétaire.
 */
class VehiculeAbsentException : public VehiculeException {
public:
	VehiculeAbsentException(const std::string& p_raison);
};

#endif /* VEHICULEEXCEPTION_H_ */

