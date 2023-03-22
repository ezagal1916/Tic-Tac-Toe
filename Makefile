CC=gcc
CFLAGS=-Wall -Wextra -pedantic -ggdb 
tic_tac_game : tic_tac_game.c
	$(CC) $(CFLAGS) -o tic_tac_game tic_tac_game.c
