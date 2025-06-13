#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"

#define SIZE 4 

Tétrominos CreerTetrominos(char figure) {
    Tétrominos piece = {0};
    piece.x = COLONNES / 2 - 2;
    
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
        case 1: 
            // 0 0 0 0
            // 0 1 1 0
            // 0 1 1 0
            // 0 0 0 0

            piece.grille[1][1] = 1;
            piece.grille[1][2] = 1;
            piece.grille[2][1] = 1;
            piece.grille[2][2] = 1;
            break;
        case 2: 
        case 't':
            // 0 1 0 0
            // 0 1 1 0
            // 0 1 0 0
            // 0 0 0 0
            piece.grille[1][0] = 2;
            piece.grille[1][1] = 2;
            piece.grille[1][2] = 2;
            piece.grille[2][1] = 2;
            break;
        case 'l':
        case 3:     
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 1 0
            // 0 0 0 0

            piece.grille[1][0] = 3;
            piece.grille[1][1] = 3;
            piece.grille[1][2] = 3;
            piece.grille[2][2] = 3;
            break;
        case 'i':
        case 4: 
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 0 0

            piece.grille[1][0] = 4;
            piece.grille[1][1] = 4;
            piece.grille[1][2] = 4;
            piece.grille[1][3] = 4;
            break;
        case 'j':
        case 5: 
            // 0 0 1 0
            // 0 0 1 0
            // 0 1 1 0
            // 0 0 0 0

            piece.grille[2][0] = 5;
            piece.grille[2][1] = 5;
            piece.grille[2][2] = 5;
            piece.grille[1][2] = 5;
            break;
        case 's':
        case 6: 
            // 0 0 1 0
            // 0 1 1 0
            // 0 1 0 0
            // 0 0 0 0

            piece.grille[1][1] = 6;
            piece.grille[1][2] = 6;
            piece.grille[2][0] = 6;
            piece.grille[2][1] = 6;
            break;
        case 'z':
        case 0: 
            // 0 1 0 0
            // 0 1 1 0
            // 0 0 1 0
            // 0 0 0 0

            piece.grille[1][0] = 7;
            piece.grille[1][1] = 7;
            piece.grille[2][1] = 7;
            piece.grille[2][2] = 7;
            break;
        default: 
            printf("forme indisponible!");
    }
    return piece;
}

void TournerTetrominos(Tétrominos* piece) {
    // tourner la pièce
    int rotation_possible = 1;
    int copie[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            int x = piece->x + i;
            int y = piece->y + j;
            if(
                (x < 0 || x >= COLONNES) ||
                (y < 0 || y >= LIGNES) ||
                (jeu.grille[x][y] != 0)
            ) {
                rotation_possible = 0;
                break;
            }
            copie[i][j] = piece->grille[j][SIZE - 1 - i];
        }
    }
    if(rotation_possible == 0) {
        return;
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            piece->grille[i][j] = copie[i][j];
        }
    }
    rafraichisFenetre();
}

// Créer un Tétrominos aléatoirement (tu utiliseras la fonction Creer Tetrominos)
Tétrominos NouveauTetrominos() {
    // 7 formes
    char figure = rand() % 7; 
    return CreerTetrominos(figure);
}