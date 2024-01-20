#include "Commande.h"

void recommencez() {
    cout << endl << "Coup invalide, recommencez" << endl;
}

bool commandeT(Joueur& joueur, Pile& talon, Pile& exposer) {
    char arg[MAX_STRING_LENGTH];
    cin >> arg;
    if (strlen(arg) != 1)
    {
        return false;
    }

    for (int i = 0; i < joueur.nombreCartes ; i++)
    {
        if(joueur.main[i].lettre == arg[0])
        {
            empiler(exposer, joueur.main[i]);
            joueur.main[i] = sommet(talon);
            depiler(talon);
            
            if (estVide(talon))
            {
                //recuperer les cartes exposées et les empiler dans le talon quand il est vide
                Carte cartes[talon.capacite];
                int j = 0;
                while (!estVide(exposer))
                {
                    cartes[j] = sommet(exposer);
                    depiler(exposer);
                    j++;
                }
                melangerPaquet(cartes, j);

                empiler(talon, cartes[0]);
                for (; j > 1; j--)
                {
                    empiler(talon, cartes[j]);
                }
            }
            return true;
        }
    }

    return false;
}

bool commandeE(Joueur& joueur, Pile& talon, Pile& exposer) {
    char lettre;
    cin >> lettre;

    for (int i = 0; i < joueur.nombreCartes; i++) {
        if (joueur.main[i].lettre == lettre) {
            Carte temp;
            temp = joueur.main[i];
            joueur.main[i] = sommet(exposer);
            depiler(exposer);
            empiler(exposer, temp);

            return true;
        }
    }
    return false;
}


bool commandeP(Dictionnaire& dictionnaire, Joueur& joueur, Plateau& plateau) {
    char mot[MAX_STRING_LENGTH];
    cin >> mot;

    // Vérifier que les lettres du mot sont détenues par le joueur
    bool dejaUtilise[joueur.nombreCartes];
    for (int i = 0; i < joueur.nombreCartes; ++i) {
        dejaUtilise[i] = false;
    }

    for (int i = 0; i < strlen(mot); ++i) {
        bool lettreTrouvee = false;

        for (int j = 0; j < joueur.nombreCartes; ++j) {
            if (joueur.main[j].lettre == mot[i] && !dejaUtilise[j]) {
                dejaUtilise[j] = true;
                lettreTrouvee = true;
                j = joueur.nombreCartes;
            }
        }
        if (!lettreTrouvee) {
            return false;
        }
    }

    if(!rechercheDichotomique(dictionnaire, mot)) {
        cout << "Mot invalide, vous passez votre tour" << endl;
        joueur.scores+=3;
        return true;
    }

    // Ajouter le mot au plateau
    ajouterMot(plateau, mot);

   int indexNouvelleMain = 0;

    for (int i = 0; i < joueur.nombreCartes; ++i) {
        if (!dejaUtilise[i]) {
            joueur.main[indexNouvelleMain] = joueur.main[i];
            ++indexNouvelleMain;
        }
    }
    joueur.nombreCartes = indexNouvelleMain;

    return true;
}


