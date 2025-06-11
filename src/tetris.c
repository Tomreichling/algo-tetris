#include "./tetris.h"

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);

int main(int argc, char **argv)
{
    srand(time(NULL));
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("OpenGL", LARGEUR, LONGUEUR);
	lanceBoucleEvenements();
	return 0;
}

// Variable globale accessible dans tous le programme.
Jeu jeu = {0};

void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL;
	
	switch (evenement)
	{
		case Initialisation:
            image = lisBMPRGB("./assets/titre-tetris.bmp");
			demandeTemporisation(-1);
			jeu.etat = MENU;
			break;
		case Temporisation:
            switch (jeu.etat)
            {
                case JEU:
                    // On vérifie si on peut descendre la pièce
                    // on la descends ou la place sur grille
                    descendre_piece();
                    
                    // On trouve les lignes complètes
                    int *indices = NULL; 
                    int lignes = trouver_indices_lignes_completes(jeu.grille, indices);
                    if(indices == NULL) {
                        break;
                    }

                    // On assigne un score en conséquent
                    assigner_score(lignes);
                    // On supprime les lignes complètes en partant du haut de la grille
                    for(int i = 0; i < lignes; i++) {
                        // retire_ligne(indices[i], jeu.grille);
                    }
                    break;
                default:
                    break;
            }
			
			rafraichisFenetre();
			break;
		case Affichage:
            switch (jeu.etat)
            {
                case MENU:
					afficheMenu(image);
                    break;
                case JEU:
					affichageJeu();
					afficherTitre(16, 3);
					afficherProchainePiece(jeu.prochaine_piece);
					afficherAides();
					afficherScore();

                    for(int i = 0; i < COLONNES; i++) {
                        for(int j = 0; j < LIGNES; j++) {
                            if(jeu.grille[i][j] == 0) {
                                continue;
                            }
                            afficherCarreau(i, j, jeu.grille[i][j]);
                        }
                    }

                    for(int i = 0; i < 4; i++) {
                        for(int j = 0; j < 4; j++) {
                            if(jeu.piece.grille[i][j] == 0) {
                                continue;
                            }
                            afficherCarreau(jeu.piece.x + i, jeu.piece.y + j, jeu.piece.grille[i][j]);
                        }
                    }
                    break;
                case FIN:
                    // Afficher le jeu + Gameover + score
                    break;
            }
			break;
		case Clavier:
            if(caractereClavier() == 'f') {
                pleinEcran = !pleinEcran;
                if (pleinEcran)
                    modePleinEcran();
                else
                    redimensionneFenetre(LARGEUR, LONGUEUR);
                break;
            }
            switch(jeu.etat) {
                // *caractereClavier() donne la touche*
                case MENU:
                    switch (caractereClavier()){
                        case 'q':
                        case 'Q':

                           libereDonneesImageRGB(&image);
					                 termineBoucleEvenements();
                            break;
                        case 32:
                            // espace pour démarrer le jeu 
                            demarrer_jeu();
                            break;
                    }
                    break;
                case JEU:
                    // p pour mettre le jeu en pause
                    // q pour aller à gauche
                    // d pour aller à droite
                    // s pour aller en bas
                    // e ou r pour tourner la pièce
                    // espace pour sauter
                    break;
                                case FIN:
				        	switch (caractereClavier()) {
					        	case 'q':
					        	case 'Q':
						        	libereDonneesImageRGB(&image);
						        	termineBoucleEvenements();
						        	break;

						//espace pour recommencer
						case 32:
							demarrer_jeu();
							break;
					}
                    break;
            }
		case ClavierSpecial:
            switch(jeu.etat) {
                case JEU:
                    // Flèche gauche -> aller à gauche
                    // Flèche droite -> aller à droite
                    // Flèche du bas -> aller en bas
                    // Flèche du haut -> tourner la pièce
                    break;
                default:
                    printf("ASCII %d\n", toucheClavier());
                    break;
            }
			break;
		
		case Redimensionnement: 
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
        default:
            break;
	}
}