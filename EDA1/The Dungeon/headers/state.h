//
// Created by rcarlini on 11/12/19.
//

#ifndef DUNGEON_STATE_H
#define DUNGEON_STATE_H

#include "dungeon.h"

typedef struct _step {
	Position origin;
	char direction;

	struct _step* next;
	struct _step* prev;
} Step;

typedef struct {
	Step* first;
	Step* last;
	size_t count;
} Path;

typedef struct {
	Dungeon* dungeon;
	Position current_position;
	int is_finished;

	Path path;
} State;

void init_state(State* state, Dungeon* dungeon);

int is_finished(State* state);

Position get_current_position(State* state);
Room* get_current_room(State* state);
int move(State* state, char direction);
int go_back(State* state, char direction);

void add_as_first_step(State* state, Position position, char direction);
void add_as_last_step(State* state, Position position, char direction);
void reset(State* state);

#endif //DUNGEON_STATE_H
