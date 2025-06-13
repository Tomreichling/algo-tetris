#include "../tetris.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

void afficheMenu(DonneesImageRGBA *demarrer,  DonneesImageRGBA *mutlijoueur , DonneesImageRGBA *quitter) {
    effaceFenetre(255, 255, 255);
    
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(5);
   
    for (int i=0; i <  largeurFenetre(); i+=hauteurFenetre()/20){
        ligne(i, 0, i, hauteurFenetre());
    }
    
   for (int j=0; j < hauteurFenetre() ; j+= hauteurFenetre()/20){
        ligne(0, j, largeurFenetre() , j);
    }

    if (demarrer != NULL && mutlijoueur != NULL && quitter != NULL) 
			{
			    ecrisImageARVB(2*(largeurFenetre()/3)+35, hauteurFenetre()/3-150, demarrer->largeurImage, demarrer->hauteurImage, (int*) demarrer->donneesRGBA);
                ecrisImageARVB(2*(largeurFenetre()/3), 2*(hauteurFenetre()/3)-200, mutlijoueur->largeurImage, mutlijoueur->hauteurImage, (int*) mutlijoueur->donneesRGBA);
                ecrisImageARVB(2*(largeurFenetre()/3)+10, hauteurFenetre()-250, quitter->largeurImage, quitter->hauteurImage, (int*) quitter->donneesRGBA);
			}


    couleurCourante(0, 0, 128);
    epaisseurDeTrait(2);
    afficheChaine("Appuyez sur Espace pour Jouer", 20, largeurFenetre()/2-150,  hauteurFenetre()/3-80);
    
}
