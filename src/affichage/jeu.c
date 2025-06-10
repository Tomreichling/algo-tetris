#include "../tetris.h"


void affichageJeu() {
    effaceFenetre (255, 255, 255);
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(3);
    
    int hauteur = hauteurFenetre();
    int taille_carreau = hauteur / LIGNES;

    ligne(0 ,0, taille_carreau * COLONNES, 0);
    ligne(0, 0, 0, hauteur);

    for (int i = 0; i < LIGNES + 1; i++) {
        ligne(0, i * taille_carreau, taille_carreau * COLONNES, i * taille_carreau);
    }

    for (int j = 0; j < COLONNES + 1; j++) {
        ligne(j * taille_carreau, 0, j * taille_carreau, taille_carreau * LIGNES);
    }
}


void afficherCarreau(int x, int y, char couleur) {

    int hauteur = hauteurFenetre();
    int taille_carreau = hauteur / LIGNES;

    int posXD = x * taille_carreau;
    int posYD = (LIGNES - y) * taille_carreau;
    int posXA = (x+1) * taille_carreau;
    int posYA = (LIGNES - y - 1) * taille_carreau;

    epaisseurDeTrait(2);
    switch (couleur) {
        case 1:
            couleurCourante(0, 240, 240);
            break;
        case 2:
            couleurCourante(240, 160, 0);
            break;
        case 3:
            couleurCourante(0, 0, 240);
            break;
        case 4:
            couleurCourante(240, 240, 0);
            break;
        case 5:
            couleurCourante(160, 0, 240);
            break;
        case 6:
            couleurCourante(0, 240, 0);
            break;
        case 7:
            couleurCourante(240, 0, 0);
            break;
    }
    rectangle(posXD + 1, posYD + 1, posXA - 1, posYA - 1);
}

void afficherTitre(int y, int x) {
    int hauteur = hauteurFenetre();
    int taille_carreau = hauteur / LIGNES;
    int taille_droite = largeurFenetre() - (taille_carreau * COLONNES);
    int Dcarreau_droite = largeurFenetre() - taille_droite;

    couleurCourante(255, 0, 0);
    rectangle(Dcarreau_droite, hauteur, largeurFenetre(), 0);
    //au dessus est la partie pour obtenir les coordonnées de la partie de droite

}