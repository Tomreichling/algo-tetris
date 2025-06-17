#include "../tetris.h"

// La grille du menu fait 25 carreaux de hauteurs
// taille_carreau -> hauteurFenetre() / 25
// lignes -> 25
// colonnes -> largeurFenetre() / taille_carreau

bool dansGrilleMenu(int x, int y) {
    return x < 0 
        || x >= (largeurFenetre() * 25) / hauteurFenetre()
        || y < 0
        || y >= 25;
}

void deplacer_piece_menu(Tétrominos* piece, int vx, int vy) {
    bool deplacement_possible = true;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(piece->grille[i][j] == 0) {
                continue;
            }

            int x = piece->x + i + vx; // vx: -1 ou 1 ou 0
            int y = piece->y + j + vy; // vy: -1 ou 1 ou 0
            if(dansGrilleMenu(x, y)) {
                deplacement_possible = false;
            }
        }
    }
    if(deplacement_possible) {
        piece->x += vx;
        piece->y += vy;
        rafraichisFenetre();
    }
}

void tourner_piece_menu(Tétrominos* piece) {
    // tourner la pièce
    bool rotation_possible = true;
    int copie[4][4];

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int x = piece->x + i;
            int y = piece->y + j;
            if(dansGrilleMenu(x, y) ||
                (jeu.grille[x][y] != 0)
            ) {
                rotation_possible = false;
                break;
            }
            copie[i][j] = piece->grille[j][3 - i];
        }
    }
    if(!rotation_possible) {
        return;
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            piece->grille[i][j] = copie[i][j];
        }
    }
    rafraichisFenetre();
}

void initialiser_pieces_menu() {
    int taille_carreau = hauteurFenetre() / 25;
    int largeur = largeurFenetre();
    for(int i = 0; i < NB_PIECES_MENU; i++) {
        pieces_menu[i] = CreerTetrominos(rand() % 7);
        int x = rand() % (largeur / taille_carreau);
        int y = rand() % 26;

        pieces_menu[i].x = x;
        pieces_menu[i].y = y;
        jeu.nb_piece++;
    }
    demandeTemporisation(1000);
}