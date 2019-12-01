/*
 * fonctionsImmatriculation.h
 *
 *  Created on: 2019-10-03
 *      Author: etudiant
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

namespace util
{

    bool validerImmatriculationPromenade(const std::string& p_immatriculation);

    bool validerImmatriculationCamion(const std::string& p_immatriculation);

    bool validerNiv(const std::string &p_niv);

//On n'utilise pas les fonctions isupper() et isdigit() parce qu'elles dépendent
//du "Locale" de l'utilisateur.
    bool estLettreMaj(char c);

    bool estNumero(char c);

    bool estConforme(const std::string &format, const std::string &p_chaine);

    bool estConforme(const std::string &format, const std::string &p_chaine, const unsigned int positionStricte);

    bool condNbChar(const std::string &p_niv);

    bool condAlphaNum(const std::string &p_niv);

    bool condLettresInterdites(const std::string &p_niv);

    bool condPositionNeufValeursPossibles(const std::string &p_niv);

    bool condPositionDix(const std::string &p_niv);

    bool condChiffreDeControle(const std::string &p_niv);

    int translitteration(const char);
}
#endif /* VALIDATIONFORMAT_H_ */
