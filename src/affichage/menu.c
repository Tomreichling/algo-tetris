#include "../tetris.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

void afficheMenu(DonneesImageRGBA *demarrer,  DonneesImageRGBA *mutlijoueur , DonneesImageRGBA *quitter, DonneesImageRGBA *titre, DonneesImageRGBA *gemme) {
    effaceFenetre(255, 255, 255);
    int tailleCarreau = hauteurFenetre() / 25;

// placement des tétrominos statique de déco
    couleurCourante(0,200,255);
    epaisseurDeTrait(3);
    rectangle(14*tailleCarreau,17*tailleCarreau, 18*tailleCarreau ,18*tailleCarreau);

    couleurCourante(240, 0, 0);
    rectangle(5*tailleCarreau,3*tailleCarreau, 8*tailleCarreau ,4*tailleCarreau);
    rectangle(6*tailleCarreau,4*tailleCarreau, 7*tailleCarreau ,5*tailleCarreau);

    couleurCourante(240, 160, 0);
    rectangle(3*tailleCarreau,14*tailleCarreau, 4*tailleCarreau ,17*tailleCarreau);
    rectangle(4*tailleCarreau,16*tailleCarreau, 5*tailleCarreau ,17*tailleCarreau); 

    couleurCourante(160, 0, 240);
    rectangle(25*tailleCarreau,6*tailleCarreau, 28*tailleCarreau ,7*tailleCarreau);
    rectangle(25*tailleCarreau,7*tailleCarreau, 26*tailleCarreau ,8*tailleCarreau); 

    couleurCourante(0, 240, 0);
    rectangle(30*tailleCarreau,16*tailleCarreau, 31*tailleCarreau ,19*tailleCarreau);
    rectangle(29*tailleCarreau,17*tailleCarreau, 30*tailleCarreau ,18*tailleCarreau); 

    couleurCourante(0, 0, 0);
    epaisseurDeTrait(5);

// recupération des données de largeur et hauteur fenêtre 
    for (int i = 0; i < largeurFenetre(); i += tailleCarreau) {
        ligne(i, 0, i, hauteurFenetre());
    }
    
    for (int j = 0; j < hauteurFenetre(); j += tailleCarreau ){
        ligne(0, j, largeurFenetre(), j);
    }

   

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

        if (jeu.score != 0) {
            char gemmes[15];
            sprintf(gemmes, "%d", jeu.score);
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

    //affichage des tetrominos de déco 
        



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
