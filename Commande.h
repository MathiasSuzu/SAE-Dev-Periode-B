#include "Plateau.h"
#include "Dictionnaire.h"

/**
 * @file
 * @brief Définition des fonctions liées au jeu utilisant le plateau, le dictionnaire, et les commandes des joueurs.
 */

/**
 * @brief Affiche un message indiquant que la commande est invalide et demande de recommencer.
 */
void recommencez();

/**
 * @brief Effectue la commande 'T' (Talon) du joueur.
 * @param[in,out] joueur Le joueur effectuant la commande.
 * @param[in,out] talon La pile représentant le talon.
 * @param[in,out] exposer La pile représentant les cartes exposées.
 * @return true si la commande est valide, sinon false.
 */
bool commandeT(Joueur& joueur, Pile& talon, Pile& exposer);

/**
 * @brief Effectue la commande 'E' (échanger) du joueur.
 * @param[in,out] joueur Le joueur effectuant la commande.
 * @param[in,out] talon La pile représentant le talon.
 * @param[in,out] exposer La pile représentant les cartes exposées.
 * @return true si la commande est valide, sinon false.
 */
bool commandeE(Joueur& joueur, Pile& talon, Pile& exposer);

/**
 * @brief Effectue la commande 'P' (poser) du joueur.
 * @param[in] dictionnaire Le dictionnaire utilisé pour vérifier les mots.
 * @param[in,out] joueur Le joueur effectuant la commande.
 * @param[in,out] plateau Le plateau sur lequel poser le mot.
 * @return true si la commande est valide, sinon false.
 */
bool commandeP(Dictionnaire& dictionnaire, Joueur& joueur, Plateau& plateau);

/**
 * @brief Effectue la commande 'R' (remplacer) du joueur.
 * @param[in] dictionnaire Le dictionnaire utilisé pour vérifier les mots.
 * @param[in,out] joueur Le joueur effectuant la commande.
 * @param[in,out] plateau Le plateau sur lequel effectuer le remplacement.
 * @return true si la commande est valide, sinon false.
 */
bool commandeR(Dictionnaire& dictionnaire, Joueur& joueur, Plateau& plateau);

/**
 * @brief Effectue la commande 'C' (composer) du joueur.
 * @param[in] dictionnaire Le dictionnaire utilisé pour vérifier les mots.
 * @param[in,out] joueur Le joueur effectuant la commande.
 * @param[in,out] plateau Le plateau sur lequel composer le mot.
 * @return true si la commande est valide, sinon false.
 */
bool commandeC(Dictionnaire& dictionnaire, Joueur& joueur, Plateau& plateau);

/**
 * @brief Vérifie la validité de la commande fournie par le joueur et l'exécute si elle est valide.
 * @param[in] dictionnaire Le dictionnaire utilisé pour vérifier les mots.
 * @param[in] command La commande fournie par le joueur.
 * @param[in,out] joueur Le joueur effectuant la commande.
 * @param[in,out] plateau Le plateau sur lequel effectuer la commande.
 * @param[in,out] talon La pile représentant le talon.
 * @param[in,out] exposer La pile représentant les cartes exposées.
 * @return true si la commande est valide, sinon false.
 */
bool commandeValide(Dictionnaire& dictionnaire, char command[], Joueur& joueur, Plateau& plateau, Pile& talon, Pile& exposer);
