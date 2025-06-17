#ifndef MENU_H
#define MENU_H
#include "../src/tetris.h"

#define NB_PIECES_MENU 8

extern Tétrominos pieces_menu[NB_PIECES_MENU];
// affichage

// Affiche la grille
void afficheGrilleMenu();
// Affiche les boutons, les gemmes et le logo tetrisen
void afficheMenu(DonneesImageRGBA *demarrer,  DonneesImageRGBA *mutlijoueur , DonneesImageRGBA *quitter, DonneesImageRGBA *titre,DonneesImageRGBA *gemme );

// Affiche un carreau de couleur sur la grille
void afficherCarreauMenu(int x, int y, char couleur);

// Affiche les pieces sur le menu
void afficherPiecesMenu();

// temporisation
bool dansGrilleMenu(int x, int y);
void deplacer_piece_menu(Tétrominos* piece, int vx, int vy);
void tourner_piece_menu(Tétrominos* piece);
void initialiser_pieces_menu();
// entrees

// si on appuit sur entrée et que le mode est bien MENU, on démarre le mode JEU.
void demarrer_avec_espace();

#endif