#include "main.h"

int main(int argc, const char* argv[])
{
    Carte paquet[NbrCartes];
    initTalon(paquet);
    Dictionnaire dictionnaire;
    strcpy(dictionnaire.file, "ods4.txt");
    //dictionnaire.file = "ods4.txt";
    verifDico(dictionnaire);
    if (dictionnaire.taille == -1) // car le dictionnaire n'a pas pu etre ouvert
    {
        return 1;
    }
    
    int nbJoueur = calculateurNBJoueur(argc, argv);
    melangerPaquet(paquet, NbrCartes);

    Joueur joueurs[nbJoueur]; // création du nombre de joueurs selon la fonction calculateurNBJoueur
    for (int i = 0; i < nbJoueur; i++)
    {
        joueurs[i].scores = 0;
        joueurs[i].enLice = true;
    }
    
    distribuerCartes(paquet, NbrCartes, joueurs, nbJoueur, MAX_CARTES);

    Pile talon;
    Pile exposer;
    Plateau plateau;
    plateau.taille = 0;

    faireTalon(talon, paquet, nbJoueur * MAX_CARTES);
    faireExpose(exposer, talon);
    
    lancerPartie(dictionnaire, joueurs, plateau, talon, exposer, nbJoueur);
    
    // Libérer la mémoire allouée
    for (int i = 0; i < plateau.taille; ++i) {
        delete[] plateau.list[i];
    }
    //delete[] plateau.list;

    return 0;
}