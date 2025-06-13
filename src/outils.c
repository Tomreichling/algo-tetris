#include "tetris.h"

void copier_tableau44(char entree[4][4], char sortie[COLONNES][LIGNES], int xi, int yi) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(entree[i][j] == 0) {
                continue;
            }
            sortie[xi + i][yi + j] = entree[i][j];
        }
    }
}

void demarrer_jeu() {
    for(int i = 0; i < COLONNES; i++) {
        for(int j = 0; j < LIGNES; j++) {
            jeu.grille[i][j] = 0;
        }
    }
    jeu.nb_piece = 0;
    jeu.t_demarrage = tempsCPU();
    jeu.piece = NouveauTetrominos();
    jeu.prochaine_piece = NouveauTetrominos();
    jeu.score = 0;
    
    printf("Lancement du jeu\n");
    demandeTemporisation(1000);
    rafraichisFenetre();
    jeu.etat = JEU;
}

void gameover() {
    jeu.etat = FIN;
    rafraichisFenetre();
    // on arrête les tics
    demandeTemporisation(-1);
}

bool dansGrille(int x, int y) {
    return (
        x >= 0 && x < COLONNES &&
        y >= 0 && y < LIGNES
    );
}

Image* images;
static int nb_images = 0;

ImageId trouveIdentifiantImage() {
    ImageId id = 1;
    int passed = 0;
    while(passed != nb_images) {
        for(int i = 0; i < nb_images; i++) {
            if(images[i].id == id) {
                id++;
            } else {
                passed++;
            }
        }
    }
}

// Lis une image, l'ajoute au tableau et renvoie son identifiant
ImageId lireImage(char *nom) {
    DonneesImageRGBA* image = lisBMPRGBA(nom);
    Image image_traite;
    image_traite.id = trouveIdentifiantImage();
    image_traite.largeur = image->largeurImage;
    image_traite.hauteur = image->hauteurImage;
    image_traite.donnees = image->donneesRGBA;
    images = (Image*) realloc(images, nb_images++ * sizeof(Image));
    images[nb_images - 1] = image_traite;

    return image_traite.id;
}
// Trouve une image dans le tableau des images
Image* trouveImage(ImageId id) {
    for(int i = 0; i < nb_images; i++) {
        if(images[i].id == id) {
            return &images[i];
        }
    }
    return NULL;
}
// Libere une image du tableau et libere son tableau de pixels
void libereImage(ImageId id) {
    bool found = false;
    for(int i = 0; i < nb_images; i++) {
        if(images[i].id == id) {
            free(images[i].donnees);
            found = true;
        } else if(found) {
            images[i - 1] = images[i];
        }
    }
    images = (Image*) realloc(images, nb_images-- * sizeof(Image));
}