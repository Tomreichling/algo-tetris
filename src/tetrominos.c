#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"

#define SIZE 4 

Tétrominos CreerTetrominos(char figure) {
    Tétrominos piece = {0};
    piece.x = COLONNES / 2 - 2;
    int couleur;
    
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
        case 0: 
            // 0 0 0 0
            // 0 1 1 0
            // 0 1 1 0
            // 0 0 0 0
            piece.couleur_piece[0] = 240;
            piece.couleur_piece[1] = 240;
            piece.couleur_piece[2] = 240;
            couleur = 0;
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][1] = couleur;
            piece.grille[2][2] = couleur;
            break;
        case 1: 
        case 't':
            // 0 1 0 0
            // 0 1 1 0
            // 0 1 0 0
            // 0 0 0 0
            piece.couleur_piece[0] = 240;
            piece.couleur_piece[1] = 240;
            piece.couleur_piece[2] = 240;
            couleur = 1;
            piece.grille[1][0] = couleur;
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][1] = couleur;
            break;
        case 'l':
        case 2:     
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 1 0
            // 0 0 0 0
            piece.couleur_piece[0] = 240;
            piece.couleur_piece[1] = 240;
            piece.couleur_piece[2] = 240;
            couleur = 2;
            piece.grille[0][0] = couleur;
            piece.grille[0][1] = couleur;
            piece.grille[0][2] = couleur;
            piece.grille[1][2] = couleur;
            break;
        case 'i':
        case 3: 
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 0 0
            // 0 1 0 0
            piece.couleur_piece[0] = 240;
            piece.couleur_piece[1] = 240;
            piece.couleur_piece[2] = 240;
            couleur = 3;
            piece.grille[1][0] = couleur;
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[1][3] = couleur;
            break;
        case 'j':
        case 4: 
            // 0 1 0 0
            // 0 1 0 0
            // 1 1 0 0
            // 0 0 0 0
            piece.couleur_piece[0] = 240;
            piece.couleur_piece[1] = 240;
            piece.couleur_piece[2] = 240;
            couleur = 4;
            piece.grille[1][0] = couleur;
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][2] = couleur;
            break;
        case 's':
        case 5: 
            // 0 0 1 0
            // 0 1 1 0
            // 0 1 0 0
            // 0 0 0 0
            piece.couleur_piece[0] = 240;
            piece.couleur_piece[1] = 240;
            piece.couleur_piece[2] = 240;
            couleur = 5;
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][0] = couleur;
            piece.grille[2][1] = couleur;
            break;
        case 'z':
        case 6: 
            // 0 1 0 0
            // 0 1 1 0
            // 0 0 1 0
            // 0 0 0 0
            piece.couleur_piece[0] = 240;
            piece.couleur_piece[1] = 240;
            piece.couleur_piece[2] = 240;
            couleur = 6;
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

