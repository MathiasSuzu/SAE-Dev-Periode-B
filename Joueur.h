#include "Carte.h"
#include "Const.h"
/**
 * @file
 * @brief Définition de la structure représentant un joueur dans le jeu.
 */

/**
 * @brief Structure représentant un joueur dans le jeu.
 */
struct Joueur
{
    unsigned int scores; /**< Le score du joueur. */
    int nombreCartes; /**< Le nombre de cartes en main du joueur. */
    Carte main[MAX_CARTES]; /**< Les cartes en main du joueur. */
    bool enLice; /**< Indique si le joueur est toujours en lice dans la partie. */
};
