#include "tetris.h"

// Créer un tétrominos (utilise TournerTetrominos)
Tétrominos CreerTetrominos(char rotation, char figure, int couleur);

// Tourne le tétrominos
void TournerTetrominos(Tétrominos* piece);

// Créer un Tétrominos aléatoirement (tu utiliseras la fonction Creer Tetrominos)
Tétrominos NouveauTetrominos();