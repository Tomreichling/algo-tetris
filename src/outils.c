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


// On a fait des fonctions pour les musiques mais on aurait pu faire un playsound direct.
//les fonctions permettent de mettre d'autre action si bsn à l'avenir si autre méthode pour lire le son
void demarrer_musique() {
    playsound("assets/tetrisic2.wav");
}

void gameOverSoundEffect() {
    playsound("assets/gameover.wav");
}

void moveSoundEffect() {
    playsound("assets/simpleMove.wav");
}

void jumpSoundEffect() {
    playsound("assets/jump.wav");
 
}

void levelUpSoundEffect() {
    playsound("assets/levelUp.wav");
}

void ligneSoundEffect() {
    playsound("assets/ligneComplete.wav");
  
}

void stopper_musique() {
    system("killall aplay");
}