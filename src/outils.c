#include "tetris.h"

void copier_tableau44(char entree[4][4], char sortie[COLONNES][LIGNES], int xi, int yi) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(entree[i][j] == 0) {
                continue;
            }
            sortie[xi + i][yi + j] = entree[i][j];
        }
    }
}

void demarrer_jeu() {
    for(int i = 0; i < COLONNES; i++) {
        for(int j = 0; j < LIGNES; j++) {
            jeu.grille[i][j] = 0;
        }
    }
    jeu.nb_piece = 0;
    jeu.t_demarrage = tempsCPU();
    jeu.piece = NouveauTetrominos();
    jeu.prochaine_piece = NouveauTetrominos();
    jeu.score = 0;
    
    printf("Lancement du jeu\n");
    demandeTemporisation(1000);
    rafraichisFenetre();
    jeu.etat = JEU;
}

void gameover() {
    jeu.etat = FIN;
    rafraichisFenetre();
    // on arrête les tics
    demandeTemporisation(-1);
}

bool dansGrille(int x, int y) {
    return (
        x >= 0 && x < COLONNES &&
        y >= 0 && y < LIGNES
    );
}

void demarrer_musique() {
    #ifdef __linux__
        playsound("aplay $(pwd)/src/tetrisic.wav");
    #elif defined(__APPLE__)
        playsound("afplay $(pwd)/src/tetrisic.wav");
    #else
        printf("ce système ne prermet pas de lancer la musique");
    #endif

}

void stopper_musique() {
    #ifdef __linux__
        system("killall aplay");
    #elif defined(__APPLE__)
        system("killall afplay");
    #else
        printf("pourquoi arrêter si il n'y a rien ?");
    #endif
}