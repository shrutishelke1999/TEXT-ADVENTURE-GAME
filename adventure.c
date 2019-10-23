#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "items.h"
#include "rooms.h"

typedef struct Room Room;
typedef struct Avatar Avatar;

//creates Avatar
struct Avatar{
  Room *current;
  Item *inventory;
  bool hasWon;
  int noofLives;
};

int main(void) {
printf("Hello World\n\n"); 

/* The board is a 2*2*2 cube, with four rooms on each floor and a total of 2 floors
   Room A is origin and that is where the player starts the game   
 

     FLOOR 2
[H:0,1,1][G;1,1,1]   -> east
[E:0,0,1][F:1,0,1]   <- west
       ^
       |  UP
       |
     FLOOR 1   
[D:0,1,0][C:1,1,0]  ^  north
[A:0,0,0][B:1,0,0]  |

*/


//Setting up rooms
Room* roomA= room(" Room A","Origin",item("head","head",NULL),NULL,NULL,NULL,NULL,NULL,NULL,0);

Room* roomB= room("Room B","Contains Monster Repellent",item("head","head",NULL),NULL,NULL,NULL,NULL,NULL,NULL,0);

Room* roomC= room("Room C","Contains Monsters",item("head","head",NULL),NULL,NULL,NULL,NULL,NULL,NULL,2);

Room* roomD= room("Room D","Contains Key",item("head","head",NULL),NULL,NULL,NULL,NULL,NULL,NULL,0);

Room* roomE= room("Room E","Contains Monster Repellent",item("head","head",NULL),NULL,NULL,NULL,NULL,NULL,NULL,0);

Room* roomF= room("Room F","Contains Monsters",item("head","head",NULL),NULL,NULL,NULL,NULL,NULL,NULL,2);

Room* roomG= room("Room G","Contains Monsters",item("head","head",NULL),NULL,NULL,NULL,NULL,NULL,NULL,2);

Room* roomH= room("Room H","Final Escape Room",item("head","head",NULL),NULL,NULL,NULL,NULL,NULL,NULL,1);


 Item * itemB = item("MonsterRepellent", "Kills Monsters and Increases Number of Lives",NULL);
 Item * itemC = item("Monster", "Ugly Red-Eyed Monster that feasts on your flesh",NULL);
 Item * itemD = item("Key", "Shiny Golden Key",NULL);
 Item * itemE = item("MonsterRepellent", "Kills Monsters and Increases Number of Lives",NULL);
 Item * itemF = item("Monster", "Scary Giant that turns you to mush",NULL);
 Item * itemG = item("Monster", "Poisonous Spider that traps you forever",NULL);
 Item * itemH = item("Gate", "Use key to unlock and win game",NULL);

//adding items to each room
  add_Item(roomB,itemB);
  add_Item(roomC,itemC);
  add_Item(roomD,itemD);
  add_Item(roomE,itemE);
  add_Item(roomF,itemF);
  add_Item(roomG,itemG);
  add_Item(roomH,itemH);

//setting directions for each room
  set_North(roomA, roomD);
  set_East(roomA, roomB);
  set_Up(roomA, roomE);
  set_North(roomB, roomC);
  set_Up(roomB, roomF);
  set_West(roomC, roomD);
  set_Up(roomC, roomG);
  set_Up(roomD, roomH);
  set_East(roomE, roomF);
  set_North(roomE, roomH);
  set_North(roomF, roomG);
  set_West(roomG,roomH);


Avatar* player=malloc(sizeof(Avatar)); //allocating memory for Avatar
  player->hasWon=false;
  player->current=roomA;
  player->inventory = item("head","head",NULL);
  player->noofLives=2;

int move;  //scans and stores move
char str[25]; //scans and stores instructions by player
char str2[25];
printf("Welcome to Adventure Land!\n\nYour objective is to collect a golden key and use it to unlock the dungeon and escape, before you run out of lives.\n\nGood Luck!");

while(1==1){     //Keeps playing till players wins or loses
  
  printf("\n\nWhat would you like to do?\n\n Look\n goNorth\n goSouth\n goEast\n goWest\n goUp\n goDown\n takeItem\n useItem\n dropItem\n\n\n\n");

  scanf("%s",str2);
 

  //Gives player information about his position on the board, his inventory and the number of lives he has left
  
  if(strcmp(str2,"Look")==0){
    printf("\nYour current room is:\n");
    printRoom(player->current);
    printf("Your inventory is:\n");
    printItem(player->inventory);
    printf("No of Lives: %i\n\n\n", player->noofLives);
  }


  //Players moves in the specified direction if there exists a room in the direction. Else it remains in its current ro    om. If it enters a room with a monster, it loses a life;
 
  else if(strcmp(str2,"goNorth")==0){
    player->current=go_North(player->current);
     if(isGate(player->current)==2){
      printf("Monster Attack. You lose a life\n");
      player->noofLives = player->noofLives - 1;
     }
  }

  else if(strcmp(str2,"goSouth")==0){
    player->current=go_South(player->current);
     if(isGate(player->current)==2){
      printf("Monster Attack. You lose a life\n");
      player->noofLives = player->noofLives - 1;
     }
  }
  
  else if(strcmp(str2,"goEast")==0){
    player->current=go_East(player->current);
     if(isGate(player->current)==2){
        printf("Monster Attack. You lose a life\n");
        player->noofLives = player->noofLives - 1;
      }
  }

 else if(strcmp(str2,"goWest")==0){
    player->current=go_West(player->current);
     if(isGate(player->current)==2){
      printf("Monster Attack. You lose a life\n");
      player->noofLives = player->noofLives - 1;
     }
  }
 
 else if(strcmp(str2,"goUp")==0){
    player->current=go_Up(player->current);
     if(isGate(player->current)==2){
      printf("Monster Attack. You lose a life\n");
      player->noofLives = player->noofLives - 1;
     }
  }
  
 else if(strcmp(str2,"goDown")==0){
    player->current=go_Down(player->current);
     if(isGate(player->current)==2){
      printf("Monster Attack. You lose a life\n");
      player->noofLives = player->noofLives - 1;
     }
  }
  
  // Takes the item from a room if it exists in the list of items in the current room, and adds it to its inventory. 

 else if(strcmp(str2,"takeItem")==0){
    printf("Name the item you would like to take: Key or MonsterRepellent.\n");
    scanf("%s",str);
    Item * temp=take_Item(str, player->current);;
    if(temp!=NULL){
      item_add(player->inventory, temp);
      printf("Your item was added to the inventory\n");
    } 
    else{
      printf("Item cannot be added to the inventory\n");
    }
      
  }

  /* Uses an item from its inventory, if it can be used in the current room. It can use a key in the Room H to win the game, and Monster Repellent in a room containing monsters to kill them and gain a life. The latter changes the state of the room.*/

 else if(strcmp(str2,"useItem")==0){
    printf("Name the item you would like to use: \n");
    scanf("%s", str);
    if(strcmp(str,"Key")==0){
      if(isGate(player->current)&&item_take("Key", player->inventory)!=NULL){
        printf("You have escaped the dungeon!\n");
        player->hasWon=true;
      }
     else printf("Key cannot be used\n");
    }
   
    if(strcmp(str,"MonsterRepellent")==0){
      if(isGate(player->current)==2&&item_take("MonsterRepellent",player->inventory)!=NULL){
        printf("You destroyed a monster and gained another life\n");
        killMonster(player->current);
        player->noofLives = player->noofLives + 1;
      }
     else printf("Monster Repellent cannot be used\n");
    }
    
  }
  
  //Allows the player to drop an item from his inventory
 else if(strcmp(str2,"dropItem")==0){
    printf("Name the item you would like to drop");
    scanf("%s", str);
    Item * temp=item_take(str, player->inventory);
    if(temp==NULL){
      printf("Item cannot be dropped\n");
    }
    else {
      printf("Item was dropped\n");
    }
    free(temp);
    temp=NULL;
  }
  
 
  
  //Player wins if he uses key in final room H. Exits while loop
  if(player->hasWon==true){
    printf("Congratulations! You win\n");
    exit(42);
  }

  //Player loses if he runs out of lives. Exits while loop
  if(player->noofLives<=0){
    printf("You have run out of lives. You lose\n");
    exit(42);
  }
}

//frees all allocated memory
free_items(itemB);
free_items(itemC);
free_items(itemD);
free_items(itemE);
free_items(itemF);
free_items(itemG);
free_items(itemH);
freeRoom(roomA);
freeRoom(roomB);
freeRoom(roomC);
freeRoom(roomD);
freeRoom(roomE);
freeRoom(roomF);
freeRoom(roomG);
freeRoom(roomH);
free_items(player->inventory);
freeRoom(player->current);
free(player);

return 0;
}
  
  
