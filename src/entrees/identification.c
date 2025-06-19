#include "../tetris.h"

void entreeNom() {

    if (caractereClavier() == 8) {
        jeu.nom[strlen(jeu.nom) - 1] = '\0';
    }
    if (strlen(jeu.nom) < 20 &&  caractereClavier() != 8 &&  caractereClavier() != 13 ){
        char caractere[2];
        caractere[0]=caractereClavier();
        caractere[1]='\0';
        strcat(jeu.nom, caractere);
    }

rafraichisFenetre();
}