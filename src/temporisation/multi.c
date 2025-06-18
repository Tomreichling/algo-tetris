#include "../tetris.h"

InstanceSocket *instance_socket = NULL;

int initialiser_socket() {
    int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(socketfd == -1) {
        printf("Le socket n'a pas pu être initialisé\n");
        return -1;
    }

    int options = 2;
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &options, sizeof(options)) != 0) {
        printf("Echec de paramètrage REUSEADDR\n");
        return -1;
    }
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEPORT, &options, sizeof(options)) != 0) {
        printf("Echec de paramètrage SO_REUSEPORT\n");
        return -1;
    }

    pthread_t pid;
    SocketThreadPayload payload = {socketfd, DESTINATAIRE, PORT};
    pthread_create(&pid, NULL, thread_socket, &payload);

    if(!attacher_socket(socketfd, PORT)) {
        return -1;
    }
    InstanceSocket instance = {0};
    instance.socketfd = socketfd;
    for(int i = 0; i < COLONNES; i++) {
        for(int j = 0; j < LIGNES; j++) {
            instance.grille[i][j] = 0;
        }
    }

    envoyer_socket(1, jeu.nom, socketfd, DESTINATAIRE, PORT);

    instance_socket = &instance;
    return socketfd;
}

bool attacher_socket(int socketfd, int port) {
    struct sockaddr_in adresse;

    adresse.sin_family = AF_INET;
    // Ecoute sur toutes les adresses (INADDR_ANY <=> 0.0.0.0)
    adresse.sin_addr.s_addr = INADDR_ANY;
    // Conversion du port en valeur réseaux (Host TO Network Short)
    adresse.sin_port = htons(port);

    if (bind(socketfd, (struct sockaddr *) &adresse, sizeof(adresse)) != 0) {
        printf("Echec binding\n");
        return false;
    }
    return true;
}

void recevoir_socket(int socketfd, char ip[], int port) {
    
    char buffer[COLONNES * LIGNES + 1];
    struct sockaddr_in adresse;

    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(port);
    inet_pton(AF_INET, ip, &adresse.sin_addr);
    socklen_t addrlen = sizeof(struct sockaddr_in);

    int n = recvfrom(socketfd, buffer, COLONNES * LIGNES + 1, 0, (struct sockaddr *) &adresse, &addrlen);
    if(n > 1) {
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

void envoyer_socket(int type, char *donnees, int socketfd, char ip[], int port) {
    char buffer[COLONNES * LIGNES + 1];
    int size;
    buffer[0] = type;
    switch (type) {
        case 0: {
            buffer[1] = (int) donnees[0];
            size = 2;
            break;
        }
        case 1: {
            int i = 0;
            while(donnees[i] != '\0' && i < COLONNES * LIGNES) {
                buffer[1 + i] = donnees[i];
                i++;
            }
            size = 1 + i;
            break;
        }
        case 2: {
            memcpy(&buffer[1], donnees, COLONNES * LIGNES);
            size = COLONNES * LIGNES + 1;
            break;
        }
        default:
            return;
    }

    struct sockaddr_in adresse;

    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(port);
    inet_pton(AF_INET, ip, &adresse.sin_addr);
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

    envoyer_socket(2, (char *) grille, instance_socket->socketfd, DESTINATAIRE, PORT);
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
    while(1) {
        if(instance_socket == NULL) {
            printf("[thread-1] Socket indisponible\n");
            sleep(100);
        } else {
            recevoir_socket(socket_payload->socketfd, socket_payload->ip, socket_payload->port);
        }
    }
    return NULL;
}