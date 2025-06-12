#include "../tetris.h"

bool descente_possible(Tétrominos *piece) {
    bool deplacement_possible = true;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(piece->grille[i][j] == 0) {
                continue;
            }

            int x = piece->x + i;
            int y = piece->y + j;
            if(jeu.grille[x][y + 1] != 0 || y + 1 == LIGNES) {
                deplacement_possible = false;
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
        jeu.nb_piece++;
    }
    rafraichisFenetre();
}

int trouver_indices_lignes_completes(char grille[COLONNES][LIGNES], int indices[4]){
    int nombre_lignes_completes = 0;
    int n = 0;

    for (int j = 0; j < LIGNES; j++) {
        n = 0;
        for (int i = 0; i < COLONNES; i++) {
            if (grille[i][j] != 0) {
                n++;
            }
            else if (grille[i][j] ==0){
                break;
            }
            
        }
        if (n == COLONNES) {
            nombre_lignes_completes++;
            indices[nombre_lignes_completes - 1] = j;
        }
    }
    return nombre_lignes_completes;
} 

void assigner_score(int nb_indices) {
    switch (nb_indices) {
        case 1:
            jeu.score += 40;
            break;
        case 2:
            jeu.score += 100;
            break;
        case 3:
            jeu.score += 300;
            break;
        case 4:
            jeu.score += 1200;
            break;
        default:
            break;
    }
}

void retire_ligne(int i) {
    for (; i > -1; i--) {
        for (int j = 0; j < COLONNES; j++) {
            if (i == 0) {
                jeu.grille[j][i] = 0;
            } else {
                jeu.grille[j][i] = jeu.grille[j][i - 1];
            }
        }
    }
}

