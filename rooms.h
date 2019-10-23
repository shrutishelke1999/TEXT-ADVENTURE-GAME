#include "items.h"
#ifndef _ROOM_
#define _ROOM_


typedef struct Room Room;

Room *room(char* name, char *description, Item *items,Room *north, Room *south, Room *east, Room *west, Room *up, Room *down, int gate);

Room * go_North(Room *current);

Room *  go_South(Room *current);

Room *  go_East(Room *current);

Room *  go_West(Room *current);

Room *  go_Up(Room *current);

Room *  go_Down(Room *current);

void set_North(struct Room* current,struct Room* north);

void set_East(struct Room* current,struct Room* east);

void set_South(struct Room* current,struct Room* south);

void set_West(struct Room* current,struct Room* west);

void set_Up(struct Room* current,struct Room* up);

void set_Down(struct Room* current,struct Room* down);

void printRoom(Room *current);

void add_Item(Room *current,Item *toAdd);

Item* take_Item(char * name, Room* current);

int isGate(Room* current);

void killMonster(Room * current);

void freeRoom(Room * room);

#endif