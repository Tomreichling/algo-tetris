#include "tetris.h"

static int numero_piece_sautant;
static Animation *animation_saut;
static Animation *scintillement = NULL;
static Animation anim_scintillement;

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

void lancer_scintillement() {
    anim_scintillement.interval = 1000;
    anim_scintillement.etape = 25;
    scintillement = &anim_scintillement;
    demandeRedessinDans_ms(scintillement->interval);
}

void scintillementPalier() {
    int hauteur = hauteurFenetre() - 80;
    int taille_carreau = hauteur / LIGNES;
    int marge = 40;
    
    //animation de scintillement a chaque palier passer
    if (scintillement != NULL && scintillement->etape > 0) {
        if (scintillement->etape % 2 == 0) {
            couleurCourante(255, 0, 0);
        }
        else {
            couleurCourante(0, 0, 0);
        }
        epaisseurDeTrait(10);
        ligne(marge, marge, marge + (taille_carreau * COLONNES), marge);
        ligne(marge, marge + (taille_carreau * LIGNES), marge + (taille_carreau * COLONNES), marge + (taille_carreau * LIGNES));
        ligne(marge, marge, marge, marge + (taille_carreau * LIGNES));
        ligne(marge + (taille_carreau * COLONNES), marge, marge + (taille_carreau * COLONNES), marge + (taille_carreau * LIGNES));
        scintillement->etape--;
        demandeRedessinDans_ms(scintillement->interval);
    
    } 
    else {
        scintillement = NULL;
    }
}

