#include "../tetris.h"


void affichageJeu() {
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(2);
    int largeur = largeurFenetre();
    int longueur = longueurFenetre();
    int taille_carreau = largeur / LIGNES;

    ligne(0 ,0, taille_carreau * COLONNES, 0);
    ligne(0, 0, largeur, 0);

    for (int i = 0; i < LIGNES; i++) {
        ligne(0, i + taille_carreau, taille_carreau * COLONNES, 0);
    }

    for (int j = 0; j < COLONNES; j++) {
        ligne(j + taille_carreau, 0, 0, largeur);
    }

}