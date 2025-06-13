#include "../tetris.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

void afficheMenu(DonneesImageRGBA *demarrer,  DonneesImageRGBA *mutlijoueur , DonneesImageRGBA *quitter) {
    effaceFenetre(255, 255, 255);
    
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(5);
   
    for (int i = 0; i < largeurFenetre(); i += hauteurFenetre() / 20){
        ligne(i, 0, i, hauteurFenetre());
    }
    
    for (int j = 0; j < hauteurFenetre(); j += hauteurFenetre() / 20){
        ligne(0, j, largeurFenetre(), j);
    }

    if (demarrer != NULL && mutlijoueur != NULL && quitter != NULL) {
        int max_x = largeurFenetre();
        int max_y = hauteurFenetre();
        int padding = 64;

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

    couleurCourante(0, 0, 128);
    epaisseurDeTrait(2);
    afficheChaine("Appuyez sur Espace pour Jouer", 20, largeurFenetre()/2-150,  hauteurFenetre()/3-80);
}
