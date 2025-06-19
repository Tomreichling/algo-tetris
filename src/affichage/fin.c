#include "../tetris.h"


void ecranGameOver() {
    int max_x = largeurFenetre();
    int max_y = hauteurFenetre();
    int padding = 64;
    
    effaceFenetre(255, 255, 255);
    affichageJeu();
    
     ecrisImageARVB(
        (max_x - padding - image_restart->largeurImage),
        (max_y - padding*7), 
         image_restart->largeurImage, image_restart->hauteurImage, (int*) image_restart->donneesRGBA
    );

       ecrisImageARVB(
        (max_x - padding - image_multijoueur->largeurImage ),
        (max_y / 2 - image_multijoueur->hauteurImage), 
        image_multijoueur->largeurImage, image_multijoueur->hauteurImage, (int*) image_multijoueur->donneesRGBA   
    );
    
    ecrisImageARVB(
        (max_x - padding - image_quitter->largeurImage),
        (padding), 
        image_quitter->largeurImage, image_quitter->hauteurImage, (int*) image_quitter->donneesRGBA
    );
 

     ecrisImageARVB(
        (max_x - padding * 10 - image_multijoueur->largeurImage),
        (max_y - padding * 4 - image_the_score->hauteurImage),
        image_the_score->largeurImage, image_the_score->hauteurImage, (int*) image_the_score->donneesRGBA
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
