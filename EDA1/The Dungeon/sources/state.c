//
// Created by rcarlini on 11/12/19.
//

#include <stddef.h>
#include <stdlib.h>
#include "../headers/state.h"

/**
 * Initializes the state, storing the dungeon in it and setting the current position to the dungeon stating position.
 * Also sets finished flag to FALSE.
 *
 * @param state The state to be initialized.
 * @param dungeon The dungeon to be set as the state dungeon.
 *
 * Pre:
 * Post:
 */
void init_state(State* state, Dungeon* dungeon) {
    state->dungeon = dungeon;
    state->current_position = get_starting_position(dungeon);
    state->is_finished = FALSE;
    state->path.first = state->path.last = NULL;
    state->path.count = 0;
}

/**
 * Sets the current position from the dungeon associated to the state.
 *
 * @param state The state that stores the current position.
 * @param row The current row coordinate.
 * @param column The current column coordinate.
 *
 * Pre:
 * Post:
 */
void set_current_position(State* state, Position position) {
    state->current_position = position;
}

/**
 * Retrieves the current position from the dungeon associated to the state.
 *
 * @param state The state that stores the current room.
 * @return The current room of the dungeon.
 *
 * Pre:
 * Post:
 */
Position get_current_position(State* state) {
    Position position = state->current_position;
    return position;
}

/**
 * Retrieves the current room from the dungeon associated to the state.
 *
 * @param state The state that stores the current room.
 * @return The current room of the dungeon.
 *
 * Pre:
 * Post:
 */
Room* get_current_room(State* state) {
    return get_room_at_position(state->dungeon, state->current_position);
}

/**
 * Sets the finished flag to finisehd value (TRUE or FALSE)
 *
 * @param state The state to be updated.
 * @param is_finished The value marking the game as finished or not.
 *
 * Pre:
 * Post:
 */
void set_finished(State* state, int finished) {
    state->is_finished = TRUE;
}

/**
 * Returns the value of is_finished flag (TRUE or FALSE), marking a game as finished.
 *
 * @param state The state to be updated.
 *
 * Pre:
 * Post:
 */
int is_finished(State* state) {
    return state->is_finished;
}

/**
 * Adds the step as the first step of the path sequence.
 *
 * @param state The current state.
 * @param direction The direction of the step.
 */
void add_as_first_step(State* state, Position position, char direction) {

    Step* s = (Step*) malloc(sizeof(Step));
    if (!s)
        return;

    s->origin = position;
    s->direction = direction;

    if (!state->path.first)
    {
        state->path.first = state->path.last = s;
        s->next = s->prev = NULL;
    }
    else
    {
        state->path.first->prev = s;
        s->next = state->path.first;

        state->path.first = s;
    }

    state->path.count++;
}

/**
 * Adds the step as the last step of the path sequence.
 *
 * @param state The current state.
 * @param direction The direction of the step.
 */
void add_as_last_step(State* state, Position position, char direction) {

    Step* s = (Step*)malloc(sizeof(Step));
    if (!s)
        return;

    s->origin = position;
    s->direction = direction;

    if (!state->path.last)
    {
        state->path.last = state->path.first = s;
        s->next = s->prev = NULL;
    }
    else
    {
        state->path.last->next = s;
        s->prev = state->path.last;

        state->path.last = s;
    }

    state->path.count++;
}

/**
 * Deletes (freeing if needed) all the steps stored in the path of the state.
 * @param state The state with the path to be cleare.
 */
void clear_path(State* state) {

    Step *s, *next;
    s = state->path.first;
    while (s)
    {
        next = s->next;
        free(s);
        s = next;
    }

    state->path.first = state->path.last = NULL;
    state->path.count = 0;
}

/**
 * Resets the state, clearing the state path and reverting the visited marks on the dungeon rooms.
 *
 * @param state The state to be reset.
 */
void reset(State* state) {
    
    clear_path(state);

    if (state->dungeon)
        reset_visited(state->dungeon);
}

/**
 * If the move is valid, moves the player in the input direction, updating the current room position.
 * If there is no room in that direction, returns INVALID_DIRECTION code.
 * If the wall in the direction does not have a door, returns NO_DOOR_ERROR.
 * If the target position is no valid, returns INVALID_MOVE code.
 *
 * @param state The current state.
 * @param direction The direction to move to.
 * @return TRUE if the move was successful, INVALID_DIRECTION code if there is no room in that direction, NO_DOOR_ERROR code if there is no door in that direction or INVALID_MOVE if the target position is invalid.
 *
 * Pre:
 * Post:
 */
int move(State* state, char direction) {

    Position pos = state->current_position;
    Room* current_room = get_current_room(state);

    Wall* next_wall = get_wall(current_room, direction);
    if (!next_wall)
        return INVALID_MOVE;

    if (!has_door(next_wall))
        return NO_DOOR_ERROR;
    if (!has_open_door(next_wall))
        return NO_DOOR_ERROR; //The door is closed.

    switch (direction)
    {
        case NORTH:
            pos.row -= 1;
            break;
        case SOUTH:
            pos.row += 1;
            break;
        case EAST:
            pos.column += 1;
            break;
        case WEST:
            pos.column -= 1;
            break;
        default:
            return INVALID_MOVE;
    }

    if (!is_valid_position(state->dungeon, pos))
        return INVALID_MOVE;

    Room* next_room = get_room_at_position(state->dungeon, pos);
    if (!next_room)
        return INVALID_DIRECTION; //no room in that direction

    if (has_exit_door(next_wall))
        state->is_finished = TRUE;

    state->current_position = pos;
    
    return TRUE;
}

/**
 * If the move is valid, moves the player in the opposite direction, updating the current room position.
 * If there is no room in that direction, returns INVALID_DIRECTION code.
 * If the wall in that direction does not have a door, returns NO_DOOR_ERROR.
 * If the target position is no valid, returns INVALID_MOVE code.
 *
 * @param state The current state.
 * @param direction The direction to move to.
 * @return TRUE if the move was successful, INVALID_DIRECTION code if there is no room in that direction, NO_DOOR_ERROR code if there is no door in that direction or INVALID_MOVE if the target position is invalid.
 *
 * Pre:
 * Post:
 */
int go_back(State* state, char direction) {
    switch (direction)
    {
        case NORTH:
            direction = SOUTH;
            break;
            
        case SOUTH:
            direction = NORTH;
            break;

        case EAST:
            direction = WEST;
            break;

        case WEST:
            direction = EAST;
            break;
    }
    return move(state, direction);
}