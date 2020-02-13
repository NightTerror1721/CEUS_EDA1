#ifndef EDA1_SEMINARS_CLIENT_LINE_H
#define EDA1_SEMINARS_CLIENT_LINE_H

#include "client.h"

typedef struct _clientline {
	Client* head;
	Client* tail;
	unsigned int count;
} ClientLine;

void init_line(ClientLine* line);
void client_appeared(ClientLine* line, Client* client);
void attend_client(ClientLine* line);
void cleanup(ClientLine* line);

#endif //EDA1_SEMINARS_CLIENT_LINE_H
