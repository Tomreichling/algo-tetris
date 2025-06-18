#include "../tetris.h"

InstanceSocket *instance_socket = NULL;

int initialiser_socket() {
    int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(socketfd == -1) {
        printf("Le socket n'a pas pu être initialisé\n");
        return -1;
    }
    // On paramètre le socket

    // les appels à recvfrom ne bloque pas le programme
    int flags = fcntl(socketfd, F_GETFL, 0);
    fcntl(socketfd, F_SETFL, flags | O_NONBLOCK);
    
    int options = 1;
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &options, sizeof(options)) != 0) {
        printf("Echec de paramètrage REUSEADDR\n");
        return -1;
    }
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEPORT, &options, sizeof(options)) != 0) {
        printf("Echec de paramètrage SO_REUSEPORT\n");
        return -1;
    }
    if(!attacher_socket(socketfd)) {
        return -1;
    }
    InstanceSocket instance = {0};
    instance.socketfd = socketfd;

    pthread_t pid;
    SocketThreadPayload payload = {socketfd, DESTINATAIRE, PORT};
    pthread_create(&pid, NULL, thread_socket, &payload);

    for(int i = 0; i < COLONNES; i++) {
        for(int j = 0; j < LIGNES; j++) {
            instance.grille[i][j] = 0;
        }
    }

    envoyer_socket(1, jeu.nom, socketfd);

    instance_socket = &instance;
    return socketfd;
}

bool attacher_socket(int socketfd) {
    struct sockaddr_in adresse;

    adresse.sin_family = AF_INET;
    inet_pton(AF_INET, ORIGINE, &adresse.sin_addr);
    adresse.sin_port = htons(PORT);

    if (bind(socketfd, (struct sockaddr *) &adresse, sizeof(adresse)) != 0) {
        printf("Echec binding\n");
        return false;
    }
    printf("[serveur] écoute à %s:%d\n", ORIGINE, PORT);
    return true;
}

void recevoir_socket(int socketfd) {
    char buffer[COLONNES * LIGNES + 1];
    struct sockaddr_in addresse;
    socklen_t addrlen = sizeof(struct sockaddr_in);

    int n = recvfrom(socketfd, buffer, COLONNES * LIGNES + 1, 0, (struct sockaddr *) &addresse, &addrlen);
    char ip_expediteur[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &addresse.sin_addr, ip_expediteur, INET_ADDRSTRLEN);

    if(n > 1 && strcmp(ip_expediteur, ORIGINE) != 0) {
        printf("[serveur] récéption de données\n");
        switch(buffer[0]) {
            case 0:
                instance_socket->score = (int) buffer[1];
                break;
            case 1:
                buffer[n] = '\0';
                strcpy(instance_socket->nom, buffer);
                break;
            case 2:
                for(int i = 0; i < COLONNES; i++) {
                    for(int j = 0; j < LIGNES; j++) {
                        instance_socket->grille[i][j] = buffer[i * COLONNES + j];
                    }
                }
                break;
        }
        rafraichisFenetre();
    }
}

void envoyer_socket(int type, char *donnees, int socketfd) {
    char buffer[COLONNES * LIGNES + 1];
    int size;
    buffer[0] = type;
    switch (type) {
        case 0: {
            printf("[serveur] envoie le score\n");
            buffer[1] = (int) donnees[0];
            size = 2;
            break;
        }
        case 1: {
            printf("[serveur] envoie le nom\n");
            int i = 0;
            while(donnees[i] != '\0' && i < COLONNES * LIGNES) {
                buffer[1 + i] = donnees[i];
                i++;
            }
            size = 1 + i;
            break;
        }
        case 2: {
            printf("[serveur] envoie la grille\n");
            memcpy(&buffer[1], donnees, COLONNES * LIGNES);
            size = COLONNES * LIGNES + 1;
            break;
        }
        default:
            return;
    }

    struct sockaddr_in adresse;

    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(PORT);
    inet_pton(AF_INET, DESTINATAIRE, &adresse.sin_addr);
    sendto(socketfd, buffer, size, MSG_DONTWAIT, (struct sockaddr *) &adresse, sizeof(struct sockaddr_in));
    // traiter erreurs
}

void envoyer_grille() {
    char grille[COLONNES][LIGNES];
    memcpy(grille, jeu.grille, COLONNES * LIGNES);
    

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(jeu.piece.grille[i][j] == 0) {
                continue;
            }

            grille[jeu.piece.x + i][jeu.piece.y + j] = jeu.piece.grille[i][j];
        }
    }

    envoyer_socket(2, (char *) grille, instance_socket->socketfd);
}

void fermer_socket() {
    if(instance_socket == NULL) {
        return;
    }
    close(instance_socket->socketfd);
    instance_socket = NULL;
}

void* thread_socket(void *payload) {
    SocketThreadPayload *socket_payload = payload; 
    printf("[serveur-thread] reçois les messages\n");
    while(1) {
        if(instance_socket == NULL) {
            printf("[thread] socket indisponible\n");
            sleep(1);
        } else {
            recevoir_socket(socket_payload->socketfd);
            usleep(10000); // 20ms
        }
    }
    return NULL;
}