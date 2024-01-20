#include "Plateau.h"
#include "Commande.h"

/**
 * @file
 * @brief Définition des fonctions pour le lancement et le déroulement du jeu.
 */

/**
 * @brief Calculateur du nombre de joueurs à partir des arguments de la ligne de commande.
 * @param[in] nbDargs Le nombre d'arguments de la ligne de commande.
 * @param[in] listDargs Les arguments de la ligne de commande.
 * @return Le nombre de joueurs spécifié ou 2 par défaut.
 */
int calculateurNBJoueur(int nbDargs, const char* listDargs[]);

/**
 * @brief Lance une partie du jeu.
 * @param[in] dictionnaire Le dictionnaire utilisé pour vérifier les mots.
 * @param[in,out] joueurs Le tableau de joueurs.
 * @param[in,out] plateau Le plateau de jeu.
 * @param[in,out] talon La pile représentant le talon.
 * @param[in,out] exposer La pile représentant les cartes exposées.
 * @param[in,out] nbJoueur Le nombre de joueurs en jeu.
 */
void lancerPartie(Dictionnaire& dictionnaire, Joueur joueurs[], Plateau& plateau, Pile& talon, Pile& exposer, int& nbJoueur);

/**
 * @brief Effectue un tour de jeu pour tous les joueurs.
 * @param[in] dictionnaire Le dictionnaire utilisé pour vérifier les mots.
 * @param[in,out] joueurs Le tableau de joueurs.
 * @param[in,out] plateau Le plateau de jeu.
 * @param[in,out] talon La pile représentant le talon.
 * @param[in,out] exposer La pile représentant les cartes exposées.
 * @param[in,out] nbJoueur Le nombre de joueurs en jeu.
 * @param[in] i La position du joueur courant.
 * @return La position du joueur dont le tour est terminé, ou -1 si tous les joueurs ont joué.
 */
int lancerUnTour(Dictionnaire& dictionnaire, Joueur joueurs[], Plateau& plateau, Pile& talon, Pile& exposer, int& nbJoueur, int i);
