temaris: main.o game.o 
	gcc -o temaris main.o game.o -lncurses

main.o: main.c game.h
	gcc -c main.c

game.o: game.c game.h
	gcc -c game.c

clear: 
	rm -f *.o
