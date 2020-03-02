//
// Created by rcarlini on 14/10/19.
//
#include <stdio.h>
#include <stdlib.h>

#include "../headers/dungeon.h"

/**
 * Sets the value for row and column into the position.
 *
 * @param position The position to be modified.
 * @param row The row value.
 * @param column The column value.
 *
 * Pre:
 * Post:
 */
void set_position(Position* position, int row, int column) {
    position->row = row;
    position->column = column;
}

/**
 * Sets the starting position of the dungeon.
 * @param dungeon The dungeon to be set.
 *
 * Pre:
 * Post:
 */
void set_starting_position(Dungeon *dungeon, int row, int column) {
    set_position(&dungeon->initial_position, row, column);
}

/**
 * Returns the starting position of the dungeon.
 * @param dungeon The dungeon to be queried.
 * @return The starting position of the dungeon.
 *
 * Pre:
 * Post:
 */
Position get_starting_position(Dungeon *dungeon) {
    Position position = dungeon->initial_position;
    return position;
}

/**
 * Returns the starting room of the dungeon.
 * @param dungeon The dungeon to be queried.
 * @return The starting room of the dungeon.
 *
 * Pre:
 * Post:
 */
Room* get_starting_room(Dungeon *dungeon) {
    return get_room_at_position(dungeon, dungeon->initial_position);
}

/**
 * Checks if the row and column values fits in the dungeon room matrix.
 *
 * @param row The row value.
 * @param column The column value.
 *
 * @return TRUE if the values are between 0 and ROWS for row and between 0 and COLUMN for column. If the row value is out of range, it returns INVALID_ROW code. If the column value is out of range, it returns INVALID_COLUMN code.
 *
 * Pre:
 * Post.
 */
int is_valid_coordinates(Dungeon* dungeon, int row, int column) {
    if (row < 0 || row >= dungeon->rows)
        return INVALID_ROW;
    if (column < 0 || column >= dungeon->columns)
        return INVALID_COLUMN;
    return TRUE;
}

/**
 * Checks if the position fits in the dungeon room matrix.
 *
 * @param position The position to be checked.
 * @return TRUE if the position is between 0 and ROWS and between 0 and COLUMN. If the row value is out of range, it returns INVALID_ROW code. If the column value is out of range, it returns INVALID_COLUMN code.
 *
 * Pre:
 * Post:
 */
int is_valid_position(Dungeon* dungeon, Position position) {
    return is_valid_coordinates(dungeon, position.row, position.column);
}

/**
 * Returns the dungeon room at the input row and column position.
 *
 * @param dungeon The dungeon from which the room should be retrieved.
 * @param row The row position of the room.
 * @param column The column position of the room.
 * @return The (reference to the) room of the dungeon corresponding to the row and column values if those are valid. NULL otherwise.
 *
 * Pre:
 * Post:
 */
Room *get_room_at(Dungeon *dungeon, int row, int column) {
    if (is_valid_coordinates(dungeon, row, column))
        return &dungeon->rooms[row * dungeon->columns + column];
    return NULL;
}

/**
 * Returns the dungeon room at the input position.
 *
 * @param dungeon The dungeon from which the room should be retrieved.
 * @param position The position of the room.
 * @return The (reference to the) room of the dungeon corresponding to the position if valid. NULL otherwise.
 *
 * Pre:
 * Post:
 */
Room* get_room_at_position(Dungeon *dungeon, Position position) {
    return get_room_at(dungeon, position.row, position.column);
}

/**
 * Releases the memory allocated when constructing the dungeon, if any.
 * @param dungeon The dungeon to be freed.
 */
void free_dungeon(Dungeon* dungeon) {
    if (dungeon->rooms)
        free(dungeon->rooms);
}

/**
 * Initializes the dungeon, setting the starting position to (0,0) and initializes each room in the matrix.
 * @param dungeon The dungeon to be initialized
 * @return SUCCESS code if the initialization was successful, ERROR code if something went wrong.
 *
 * Pre:
 * Post:
 */
int init_dungeon(Dungeon *dungeon) {

    set_starting_position(dungeon, 0, 0);

    dungeon->rows = dungeon->columns = 0;
    dungeon->rooms = NULL;

    return SUCCESS;
}

/**
 * Resizes the dungeon, freeing the previously allocated rooms if needed.
 * @param dungeon  The dungeon to be resized.
 * @param rows The rows of the new dungeon
 * @param columns The columns of the new dungeon.
 * @return SUCCESS code if the initialization was successful, ERROR code if something went wrong.
 */
int resize_dungeon(Dungeon* dungeon, int rows, int columns) {

    if (rows < 1 || columns < 1)
        return ERROR;

    // Reservamos memoria para (rows * columns) Rooms //
    Room* new_rooms = (Room*) calloc(rows * columns, sizeof(Room));
    if (!new_rooms) // Nos aseguramos de que no haya fallado la reserva //
        return ERROR;

    // Si ya habia Rooms reservadas previamente, copiamos aquellas que puedan caber en la nueva dungeon //
    if (dungeon->rooms)
    {
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < columns; ++c)
            {
                // Si la fila y la columna actual es valida en la dungeon antigua, entonces copiamos //
                if (r < dungeon->rows && c < dungeon->columns)
                    new_rooms[r * columns + c] = dungeon->rooms[r * dungeon->columns + c];
                else // Si no, entonces inicializamos la Room //
                    init_room(&new_rooms[r * columns + c]);
            }

        // Destruimos la memoria de las Rooms viejas //
        free_dungeon(dungeon);
    }
    else // Si no habia Rooms en la dungeon, entonces las inicializamos todas //
    {
        int len = rows * columns;
        for (int i = 0; i < len; ++i)
            init_room(new_rooms + i);
    }

    dungeon->rows = rows;
    dungeon->columns = columns;
    dungeon->rooms = new_rooms;

    return SUCCESS;
}

/**
 * Resets the visited flag in all the rooms, clearing it.
 * @param dungeon The dungeon to be reset.
 * @return SUCCESS code if the reset was successful, ERROR code if something went wrong.
 */
int reset_visited(Dungeon* dungeon) {
    if(!dungeon->rooms)
        return ERROR;

    int len = dungeon->rows * dungeon->columns;
    for (int i = 0; i < len; ++i)
        clear_visited(dungeon->rooms + i);

    return SUCCESS;
}