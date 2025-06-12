#include "../tetris.h"

void affichageJeu() {
    int marge = 40;
    effaceFenetre (255, 255, 255);
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(3);
    
    int hauteur = hauteurFenetre() - 80;
    int taille_carreau = hauteur / LIGNES;

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
            couleurCourante(0, 0, 240); //bleu
            break;
        case 6:
            couleurCourante(0, 240, 0); //vert
            break;
        case 7:
            couleurCourante(240, 0, 0);//rouge
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

void afficherProchainePiece(Tétrominos piece) {
    int hauteur = hauteurFenetre();
    int taille_carreau = hauteur / LIGNES;
    int taille_droite = largeurFenetre() - (taille_carreau * COLONNES);
    int Dcarreau_droite = largeurFenetre() - taille_droite; 
    int posXD, posYD, posXA, posYA, x = 0, y = 0;
    static char couleur = 0;

    couleurCourante(0, 0, 0);
    epaisseurDeTrait(2);
    for (int i = 0; i <= 4; i++) {
        ligne(Dcarreau_droite + (taille_droite / 5), (hauteur / 2.5) + (i * taille_carreau), Dcarreau_droite + (taille_droite / 5) + (taille_carreau * 4), (hauteur / 2.5) + (i * taille_carreau));
    }
    for (int j = 0; j <= 4; j++) {
        ligne(Dcarreau_droite + (taille_droite / 5) + (j * taille_carreau), hauteur / 2.5, Dcarreau_droite + (taille_droite / 5) + (j * taille_carreau), (hauteur / 2.5) + (4 * taille_carreau));
    }

    couleurCourante(255, 0, 0);
    for (int ki = 0; ki < 4; ki++) {
        for (int kj = 0; kj < 4; kj++) {
            if (piece.grille[ki][kj] != 0) {
                x = ki;
                y = kj;
                posXD = Dcarreau_droite + (taille_droite / 5) + x * taille_carreau;
                posYD = (hauteur / 2.5) + (3 - y) * taille_carreau;
                posXA = Dcarreau_droite + (taille_droite / 5) + (x + 1) * taille_carreau;
                posYA = (hauteur / 2.5) + (4 - y) * taille_carreau;
                couleur = piece.grille[ki][kj];
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
                        couleurCourante(0, 0, 240); //bleu
                        break;
                    case 6:
                        couleurCourante(0, 240, 0); //vert
                        break;
                    case 7:
                        couleurCourante(240, 0, 0);//rouge
                        break;
                }
                rectangle(posXD + 1, posYD + 1, posXA - 1, posYA - 1);
            }
        }
    } 
}


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
    char score[100];
    float xbarre = Dcarreau_droite + taille_droite - (taille_droite / 10);
    float proportion_score = jeu.score /100.0;

    if (jeu.score < 500) {
        proportion_score = jeu.score / 500.0;
        sprintf(score, "Score : %d / 500", jeu.score);    
    } 
    else if (jeu.score < 2000) {
        proportion_score = jeu.score / 2000.0;
        sprintf(score, "Score : %d / 2000", jeu.score);
    } 
    else if (jeu.score < 5000) {
        proportion_score = jeu.score / 5000.0;
        sprintf(score, "Score : %d / 5000", jeu.score);
    } 
    else {
        proportion_score = jeu.score / 10000.0;
        sprintf(score, "Score : %d / 10000", jeu.score);
    }

    couleurCourante(0, 0, 0);
    afficheChaine(score, 30, Dcarreau_droite + (taille_droite / 10), hauteur / 7);
    afficheChaine("7:07", 30, Dcarreau_droite + taille_droite - (taille_droite / 6), hauteur / 7); //j'ai mis le temps de jeu dans le score

    couleurCourante(150, 150, 150);
    rectangle(Dcarreau_droite + (taille_droite / 10), hauteur / 8, xbarre, hauteur / 12);

    if (proportion_score > 1) {
        proportion_score = 1;
    }
    
    couleurCourante(95, 0, 60);
    rectangle(Dcarreau_droite + (taille_droite / 10)+2, hauteur / 8-2, (Dcarreau_droite + (taille_droite / 10)+2)-(((Dcarreau_droite + (taille_droite / 10)+2)-xbarre) * proportion_score), (hauteur / 12)+2);

    


}

void afficherPrevisualisation(int x, int y, char couleur) { //refaire la fonctions pour les differents tetrominos
    int marge = 40;
    int hauteur = hauteurFenetre() - 80;
    int taille_carreau = hauteur / LIGNES;

    int posXD = x * taille_carreau;
    int posYD = (LIGNES - y) * taille_carreau;
    int posXA = (x+1) * taille_carreau;
    int posYA = (LIGNES - y - 1) * taille_carreau;

    epaisseurDeTrait(3);
    couleurCourante(100, 100, 100);
           
    rectangle(marge + posXD + 1, marge + posYD - 1, marge + posXA - 1, marge + posYA + 1);
}
