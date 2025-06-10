#include "../tetris.h"


void affichageJeu() {
    int marge = 40;
    effaceFenetre (255, 255, 255);
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(3);
    
    int hauteur = hauteurFenetre() - 80;
    int taille_carreau = hauteur / LIGNES;

    // ligne(marge , marge, taille_carreau * COLONNES, 0);
    // ligne(marge, marge, marge, hauteur);

    for (int i = 0; i <= LIGNES; i++) {
        ligne(marge, marge + (i * taille_carreau), marge + (taille_carreau * COLONNES), marge + (i * taille_carreau));
    }

    for (int j = 0; j <= COLONNES; j++) {
        ligne(marge + (j * taille_carreau), marge, marge + (j * taille_carreau), marge + (taille_carreau * LIGNES));
    }
}


void afficherCarreau(int x, int y, char couleur) {
    int marge = 40;
    int hauteur = hauteurFenetre() - 80;
    int taille_carreau = hauteur / LIGNES;

    int posXD = x * taille_carreau;
    int posYD = (LIGNES - y) * taille_carreau;
    int posXA = (x+1) * taille_carreau;
    int posYA = (LIGNES - y - 1) * taille_carreau;

    epaisseurDeTrait(3);
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
    rectangle(marge + posXD + 1, marge + posYD - 1, marge + posXA - 1, marge + posYA + 1);
}


void afficherTitre(int y, int x) {
    int hauteur = hauteurFenetre();
    int taille_carreau = hauteur / LIGNES;
    int taille_droite = largeurFenetre() - (taille_carreau * COLONNES);
    int Dcarreau_droite = largeurFenetre() - taille_droite;

    couleurCourante(255, 255, 255);
    rectangle(Dcarreau_droite, hauteur, largeurFenetre(), 0);
    //au dessus est la partie pour obtenir les coordonnées de la partie de droite
    //en dessous l'endroit ou on met le titre
    couleurCourante(0, 0, 0);
    afficheChaine("TETRISEN", 89, Dcarreau_droite + (taille_droite / 3), hauteur - (hauteur / 5));
}

// void afficherProchainePiece(Tétrominos piece) {
//     int hauteur = hauteurFenetre();
//     int taille_carreau = hauteur / LIGNES;
//     int taille_droite = largeurFenetre() - (taille_carreau * COLONNES);
//     int Dcarreau_droite = largeurFenetre() - taille_droite;

// }

// affiche une aide pour les touches
void afficherAides() {
    int hauteur = hauteurFenetre();
    int taille_carreau = hauteur / LIGNES;
    int taille_droite = largeurFenetre() - (taille_carreau * COLONNES);
    int Dcarreau_droite = largeurFenetre() - taille_droite;
    int marge = 20;
    int taille_text;

    //trait de séparation entre les deux parties
    couleurCourante(0, 0, 0);
    ligne(Dcarreau_droite + (taille_droite / 2), hauteur / 4, Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 4));

    //on va afficher les regles des différentes touches 
    //le if parce que c'est responsive
    if (hauteurFenetre() == 800 && largeurFenetre() == 1200) {
        taille_text = 13;
        afficheChaine("Q/Fleche de gauche pour se deplacer a gauche", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3));
        afficheChaine("D/Fleche de droite pour se deplacer a droite", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3) - 50);
        afficheChaine("S/Fleche du bas pour accelerer", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3) - 100);
        afficheChaine("A pour tourner", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3) - 150);
        afficheChaine("Espace pour sauter", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3) - 200);    
    }
    else {
        taille_text = 23;
        afficheChaine("Q/Fleche de gauche pour se deplacer a gauche", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3));
        afficheChaine("D/Fleche de droite pour se deplacer a droite", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3) - 100);
        afficheChaine("S/Fleche du bas pour accelerer", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3) - 200);
        afficheChaine("A pour tourner", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3) - 300);
        afficheChaine("Espace pour sauter", taille_text, marge + Dcarreau_droite + (taille_droite / 2), hauteur - (hauteur / 3) - 400);
    }
}

// affiche le score du joueur, le temps écoulé (utiliser)
void afficherScore() {
    int hauteur = hauteurFenetre();
    int taille_carreau = hauteur / LIGNES;
    int taille_droite = largeurFenetre() - (taille_carreau * COLONNES);
    int Dcarreau_droite = largeurFenetre() - taille_droite;

    couleurCourante(0, 0, 0);
    afficheChaine("SCORE : 1000000", 30, Dcarreau_droite + (taille_droite / 10), hauteur / 7);
    afficheChaine("7:07", 30, Dcarreau_droite + taille_droite - (taille_droite / 6), hauteur / 7); //j'ai mis le temps de jeu dans le score

    couleurCourante(150, 150, 150);
    rectangle(Dcarreau_droite + (taille_droite / 10), hauteur / 8, Dcarreau_droite + taille_droite - (taille_droite / 10), hauteur / 12);
}

void afficherPrevisualisation(int x, int y, char couleur) {
    int marge = 40;
    int hauteur = hauteurFenetre() - 80;
    int taille_carreau = hauteur / LIGNES;

    int posXD = x * taille_carreau;
    int posYD = (LIGNES - 19) * taille_carreau;
    int posXA = (x+1) * taille_carreau;
    int posYA = (LIGNES - 19 - 1) * taille_carreau;

    epaisseurDeTrait(3);
    switch (couleur) {
        case 1:
            couleurCourante(0, 230, 230);
            break;
        case 2:
            couleurCourante(220, 140, 0);
            break;
        case 3:
            couleurCourante(0, 0, 220);
            break;
        case 4:
            couleurCourante(220, 220, 0);
            break;
        case 5:
            couleurCourante(140, 0, 220);
            break;
        case 6:
            couleurCourante(0, 220, 0);
            break;
        case 7:
            couleurCourante(220, 0, 0);
            break;
    }
    rectangle(marge + posXD + 1, marge + posYD - 1, marge + posXA - 1, marge + posYA + 1);

}