#include "tetris.h"

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

void gestionEvenement(EvenementGfx evenement){
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static bool pause = false;
	static DonneesImageRGB *image = NULL;
    static DonneesImageRGB *image2 = NULL;
    static DonneesImageRGB *image3 = NULL;
    int static minutes;
    int static secondes;
	
	switch (evenement)
	{
		case Initialisation:
            image = lisBMPRGB("./assets/Group_1.bmp");
            image2 = lisBMPRGB("./assets/Group_2.bmp");
            image3 = lisBMPRGB("./assets/Group_3.bmp");
			demandeTemporisation(-1);
			jeu.etat = MENU;

			break;
		case Temporisation:
            switch (jeu.etat)
            {
                case JEU: {
                    // On vérifie si on peut descendre la pièce
                    // on la descends ou la place sur grille
                    descendre_piece();
                    
                    // On trouve les lignes complètes
                    int static indices[4]; 
                    int lignes = trouver_indices_lignes_completes(jeu.grille, indices);

                    //timer
                    secondes ++;
                    if (secondes == 60) {
                        minutes ++;
                        secondes = 0;
                    }
                    
                    // On assigne un score en conséquent
                    assigner_score(lignes);
                    // On supprime les lignes complètes en partant du haut de la grille
                    for(int i = 0; i < lignes; i++) {
                        retire_ligne(indices[i]);
                    }
                    break;
                }
                default:
                    break;
            }
			
			rafraichisFenetre();
			break;
		case Affichage:
            switch (jeu.etat)
            {
                case MENU:
					afficheMenu(image, image2, image3);
                    break;
                case JEU:
					affichageJeu();
					afficherTitre(16, 3);
					afficherProchainePiece(jeu.prochaine_piece);
					afficherAides();
					afficherScore();
                    afficherTimer(minutes, secondes);


                    int y_previ, y_base = jeu.piece.y;
                    while (descente_possible(&jeu.piece)) {   
                            jeu.piece.y++;
                    }    
                    y_previ = jeu.piece.y;
                    jeu.piece.y = y_base;

                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            if (jeu.piece.grille[i][j] == 0) {
                                continue;
                            }
                            afficherPrevisualisation(jeu.piece.x + i, y_previ + j, jeu.piece.grille[i][j]);
                        }
                    }

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
		case Clavier: {
            char caractere = caractereClavier();
            
            if(caractere == 'f') {
                pleinEcran = !pleinEcran;
                if (pleinEcran)
                    modePleinEcran();
                else
                    redimensionneFenetre(LARGEUR, LONGUEUR);
                break;
            } else if(caractere == 'p') {
                pause = !pause;
                if(pause) {
                    demandeTemporisation(-1);
                } else {
                    demandeTemporisation(1000);
                }
            }
            if(pause) break;
            switch(jeu.etat) {
                // *caractereClavier() donne la touche*
                case MENU:
                    switch (caractere){
                        case 'q':
                        case 'Q':

                            libereDonneesImageRGB(&image);
                            libereDonneesImageRGB(&image2);
                            libereDonneesImageRGB(&image3);

					        termineBoucleEvenements();
                            break;
                        case 32:
                            demarrer_jeu();
                            break;
                    }
                    break;
                case JEU:
                    entrees_jeu();
                    break;
                case FIN:
				    switch (caractere) {
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
            break;
        }
		case ClavierSpecial:
            if(pause) break;
            switch(jeu.etat) {
                case JEU:
                    entrees_speciales_jeu();
                    break;
                default:
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