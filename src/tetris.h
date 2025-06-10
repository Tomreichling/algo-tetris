#ifndef TETRIS_H
#define TETRIS_H

// ecran
#define LARGEUR 1200
#define LONGUEUR 800

// Tableau
#define COLONNES 10
#define LIGNES 20

typedef struct tetrominos{
    int x;
    int y;
    char rotation;
    char grille[4][4];
}Tétrominos;

enum ETAT_JEU { MENU, JEU, FIN };
typedef struct jeu{
    int temps; 
    int score;
    int etat;
    char grille[COLONNES][LIGNES];
    // actuelle
    Tétrominos piece;
    // next
    Tétrominos prochaine_piece;
} Jeu;

extern Jeu jeu;

#endif