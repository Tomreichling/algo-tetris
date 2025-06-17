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


// void affichageSupp() {
//     //dans cette fonction on a tous les affichages supplémentaire a la grille
//     //barre séparant les deux parties

//     couleurCourante(0, 0, 0);
//     ligne(largeurFenetre() / 2, 40, largeurFenetre() / 2, hauteurFenetre() - 40);
// }

void afficherCarreauEnnemi(int x, int y, char couleur) {
    int marge = 40;
    int hauteur = hauteurFenetre() - 80;
    int taille_carreau = hauteur / LIGNES;
    int taille_droite = largeurFenetre() - marge - (taille_carreau * COLONNES);

    //on prend les coordonnées des carreaux a colorier
    int posXD = x * taille_carreau;
    int posYD = (LIGNES - y) * taille_carreau;
    int posXA = (x+1) * taille_carreau;
    int posYA = (LIGNES - y - 1) * taille_carreau;

    epaisseurDeTrait(3);
    switch (couleur) {
        case 1:
            couleurCourante(240, 240, 0); //jaune
            break;
        case 2:
            couleurCourante(160, 0, 240); //violet
            break;
        case 3:
            couleurCourante(240, 160, 0); //orange
            break;
        case 4:
            couleurCourante(0, 240, 240); //turquoise
            break;
        case 5:
            couleurCourante(0, 0, 220); //bleu
            break;
        case 6:
            couleurCourante(0, 220, 0); //vert
            break;
        case 7:
            couleurCourante(220, 0, 0);//rouge
            break;
        case 8:
            couleurCourante(150, 150, 150); //gris previsualisation
            break;
    }
    rectangle(taille_droite + posXD + 1, marge + posYD - 1, taille_droite + posXA - 1, marge + posYA + 1);
    switch (couleur) {
        case 1:
            couleurCourante(255, 255, 0); //jaune
            break;
        case 2:
            couleurCourante(180, 0, 255); //violet
            break;
        case 3:
            couleurCourante(255, 180, 0); //orange
            break;
        case 4:
            couleurCourante(0, 255, 255); //turquoise
            break;
        case 5:
            couleurCourante(0, 0, 255); //bleu
            break;
        case 6:
            couleurCourante(0, 255, 0); //vert
            break;
        case 7:
            couleurCourante(255, 0, 0);//rouge
            break;
        case 8:
            couleurCourante(170, 170, 170); //gris previsualisation
            break;
    }
    rectangle(taille_droite + posXD + 10, marge + posYD - 10, taille_droite + posXA - 10, marge + posYA + 10);
}