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

void affichageBarresScroll(DonneesImageRGBA *gemme, DonneesImageRGBA *gemmeRouge) {
    int marge = 40;
    int hauteur = hauteurFenetre() - 80;
    int taille_carreau = hauteur / LIGNES;
    int tailleGrille = (2 * marge) + (taille_carreau * COLONNES);
    couleurCourante(150, 150, 150);

    char score[100], scoreEnnemi[100];
    int static dernier = -1;
    float palier;
    float xbarre = (3.2 * marge) + tailleGrille + (taille_carreau * COLONNES);
    float proportion_score;
    
    //on met les memes plaiers que pour le jeu
    //et en meme temps on fait notre score
    if (jeu.score < 500) {
        palier = 500;
        proportion_score = jeu.score / palier;
        sprintf(score, "%d / 500", jeu.score);  
        demandeTemporisation(1300);
    } 
    else if (jeu.score < 2000) {
        palier = 2000;
        proportion_score = jeu.score / palier;
        sprintf(score, "%d / 2000", jeu.score);
        demandeTemporisation(1000); 
    } 
    else if (jeu.score < 5000) {
        palier = 5000;
        proportion_score = jeu.score / palier;
        sprintf(score, "%d / 5000", jeu.score);
        demandeTemporisation(700); 
    } 
    else {
        palier = 10000;
        proportion_score = jeu.score / palier;
        sprintf(score, "%d / 10000", jeu.score);
        demandeTemporisation(300); 
    }

    if (proportion_score > 1) {
    proportion_score = 1;
    }   
    
    //je met le if car sinon la barre se retrouve sur la grille
    if (largeurFenetre() != 1200 && hauteurFenetre() != 800) {
        rectangle(tailleGrille - 30 + gemme->largeurImage / 2, hauteur, xbarre, hauteur - 70); //barre du haut (la notre)
        rectangle(tailleGrille - 30 + gemmeRouge->largeurImage / 2, 2 * marge, xbarre, 4 * marge); //barre du bas (ennemi)

        //on affiche la barre de score qui se remplie en fonction de la proportion score/score_max
        couleurCourante(95, 0, 60); 
        rectangle((tailleGrille - 30 + gemme->largeurImage / 2) + 20, hauteur, (tailleGrille - 30 + gemme->largeurImage / 2) + ((xbarre - (tailleGrille - 30 + gemme->largeurImage / 2) - marge) * proportion_score), hauteur - 70); 
         
        //il faut faire la meme chose pour la barre ennemi


        //affichage des gemmes sur les barres de scores
        //affichage de notre gemme
        couleurCourante(255, 255, 255);
        ecrisImageARVB(
                tailleGrille - 30, 
                ((2 * hauteur - 70) / 2) - (gemme->hauteurImage / 2), 
                gemme->largeurImage, 
                gemme->hauteurImage, 
                (int*) gemme->donneesRGBA
            );
        
        //affichage de la gemme ennemi (rouge)
        ecrisImageARVB(
                tailleGrille - 30, 
                2.5 * marge + ((-gemmeRouge->hauteurImage + marge) / 2), 
                gemmeRouge->largeurImage, 
                gemmeRouge->hauteurImage, 
                (int*) gemmeRouge->donneesRGBA
            );
    }

    //on affiche notre score de partie
    couleurCourante(255, 255, 255);
    afficheChaine(score, 50, tailleGrille + 130, hauteur - 55);
    
    //on affiche notre score ennemi
    couleurCourante(255, 255, 255);
    afficheChaine(score, 50, tailleGrille + 130, 2.5 * marge);

    //on fait l'animation de scintillement
    if (palier != dernier && dernier != -1) {
        lancer_scintillement();
    }
    dernier = palier;
}