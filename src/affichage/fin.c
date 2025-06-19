#include "../tetris.h"


void ecranGameOver(DonneesImageRGBA *quitter, DonneesImageRGBA *multijoueur, DonneesImageRGBA *the_score, DonneesImageRGBA *restart ) {
    int max_x = largeurFenetre();
    int max_y = hauteurFenetre();
    int padding = 64;

    effaceFenetre(255, 255, 255);
    affichageJeu();
    
     ecrisImageARVB(
        (max_x - padding - restart->largeurImage),
        (max_y - padding*7), 
        restart->largeurImage, restart->hauteurImage, (int*) restart->donneesRGBA
    );

       ecrisImageARVB(
        (max_x - padding - multijoueur->largeurImage ),
        (max_y / 2 - multijoueur->hauteurImage), 
        multijoueur->largeurImage, multijoueur->hauteurImage, (int*) multijoueur->donneesRGBA   
    );
    
    ecrisImageARVB(
        (max_x - padding - quitter->largeurImage),
        (padding), 
        quitter->largeurImage, quitter->hauteurImage, (int*) quitter->donneesRGBA
    );
 

     ecrisImageARVB(
        (max_x - padding * 10 - multijoueur->largeurImage),
        (max_y - padding * 4 - the_score->hauteurImage),
        the_score->largeurImage, the_score->hauteurImage, (int*) the_score->donneesRGBA
    );
    char score[100];
    sprintf(score, "%d" , jeu.score); // tab de chaine , ce qu'il contient , reference du %d
    // void afficheChaine(const char *chaine, float taille, float x, float y)
    couleurCourante(206, 54, 116);
    epaisseurDeTrait(3);
    afficheChaine(score, 100.0, 700 , 600);
    
    animer_gameover();
    gameOverSoundEffect();
    
    ecrisImageARVB(
        max_x - padding - image_gameover->largeurImage,
        max_y - padding - image_gameover->hauteurImage,
        image_gameover->largeurImage, image_gameover->hauteurImage, (int*) image_gameover->donneesRGBA   
    );

    
}
