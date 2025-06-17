#include "../tetris.h"

Tétrominos pieces_menu[NB_PIECES_MENU];

void afficheGrilleMenu() {
    effaceFenetre(255, 255, 255);
    int posCarreau = hauteurFenetre() / 25;

    couleurCourante(0, 0, 0);
    epaisseurDeTrait(3);

    // recupération des données de largeur et hauteur fenêtre 
    for (int i = 0; i < largeurFenetre(); i += tailleCarreau) {
        ligne(i, 0, i, hauteurFenetre());
    }
    
    for (int j = 0; j < hauteurFenetre(); j += posCarreau ){
        ligne(0, j, largeurFenetre(), j);
    }
}

void afficheMenu(DonneesImageRGBA *demarrer,  DonneesImageRGBA *mutlijoueur , DonneesImageRGBA *quitter, DonneesImageRGBA *titre, DonneesImageRGBA *gemme) {
    if (demarrer != NULL && mutlijoueur != NULL && quitter != NULL) {
        int max_x = largeurFenetre();
        int max_y = hauteurFenetre();
        int padding = 64;


    // affichage du menu statique gemmes

        // base fond du menu gemme
        couleurCourante(80, 80, 80); 
        rectangle(0,(max_y-max_y/8) - gemme->hauteurImage, (max_x/6) - (gemme->largeurImage/2), (max_y-max_y/8));

        //affichage du nombre de gemmes
        couleurCourante(255, 255, 255);
        epaisseurDeTrait(5);

        printf("%d", jeu.gemmes);
        if (jeu.gemmes != 0) {
            char gemmes[15];
            sprintf(gemmes, "%d", jeu.gemmes);
            afficheChaine(gemmes, hauteurFenetre()/20, ((max_x/6) - (gemme->largeurImage/2))/5,(max_y-max_y/8) - gemme->hauteurImage*0.7);
        }
        else {
            afficheChaine(" 0", hauteurFenetre()/20, ((max_x/6) - (gemme->largeurImage/2))/5,(max_y-max_y/8) - gemme->hauteurImage*0.7);

        }
        
        //nombre de gemmes affichées
        ecrisImageARVB(
            ((max_x/6) - gemme->largeurImage), 
            ((max_y-max_y/8) - gemme->hauteurImage), 
            gemme->largeurImage, gemme->hauteurImage, (int*) gemme->donneesRGBA
        );

        //affichage titre à gauche
        ecrisImageARVB(
            ((max_x/2) - titre->largeurImage), 
            ((max_y/2) - titre->hauteurImage), 
            titre->largeurImage, titre->hauteurImage, (int*) titre->donneesRGBA
        );



    // affichage des 3 boutons
	    ecrisImageARVB(
            (max_x - padding - demarrer->largeurImage), 
            (max_y - padding - demarrer->hauteurImage), 
            demarrer->largeurImage, demarrer->hauteurImage, (int*) demarrer->donneesRGBA
        );
        ecrisImageARVB(
            (max_x - padding - mutlijoueur->largeurImage),
            (max_y / 2 - mutlijoueur->hauteurImage / 2), 
            mutlijoueur->largeurImage, mutlijoueur->hauteurImage, (int*) mutlijoueur->donneesRGBA
        );
        ecrisImageARVB(
            (max_x - padding - quitter->largeurImage),
            (padding), 
            quitter->largeurImage, quitter->hauteurImage, (int*) quitter->donneesRGBA
        );
	}

    //affichage des droits du projets + signature projet etudiant
    couleurCourante(0, 0, 15);
    epaisseurDeTrait(3);
    afficheChaine("Projet etudiant 2025, tous droits reserves", hauteurFenetre()/50, largeurFenetre()-largeurFenetre()/3,  28);
}
void afficherCarreauMenu(int x, int y, char couleur) {
    int taille_carreau = hauteurFenetre() / 25;

    //on prend les coordonnées des carreaux a colorier
    int posXD = x * taille_carreau;
    int posYD = (25 - y) * taille_carreau;
    int posXA = (x + 1) * taille_carreau;
    int posYA = (25 - y - 1) * taille_carreau;

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
    rectangle(posXD + 1, posYD - 1, posXA - 1, posYA + 1);
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
    rectangle(posXD + 8, posYD - 8, posXA - 8, posYA + 8);
}

void afficherPiecesMenu() {
    for(int n = 0; n < NB_PIECES_MENU; n++) {
        Tétrominos *piece = &pieces_menu[n];
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int x = piece->x + i;
                int y = piece->y + j;
                if(piece->grille[i][j] == 0) {
                    continue;
                }
                afficherCarreauMenu(x, y, piece->grille[i][j]);
            }
        }
    }
}