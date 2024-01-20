#include "Plateau.h"

void initTalon(Carte paquet[NbrCartes]) {
    int k = 0;
    char lettres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int quantites[] = { 2, 2, 2, 2, 5, 1, 2, 2, 4, 1, 1, 2, 1, 3, 2, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1 };
    int points[] = { 10, 2, 8, 6, 10, 2, 4, 8, 10, 6, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 2, 4, 2 };
    for (int i = 0; i < NbrCartes;)
    {
        for (int  j = 0; j < quantites[k]; j++)
        {
            paquet[i].lettre = lettres[k];
            paquet[i].points = points[k];
            ++i;
        }
        ++k;
    }
}

void melangerPaquet(Carte paquet[], int taille) {
    time_t t;
    time(&t);
    
    srand((unsigned int)t);

    for (int i = taille - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Carte temp = paquet[i];
        paquet[i] = paquet[j];
        paquet[j] = temp;
    }
}

void showpaqueta(Carte paquet[], int nb) {
    for (int i = 0; i < nb; ++i) {
        cout << paquet[i].lettre;
    }
    cout << endl;
}

void showPlateau(Plateau& plateau) {
    for (int i = 0; i < plateau.taille; i++)
    {
        cout << i + 1 << " - " << plateau.list[i] << endl;
    }
    
}

void distribuerCartes(Carte paquet[], int taille, Joueur joueurs[], int nbJoueurs, int cartesParJoueur) {
    int indexCarte = 0;

    for (int i = 0; i < nbJoueurs; ++i) {
        if (joueurs[i].enLice)
        {
        
            for (int j = 0; j < cartesParJoueur; ++j) {
                joueurs[i].main[j] = paquet[indexCarte];
                indexCarte++;
            }
            joueurs[i].nombreCartes = cartesParJoueur;
        }
        else
            joueurs[i].nombreCartes = 0;
    }
}

void faireTalon(Pile& talon ,Carte paquet[], int indexCartesRestantes)  {
    
    initialiser(talon, NbrCartes - indexCartesRestantes);

    for (int i = indexCartesRestantes; i < NbrCartes; ++i) {
        empiler(talon, paquet[i]);
    }
}

void faireExpose(Pile& exposer, Pile& talon) {
    initialiser(exposer, talon.capacite);
    empiler(exposer, sommet(talon));
    depiler(talon);
}

void ajouterMot(Plateau& plateau, const char* mot) {

    // Allouer de la mémoire pour stocker le mot
    plateau.list[plateau.taille] = new char[strlen(mot) + 1];
    strcpy(plateau.list[plateau.taille], mot);

    // Augmenter la taille du plateau
    plateau.taille++;
}