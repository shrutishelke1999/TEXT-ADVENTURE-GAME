# TEXT-ADVENTURE-GAME

README: Text Adventurer

Objective: The objective of the game is to find a key in the building and use it in the room with dungeon exit to escape the building and win the game, before running out of lives.
 
 
Game Board: The building is a 2*2*2 cube, with 4 rooms on each floor and a total of 2 florrs. Each room consists of a name, descripti on, list of items, directions to rooms North, South, East, West, Up and Down, and a gate number. 

For each room, there is a list of items that specifies the items in the room: it could either be a key, a monster or a monster repellent.

The gate number is used to keep track of items in room and change the state of the room. For example, a room with monsters will have gate number 2. If you use a monster repellent in such a room, the monsters die, player gains a life and state of room changes by changing room name, room decription and room gate number.


Avatar: The avatar is used to represent state of player. It contains the current room,  inventory, number of lives and winning status. These change with every move the player makes. Player begins in origin(Room A) with 2 lives, hasWon=false, no inventory.


Game Play: If the player enters a room with a monster, it loses a life. If he uses a monster repellent, it gains a life and kills the monsters in that room, hence changing the room's state. The player keeps playing till he runs out of lives or escapes the dungeon.


Look: The look command gives the player information about his current room, inventory and no of lives.


goDirection: Allows the player to move in the specified direction, if a room exists in that direction. Else, he stays in the current room. 
 

takeItem: Allows the player to collect an item from the room if the item exists in that room. After taking the item, it is added in the player's inventory and the room no longer contains that item anymore.


dropItem: Allows the player to lose an item from his inventory


useItem: Allows the player to use key to unlock door in Room H, or kill monsters using Monster Repellent in rooms containing monsters. Item can only be used if it is in the inventory.


Winning State: Winning state is achieved when the player uses key to unlock door in Room H.


Losing State: Player runs out of lives.


Game Over: By attaining losing or winning state.

 
Changing Room State: Room state is changed when monster repellent is used in rooms with monsters. It kills monsters, hence changing the room's name, description and gate number. The player can later enter the room again, without losing a life. 
  

Here is a link to my YouTube channel that contains the video: https://www.youtube.com/channel/UCgvrB7-GTR08aMZoXMVJqJg?view_as=subscriber
