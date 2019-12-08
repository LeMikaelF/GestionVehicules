/*
 * VehiculeException.cpp
 *
 *  Created on: 2019-11-30
 *      Author: etudiant
 */

#include "VehiculeException.h"

using namespace std;

/**
 * \brief	Constructeur de la classe VehiculeException
 * \param	Une chaîne de caractères représentant le raison de l'exception.
 */
VehiculeException::VehiculeException(const std::string& p_raison)
: runtime_error(p_raison) {
}

/**
 * \brief	Constructeur de la classe VehiculeDejaPresentException
 * \param	Une chaîne de caractères représentant le raison de l'exception.
 */
VehiculeDejaPresentException::VehiculeDejaPresentException(const std::string& p_raison)
: VehiculeException(p_raison){}

/**
 * \brief	Constructeur de la classe VehiculeAbsentException
 * \param	Une chaîne de caractères représentant le raison de l'exception.
 */
VehiculeAbsentException::VehiculeAbsentException(const std::string& p_raison)
: VehiculeException(p_raison){}
