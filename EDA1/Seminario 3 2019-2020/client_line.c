#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client_line.h"

#define INITIAL_MAX_CLIENTS 3

void init_line(ClientLine* line) {
	line->count = 0;
	line->tail = NULL;
	line->head = NULL;
}

void client_appeared(ClientLine* line, Client* client) {
	if (!line->head)
	{
		line->head = line->tail = client;
		client->next = NULL;
	}
	else
	{
		line->tail->next = client;
		client->next = NULL;
		line->tail = client;
	}
	line->count++;
}

void attend_client(ClientLine* line) {
	if (!line->head)
		return;

	if (line->head == line->tail)
	{
		free(line->head);
		line->head = line->tail = NULL;
	}
	else
	{
		Client* c = line->head;
		line->head = line->head->next;
		free(c);
	}
	line->count--;
}

void cleanup(ClientLine* line) {
	Client* c = line->head;
	Client* n;
	while (c)
	{
		n = c->next;
		free(c);
		c = n;
	}
	line->count = 0;
}
