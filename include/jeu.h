#ifndef JEU_H
#define JEU_H
#include "../src/tetris.h"
///////////////
// Affichage //
///////////////
void affichageJeu();

// affiche un carreau d'une couleur donnée
void afficherCarreau(int y, int x, char couleur);
// affiche Tetris en haut à droite à gauche de l'écran
void afficherTitre(int y, int x);
// affiche prochaine pièce
void afficherProchainePiece(Tétrominos piece);
// affiche une aide pour les touches
void afficherAides();
// affiche le score du joueur, le temps écoulé (utiliser)
void afficherScore();

// on utilise la variable globale jeu
void afficherPrevisualisation();

///////////////////
// Temporisation //
///////////////////

// chaque 30s, la temporisation s'accélère.
// trouve le temps depuis le démarrage de la partie 
// (avec jeu.temps, tempsCPU() et demandeTemporisation(...))
void gestion_rapidite(); 

// trouve les indices de toutes les lignes completes
// retourne le nombre d'indices et on remplit les indices dans le tableau passé en paramètres
int trouver_indices_lignes_completes(char *grille[LIGNES][COLONNES], int *indices);

// utiliser la variable global jeu pour monter la pièce
// renvoie 1 si ça fonctionne et 0 ça fonctionne pas.
void descendre_piece();

/////////////
// Entrées //
/////////////

// gères toutes les entrées de l'utilisateur
// - Q -> bouger la pièce à Gauche
// - D -> bouger la pièce à Droite
// - Z -> accélerer la pièce
// - Espace -> Faire sauter la pièce
void entreesJeu();

// gères toutes les entrées spéciales de l'utilisateur
// - Flèche de gauche pour aller à gauche -> bouger la pièce à Gauche
// - Flèche de droite pour aller à droite -> bouger la pièce à Droite
// - Flèche du haut pour accélerer -> accélérer la piècer
void entreesSpécialesJeu();

// bouge la pièce dans la variable globale jeu vers la droite si possible
void bouger_piece_droite();

// bouge la pièce dans la variable globale jeu vers la gauche si possible
void bouger_piece_gauche();

#endif