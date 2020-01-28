//
// Created by rcarlini on 15/10/19.
//

#ifndef DUNGEON_ROOM_H
#define DUNGEON_ROOM_H

#include "common.h"
#include "wall.h"

#define NORTH 'N'
#define EAST 'E'
#define SOUTH 'S'
#define WEST 'W'
#define QUIT 'Q'

typedef struct {
	Wall north;
	Wall south;
	Wall east;
	Wall west;

	int is_enabled;
	int is_visited;
} Room;

void init_room(Room* room);

void enable_room(Room* room);
void disable_room(Room* room);
int is_enabled(Room* room);

void mark_visited(Room* room);
void clear_visited(Room* room);
int is_visited(Room* room);

Wall* get_wall(Room* room, char direction);

#endif //DUNGEON_ROOM_H
