#pragma once

#include <fstream>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Dictionnaire.h"
#include "Const.h"

using namespace std;

/**
 * @file
 * @brief Définition des fonctions liées à la gestion du dictionnaire.
 */

/**
 * @struct Dictionnaire
 * @brief Structure représentant un dictionnaire avec une taille et un nom de fichier.
 */
struct Dictionnaire
{
    long taille; /**< Taille du dictionnaire. */
    char file[MAX_STRING_LENGTH]; /**< Nom du fichier associé au dictionnaire. */
};

/**
 * @brief Vérifie si le dictionnaire est bien ouvrable et met à jour sa taille.
 * @param[in,out] dictionnaire Le dictionnaire à vérifier.
 */
void verifDico(Dictionnaire& dictionnaire);

/**
 * @brief Vérifie si un caractère est vide (espace, tabulation, retour à la ligne, etc.).
 * @param[in] caractere Le caractère à vérifier.
 * @return true si le caractère est vide, sinon false.
 */
bool videChar(char& caractere);

/**
 * @brief Trouve la position du début du mot à partir d'une position donnée dans un fichier.
 * @param[in] fichier Le fichier dans lequel chercher.
 * @param[in] position La position à partir de laquelle chercher.
 * @param[in] debut La position de début du fichier.
 * @return La position du début du mot.
 */
long posDebut(ifstream& fichier, long position, long debut);

/**
 * @brief Trouve la position du caractère suivant à partir d'une position donnée dans un fichier.
 * @param[in] fichier Le fichier dans lequel chercher.
 * @param[in] position La position à partir de laquelle chercher.
 * @param[in] fin La position de fin du fichier.
 * @return La position du caractère suivant.
 */
long posSuivant(ifstream& fichier, long position, long fin);

/**
 * @brief Trouve la position du caractère précédent à partir d'une position donnée dans un fichier.
 * @param[in] fichier Le fichier dans lequel chercher.
 * @param[in] position La position à partir de laquelle chercher.
 * @param[in] debut La position de début du fichier.
 * @return La position du caractère précédent.
 */
long posPrecedent(ifstream& fichier, long position, long debut);

/**
 * @brief Effectue une recherche dichotomique dans le dictionnaire pour un mot donné.
 * @param[in] dictionnaire Le dictionnaire dans lequel effectuer la recherche.
 * @param[in] motRecherche Le mot à rechercher.
 * @return true si le mot est trouvé, sinon false.
 */
bool rechercheDichotomique(Dictionnaire& dictionnaire, const char motRecherche[]);
