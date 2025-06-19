#include "../tetris.h"

void boutons_souris_menu() {
    switch (etatBoutonSouris()) {
        case GaucheAppuye:
            printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
            int max_x = largeurFenetre();
            int max_y = hauteurFenetre();
            int padding = 64;
            // Si le bouton gauche de la souris est appuye, faire repartir
            // la balle de la souris
            int sourisX = abscisseSouris();
            int sourisY = ordonneeSouris();
					
            int demarrerX = max_x - padding - image_demarrer->largeurImage;
            int demarrerY = max_y - padding - image_demarrer->hauteurImage;
        
            int multiX = max_x - padding - image_multijoueur->largeurImage;
            int multiY = max_y / 2 - image_multijoueur->hauteurImage / 2;
        
            int quitterX = max_x - padding - image_quitter->largeurImage;
            int quitterY = padding;

            int nouveauX = demarrerX + image_demarrer->largeurImage;
            int nouveauY = demarrerY + image_demarrer->hauteurImage;

            int nouveauX_Multi = multiX + image_multijoueur->largeurImage;
            int nouveauY_Multi = multiY + image_multijoueur->hauteurImage;

            int nouveauX_Quitter = quitterX + image_quitter->largeurImage;
            int nouveauY_Quitter = quitterY + image_quitter->hauteurImage;

            if ((sourisX >= demarrerX) && (sourisX <= nouveauX) && (sourisY >= demarrerY) && (sourisY <= nouveauY)) {
                printf("Clic dans la zone du bouton DÉMARRER\n");
            } else if((sourisX >= multiX) && (sourisX <= nouveauX_Multi) && (sourisY >= multiY) && (sourisY <= nouveauY_Multi)) {
                printf("Clic dans la zone du bouton MULTIJOUEUR\n");
            } else if ((sourisX >= quitterX) && (sourisX <= nouveauX_Quitter) && (sourisY >= quitterY) && (sourisY <= nouveauY_Quitter)) {
                printf("Clic dans la zone du bouton QUITTER\n");
            }
        default:
            break;
    }
}
