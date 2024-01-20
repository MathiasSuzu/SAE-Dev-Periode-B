#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include "Carte.h"
#include "Const.h"
#include "./Conteneurs/Pile.h"
#include "Joueur.h"

using namespace std;

/**
 * @struct Plateau
 * @brief Structure représentant un plateau avec une taille et une liste de chaînes de caractères.
 */
struct Plateau
{
    int taille; /**< Taille du plateau. */
    char* list[MAX_STRING_LENGTH]; /**< Liste de chaînes de caractères représentant le plateau. */
};

/**
 * @brief Initialise un paquet de cartes avec des lettres, des points, et des quantités prédéfinies.
 * @param[in,out] paquet Le paquet de cartes à initialiser.
 */
void initTalon(Carte paquet[NbrCartes]);

/**
 * @brief Mélange aléatoirement les cartes dans un paquet.
 * @param[in,out] paquet Le paquet de cartes à mélanger.
 * @param[in] taille La taille du paquet.
 */
void melangerPaquet(Carte paquet[], int taille);

/**
 * @brief Affiche les lettres des cartes dans un paquet.
 * @param[in] paquet Le paquet de cartes à afficher.
 * @param[in] nb Le nombre de cartes à afficher.
 */
void showpaqueta(Carte paquet[], int nb);

/**
 * @brief Affiche les mots sur un plateau.
 * @param[in] plateau Le plateau contenant les mots à afficher.
 */
void showPlateau(Plateau& plateau);

/**
 * @brief Distribue les cartes du paquet aux joueurs.
 * @param[in] paquet Le paquet de cartes à distribuer.
 * @param[in] taille La taille du paquet.
 * @param[in,out] joueurs Un tableau de joueurs auxquels distribuer les cartes.
 * @param[in] nbJoueurs Le nombre de joueurs.
 * @param[in] cartesParJoueur Le nombre de cartes à distribuer à chaque joueur.
 */
void distribuerCartes(Carte paquet[], int taille, Joueur joueurs[], int nbJoueurs, int cartesParJoueur);

/**
 * @brief Crée un talon à partir du paquet de cartes, à partir de l'index spécifié.
 * @param[out] talon Le talon à créer.
 * @param[in] paquet Le paquet de cartes d'origine.
 * @param[in] indexCartesRestantes L'index à partir duquel créer le talon.
 */
void faireTalon(Pile& talon, Carte paquet[], int indexCartesRestantes);

/**
 * @brief Crée un exposé à partir du sommet du talon.
 * @param[out] exposer L'exposé à créer.
 * @param[in,out] talon Le talon d'où extraire la carte pour l'exposé.
 */
void faireExpose(Pile& exposer, Pile& talon);

/**
 * @brief Ajoute un mot au plateau.
 * @param[in,out] plateau Le plateau auquel ajouter le mot.
 * @param[in] mot Le mot à ajouter.
 */
void ajouterMot(Plateau& plateau, const char* mot);
