#include "../tetris.h"

void afficheIdent(DonneesImageRGBA *titre) {
    
    effaceFenetre(255, 255, 255);

    //affichage titre centre 
    ecrisImageARVB(
        (largeurFenetre()/2 -  titre->largeurImage/2), 
        (hauteurFenetre()/2 + hauteurFenetre()/5), 
        titre->largeurImage, titre->hauteurImage, (int*) titre->donneesRGBA
    );

    couleurCourante(0,0,10);
    epaisseurDeTrait(5);
    afficheChaine("entrez votre nom : ", 60, largeurFenetre()/2- largeurFenetre()/3, hauteurFenetre()/2 + hauteurFenetre()/15);

    couleurCourante(181,56,202);
    rectangle(largeurFenetre()/2- largeurFenetre()/3,hauteurFenetre()/2- hauteurFenetre()/8, largeurFenetre()/2 + largeurFenetre()/3 ,hauteurFenetre()/2 );

    if (strlen(jeu.nom) != 0) {
        couleurCourante(255,255,255);
        afficheChaine(jeu.nom, largeurFenetre()/25,largeurFenetre()/2- largeurFenetre()/3 + 10 , hauteurFenetre()/2- hauteurFenetre()/10 + 10 );
    } else {
        couleurCourante(255,255,255);
        afficheChaine("|",largeurFenetre()/25,largeurFenetre()/2- largeurFenetre()/3 + 10 , hauteurFenetre()/2- hauteurFenetre()/10 + 10 );
    }
}