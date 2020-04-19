#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "gameFunctions.h"

Piece blacks[12];
Piece whites[12];


int main()
{
	Game game;
	
	initializeGame(&game);
	initializeBlackPieces(blacks);
	initializeWhitePieces(whites);
	while (game.running)
	{
		updateBoard(blacks, whites, &game.board);

		system("cls");
		displayBoard(game.board);
		printf("%s", "White's turn\n");
		//move whites
		movePieces(whites, 'w', blacks);
		updateBoard(blacks, whites, &game.board);
		system("cls");
		displayBoard(game.board);
		printf("%s", "Black's turn\n");
		//move blacks
		movePieces(blacks, 'b', whites);
		
		//moves!

	}
}