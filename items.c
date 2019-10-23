#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items.h"
#include "rooms.h"


typedef struct Item Item;

struct Item{
  char *name;
  char *description;
  Item *next;
};

//returns pointer to item with given specifications after allocating required memory

Item *item(char* name, char* description, Item *next){
   
    Item *item = (struct Item *)malloc(sizeof(struct Item));
    item->description = description;
    item->name = name;
    item->next = next;
    return item;
}


//returns item name
char * item_name(Item *item){
    return item->name;
}

//returns item description
char * item_description(Item *item){
    return item->description;
}

//returns pointer to next item
struct Item * item_next(Item *item){
    return item->next;
}

//removes an item from a list of items, and returns it. Returns NULL if item does not exist in list

Item * item_take(char * name, Item * head){
   if(head==NULL){
    return NULL;
  }
  if(head->next==NULL){
    return NULL;
  }

  if(strcmp(name,head->name)==0){ 
     Item *temp = head; 
     head = head->next; 
     temp->next=NULL;
     return temp;
      
  }

  if(strcmp(name,head->next->name)==0){
    Item *temp = head->next;
    head->next=head->next->next;
    return temp;
  }
  return item_take(name, head->next);
}

//prints list of items with name and description
void printItem(Item *head){
  if(head==NULL){
    printf("Nothing\n");
    return;
  }
   while (head->next != NULL)
  {
    head = head->next;
    printf("Name of Item: %s , Description of Item: %s\n\n", head->name, head->description);
    
  }
}

//adds new item to list
void item_add(Item *head,Item *toAdd){
  while(head->next!=NULL){
    head = head->next;
  }
  head->next = toAdd;
 
}

//frees linked list of items. Code used from discussions in class
Item *free_items(Item *item){
  if (item == NULL){
    return NULL;
  }
  free_items(item->next); //free the rest of the list
  free(item);             //free this node
  return NULL;
}
