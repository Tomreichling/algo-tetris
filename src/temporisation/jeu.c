#include "../tetris.h"

int descente_possible(Tétrominos *piece) {
    int deplacement_possible = 1;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(piece->grille[i][j] == 0) {
                continue;
            }

            int x = piece->x + i;
            int y = piece->y + j;
            if(jeu.grille[x][y + 1] != 0 || y + 1 == LIGNES) {
                deplacement_possible = 0;
                break;
            } 
        }
    }
    return deplacement_possible;
}

void descendre_piece() {
    // le but est de descendre si tous les points de du Tétromos le peuvent
    // sinon on passe la pièce dans la grille et on passe à la pièce suivante.
    int deplacement_possible = descente_possible(&jeu.piece);
    
    if(deplacement_possible) {
        jeu.piece.y++;
    } else if(jeu.piece.y == 0) {
        // Si le déplacement n'est pas possible 
        // et que l'on est tout en haut, on perds!
        gameover();
    } else {
        copier_tableau44(jeu.piece.grille, jeu.grille, jeu.piece.x, jeu.piece.y);
        jeu.piece = jeu.prochaine_piece;
        jeu.prochaine_piece = NouveauTetrominos();
    }
}