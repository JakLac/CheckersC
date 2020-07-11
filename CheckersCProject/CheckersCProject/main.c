#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "gameFunctions.h"

Piece blacks[12];
Piece whites[12];

/*!
* \file
* \brief Plik z funkcj� main
*
* Plik z funkcj� g��wna, przyjmuj�c� argumenty zawieraj�ce nazwy plik�w i innych danych wej�ciowych na kt�rych program b�dzie operowa�
*/

/** Funkcj� g��wna. W niej dzieje si� ca�a p�tla gry oraz zapis rozpocz�tych rozgrywek.
*/

int main()
{
	FILE* fp;
	int games = 0;
	fp = fopen("StartedGamesCnt.txt", "r+");
	fscanf(fp, "%d", &games);
	fclose(fp);
	games++;
	fp = fopen("StartedGamesCnt.txt", "w+");
	fprintf(fp, "%d", games);
	fclose(fp);
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
		game.running == !checkIfFinish(blacks, whites);
		updateBoard(blacks, whites, &game.board);
		system("cls");
		displayBoard(game.board);
		printf("%s", "Black's turn\n");
		//move blacks
		movePieces(blacks, 'b', whites);
		game.running == !checkIfFinish(blacks, whites);
		//moves!

	}
	for (int i = 0; i < 8; i++)\
	{
		free(game.board[i]);
		free(game.board);
	}
	return 0;
}