#ifndef TETRIS_H
#define TETRIS_H

// #define PRODUCTION; // Mettre en commentaire pour WSL & Mac

// MULTI
#define DESTINATAIRE "127.0.0.1"
#define ORIGINE "127.0.0.1"
#define PORT 3000

// ecran
#define LARGEUR 1200
#define LONGUEUR 800

// Tableau
#define COLONNES 10
#define LIGNES 20

#define _GNU_SOURCE
#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>

#ifdef PRODUCTION
    #include <unistd.h>
    #include <sys/prctl.h>
    #include <signal.h>
#endif

#include "../gfx/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../gfx/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../gfx/ESLib.h" // Pour utiliser valeurAleatoire()

#include "../include/tetrominos.h" // Fonctions tetrominos
#include "../include/outils.h" // Fonctions utilitaires
#include "../include/animations.h" // Gestion des animations

#include "../include/fin.h" // Fonctions affichage/tempo/entrees dans le mode "fin"
#include "../include/menu.h" // Fonctions affichage/tempo/entrees dans le mode "menu"
#include "../include/jeu.h" // Fonctions affichage/tempo/entrees dans le mode "jeu"
#include "../include/identification.h" // Fonctions affichage/tempo/entrees dans le mode "identite"
#include "../include/multi.h" //Fonctions affichage/tempo/entrees dans le mode "multi"
#include "../include/souris.h"

enum ETAT_JEU { MENU, JEU, FIN, MULTI, IDENTITE };

typedef struct jeu{
    int score;
    int nb_piece; // le nombre de pièce écoulé
    int etat; // enum ETAT_JEU
    char grille[COLONNES][LIGNES];
    int minutes;
    int secondes;
    char nom[21];
    int gemmes;
    // actuelle
    Tétrominos piece;
    // next
    Tétrominos prochaine_piece;
} Jeu;

extern Jeu jeu;

// Images
extern DonneesImageRGBA *image_gameover;
extern DonneesImageRGBA *image_demarrer;
extern DonneesImageRGBA *image_multijoueur;
extern DonneesImageRGBA *image_quitter;
extern DonneesImageRGBA *image_titre;
extern DonneesImageRGBA *image_gemme;
extern DonneesImageRGBA *image_gemRouge;
#endif