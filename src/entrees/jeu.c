#include "../tetris.h"

// Entrées
void entrees_jeu() {
    switch (caractereClavier()){
        case 'q': 
        case 'Q': 
           bouger_piece_gauche();
           break;
        case 'd':
        case 'D':
            bouger_piece_droite();
            break;
        case 'S':
        case 's':
            descendre_piece();
            break;
        case 'z':
        case 'Z':
            TournerTetrominos(&jeu.piece);
            break;
        case 32: // Barre espace
            sauter_piece();
            break;
        default:
            break;
    }
}
// gères toutes les entrées spéciales de l'utilisateur
void entrees_speciales_jeu() {
    switch(toucheClavier()) {
        case 16: // fleche droite 
            bouger_piece_droite();
            break;
        case 15: // flèche gauche
            bouger_piece_gauche();
            break;
        case 13: // flèche du haut
            TournerTetrominos(&jeu.piece);
            break;
        case 14:  // flèche du bas
            descendre_piece();
            break;
        default:
            break;
    }
}

// en fonction de x 
void bouger_piece_droite() {
    bool deplacement_valide = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            if (jeu.piece.grille[i][j] == 0){
                continue; 
            }
            int x = jeu.piece.x + i;
            int y = jeu.piece.y + j;
            if (jeu.grille[x + 1][y] != 0 || !dansGrille(x + 1, y)){
                deplacement_valide = false;
                break;
            }
        }
    }
    if (deplacement_valide){
        jeu.piece.x++;
        rafraichisFenetre();
    }
}
// en fonction de -x
void bouger_piece_gauche(){
    bool deplacement_valide = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            if (jeu.piece.grille[i][j] == 0){
                continue; 
            }
            int x = jeu.piece.x + i;
            int y = jeu.piece.y + j;
            if (!dansGrille(x - 1, y)|| jeu.grille[x - 1][y] != 0){
                deplacement_valide = false;
                break;
            }
        }
    }
    if (deplacement_valide){
        jeu.piece.x--;
        rafraichisFenetre();
    }
}


void sauter_piece() {
    int numero_piece = jeu.nb_piece;
    while (numero_piece == jeu.nb_piece && jeu.etat == JEU){
        descendre_piece();
    }
}