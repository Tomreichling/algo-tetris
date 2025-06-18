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

// Variable globale du jeu pour l'ennemi (en pointeur)
Jeu *jeu_ennemi = NULL;

// Images accessibles globalement
DonneesImageRGBA *image_gameover;
DonneesImageRGBA *image_demarrer;
DonneesImageRGBA *image_multijoueur;
DonneesImageRGBA *image_quitter;
DonneesImageRGBA *image_titre;
DonneesImageRGBA *image_gemme;
DonneesImageRGBA *image_gemmeRouge;

void gestionEvenement(EvenementGfx evenement){
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static bool pause = false;

	switch (evenement)
	{
		case Initialisation:
            image_titre = lisBMPRGBA("./assets/tetrisen.bmp");
			demandeTemporisation(-1);
			jeu.etat = IDENTITE;

            initialiser_pieces_menu();
			break;
		case Temporisation:
            switch (jeu.etat)
            {
                case MULTI:
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
					afficheIdent(image_titre);
                    break;
                case MENU:
                    recupGemmes();
                    afficheGrilleMenu();
                    afficherPiecesMenu();
					afficheMenu(image_demarrer, image_multijoueur, image_quitter, image_titre, image_gemme);
                    break;
                case JEU:
					affichageJeu();
                    scintillementPalier();
					afficherTitre(16, 3, image_titre);
					afficherProchainePiece(jeu.prochaine_piece);
					afficherAides();
					afficherScore(image_gemme);
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
                    ecranGameOver();
                    for(int i = 0; i < COLONNES; i++) {
                        for(int j = 0; j < LIGNES; j++) {
                            if(jeu.grille[i][j] == 0) {
                                continue;
                            }
                            afficherCarreau(i, j, jeu.grille[i][j]);
                        }
                    }
                    break;
                case MULTI: //mode multijoueur
                    affichageJeu();
                    affichageEnnemi();
                    // affichageSupp();
                    affichageBarresScroll(image_gemme, image_gemmeRouge);
                    afficherProchainePiece(jeu.prochaine_piece);

                    animer_saut();
                    
                    //ici on fait la meme chose que pour jeu, on affiche dans la grille les pieces et le previsualisation de la premiere grille
                    int y_previMulti, y_baseMulti = jeu.piece.y;
                    while (descente_possible(&jeu.piece)) {   
                        jeu.piece.y++;
                    }    
                    y_previMulti = jeu.piece.y;
                    jeu.piece.y = y_baseMulti;

                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            if (jeu.piece.grille[i][j] == 0) {
                                continue;
                            }
                            afficherCarreau(jeu.piece.x + i, y_previMulti + j, 8);
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
                    
                    //fin affichage dans la premiere grille
                    //on fait la meme chose mais pour la grille ennemi
                    //on ne met pas de previsualisation car pas besoin

                    for(int i = 0; i < COLONNES; i++) {
                        for(int j = 0; j < LIGNES; j++) {
                            if(jeu.grille[i][j] == 0) {
                                continue;
                            }
                            afficherCarreauEnnemi(i, j, jeu.grille[i][j]);
                        }
                    }

                    for(int i = 0; i < 4; i++) {
                        for(int j = 0; j < 4; j++) {
                            if(jeu.piece.grille[i][j] == 0) {
                                continue;
                            }
                            afficherCarreauEnnemi(jeu.piece.x + i, jeu.piece.y + j, jeu.piece.grille[i][j]);
                        }
                    }
                    break;
                    //fin de l'affichage dans la grille ennemi
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
            } else if(caractere == 'p'  && jeu.etat != IDENTITE && jeu.etat != MULTI) {
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
                        case 27: // echap
                            libereDonneesImageRGBA(&image_titre);
                            termineBoucleEvenements();
                            break;
                        case 13: // entrer
                            image_demarrer = lisBMPRGBA("./assets/demarrer.bmp");
                            image_gemme = lisBMPRGBA("./assets/gem.bmp");
                            image_multijoueur = lisBMPRGBA("./assets/multijoueur.bmp");
                            image_quitter = lisBMPRGBA("./assets/quitter.bmp");
                            jeu.etat = MENU;
                            break;
                    }
                    break;
                case MENU:
                    switch (caractere){
                        case 27: // echap
                            libereDonneesImageRGBA(&image_demarrer);
                            libereDonneesImageRGBA(&image_multijoueur);
                            libereDonneesImageRGBA(&image_quitter);
                            libereDonneesImageRGBA(&image_titre);
                            libereDonneesImageRGBA(&image_gemme);
                            stopper_musique();
                            termineBoucleEvenements();
                            break;
                        case 32: // barre d'espace
                            libereDonneesImageRGBA(&image_demarrer);
                            libereDonneesImageRGBA(&image_multijoueur);
                            libereDonneesImageRGBA(&image_quitter);
                            
                            stopper_musique();
                            demarrer_jeu();
                            demarrer_musique();
                            break;
                        case 'M': //touche M
                        case 'm': //touche m 
                            image_gemmeRouge = lisBMPRGBA("./assets/gem-rouge.bmp");
                            stopper_musique();
                            demarrer_multi();
                            demarrer_musique();
                            libereDonneesImageRGBA(&image_demarrer);
                            libereDonneesImageRGBA(&image_titre);
                            libereDonneesImageRGBA(&image_multijoueur);
                            libereDonneesImageRGBA(&image_quitter);
                            break;
                    }   
                    break;
                case MULTI: 
                case JEU:
                    entrees_jeu();
                        switch (caractere){
                            case 27: // echap
                                libereDonneesImageRGBA(&image_demarrer);
                                libereDonneesImageRGBA(&image_multijoueur);
                                libereDonneesImageRGBA(&image_quitter);
                                libereDonneesImageRGBA(&image_titre);
                                libereDonneesImageRGBA(&image_gemme);
                                stopper_musique();
				                termineBoucleEvenements();
                            break;
                    }
                    break;                   
                case FIN:
				    switch (caractere) {
				    	case 27: // echap
                            enregistrerScores();
                            libereDonneesImageRGBA(&image_demarrer);
                            libereDonneesImageRGBA(&image_multijoueur);
                            libereDonneesImageRGBA(&image_quitter);
                            libereDonneesImageRGBA(&image_titre);
                            libereDonneesImageRGBA(&image_gemme);
                            libereDonneesImageRGBA(&image_gameover);
                            stopper_musique();
                            termineBoucleEvenements();
                            break;
                        case 32:
                            enregistrerScores();
                            stopper_musique();
                            demarrer_jeu();
                            demarrer_musique();
                            
                            libereDonneesImageRGBA(&image_gameover);
                            libereDonneesImageRGBA(&image_demarrer);
                            libereDonneesImageRGBA(&image_multijoueur);
                            libereDonneesImageRGBA(&image_quitter);
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
                case MULTI:
                    entrees_speciales_jeu();
                    break;
                default:
                    break;
            }
			break;
        case BoutonSouris:
            switch(jeu.etat) {
                case MENU:
                    boutons_souris_menu();
                    break;
            }
            break;
        default:
            break;
	}
}