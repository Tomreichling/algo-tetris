#include "./tetris.h"

void copier_tableau44(char entree[4][4], char sortie[COLONNES][LIGNES], int xi, int yi) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(entree[i][j] == 0) {
                continue;
            }
            sortie[xi + i][yi + i] = entree[i][j];
        }
    }
}

void demarrer_jeu() {
    for(int i = 0; i < COLONNES; i++) {
        for(int j = 0; j < LIGNES; j++) {
            jeu.grille[i][j] = 0;
        }
    }
    jeu.t_demarrage = tempsCPU();
    jeu.piece = NouveauTetrominos();
    jeu.prochaine_piece = NouveauTetrominos();
    jeu.score = 0;
    
    printf("Lancement du jeu\n");
    demandeTemporisation(1000);
    rafraichisFenetre();
    jeu.etat = JEU;
}