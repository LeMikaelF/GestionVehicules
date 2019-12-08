/*
 * fonctionsImmatriculation.cpp
 *
 *  Created on: 2019-10-03
 *      Author: etudiant
 */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "validationFormat.h"

using namespace std;

namespace util
{

    const int LONGUEUR_NIV = 17;
    std::map<char, int> map = {
            {'A', 1},
            {'B', 2},
            {'C', 3},
            {'D', 4},
            {'E', 5},
            {'F', 6},
            {'G', 7},
            {'H', 8},
            {'J', 1},
            {'K', 2},
            {'L', 3},
            {'M', 4},
            {'N', 5},
            {'P', 7},
            {'R', 9},
            {'S', 2},
            {'T', 3},
            {'U', 4},
            {'V', 5},
            {'W', 6},
            {'X', 7},
            {'Y', 8},
            {'Z', 9}
    };
    const int POIDS_TRANSLITTERATION[17] = {8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2};

/**
 * @brief valide un numéro NIV (numéro d'identification du véhicule)
 * @param p_niv Une chaîne de caractères représent le numéro à valider
 * @return Une valeur booléenne représentant le résultat de la vérification
 */
    bool validerNiv(const string &p_niv)
    {
        return condNbChar(p_niv)
               && condAlphaNum(p_niv)
               && condLettresInterdites(p_niv)
               && condPositionNeufValeursPossibles(p_niv)
               && condPositionDix(p_niv)
               && condChiffreDeControle(p_niv);
    }

    bool condNbChar(const string &p_niv)
    {
        return p_niv.length() == LONGUEUR_NIV;
    }

    bool condAlphaNum(const string &p_niv)
    {
        bool estValide = true;
        for (int i = 0; estValide && i < LONGUEUR_NIV; i++)
        {
            if (!estLettreMaj(p_niv.at(i)) && !estNumero(p_niv.at(i)))
            {
                estValide = false;
            }
        }
        return estValide;
    }

    bool condLettresInterdites(const string &p_niv)
    {
        const int NB_LETTRES_INTERDITES = 3;
        const char LETTRES_INTERDITES[NB_LETTRES_INTERDITES] = {'I', 'O', 'Q'};

        bool estValide = true;
        for (int i = 0; estValide && i < NB_LETTRES_INTERDITES; i++)
        {
            if (p_niv.find(LETTRES_INTERDITES[i]) != string::npos)
            {
                estValide = false;
            }
        }

        return estValide;
    }

    bool condPositionNeufValeursPossibles(const string &p_niv)
    {
        const int NB_CHAR_POSSIBLES = 11;
        const char CHAR_POSSIBLES[NB_CHAR_POSSIBLES] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X'};

        bool estValide = false;
        for (int i = 0; !estValide && i < NB_CHAR_POSSIBLES; i++)
        {
            if (p_niv.at(8) == CHAR_POSSIBLES[i])
            {
                estValide = true;
            }
        }
        return estValide;
    }

    bool condPositionDix(const string &p_niv)
    {
        const int NB_LETTRES_INTERDITES = 2;
        const char LETTRES_INTERDITES[2] = {'U', 'Z'};

        bool estValide = true;
        for (int i = 0; estValide && i < NB_LETTRES_INTERDITES; i++)
        {
            if (p_niv.at(9) == LETTRES_INTERDITES[i])
            {
                estValide = false;
            }
        }
        return estValide;
    }

    bool condChiffreDeControle(const string &p_niv)
    {
        int transformes[LONGUEUR_NIV];
        for (int i = 0; i < LONGUEUR_NIV; i++)
        {
            if (estLettreMaj(p_niv.at(i)))
            {
                transformes[i] = translitteration(p_niv.at(i)) * POIDS_TRANSLITTERATION[i];
            }
            else if (estNumero(p_niv.at(i)))
            {
                transformes[i] = (p_niv.at(i) - '0') * POIDS_TRANSLITTERATION[i];
            }
        }

        int somme = 0;
        for (int i = 0; i < LONGUEUR_NIV; i++)
        {
            somme += transformes[i];
        }

        int chiffreDeControle = somme % 11;
        char charDeControle = chiffreDeControle == 10 ? 'X' : chiffreDeControle + 48;

        return p_niv.at(8) == charDeControle;

    }

