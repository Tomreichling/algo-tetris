#include "../tetris.h"

#define HauteurFenetre 600
#define LargeurFenetre 800


void afficheIdent(DonneesImageRGBA *titre) {
    effaceFenetre(255, 255, 255);
    int x1 = largeurFenetre()/2 - largeurFenetre()/3;
    int y1 = hauteurFenetre()/2 - hauteurFenetre()/8;
    int x2 = largeurFenetre()/2 + largeurFenetre()/3;
    int y2 = hauteurFenetre()/2;
    
       //affichage titre centre 
        ecrisImageARVB(
            (largeurFenetre()/2 -  titre->largeurImage/2), 
            (hauteurFenetre()/2 + hauteurFenetre()/5), 
            titre->largeurImage, titre->hauteurImage, (int*) titre->donneesRGBA
        );

    couleurCourante(0,0,10);
    epaisseurDeTrait(5);
    afficheChaine( "entrez votre nom : ",70,largeurFenetre()/2 - (60 * strlen("entrez votre nom : ")/2)/2, y2 + hauteurFenetre()/30);

    couleurCourante(181,56,202);
    rectangle(x1, y1, x2, y2);

    if (strlen(jeu.nom)){
        couleurCourante(255,255,255),
        afficheChaine(jeu.nom,largeurFenetre()/25,x1 + 10, y1 + (y2 - y1 - largeurFenetre()/25)/2);
        }
    else {
    couleurCourante(255,255,255),
    afficheChaine("|", largeurFenetre()/25,x1 + 10, y1 + (y2 - y1 - largeurFenetre()/25)/2 );
    }
   
}