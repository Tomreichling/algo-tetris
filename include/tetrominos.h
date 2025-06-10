#ifndef TETROMINOS_H
#define TETROMINOS_H
#include "../src/tetris.h"

typedef struct tetrominos{
    int x;
    int y;
    char rotation;
    char grille[4][4];
} Tétrominos;

// Créer un tétrominos (utilise TournerTetrominos)
Tétrominos CreerTetrominos(char rotation, char figure, int couleur);

// Tourne le tétrominos
void TournerTetrominos(Tétrominos* piece);

// Créer un Tétrominos aléatoirement (tu utiliseras la fonction Creer Tetrominos)
Tétrominos NouveauTetrominos();

#endif