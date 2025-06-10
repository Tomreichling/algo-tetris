#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"

#define SIZE 4 

Tétrominos CreerTetrominos(char figure, int couleur) {
    Tétrominos piece = {0};
    
    // On initialise à 0
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            piece.grille[i][j] = 0;
        }
    }

    // On place les couleurs
    switch (figure)
    {
        case 'o':
        
            piece.grille[1][1] = couleur;
            piece.grille[2][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][2] = couleur;
            break;
        
            case 't':
            
            piece.grille[1][0] = couleur;
            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][1] = couleur;
            break;
        
        case 'l':
            
            piece.grille[0][0] = couleur;
            piece.grille[0][1] = couleur;
            piece.grille[0][2] = couleur;
            piece.grille[1][2] = couleur;
            break;

               
        case 'i':

            piece.grille[0][0] = couleur;
            piece.grille[0][1] = couleur;
            piece.grille[0][2] = couleur;
            piece.grille[0][3] = couleur;
            break;

        case 'j':

               piece.grille[1][0] = couleur;
               piece.grille[1][1] = couleur;
               piece.grille[1][2] = couleur;
               piece.grille[2][0] = couleur;
            break;

        case 's':

            piece.grille[1][1] = couleur;
            piece.grille[1][2] = couleur;
            piece.grille[2][0] = couleur;
            piece.grille[2][1] = couleur;
            break;

        case 'z':

            piece.grille[1][0] = couleur;
            piece.grille[1][1] = couleur;
            piece.grille[2][1] = couleur;
            piece.grille[2][2] = couleur;
            break;

        default: 
            printf("forme indisponible!");

    }
    return piece;
}

void TournerTetrominos(Tétrominos* piece) {
    // tourner la pièce
    int copie[SIZE][SIZE];

   for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            copie [i][j] =  piece->grille[i][j] ;
        }
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            piece->grille[j][SIZE - 1 - i] = copie [i][j] ;
        }
    }
}

void afficher (Tétrominos* piece){
    for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
              
            
            if (piece->grille[i][j] != 0) {
                printf("1");
            } else {
                printf("0"); 
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Créer un Tétrominos aléatoirement (tu utiliseras la fonction Creer Tetrominos)
Tétrominos NouveauTetrominos() {

}
