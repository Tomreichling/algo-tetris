#include "tetris.h"

static int numero_piece_sautant;
static Animation *animation_saut;
void lancer_animation_saut() {
    numero_piece_sautant = jeu.nb_piece;
    Animation animation = {100, 0};
    animation_saut = &animation;
    demandeRedessinDans_ms(animation_saut->interval);
}

void animer_saut() {
    if(animation_saut != NULL 
        && numero_piece_sautant == jeu.nb_piece 
        && jeu.etat == JEU) {
        descendre_piece();
        demandeRedessinDans_ms(animation_saut->interval);
    } else if(animation_saut != NULL && 
        (numero_piece_sautant != jeu.nb_piece)) {
        animation_saut = NULL;
    }
}
