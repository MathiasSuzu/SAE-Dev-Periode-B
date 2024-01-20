#include "Dictionnaire.h"

// On vérifie que le dictionnaire est bien ouvrable
void verifDico(Dictionnaire& dictionnaire) {
    ifstream fichier(dictionnaire.file, ios::ate);
    fichier.seekg(0, ios::end);
    dictionnaire.taille = fichier.tellg();
    fichier.close();
}

bool videChar(char& caractere) {
    return (caractere == ' ' || caractere == '\t' || caractere == '\n' || caractere == '\r' || caractere == '\v' || caractere == '\f');
}


long posDebut(ifstream& fichier, long position, long debut) {
    fichier.seekg(position, ios::beg);
    char c = fichier.get();
    while (!videChar(c) && position > debut)
    {
        position--;
        fichier.seekg(position, ios::beg);
        c = fichier.get();
    }
    position++;
    return position;
}

long posSuivant(ifstream& fichier, long position, long fin) {
    fichier.seekg(position, ios::beg);
    char c = fichier.get();
    
    while (!videChar(c) && position < fin)
    {
        position++;
        fichier.seekg(position, ios::beg);
        c = fichier.get();
    }
    position++;
    return position;
    
}

long posPrecedent(ifstream& fichier, long position, long debut) {
    position--;
    return posDebut(fichier, position, debut);
}

bool rechercheDichotomique(Dictionnaire& dictionnaire, const char motRecherche[]) {
    ifstream fichier(dictionnaire.file, ios::ate);
    long debut = 0;
    long fin = dictionnaire.taille;
    while (debut < fin - 1)
    {
        long milieu = (debut + fin) / 2;
        
        //trouver le premier caractère vide donc la fin du mot précédant
        milieu = posDebut(fichier, milieu, debut);

        char motTrouve[MAX_STRING_LENGTH];
        fichier.getline(motTrouve, MAX_STRING_LENGTH);
        int compare = strcmp(motTrouve, motRecherche); 
        // cout << motTrouve << " - " << debut << " - " << fin << endl;
        if (compare == 0)
        {
            fichier.close();
            return true;
        }
        else if (compare < 0)
            debut = posSuivant(fichier, milieu, fin);
        else
            fin = posPrecedent(fichier, milieu, debut);
        
    }
    fichier.close();
    return false;
}
