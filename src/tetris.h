#ifndef TETRIS_H
#define TETRIS_H

// ecran
#define LARGEUR 1200
#define LONGUEUR 800

// Tableau
#define COLONNES 10
#define LIGNES 20

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h> // Pour pouvoir utiliser sin() et cos()

#include "../gfx/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../gfx/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../gfx/ESLib.h" // Pour utiliser valeurAleatoire()

#include "../include/tetrominos.h" // Fonctions tetrominos
#include "../include/outils.h" // Fonctions utilitaires

#include "../include/fin.h" // Fonctions affichage/tempo/entrees dans le mode "fin"
#include "../include/menu.h" // Fonctions affichage/tempo/entrees dans le mode "menu"
#include "../include/jeu.h" // Fonctions affichage/tempo/entrees dans le mode "jeu"

enum ETAT_JEU { MENU, JEU, FIN };

typedef struct jeu{
    int t_demarrage; // temps auquel la partie a commencé (secondes)
    int score;
    int etat; // enum ETAT_JEU
    char grille[COLONNES][LIGNES];
    // actuelle
    Tétrominos piece;
    // next
    Tétrominos prochaine_piece;
} Jeu;

extern Jeu jeu;

#endif