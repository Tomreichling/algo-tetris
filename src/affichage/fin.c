#include "../tetris.h"


void ecranGameOver(DonneesImageRGBA *quitter, DonneesImageRGBA *multijoueur) {
    int max_x = largeurFenetre();
    int max_y = hauteurFenetre();
    int padding = 64;

    effaceFenetre(255, 255, 255);
    affichageJeu();
    ecrisImageARVB(
        (max_x - padding - quitter->largeurImage),
        (padding), 
        quitter->largeurImage, quitter->hauteurImage, (int*) quitter->donneesRGBA
    );
    ecrisImageARVB(
        (max_x - padding - multijoueur->largeurImage),
        (max_y / 2 - multijoueur->hauteurImage / 2), 
        multijoueur->largeurImage, multijoueur->hauteurImage, (int*) multijoueur->donneesRGBA
    );
    // afficherScore(); 
    
    animer_gameover();
    gameOverSoundEffect();
    
    ecrisImageARVB(
        max_x - padding - image_gameover->largeurImage,
        max_y - padding - image_gameover->hauteurImage,
        image_gameover->largeurImage, image_gameover->hauteurImage, (int*) image_gameover->donneesRGBA   
    );
    afficherScore(); 
    animer_gameover();
    gameOverSoundEffect();
}
