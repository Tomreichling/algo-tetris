#ifndef OUTILS_H
#define OUTILS_H
#include "../src/tetris.h"

// Copie un tableau 4x4 dans la grille
void copier_tableau44(char tableau[4][4], char grille[COLONNES][LIGNES], int xi, int yi);

// Passe du mode MENU au mode JEU
//  - reinitialise la partie
//  - passe le mode à JEU
void demarrer_jeu();

#endif