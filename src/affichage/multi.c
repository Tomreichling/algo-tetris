#include "../tetris.h"

void affichageEnnemi() {
    int marge = 40;
    couleurCourante(255, 0, 0);
    epaisseurDeTrait(3);
    
    int hauteur = hauteurFenetre() - 80;
    int taille_carreau = hauteur / LIGNES;
    int taille_droite = largeurFenetre() - marge - (taille_carreau * COLONNES);
    
    for (int i = 0; i <= LIGNES; i++) {
        ligne(taille_droite, marge + (i * taille_carreau), taille_droite + (taille_carreau * COLONNES), marge + (i * taille_carreau));
    }
    for (int j = 0; j <= COLONNES; j++) {
        ligne(taille_droite + (j * taille_carreau), marge, taille_droite + (j * taille_carreau), marge + (taille_carreau * LIGNES));
    }
}


void affichageSupp() {
    
}