bool commandeR(Dictionnaire& dictionnaire, Joueur& joueur, Plateau& plateau) {
    int numero;
    char nouveauMot[MAX_STRING_LENGTH];
    cin >> numero >> nouveauMot;

    // Vérifier si le numéro est valide
    if (numero < 1 || numero > plateau.taille || strcmp(plateau.list[numero - 1], nouveauMot) == 0 || strlen(nouveauMot) != strlen(plateau.list[numero - 1])) {
        return false;
    }

    // Vérifier si le nouveau mot peut être construit à partir du mot actuel
    int emplacementDeRemplacement[joueur.nombreCartes];
    for (int i = 0; i < joueur.nombreCartes; ++i) {
        emplacementDeRemplacement[i] = -1;
    }

    char* motActuel = plateau.list[numero - 1];
    for (int i = 0; i < strlen(motActuel); ++i) {
        if (motActuel[i] != nouveauMot[i]) {
            bool lettreTrouvee = false;
            for (int j = 0; j < joueur.nombreCartes; ++j) {
                if (joueur.main[j].lettre == nouveauMot[i] && emplacementDeRemplacement[j] == -1) {
                    emplacementDeRemplacement[j] = i;
                    lettreTrouvee = true;
                    j = joueur.nombreCartes;
                }
            }
            if (!lettreTrouvee) {
                return false;
            }
        }
    }

    if (!rechercheDichotomique(dictionnaire, nouveauMot)) {
        cout << "Mot invalide, vous passez votre tour" << endl;
        joueur.scores+=3;
        return true;
    }

    int points[] = { 10, 2, 8, 6, 10, 2, 4, 8, 10, 6, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 2, 4, 2 };
    //remplacer les cartes du joueur
    for (int i = 0; i < joueur.nombreCartes; i++)
    {
        if(emplacementDeRemplacement[i] != -1)
        {
            char temp = joueur.main[i].lettre;
            joueur.main[i].lettre = motActuel[emplacementDeRemplacement[i]];
            joueur.main[i].points = points[motActuel[emplacementDeRemplacement[i]] - 'A']; //vue que c'est le char ascii ca permet de le mettre a 0 et donc ca ce suit apres genre B c'est 1 ect...
            plateau.list[numero - 1][emplacementDeRemplacement[i]] = temp;
        }
    }

    return true;
}

bool commandeC(Dictionnaire& dictionnaire, Joueur& joueur, Plateau& plateau) {
    int numero;
    char nouveauMot[MAX_STRING_LENGTH];
    cin >> numero >> nouveauMot;
    int tailleNouveau = strlen(nouveauMot);

    if (numero < 1 || numero > plateau.taille || strcmp(plateau.list[numero - 1], nouveauMot) == 0 || tailleNouveau == strlen(plateau.list[numero - 1])) {
        return false;
    }

    // Récupérer le mot actuel sur le plateau
    char* motActuel = plateau.list[numero - 1];

    int indexMotActuel = 0;

    bool dejaUtilise[joueur.nombreCartes];
    for (int i = 0; i < joueur.nombreCartes; ++i) {
        dejaUtilise[i] = false;
    }

    // Parcourir chaque lettre du nouveau mot
    for (int i = 0; i < tailleNouveau; ++i) {
        if (nouveauMot[i] == motActuel[indexMotActuel]) {
            indexMotActuel++;
        }
        else {
            //chercher la lettre dans la main du joueur
            bool lettreTrouvee = false;
            for (int j = 0; j < joueur.nombreCartes; ++j) {
                if (joueur.main[j].lettre == nouveauMot[i] && !dejaUtilise[j]) {
                    dejaUtilise[j] = true;
                    lettreTrouvee = true;
                    j = joueur.nombreCartes;
                }
            }
            if (!lettreTrouvee) {
                return false;
            }
        }
    }

    if (!rechercheDichotomique(dictionnaire, nouveauMot)) {
        cout << "Mot invalide, vous passez votre tour" << endl;
        joueur.scores+=3;
        return true;
    }

    int indexNouvelleMain = 0;
    int ancienneMain = joueur.nombreCartes;
    for (int i = 0; i < ancienneMain; ++i) {
        if (!dejaUtilise[i]) {
            joueur.main[indexNouvelleMain] = joueur.main[i];
            ++indexNouvelleMain;
        }
    }

    joueur.nombreCartes = indexNouvelleMain;

    strcpy(plateau.list[numero - 1], nouveauMot);

    return true;

}

bool commandeValide(Dictionnaire& dictionnaire, char command[], Joueur& joueur, Plateau& plateau, Pile& talon, Pile& exposer) {

    bool valide;
    if(strlen(command) != 1 )
        valide = false;
    
    else if(command[0] == 'T')
        valide = commandeT(joueur, talon, exposer);

    else if (command[0] == 'E')
        valide = commandeE(joueur, talon, exposer);

    else if (command[0] == 'P')
        valide = commandeP(dictionnaire, joueur, plateau);

    else if (command[0] == 'R')
        valide = commandeR(dictionnaire, joueur, plateau);

    else if (command[0] == 'C')
        valide = commandeC(dictionnaire, joueur, plateau);

    else
        valide = false;

    if(!valide)
        recommencez();
        
    char videligne[MAX_STRING_LENGTH];
    fgets(videligne, sizeof(videligne), stdin);

    return valide;
      
}