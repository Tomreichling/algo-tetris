#ifndef MENU_H
#define MENU_H
#include "../src/tetris.h"
// affichage
void afficheMenu(DonneesImageRGBA *image, DonneesImageRGBA *image3 , DonneesImageRGBA *image2);

// temporisation

// entrees

// si on appuit sur entrée et que le mode est bien MENU, on démarre le mode JEU.
void demarrer_avec_espace();

#endif