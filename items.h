#ifndef ITEMS_H_
#define ITEMS_H_

typedef struct Item Item;

Item* item(char* name, char* description,Item *next);

char* item_name(Item *data);

char* item_description(Item *data);

Item* item_next(Item *data);

Item* item_take(char* name, Item *head);

void item_add(Item *head,Item *toAdd);

Item *free_items(Item *item);

void printItem(Item *head);
#endif