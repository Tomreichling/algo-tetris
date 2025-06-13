#ifndef OUTILS_H
#define OUTILS_H
#include "../src/tetris.h"

// Copie un tableau 4x4 dans la grille
void copier_tableau44(char tableau[4][4], char grille[COLONNES][LIGNES], int xi, int yi);

// Passe du mode MENU au mode JEU
//  - reinitialise la partie
//  - passe le mode à JEU
void demarrer_jeu();

// Passe du mode JEU au mode FIN
//  - Change la temporisation
//  - rafraichis l'affichage
void gameover();

// Vérifie si des coordonées sont comprises dans la grille
bool dansGrille(int x, int y);

//////////////////////// 
// Gestion des images //
////////////////////////
typedef unsigned int ImageId;
typedef struct image {
    ImageId id;
    unsigned int largeur;
    unsigned int hauteur;
    unsigned char *donnees;
} Image;


// Tableau des images disponible globalement
extern Image* images;
extern int nb_images;

// Lis une image, l'ajoute au tableau et renvoie son identifiant
ImageId lireImage(char *nom);
// Trouve une image dans le tableau des images
Image* trouveImage(ImageId id);
// Libere une image du tableau et libere son tableau de pixels
void libereImage(ImageId id);


#endif