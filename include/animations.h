#ifndef ANIMATIONS_H
#define ANIMATIONS_H
#include "../src/tetris.h"

// Pour faire une animation, il faut recharger l'affichage à chaque instant de l'animation 
// et faire évoluer une propriété dans la fonction qui affiche

// pour faire ça gfxlib nous donne
// demandeRedessinDans_ms pour recharger l'affichage après un temps donne

// il faudra faire une fonction que l'on executera au déclenchement de l'animation hors de l'affichage
// et qui fera appel à demandeRedessinDans_ms

typedef struct animation {
    int id; // identifiant de l'animation (unique pour chaque animation, ex: 1 pour le saut, 2 pour le temps)
    unsigned int etapes; // en combien d'étapes l'animation se fait (ex: 10 actualisations sur 1 secondes)
    unsigned int interval; // en millisecondes
    unsigned int duree; // duree en millisecondes
    unsigned int etape; // l'étape à laquelle on est.
} Animation;

#endif