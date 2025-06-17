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
    jeu.piece = NouveauTetrominos();
    jeu.prochaine_piece = NouveauTetrominos();
    jeu.score = 0;
    jeu.minutes = 0;
    jeu.secondes = 0;
    
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


// On a fait des fonctions pour les musiques mais on aurait pu faire un playsound direct.
//les fonctions permettent de mettre d'autre action si bsn à l'avenir si autre méthode pour lire le son
void demarrer_musique() {
    playsound("assets/tetrisic2.wav");
}

void gameOverSoundEffect() {
    playsound("assets/gameover.wav");
}

void moveSoundEffect() {
    playsound("assets/simpleMove.wav");
}

void jumpSoundEffect() {
    playsound("assets/jump.wav");
 
}

void levelUpSoundEffect() {
    playsound("assets/levelUp.wav");
}

void ligneSoundEffect() {
    playsound("assets/ligneComplete.wav");
  
}

void stopper_musique() {
    system("killall aplay");
}


//recup des gemmes du joueurs
void recupGemmes() {
    FILE * f;
    char **nomsJoueurs = NULL;
    int *scoresJoueurs = NULL;
    int nbJoueurs = 0;
    char nomLu[21];
    int scoreLu;
    

    f = fopen("donnes.txt", "r");
 
    if(f == NULL){
        printf("Erreur lors de la lecture du fichier");
        exit(1);
    }

    // on vérifie pour chaque ligne où on a un nom et un score
    while (fscanf(f, "Nom : %s\tGemmes : %d\n", nomLu, &scoreLu) == 2) {
        
        nomsJoueurs = realloc(nomsJoueurs, (nbJoueurs + 1) * sizeof(char*));
        scoresJoueurs = realloc(scoresJoueurs, (nbJoueurs + 1) * sizeof(int));

        if (nomsJoueurs == NULL || scoresJoueurs == NULL) {
            printf("Erreur d'allocation mémoire\n");
            fclose(f);
            exit(1);
        }
        
        nomsJoueurs[nbJoueurs] = malloc(strlen(nomLu) + 1);
        strcpy(nomsJoueurs[nbJoueurs], nomLu);
        scoresJoueurs[nbJoueurs] = scoreLu;
        nbJoueurs ++;
    }


    
    for (int i=0 ; i< nbJoueurs ; i++) {

        if (strcmp(nomsJoueurs[i],jeu.nom) == 0) {
            jeu.gemmes = scoresJoueurs[i];
            break;
        }

    }

    fclose(f);



}





//on va essayer de gérer l'enregistrement des scores sur un fichier .txt
void enregistrerScores() { 

    //lecture des données et placement dans des tableaux
    FILE * f;
    char **nomsJoueurs = NULL;
    int *scoresJoueurs = NULL;
    int nbJoueurs = 0;
    char nomLu[21];
    int scoreLu;
    

    f = fopen("donnes.txt", "r");
 
    if(f == NULL){
        printf("Erreur lors de la lecture du fichier");
        exit(1);
    }

    // on vérifie pour chaque ligne où on a un nom et un score
    while (fscanf(f, "Nom : %s\tGemmes : %d\n", nomLu, &scoreLu) == 2) {
        
        nomsJoueurs = realloc(nomsJoueurs, (nbJoueurs + 1) * sizeof(char*));
        scoresJoueurs = realloc(scoresJoueurs, (nbJoueurs + 1) * sizeof(int));

        if (nomsJoueurs == NULL || scoresJoueurs == NULL) {
            printf("Erreur d'allocation mémoire\n");
            fclose(f);
            exit(1);
        }
        
        nomsJoueurs[nbJoueurs] = malloc(strlen(nomLu) + 1);
        strcpy(nomsJoueurs[nbJoueurs], nomLu);
        scoresJoueurs[nbJoueurs] = scoreLu;
        nbJoueurs ++;
    }

    fclose(f);

    

    //on enregistre le nouveau score ci dessous
   
    int joueurTrouve = 0;
    //on vérifie si le joueur portant ce nom existe déjà ?
    for (int i = 0; i < nbJoueurs; i++) {
        if (strcmp(jeu.nom, nomsJoueurs[i]) == 0) {
            //comme il existe on modifie juste son score
            scoresJoueurs[i] += jeu.score;
            joueurTrouve = 1;
            break;
        }
    }

    //si il n'existe pas on rajoute une ligne aux 2 tbl pour ce nouveau joueur
    if (joueurTrouve == 0) {
    nomsJoueurs = realloc(nomsJoueurs, (nbJoueurs + 1) * sizeof(char *));
        if (nomsJoueurs == NULL) {
            printf("Erreur realloc nomsJoueurs\n");
            exit(1);
        }

    scoresJoueurs = realloc(scoresJoueurs, (nbJoueurs + 1) * sizeof(int));
        if (scoresJoueurs == NULL) {
            printf("Erreur realloc scoresJoueurs\n");
            exit(1);
        }

    nomsJoueurs[nbJoueurs] = malloc(strlen(jeu.nom) + 1);
    strcpy(nomsJoueurs[nbJoueurs], jeu.nom);
    scoresJoueurs[nbJoueurs] = jeu.score;
    nbJoueurs++;
}



    //on peut mtn écrire les données des tableau sans souci
    f = fopen("donnes.txt", "w");

    if (f == NULL) {
        printf("erreur lors de la lecture du fichier");
        exit (1);
    }


    for (int i = 0; i < nbJoueurs; i++) {
        fprintf(f, "Nom : %s\tGemmes : %d\n", nomsJoueurs[i], scoresJoueurs[i]);
    }
    fclose(f);
    


    // Libération mémoire !
    for (int i = 0; i < nbJoueurs; i++) {
        free(nomsJoueurs[i]);
    }
    free(nomsJoueurs);
    free(scoresJoueurs);
}


