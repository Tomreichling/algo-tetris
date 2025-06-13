#include "tetris.h"

static int numero_piece_sautant;
static Animation *animation_saut;
void lancer_animation_saut() {
    numero_piece_sautant = jeu.nb_piece;
    Animation animation = {1, 10, 75, 900, 0, 0};
    *animation_saut = animation;
    // while (numero_piece == jeu.nb_piece && jeu.etat == JEU){
    //     descendre_piece();
    // }
}

void animer_saut() {
    if(animation_saut != NULL) {
        
    }
}
