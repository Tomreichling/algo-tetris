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
DonneesImageRGBA *image_gameover;

void gestionEvenement(EvenementGfx evenement){
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static bool pause = false;
	static DonneesImageRGBA *demarrer = NULL;
	static DonneesImageRGBA *multijoueur = NULL;
	static DonneesImageRGBA *quitter = NULL;
    static DonneesImageRGBA *titre = NULL;
    static DonneesImageRGBA *gemme = NULL;
    static DonneesImageRGBA *the_score = NULL; 
    static DonneesImageRGBA *restart = NULL;

	switch (evenement)
	{
		case Initialisation:
            demarrer = lisBMPRGBA("./assets/demarrer.bmp");
            multijoueur = lisBMPRGBA("./assets/multijoueur.bmp");
            quitter = lisBMPRGBA("./assets/quitter.bmp");
            titre = lisBMPRGBA("./assets/tetrisen.bmp");
            gemme = lisBMPRGBA("./assets/gem.bmp");
            the_score= lisBMPRGBA ("./assets/the_score.bmp");
            restart = lisBMPRGBA ("./assets/redemarrer.bmp");
			demandeTemporisation(-1);
			jeu.etat = IDENTITE;

            initialiser_pieces_menu();
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
                    jeu.secondes ++;
                    if (jeu.secondes == 60) {
                        jeu.minutes ++;
                        jeu.secondes = 0;
                    }
                    
                    // On assigne un score en conséquent
                    assigner_score(lignes);
                    // On supprime les lignes complètes en partant du haut de la grille
                    for(int i = 0; i < lignes; i++) {
                        retire_ligne(indices[i]);
                    }
                    break;
                }
                case MENU:
                    for(int n = 0; n < NB_PIECES_MENU; n++) {
                        int operation = rand() % 6; 
                        switch(operation) {
                            // 0 rien
                            case 1: // gauche
                                deplacer_piece_menu(&pieces_menu[n], -1, 0);
                                break;
                            case 2: // droite
                                deplacer_piece_menu(&pieces_menu[n], 1, 0);
                                break;
                            case 3: // haut
                                deplacer_piece_menu(&pieces_menu[n], 0, -1);
                                break;
                            case 4: // droite
                                deplacer_piece_menu(&pieces_menu[n], 0, 1);
                                break;
                            case 5: // tourner
                                tourner_piece_menu(&pieces_menu[n]);
                                break;
                            
                        }
                    }
                default:
                    break;
            }
			
			rafraichisFenetre();
			break;
		case Affichage:
            switch (jeu.etat)
            {
                case IDENTITE:
					afficheIdent(titre);
                    break;

                case MENU:
                    recupGemmes();
                    afficheGrilleMenu();
                    afficherPiecesMenu();
					afficheMenu(demarrer, multijoueur, quitter, titre, gemme);
                    break;
                case JEU:
					affichageJeu();
                    scintillementPalier();
					afficherTitre(16, 3, titre);
					afficherProchainePiece(jeu.prochaine_piece);
					afficherAides();
					afficherScore();
                    afficherTimer(jeu.minutes, jeu.secondes);

                    animer_saut();
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
                            afficherCarreau(jeu.piece.x + i, y_previ + j, 8);
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
                    ecranGameOver(quitter, multijoueur, the_score, restart);
                    for(int i = 0; i < COLONNES; i++) {
                        for(int j = 0; j < LIGNES; j++) {
                            if(jeu.grille[i][j] == 0) {
                                continue;
                            }
                            afficherCarreau(i, j, jeu.grille[i][j]);
                        }
                    }
                    break;
            }
			break;
		case Clavier: {
            char caractere = caractereClavier();
            
            if(caractere == 'f' && jeu.etat != IDENTITE) {
                pleinEcran = !pleinEcran;
                if (pleinEcran)
                    modePleinEcran();
                else
                    redimensionneFenetre(LARGEUR, LONGUEUR);
                break;
            } else if(caractere == 'p'  && jeu.etat != IDENTITE) {
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
                case IDENTITE:
                    entreeNom();
                    switch (caractere){

                        case 27 :
                            libereDonneesImageRGBA(&demarrer);
                            libereDonneesImageRGBA(&multijoueur);
                            libereDonneesImageRGBA(&quitter);
                            libereDonneesImageRGBA(&titre);
                            libereDonneesImageRGBA(&gemme);
                            libereDonneesImageRGBA(&restart);
                            libereDonneesImageRGBA(&the_score);
                            termineBoucleEvenements();
                            break;
                        case 13:
                            jeu.etat = MENU;
                            break;
                    }
                    break;
                    
                case MENU:
                    switch (caractere){
                        case 27 :
                            libereDonneesImageRGBA(&demarrer);
                            libereDonneesImageRGBA(&multijoueur);
                            libereDonneesImageRGBA(&quitter);
                            libereDonneesImageRGBA(&titre);
                            libereDonneesImageRGBA(&gemme);
                            libereDonneesImageRGBA(&restart);
                            libereDonneesImageRGBA(&the_score);
                            stopper_musique();
                            termineBoucleEvenements();
					        
                            break;
                        case 32:
                            libereDonneesImageRGBA(&demarrer);
                            // libereDonneesImageRGBA(&multijoueur);
                            // libereDonneesImageRGBA(&quitter);
                            libereDonneesImageRGBA(&gemme);
                            stopper_musique();
                            demarrer_jeu();
                            libereDonneesImageRGBA(&demarrer);
                            // libereDonneesImageRGBA(&multijoueur);
                            // libereDonneesImageRGBA(&quitter);

                            break;
                    }
                    break;
                case JEU:
                    entrees_jeu();
                        switch (caractere){
                            case 27 :
                                libereDonneesImageRGBA(&demarrer);
                                libereDonneesImageRGBA(&restart);
                                libereDonneesImageRGBA(&the_score);
                                libereDonneesImageRGBA(&multijoueur);
                                libereDonneesImageRGBA(&quitter);
                                libereDonneesImageRGBA(&titre);
                                libereDonneesImageRGBA(&gemme);
                                stopper_musique();
				                termineBoucleEvenements();
                            break;
                    }
                    break;                   
                case FIN:
				    switch (caractere) {
				    	case 27 :
                            enregistrerScores();
                            libereDonneesImageRGBA(&demarrer);
                            libereDonneesImageRGBA(&multijoueur);
                            libereDonneesImageRGBA(&quitter);
                            libereDonneesImageRGBA(&titre);
                            libereDonneesImageRGBA(&gemme);
                            libereDonneesImageRGBA(&image_gameover);
                            libereDonneesImageRGBA(&the_score);
                            libereDonneesImageRGBA (&restart);
                            stopper_musique();
                            termineBoucleEvenements();
				    
						case 32:

                            enregistrerScores();
                            stopper_musique();
                            demarrer_jeu();
                            demarrer_musique();

                            libereDonneesImageRGBA(&demarrer);
                            libereDonneesImageRGBA(&gemme);
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
        default:
            break;
	}
}