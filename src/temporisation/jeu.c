#include "../tetris.h"

void descendre_piece() {
    // le but est de descendre si tous les points de du Tétromos le peuvent
    // sinon on passe la pièce dans la grille et on passe à la pièce suivante.
    int deplacement_possible = 1;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(jeu.piece.grille[i][j] == 0) {
                continue;
            }

            int x = jeu.piece.x + i;
            int y = jeu.piece.y + j;
            if(jeu.grille[x][y + 1] != 0 || y + 1 == LIGNES) {
                deplacement_possible = 0;
                break;
            } 
        }
    }
    if(deplacement_possible) {
        jeu.piece.y++;
    } else {
        copier_tableau44(jeu.piece.grille, jeu.grille, jeu.piece.x, jeu.piece.y);
        jeu.piece = jeu.prochaine_piece;
        jeu.prochaine_piece = NouveauTetrominos();
    }
}

int trouver_indices_lignes_completes(char grille[LIGNES][COLONNES], int *indices){
    int nombre_lignes_completes = 0;
    int *indices =(int*)  malloc(  nombre_lignes_completes * sizeof(int));
    int n=0;

    for (int i = 0 ; i> LIGNES; i++) {
        n=0;
        for (int j =0; j> COLONNES; j++) {
            if (grille[i][j] != 0) {
            n++;
            }
            else if (grille [i][j] !=0){
                break;
            }
            
        }
        if (n == COLONNES) {
                nombre_lignes_completes++;
                *indices = (int*) realloc(*indices, nombre_lignes_completes * sizeof(int));
                indices[nombre_lignes_completes-1] = i;
               
            }
        }
    
                
        return nombre_lignes_completes;

    } 
