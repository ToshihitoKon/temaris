temaris: main.o game.o 
	gcc -o temaris main.o game.o -lncurses

main.o: main.c
	gcc -c main.c

game.o: game.c
	gcc -c game.c
