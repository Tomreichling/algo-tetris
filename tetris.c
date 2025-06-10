#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "gfx/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "gfx/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "gfx/ESLib.h" // Pour utiliser valeurAleatoire()

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);



int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	
	prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
	
	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();
	
	return 0;
}

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas

	
	switch (evenement)
	{
		case Initialisation:
			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			
			rafraichisFenetre();
			break;
			
		case Affichage:
			
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			
			// Affichage d'une ligne bleue
			couleurCourante(0, 0, 255);
			epaisseurDeTrait(10);
			ligne(0, 0, (largeurFenetre()-600)/2, (hauteurFenetre()-400)/2);

			// Affichage d'un rectangle "saumon"
			couleurCourante(255, 128, 128);
			rectangle((largeurFenetre()-600)/2, (hauteurFenetre()-400)/2, (largeurFenetre()-600)/2+600, (hauteurFenetre()-400)/2+400);

			// Affichage d'un texte vert sombre avec ombrage en police de taille 20
			// L'effet d'ombrage vient tout simplement du dessin du texte en gris clair
			// sous le texte voulu, avec un léger décalage
			couleurCourante(210, 210, 210);
			epaisseurDeTrait(3);
			afficheChaine("L'algo c'est rigolo", 20, 77, 13);
			couleurCourante(0, 128, 0);
			epaisseurDeTrait(2);
			afficheChaine("L'algo c'est rigolo", 20, 75, 15);

			couleurCourante(255, 0, 0);
			break;
			
		case Clavier:
			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					break;
				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
				case 'r':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'S':
				case 's':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
			}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			switch (etatBoutonSouris())
			{
				case GaucheAppuye:
					printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
					// Si le bouton gauche de la souris est appuye, faire repartir
					// la balle de la souris
					break;
				case GaucheRelache:
					printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
					break;
				case DroiteAppuye:
				case DroiteRelache:
					puts("Bouton droite");
					break;
				case MilieuAppuye:
				case MilieuRelache:
					puts("Bouton milieu");
					break;
				case ScrollDown:
					puts("Scroll down");
					break;
				case ScrollUp:
					puts("Scroll up");
					break;
				case ScrollRight:
					puts("Scroll right");
					break;
				case ScrollLeft:
					puts("Scroll left");
					break;
			}
			break;
		
		case Souris: // Si la souris est deplacee
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}
