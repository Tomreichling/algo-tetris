#include "../tetris.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

void afficheMenu(DonneesImageRGB *image) {
    effaceFenetre(255, 255, 255);
    
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(10);
   
    for (int i=0; i <  largeurFenetre(); i+=50){
    ligne(i, 0, i, hauteurFenetre());
    }
   for (int j=0; j < hauteurFenetre() ; j+=50){
    ligne(0, j, largeurFenetre() , j);
    }

    couleurCourante(0, 0, 0);
    epaisseurDeTrait(5);
    afficheChaine("Tetris", 25, largeurFenetre()/2,hauteurFenetre()/2 );

    if (image != NULL) 
			{
			    ecrisImage(largeurFenetre()/2-125, hauteurFenetre()/2-25, image->largeurImage, image->hauteurImage, image->donneesRGB);
			}


    couleurCourante(0, 0, 128);
    epaisseurDeTrait(2);
    afficheChaine("Appuyez sur Espace pour Jouer", 20, 100, 55);
}
