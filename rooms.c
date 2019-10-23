#include "rooms.h"
#include "items.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Room Room;


struct Room{
  char *name;
  char* description;
  Item* items;
  Room *north; 
  Room *south;
  Room *east;
  Room *west;
  Room *up;
  Room *down;
  int gate;
};

//returns pointer to room with given specifications after allocating required memory
struct Room * room(char* name, char* description, struct Item* items, struct Room *north, struct Room *south, struct Room *east, struct Room *west, struct Room *up, struct Room *down, int gate){
    struct Room * room = (struct Room *)malloc(sizeof(struct Room));
    room->name = name;
    room->description = description;
    room->items = items;
    room-> north = north;
    room->south = south;
    room->east = east;
    room->west = west;
    room->up = up;
    room->down = down;
    room->gate = gate;
    return room;
}

//Goes in specified direction if possible, and returns pointer to current room
Room * go_North(Room *current){
  if (current->north == NULL){
    printf("Cannot go North\n");
    return current;
  }
   return current->north;
}

Room * go_South(Room *current){
  if (current->south == NULL){
    printf("Cannot go South\n");
    return current;
  }
   return current->south;
}

Room * go_East(Room *current){
  if (current->east == NULL){
    printf("Cannot go East\n");
    return current;
  }
   return current->east;
}

Room * go_West(Room *current){
  if (current->west == NULL){
    printf("Cannot go West\n");
    return current;
  }
   return current->west;
}

Room * go_Up(Room *current){
  if (current->up == NULL){
    printf("Cannot go Up\n");
    return current;
  }
   return current->up;
}

Room * go_Down(Room *current){
  if (current->down == NULL){
    printf("Cannot go Down\n");
    return current;
  }
   return current->down;
}

//sets directions between rooms to create building
void set_North(Room* current,Room* other){
  current->north=other;
  other->south=current;
}

void set_South(Room* current,Room* other){
  current->south=other;
  other->north=current;
}

void set_East(Room* current,Room* other){
  current->east=other;
  other->west=current;
}

void set_West(Room* current,Room* other){
  current->west=other;
  other->east=current;
}

void set_Up(Room* current,Room* other){
  current->up=other;
  other->down=current;
}

void set_Down(Room* current,Room* other){
  current->down=other;
  other->up=current;
}

//prints room name, description, information about each direction and list of items in the room 

void printRoom(Room *head){
  printf("Name of Room: %s , Description of Room: %s\n\n", head->name, head->description);
  if(head->north!=NULL){
    printf("There is a room to your North: %s\n", head->north->name);
  }
  else{
    printf("There is a wall to your North\n");
  }

  if(head->south!=NULL){
    printf("There is a room to your South: %s\n", head->south->name);
  }
  else{
    printf("There is a wall to your South\n");
  }
  
  if(head->west!=NULL){
    printf("There is a room to your West: %s\n", head->west->name);
  }
  else{
    printf("There is a wall to your West\n");
  }
  
  if(head->east!=NULL){
    printf("There is a room to your East: %s\n", head->east->name);
  }
  else{
    printf("There is a wall to your East\n");
  }

  if(head->up!=NULL){
    printf("There is a room Up: %s\n", head->up->name);
  }
  else{
    printf("There is a wall Up\n");
  }
  
  if(head->down!=NULL){
    printf("There is a room Down: %s\n", head->down->name);
  }
  else{
    printf("There is a wall Down\n\n");
  }

  printf("Inside this room, these are the following items:\n ");
  printItem(head->items);  
  printf("\n\n\n");
  return; 
}

//adds new item to list of items in room
void add_Item(Room *current,Item *toAdd){
 item_add(current->items, toAdd);
}

//removes specified item from list of items in room if possible, and returns a pointer to that item

Item* take_Item(char * name, Room* current){
  return item_take(name, current->items);
}

int isGate(struct Room* current){
  if(current->gate==1){
    return 1;
  }
  if(current->gate==2){
    return 2;
  }
  return 0;
}

//kills Monster in room and changes state of room by chanaging gate number and description

void killMonster(Room * current){
  current->gate = 0;
  current->description = "Monster Killed";
  item_take("Monster",current->items);
}

//frees room and items in room
void freeRoom(Room * room){
  Room * temp=room;
  free_items(temp->items);
  free(temp);
}