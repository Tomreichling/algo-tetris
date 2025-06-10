
// ecran
#DEFINE LARGEUR 1200
#DEFINE LONGUEUR 800

// Tableau
#DEFINE COLONNES 10
#DEFINE LIGNES 20

typedef struct {
    int temps; 
    int score;
    int etat;
    char grille [COLONNES][LIGNES];
    // actuelle
    Tétrominos piece;
    // next
    Tétrominos prochaine_piece;
    
}Jeu;

typedef struct {
    int x;
    int y;
    char rotation;
    char grille [4][4];

}Tétrominos;
 

