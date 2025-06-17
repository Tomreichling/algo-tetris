#include "tetris.h"

static int numero_piece_sautant;
static Animation *animation_saut;
static Animation *scintillement;

void lancer_animation_saut() {
    numero_piece_sautant = jeu.nb_piece;
    Animation animation = {100, 0};
    animation_saut = &animation;
    demandeRedessinDans_ms(animation_saut->interval);
}

void animer_saut() {
    if(animation_saut != NULL 
        && numero_piece_sautant == jeu.nb_piece 
        && (jeu.etat == JEU || jeu.etat == MULTI)) {
        descendre_piece();
        demandeRedessinDans_ms(animation_saut->interval);
    } else if(animation_saut != NULL && 
        (numero_piece_sautant != jeu.nb_piece)) {
        animation_saut = NULL;
    }
}

void lancer_scintillement() {
    Animation animation = {1000, 3};
    scintillement = &animation;
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
            // couleurCourante(0, 0, 0); //pour les lignes
            couleurCourante(255, 255, 255); //pour les rectangles
        }
        rectangle(marge, marge, marge + (taille_carreau * COLONNES), marge + (taille_carreau * LIGNES));
        // ligne(marge, marge, marge + (taille_carreau * COLONNES), marge);
        // ligne(marge, marge + (taille_carreau * LIGNES), marge + (taille_carreau * COLONNES), marge + (taille_carreau * LIGNES));
        // ligne(marge, marge, marge, marge + (taille_carreau * LIGNES));
        // ligne(marge + (taille_carreau * COLONNES), marge, marge + (taille_carreau * COLONNES), marge + (taille_carreau * LIGNES));
        scintillement->etape--;
        demandeRedessinDans_ms(scintillement->interval);
    } else {
        scintillement = NULL;
    }
}

void animer_gameover() {
    static int t = 0;
    if (image_gameover == NULL){
        return; 
    }
    t += 1;
    unsigned char *pixels = image_gameover->donneesRGBA;
    for (int i = 0; i < (4 * image_gameover->largeurImage * image_gameover->hauteurImage); i += 4){
        if(pixels[i] == 0 && pixels[i + 1] == 0 && pixels[i + 2] == 0 && pixels[i + 3] == 0) {
            // donc zone qui contient pas de texte 
            continue;
        }

        // pixels[i] = 80;
        // pixels[i + 1] = 0;
        // pixels[i + 2] = 250;
        pixels[i + 3] = (char) 255.0 * (1.0 + cos (0.1 * t) * 0.5); // devenu un char 

    }
    demandeRedessinDans_ms(100); 
}