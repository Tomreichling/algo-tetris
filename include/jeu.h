#ifndef JEU_H
#define JEU_H
#include "../src/tetris.h"

// affichage
void affichageJeu();

// affiche un carreau d'une couleur donnée
void afficherCarreau(int x, int y, char couleur);
// affiche Tetris en haut à droite à gauche de l'écran
void afficherTitre(int x, int y);
// affiche prochaine pièce
void afficherProchainePiece(Tétrominos piece);
// affiche une aide pour les touches
void afficherAides();
// affiche le score du joueur, le temps écoulé (utiliser)
void afficherScore();

// temporisation

// entrees
#endif