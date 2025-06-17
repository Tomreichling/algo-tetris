void boutons_souris_menu(DonneesImageRGBA* demarrer, DonneesImageRGBA *multijoueur, DonneesImageRGBA* quitter) {
    switch (etatBoutonSouris()) {
        case GaucheAppuye:
            printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
            // Si le bouton gauche de la souris est appuye, faire repartir
            // la balle de la souris
            int sourisX = abscisseSouris();
            int sourisY = ordonneeSouris();
					
            int demarrerX = max_x - padding - demarrer->largeurImage;
            int demarrerY = max_y - padding - demarrer->hauteurImage;
        
            int multiX = max_x - padding - mutlijoueur->largeurImage;
            int multiY = max_y / 2 - mutlijoueur->hauteurImage / 2;
        
            int quitterX = max_x - padding - quitter->largeurImage;
            int quitterY = padding;

            int nouveauX = demarrerX + demarrer->largeurImage;
            int nouveauY = demarrerY + demarrer->hauteurImage;

            int nouveauX_Multi = multiX + mutlijoueur->largeurImage;
            int nouveauY_Multi = multiY + mutlijoueur->hauteurImage;

            int nouveauX_Quitter = quitterX + quitter->largeurImage;
            int nouveauY_Quitter = quitterY + quitter->hauteurImage;

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
