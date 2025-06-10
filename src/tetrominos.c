#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"

#define SIZE 4 

Tétrominos CreerTetrominos(char figure, int couleur) {
    Tétrominos piece = {0};
    
    // On initialise à 0
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            piece.grille[i][j] = 0;
        }
    }

    // On place les couleurs
    switch (figure)
    {
        case 'o':
            // 0 0 0 0
            // 0 1 1 0
            // 0 1 1 0
            // 0 0 0 0
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][1] = couleur;
            piece.grille[2][2] = couleur;
            break;
        
        case 't':
            // 0 1 0 0
            // 0 1 1 0
            // 0 1 0 0
            // 0 0 0 0
            piece.grille[1][0] = couleur;
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][1] = couleur;
            break;
        case 'l':
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 0 0
            piece.grille[0][0] = couleur;
            piece.grille[0][1] = couleur;
            piece.grille[0][2] = couleur;
            piece.grille[1][2] = couleur;
            break;
        case 'i':
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 0 0
            piece.grille[1][0] = couleur;
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[1][3] = couleur;
            break;
        case 'j':
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 1 0
            // 0 0 0 0
            piece.grille[1][0] = couleur;
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][2] = couleur;
            break;
        case 's':
            // 0 0 1 0
            // 0 1 1 0
            // 0 1 0 0
            // 0 0 0 0
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][0] = couleur;
            piece.grille[2][1] = couleur;
            break;
        case 'z':
            // 0 1 0 0
            // 0 1 1 0
            // 0 0 1 0
            // 0 0 0 0
            piece.grille[1][0] = couleur;
            piece.grille[1][1] = couleur;
            piece.grille[2][1] = couleur;
            piece.grille[2][2] = couleur;
            break;
        default: 
            printf("forme indisponible!");
    }
    return piece;
}

void TournerTetrominos(Tétrominos* piece) {
    // tourner la pièce
    int copie[SIZE][SIZE];

   for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            copie[i][j] =  piece->grille[i][j];
        }
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            piece->grille[j][SIZE - 1 - i] = copie[i][j];
        }
    }
}

// Créer un Tétrominos aléatoirement (tu utiliseras la fonction Creer Tetrominos)
Tétrominos NouveauTetrominos() {

}
