/*
 * VehiculeException.cpp
 *
 *  Created on: 2019-11-30
 *      Author: etudiant
 */

#include "VehiculeException.h"

using namespace std;

VehiculeException::VehiculeException(const std::string& p_raison)
: runtime_error(p_raison) {
}

VehiculeDejaPresentException::VehiculeDejaPresentException(const std::string& p_raison)
: VehiculeException(p_raison){}

VehiculeAbsentException::VehiculeAbsentException(const std::string& p_raison)
: VehiculeException(p_raison){}
