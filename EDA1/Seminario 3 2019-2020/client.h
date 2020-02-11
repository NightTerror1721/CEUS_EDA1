//
// Created by rcarlini on 10/2/20.
//

#ifndef EDA1_SEMINARS_CLIENT_H
#define EDA1_SEMINARS_CLIENT_H

#define MAX_NAME_LENGTH 30

typedef struct _client {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    struct _client* next;
} Client;




Client* create_sample_client();
Client* read_client_from_stdin();
Client* read_client_from_stdin();
void print_client(Client* client);

#endif //EDA1_SEMINARS_CLIENT_H