    int translitteration(const char c)
    {
        return map.find(c)->second;
    }
/**
 * @brief vérifie si une chaîne de caractère est de même longueur qu'un format donné et
 *        qu'elle contient des caractères alphanumériques, des numéros ou des espaces
 *        aux mêmes positions que ce format.
 * @param p_format le format contre lequel faire la vérification
 * @param p_chaine la chaîne de caractères à vérifier
 * @return une valeur booléenne représentant le résultat de la vérification
 */
    bool estConforme(const string &p_format, const string &p_chaine)
    {
        bool estConforme = true;

        if (p_format.length() != p_chaine.length())
        {
            estConforme = false;
        }

        for (unsigned int i = 0; estConforme && i < p_chaine.length(); i++)
        {
            if (estLettreMaj(p_format.at(i)))
            {
                estConforme = estLettreMaj(p_chaine.at(i));
            }
            else if (estNumero(p_format.at(i)))
            {
                estConforme = estNumero(p_chaine.at(i));
            }
        }
        return estConforme;
    }

/**
 * @brief une version surchargée de estConforme(const string p_format, const string p_chaine)
 *        qui supporte un index pour lequel le caractère de la chaîne à tester doit correspondre
 *        exactement au caractère au même index dans le format spécifié.
 * @param p_format le format contre lequel faire la vérification
 * @param p_chaine la chaîne de caractères à vérifier
 * @param positionStricte l'index pour lequel la chaîne doit correspondre exactement au format
 * @return une valeur booléenne représentant le résultat de la vérification. Retourne false si l'index
 *         spécifié déborde de la chaîne de format.
 */
    bool estConforme(const string &p_format, const string &p_chaine, const unsigned int positionStricte)
    {
        return p_format.length() == p_chaine.length()
        	   && positionStricte >= 0 && positionStricte <= p_format.length()
               && p_format.at(positionStricte) == p_chaine.at(positionStricte)
               && estConforme(p_format, p_chaine);
    }

    bool estLettreMaj(char c)
    {
        return 64 < c && c < 91;
    }

    bool estNumero(char c)
    {
        return 47 < c && c < 58;
    }

    /**
     * @brief valide un numéro de plaque d'immatriculation québécoise au format «sans préfixe» (incluant les
     *        véhicules électriques)
     * @param p_immatriculation une chaîne de caractères représentant le numéro de plaque d'immatriculation
     * @return une valeur booléenne représentant le résultat de la vérification.
     */
    bool validerImmatriculationPromenade(const std::string &p_immatriculation)
    {
        vector<string> formatsNonStricts = {
                "000 ABC",  //Format sans préfixe type 1
                "000H000",  //Format sans préfixe type 2
                "A00 ABC",  //Format sans préfixe type 3
                "ABC 000",  //Format sans préfixe type 4
                "SAAQ",     //Format sans préfixe type 5
                "SAAQ"};    //Format sans préfixe type 6
        return any_of(formatsNonStricts.begin(), formatsNonStricts.end(),
                          [p_immatriculation](const string &format)
                          { return estConforme(format, p_immatriculation); });
    }

    /**
     * @brief 	valide un numéro de plaque d'immatriculation québécoise au format
     * 			«camion et ensemble de véhicules routiers» (plaque L).
     * @param 	p_immatriculation une chaîne de caractères représentant le numéro de plaque d'immatriculation
     * @return 	une valeur booléenne représentant le résultat de la vérification.
     */
    bool validerImmatriculationCamion(const std::string &p_immatriculation)
    {
        return estConforme("L000000", p_immatriculation, 0);
    }
}
