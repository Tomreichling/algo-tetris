#include "../tetris.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

void afficheMenu(DonneesImageRGB *image,  DonneesImageRGB *image2 , DonneesImageRGB *image3) {
    effaceFenetre(255, 255, 255);
    
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(5);
   
    for (int i=0; i <  largeurFenetre(); i+=hauteurFenetre()/20){
        ligne(i, 0, i, hauteurFenetre());
    }
    
   for (int j=0; j < hauteurFenetre() ; j+= hauteurFenetre()/20){
        ligne(0, j, largeurFenetre() , j);
    }

    if (image && image2 && image3 != NULL) 
			{
			    ecrisImage(2*(largeurFenetre()/3)+35, hauteurFenetre()/3-150, image2->largeurImage, image2->hauteurImage, image2->donneesRGB);
                ecrisImage(2*(largeurFenetre()/3), 2*(hauteurFenetre()/3)-200, image3->largeurImage, image3->hauteurImage, image3->donneesRGB);
                ecrisImage(2*(largeurFenetre()/3)+10, hauteurFenetre()-250, image->largeurImage, image->hauteurImage, image->donneesRGB);
			}


    couleurCourante(0, 0, 128);
    epaisseurDeTrait(2);
    afficheChaine("Appuyez sur Espace pour Jouer", 20, largeurFenetre()/2-150,  hauteurFenetre()/3-80);
    
}
