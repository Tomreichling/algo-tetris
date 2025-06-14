#ifndef MENU_H
#define MENU_H
#include "../src/tetris.h"
// affichage
void afficheMenu(DonneesImageRGBA *demarrer,  DonneesImageRGBA *mutlijoueur , DonneesImageRGBA *quitter, DonneesImageRGBA *titre,DonneesImageRGBA *gemme );
// temporisation

// entrees

// si on appuit sur entrée et que le mode est bien MENU, on démarre le mode JEU.
void demarrer_avec_espace();

#endif