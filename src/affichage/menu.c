#include "../tetris.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

void afficheMenu(DonneesImageRGB *image) {
    effaceFenetre(255, 255, 255);
    
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(10);
   
    for (int i=0; i <  largeurFenetre(); i+=45){
        ligne(i, 0, i, hauteurFenetre());
    }
    
   for (int j=0; j < hauteurFenetre() ; j+=45){
        ligne(0, j, largeurFenetre() , j);
    }

    if (image != NULL) 
			{
			    ecrisImage(largeurFenetre()/2-150, hauteurFenetre()/2-75, image->largeurImage, image->hauteurImage, image->donneesRGB);
			}


    couleurCourante(0, 0, 128);
    epaisseurDeTrait(2);
    afficheChaine("Appuyez sur Espace pour Jouer", 20, largeurFenetre()/2-150,  hauteurFenetre()/3-80);
}
