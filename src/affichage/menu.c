#include "../tetris.h"

#define LargeurFenetre 800
#define HauteurFenetre 600


void afficheMenu(DonneesImageRGB *image) {
    effaceFenetre(255, 255, 255);
    
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(10);
    //grille jusqu'à 15 (on modifiera si besoin)
    for (int i=0; i < hauteurFenetre() ; i+=20){
    ligne(i, 0, largeurFenetre(), 0);
    }
   for (int j=0; j < largeurFenetre() ; j+=20){
    ligne(0, j, 0, hauteurFenetre());
    }

    couleurCourante(0, 0, 0);
    epaisseurDeTrait(5);
    afficheChaine("Tetris", 25, hauteurFenetre()/2, largeurFenetre()/2);

    if (image != NULL) 
			{
			    ecrisImage(0, 0, image->largeurImage, image->hauteurImage, image->donneesRGB);
			}


    couleurCourante(0, 0, 128);
    epaisseurDeTrait(2);
    afficheChaine("Appuyez sur Espace pour Jouer", 20, 50, 15);
}
