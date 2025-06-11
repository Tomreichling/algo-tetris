#ifndef JEU_H
#define JEU_H
#include "../src/tetris.h"
///////////////
// Affichage //
///////////////


void affichageJeu();

// affiche un carreau d'une couleur donnée
void afficherCarreau(int x, int y, char couleur);
// affiche Tetris en haut à droite à gauche de l'écran
void afficherTitre(int y, int x);
// affiche prochaine pièce
void afficherProchainePiece(Tétrominos piece);
// affiche une aide pour les touches
void afficherAides();
// affiche le score du joueur, le temps écoulé (utiliser)
void afficherScore();

// on utilise la variable globale jeu
void afficherPrevisualisation(int x, int y, char couleur);

///////////////////
// Temporisation //
///////////////////


// Alla 


// chaque 30s, la temporisation s'accélère.
// trouve le temps depuis le démarrage de la partie 
// (avec jeu.temps, tempsCPU() et demandeTemporisation(...))
void gestion_rapidite(); 

// trouve les indices de toutes les lignes completes
// retourne le nombre d'indices et on remplit les indices dans le tableau passé en paramètres
int trouver_indices_lignes_completes(char grille[LIGNES][COLONNES], int *indices);

// Assigne un certain score en fonction d'un nombre de lignes detruites
// ex: 2 lignes detruites => + 200pts (utilise jeu.score)
void assigner_score(int nb_indices);

// supprime la ligne d'indice i et descends le reste du tableau d'une ligne 
// (seulement les lignes haut-dessus)
void retire_ligne(int i, char grille[LIGNES][COLONNES]);

// Renvoie 1 si on peut descendre la pièce de y + 1 sinon 0
int descente_possible(Tétrominos *piece);

// utiliser la variable global jeu pour monter la pièce
void descendre_piece();

/////////////
// Entrées //
/////////////

// gères toutes les entrées de l'utilisateur
// - Q -> bouger la pièce à Gauche
// - D -> bouger la pièce à Droite
// - Z -> accélerer la pièce
// - Espace -> Faire sauter la pièce
void entrees_jeu();

// gères toutes les entrées spéciales de l'utilisateur
// - Flèche de gauche pour aller à gauche -> bouger la pièce à Gauche
// - Flèche de droite pour aller à droite -> bouger la pièce à Droite
// - Flèche du haut pour accélerer -> accélérer la piècer
void entrees_speciales_jeu();

// bouge la pièce dans la variable globale jeu vers la droite si possible
void bouger_piece_droite();

// bouge la pièce dans la variable globale jeu vers la gauche si possible
void bouger_piece_gauche();

#endif