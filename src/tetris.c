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
                    // - Vérifier si on peut descendre la pièce actuelle
                    // - Descendre la pièce actuelle si possible
                    // - sinon placer la pièce dans la grille
                    // - et prendre la suivante
                    // - vérifier si des lignes peuvent se supprimer
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
					afficherCarreau(0, 0, 1);
					afficherCarreau(0, 19, 2);
					afficherCarreau(9, 19, 3);
					afficherCarreau(9, 0, 4);
					afficherCarreau(4, 9, 1);
					afficherTitre(16, 3);
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
                            demarrer_jeu();
                            break;
                    }
                    // espace pour démarrer le jeu 
                    // q pour quitter le jeu
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
                    // q pour quitter le jeu
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
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
        default:
            break;
	}
}

 