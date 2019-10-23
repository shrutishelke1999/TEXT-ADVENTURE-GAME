SRC = adventure.c rooms.c items.c
OBJ = adventure.o rooms.o items.o

adventure: $(OBJ)
	gcc -o adventure $(OBJ)

adventure.o: adventure.c rooms.h items.h
	gcc -c adventure.c -o adventure.o

rooms.o: rooms.c rooms.h items.h
	gcc -c rooms.c -o rooms.o

items.o: items.c items.h
	gcc -c items.c -o items.o

