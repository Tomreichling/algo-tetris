#include "../tetris.h"

// Entrées
// gères toutes les entrées de l'utilisateur
// - Q -> bouger la pièce à Gauche
// - D -> bouger la pièce à Droite
// - S -> accélerer la pièce
// - Espace -> Faire sauter la pièce
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
        case 'e':
        case 'E':
            TournerTetrominos(&jeu.piece);
            break;

        // case 32: {
        //    sauter  la piece 
        // }
        // default:
        // {
        //     printf("%d -> %c\n", caractereClavier(), caractereClavier());
        // }
    }
}
// gères toutes les entrées spéciales de l'utilisateur
// - Flèche de gauche pour aller à gauche -> bouger la pièce à Gauche
// - Flèche de droite pour aller à droite -> bouger la pièce à Droite
// - Flèche du haut pour accélerer -> accélérer la piècer
void entrees_speciales_jeu() {
    switch(toucheClavier()) {
        // fleche droite 
        case 16: 
            bouger_piece_droite();
            break;
        // gauche
        case 15: 
            bouger_piece_gauche();
            break;
        // fleche haut <=> rotation
        case 13:
            TournerTetrominos(&jeu.piece);
            break;
        // bas
        case 14: 
            descendre_piece();
            break;
    }
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


// void sauter_piece (){

// }