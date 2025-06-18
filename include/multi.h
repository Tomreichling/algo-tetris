#ifndef MULTI_H
#define MULTI_H
#include "../src/tetris.h"

//afficher la grille ennemi
void affichageEnnemi();

//affiche les choses supplémentaire a la grille
// void affichageSupp();

//affiche la grille ennemi
void afficherCarreauEnnemi(int x, int y, char couleur);

void affichageBarresScroll(DonneesImageRGBA *gemme, DonneesImageRGBA *gemmeRouge);

///////////////////
// Temporisation //
///////////////////

#include <sys/socket.h> // socket()
#include <netinet/in.h> // structs
#include <unistd.h> // defs
#include <pthread.h> // threads pour récupérer données en arrière_plan
#include <arpa/inet.h> // defs

typedef struct {
    int socketfd;
    char *nom;
    int score;
    char grille[COLONNES][LIGNES];
} InstanceSocket;

extern InstanceSocket *instance_socket;

// renvoie un file descriptor (pour identifier socketfd)
int initialiser_socket();

// bind() (on écoute sur un port)
bool attacher_socket(int socketfd, int port);

// reçois les données et agis en conséquence
// on distingue 3 types de données avec la première valeur du buffer
// 0 -> score
// 1 -> nom
// 2 -> grille
void recevoir_socket(int socketfd, char ip[], int port);
void envoyer_socket(int type, char *donnees, int socketfd, char ip[], int port);
void envoyer_grille();
void fermer_socket();

typedef struct {
    int socketfd;
    char *ip;
    int port;
} SocketThreadPayload;
void* thread_socket(void *payload);

#endif