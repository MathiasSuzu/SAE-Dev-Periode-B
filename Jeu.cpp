#include "Jeu.h"

int calculateurNBJoueur(int nbDargs, const char* listDargs[]) {

    if (nbDargs < 2) { // c'est pas inférieur ou = c'est juste inférieur ici sinon tu rentres jamais dans ton else // bien vue
        //cout << "Le nombre de joueur n'a pas été spécifié en paramètre." << endl << "Il sera donc de 2." << endl;
        return 2;
    }
    else if(strlen(listDargs[1]) == 1  && (listDargs[1][0] == '2' || listDargs[1][0] == '3' || listDargs[1][0] == '4')) 
        return atoi(listDargs[1]);
        
    else {
        //cout << "Le nombre de joueur est invalide." << endl << "Il sera donc de 2." << endl;
        return 2;
    }  
}

void lancerPartie(Dictionnaire& dictionnaire, Joueur joueurs[], Plateau& plateau, Pile& talon, Pile& exposer , int& nbJoueur) {
    cout << "(Commandes valides : TEPRC)" << endl << endl;
    int nbJoueurEnLice = nbJoueur;
    int tourTerminer = -1;
    bool partieTerminee = false;

    while (!partieTerminee)
    {
        do {
            tourTerminer = lancerUnTour(dictionnaire, joueurs, plateau, talon, exposer, nbJoueur, tourTerminer);
        } while (tourTerminer == -1);

        cout << "Le tour est fini" << endl
            << "* Scores" << endl;

        for (int i = 0; i < nbJoueur; i++)
        { 
            if (joueurs[i].enLice)
            {
                for (int j = 0; j < joueurs[i].nombreCartes; j++)
                {
                    joueurs[i].scores += joueurs[i].main[j].points;
                }
                if(joueurs[i].scores > SCORE_DEFAITE)
                {
                    joueurs[i].enLice = false;
                    nbJoueurEnLice--;
                }

                
            }
            
            cout << "Joueur " << i + 1 << " : " << joueurs[i].scores << " points" << endl;
            
        }
        cout << endl;

        while (!estVide(talon))
                depiler(talon);

        while (!estVide(exposer))
            depiler(exposer);
            
        detruire(talon);
        detruire(exposer);

        if(nbJoueurEnLice > 1)
        {
            Carte paquet[NbrCartes];
            initTalon(paquet);
            melangerPaquet(paquet, NbrCartes);
            distribuerCartes(paquet, NbrCartes, joueurs, nbJoueur, MAX_CARTES);

            faireTalon(talon, paquet, nbJoueurEnLice * MAX_CARTES);
            faireExpose(exposer, talon);
        }

        else {
            cout << "La partie est finie" << endl;
            partieTerminee = true;
        }
    }
    
}

int lancerUnTour(Dictionnaire& dictionnaire, Joueur joueurs[], Plateau& plateau, Pile& talon, Pile& exposer ,int& nbJoueur, int i) {
    i++; //position du joueur courant

    for (; i < nbJoueur; i++)
    {
        char command[MAX_STRING_LENGTH];
        do
        {
            if(joueurs->enLice) {
                if(joueurs[i].nombreCartes == 0)
                    return i;
                cout << "* Joueur " << i + 1 << " (" << sommet(exposer).lettre << ") ";
                showpaqueta(joueurs[i].main, joueurs[i].nombreCartes);
                showPlateau(plateau);
                cout << "> ";
                cin >> command;
            }
            else {
                i++;
            }
        } while (!commandeValide(dictionnaire, command, joueurs[i], plateau, talon, exposer));
        cout << endl;
    }

    return -1;
}