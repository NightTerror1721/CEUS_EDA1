//
// Created by rcarlini on 10/2/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

Client* create_sample_client() {
    Client* client = (Client*) malloc(sizeof(Client));
    strcpy(client->name, "Pepita");
    strcpy(client->surname, "Pulgarcita");
    return client;
}

Client* read_client(FILE* fd, Client* client) {

    int matches = fscanf(fd, "%s", client->name);
    if (matches == 1) {
        fscanf(fd, "%s", client->surname);
        if (matches != 1) {
            client = NULL;
        }
    } else {
        client = NULL;
    }

    return client;
}

Client* read_client_from_stdin(Client* client) {
    printf("Please input a name and a surname:\n");
    return read_client(stdin, client);
}

void print_client(Client* client) {
    printf("Client name: %s\n", client->name);
    printf("Client surname: %s\n", client->surname);
}
