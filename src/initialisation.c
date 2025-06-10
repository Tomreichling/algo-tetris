#include "./tetris.h"
#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()


#DEFINE CARREAU 4
// Tétrominos sept formes
switch (Grille) 
{
    // vide
    case: 0
        0 0 0 0
        0 0 0 0
        0 0 0 0
        0 0 0 0
    break;

    case: 1
    // Forme I 

        0 0 0 0
        1 1 1 1
        0 0 0 0 
        0 0 0 0

    break;

    case:2
    // forme T 

        0 0 0 0
        0 1 1 1
        0 0 1 0
        0 0 0 0



    break;

    // forme O
    case: 3

        0 0 0 0
        0 1 1 0
        0 1 1 0
        0 0 0 0

    
    break;

    // forme L 
    case: 4
        0 0 0 0
        0 0 0 0
        1 0 0 0
        1 1 1 1
    break; 

    // forme s 
    case:5
        0 0 0 0
        1 0 0 0
        0 1 1 0
        0 0 0 1
    break;

    // forme j
    case:6
        0 0 0 0
        0 1 0 0
        0 1 0 0
        1 1 0 0
    break;

    // forme Z 
        0 0 0 0
        1 1 0 0
        0 1 1 0
        0 0 0 0


}

// Rotation Tétrominos
// 90
void sens_horaire (Tétrominos){
    for (int i=0; i<CARREAU; i++){
        for (int j=0; j<CARREAU; j++){
            grille [j][i]= grille [i][j];

            return grille [j][i];
        }
    }
}

