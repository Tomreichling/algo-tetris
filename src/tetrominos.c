#include "tetris.h"

Tétrominos CreerTetrominos(char rotation, char figure, int couleur) {
    Tétrominos piece = {0};
    piece.rotation = rotation;
    
    // On initialise à 0
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            piece.grille[i][j] = 0;
        }
    }

    // On place les couleurs
    switch (figure)
    {
        case 'o':
            piece.grille[1][1] = couleur;
            piece.grille[2][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][2] = couleur;
            break;
        case 't':
            // a finir
            break;
        // a finir
    }
    return piece;
}

void TournerTetrominos(Tétrominos* piece) {
    // tourner la pièce
}

// Créer un Tétrominos aléatoirement (tu utiliseras la fonction Creer Tetrominos)
Tétrominos NouveauTetrominos() {

}