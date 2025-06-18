#include "../tetris.h"


void ecranGameOver() {
    int max_x = largeurFenetre();
    int max_y = hauteurFenetre();
    int padding = 64;
    
    effaceFenetre(255, 255, 255);
    affichageJeu();
    ecrisImageARVB(
        (max_x - padding - image_quitter->largeurImage),
        (padding), 
        image_quitter->largeurImage, image_quitter->hauteurImage, (int*) image_quitter->donneesRGBA
    );
    ecrisImageARVB(
        (max_x - padding - image_multijoueur->largeurImage),
        (max_y / 2 - image_multijoueur->hauteurImage / 2), 
        image_multijoueur->largeurImage, image_multijoueur->hauteurImage, (int*) image_multijoueur->donneesRGBA
    );
    ecrisImageARVB(
        max_x - padding - image_gameover->largeurImage,
        max_y - padding - image_gameover->hauteurImage,
        image_gameover->largeurImage, image_gameover->hauteurImage, (int*) image_gameover->donneesRGBA   
    );


    

    //rectangle du leaderboard
    couleurCourante(181, 98, 245);
    rectangle(largeurFenetre()/3,hauteurFenetre()/10,largeurFenetre()/(1.6), hauteurFenetre()/(2.5));
    couleurCourante(0,0,10);
    epaisseurDeTrait(3);
    afficheChaine( "Top 3 Joueurs LeaderBoard ",largeurFenetre()/55,largeurFenetre()/3 + 4,hauteurFenetre()/(2.8));
    epaisseurDeTrait(3);
    ligne(largeurFenetre()/3 + 4,hauteurFenetre()/(3),largeurFenetre()/(1.6)-4,hauteurFenetre()/(3));
    leaderboardRecup();


    // afficherScore(); 
    animer_gameover();
}
