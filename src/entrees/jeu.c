#include "../tetris.h"
#include <stdbool.h>

// Entrées

void entreesJeu(){

}


// en fonction de x 
void bouger_piece_droite() {
    int deplacement_valide = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            int x = jeu.piece.x + i;
            if (jeu.piece.grille[i][j] == 0){
                continue; 
            }
            if (jeu.grille[x + 1][j] != 0 && i + 1 == COLONNES){
                deplacement_valide = 0;
                break;
            }
        }
    }
    if (deplacement_valide == 1){
        jeu.piece.x++;
    }
}
// en fonction de -x
void bouger_piece_gauche(){
    int deplacement_valide = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            int x = jeu.piece.x + i;
            if (jeu.piece.grille[i][j] == 0){
                continue; 
            }
            if (jeu.grille[x - 1][j] != 0 && x - 1 == - 1){
                deplacement_valide = 0;
                break;
            }
        }
    }
    if (deplacement_valide == 1){
        jeu.piece.x--;
    }
}