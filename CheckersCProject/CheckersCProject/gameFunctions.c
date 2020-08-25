#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameFunctions.h"

/*!
* \file
* \brief Definicje funkcji z pliku gameFunctions.h
*
* Plik zawiera definicje wszystkich funkcji z gameFunctions.h
*/

//NO LONGER NEEDED.
 const char defaultGameBoard[9][9] =
 {
	 {'0', 'w', '0', 'w', '0', 'w', '0', 'w'},
	{'w', '0', 'w', '0', 'w', '0', 'w', '0'},
	{'0', 'w', '0', 'w', '0', 'w', '0', 'w'},
	{'0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0'},
	{'b', '0', 'b', '0', 'b', '0', 'b', '0'},
	{'0', 'b', '0', 'b', '0', 'b', '0', 'b'},
	{'b', '0', 'b', '0', 'b', '0', 'b', '0'}
};

 void startGamesPlayed()
 {
	 int *gamesPlayed;
	 int foundGamesPlayed = 0;
	 char stringName[256];
	 char **stringFile;
	 char foundName[256];

	 int i = 0;

	 FILE* file;
	 file = fopen("Players.txt", "a+");
	 printf("WHITE PLAYER, STATE YOUR NAME\n");
	 scanf("%s", stringName);

	 gamesPlayed = malloc(sizeof(int) * 5000);
	 stringFile = malloc(sizeof(char*) * 5000);
	 for (int i = 0; i < 5000; i++)
	 {
		 stringFile[i] = malloc(sizeof(char) * 256);
	 }

	 bool found = false;
	 while (!feof(file))
	 {
		 fscanf(file, "%s%d", stringFile[i], &gamesPlayed[i]);
		 if (strcmp(stringName, stringFile[i]) == 0)
		 {
			 strcpy(foundName, stringFile[i]);
			 foundGamesPlayed = gamesPlayed[i];
			 found = true;
			 gamesPlayed[i]++;
		 }
		 i++;
	 }
	 i--;
	 if (found)
	 {
		 printf("HELLO %s, YOU HAVE PLAYED %d GAMES ALREADY\n", foundName, foundGamesPlayed);

	 }
	 else
	 {
		 printf("HELLO %s, YOU ARE A FIRST-TIME PLAYER\n", stringName);

	 }
	 fclose(file);
	 file = fopen("Players.txt", "w");
	 for (int a = 0; a < i; a++)
	 {
		 fprintf(file, "%s", stringFile[a]);
		 fprintf(file, "%s", " ");
		 fprintf(file, "%d", gamesPlayed[a]);
		 fprintf(file, "%s", "\n");
	 }
	 if (!found)
	 {
		 fprintf(file, "%s", stringName);
		 fprintf(file, "%s", " ");
		 fprintf(file, "%d", 1);
		 fprintf(file, "%s", "\n");
	}
	 fclose(file);
	
	 for (int a = 0; a < 5000; a++)
	 {
		 free(stringFile[a]);
	 }
	 free(stringFile);
	 free(gamesPlayed);

	 file = fopen("Players.txt", "a+");
	 printf("BLACK PLAYER, STATE YOUR NAME\n");
	 scanf("%s", stringName);

	 gamesPlayed = malloc(sizeof(int) * 5000);
	 stringFile = malloc(sizeof(char*) * 5000);
	 for (int i = 0; i < 5000; i++)
	 {
		 stringFile[i] = malloc(sizeof(char) * 256);
	 }

	 i = 0;
	 found = false;
	 while (!feof(file))
	 {
		 fscanf(file, "%s%d", stringFile[i], &gamesPlayed[i]);
		 if (strcmp(stringName, stringFile[i]) == 0)
		 {
			 strcpy(foundName, stringFile[i]);
			 foundGamesPlayed = gamesPlayed[i];
			 found = true;
			 gamesPlayed[i]++;
		 }
		 i++;
	 }
	 i--;
	 if (found)
	 {
		 printf("HELLO %s, YOU HAVE PLAYED %d GAMES ALREADY\n", foundName, foundGamesPlayed);

	 }
	 else
	 {
		 printf("HELLO %s, YOU ARE A FIRST-TIME PLAYER\n", stringName);

	 }


	 fclose(file);
	 file = fopen("Players.txt", "w");
	 for (int a = 0; a < i; a++)
	 {
		 fprintf(file, "%s", stringFile[a]);
		 fprintf(file, "%s", " ");
		 fprintf(file, "%d", gamesPlayed[a]);
		 fprintf(file, "%s", "\n");
	 }
	 if (!found)
	 {
		 fprintf(file, "%s", stringName);
		 fprintf(file, "%s", " ");
		 fprintf(file, "%d", 1);
		 fprintf(file, "%s", "\n");
	 }


	 fclose(file);


	 for (int a = 0; a < 5000; a++)
	 {
		 free(stringFile[a]);
	 }
	 free(stringFile);
	 free(gamesPlayed);

 }

void initializeGame(Game* game)
{
	game->running = true;
	game->activeBlack = 12;
	game->activeWhite = 12;

	initializeBoard(&game->board);

}

void initializeBlackPieces(Piece* pieces)
{
	for (int i = 0; i < 12; i++)
	{
		pieces[i].colour = 'b';
		pieces[i].active = true;
	}

	pieces[0].ypos = 5; 
	pieces[0].xpos = 0; 

	pieces[1].ypos = 5; //5
	pieces[1].xpos = 2; //2

	pieces[2].ypos = 5;
	pieces[2].xpos = 4; 

	pieces[3].ypos = 5; //5
	pieces[3].xpos = 6; //6

	pieces[4].ypos = 6; //6
	pieces[4].xpos = 1; //1

	pieces[5].ypos = 6; 
	pieces[5].xpos = 3;

	pieces[6].ypos = 6;
	pieces[6].xpos = 5;

	pieces[7].ypos = 6;
	pieces[7].xpos = 7;

	pieces[8].ypos = 7; //7
	pieces[8].xpos = 0; //0

	pieces[9].ypos = 7;
	pieces[9].xpos = 2;

	pieces[10].ypos = 7;
	pieces[10].xpos = 4;

	pieces[11].ypos = 7;
	pieces[11].xpos = 6;
}

void initializeWhitePieces(Piece* pieces)
{
	for (int i = 0; i < 12; i++)
	{
		pieces[i].colour = 'w';
		pieces[i].active = true;
	}

	pieces[0].ypos = 0;
	pieces[0].xpos = 1;

	pieces[1].ypos = 0;
	pieces[1].xpos = 3;

	pieces[2].ypos = 0;
	pieces[2].xpos = 5;

	pieces[3].ypos = 0; //0
	pieces[3].xpos = 7; //7

	pieces[4].ypos = 1;
	pieces[4].xpos = 0;

	pieces[5].ypos = 1;
	pieces[5].xpos = 2;

	pieces[6].ypos = 1;
	pieces[6].xpos = 4;

	pieces[7].ypos = 1; //1
	pieces[7].xpos = 6; //6

	pieces[8].ypos = 2;
	pieces[8].xpos = 1;

	pieces[9].ypos = 2; 
	pieces[9].xpos = 3;

	pieces[10].ypos = 2; //2
	pieces[10].xpos = 5; //5

	pieces[11].ypos = 2; //2
	pieces[11].xpos = 7; //7




}

Piece* InputFindPiece(Piece* pieces, int* xpos, int* ypos, char colour, Piece* enemyPieces)
{

	bool incorrect = false;
	printf("%s", "First give xpos, then ypos (0-7)");

	do
	{
		printf("%c", colour);
		if (incorrect)
			printf("%s", "Incorrect input!");
		incorrect = false;
		// scanf("%d", xpos);
		//scanf("%d", ypos);
		if (!scanf("%d", xpos))
		{
			fseek(stdin, 0, SEEK_END);
			incorrect = true;
		}
		if (!scanf("%d", ypos))
		{
			fseek(stdin, 0, SEEK_END);
			incorrect = true;
		}
		printf("%d", *xpos);
		printf("%d", *ypos);

		if (*xpos < 0 || *ypos < 0 || *xpos>7 || *ypos>7)
			incorrect = true;
	} while (incorrect);

	Piece* foundPiece = NULL;


	bool found = true;

	do
	{
		if (found == false)
		{
			printf("%s", "Piece not there!");
			if (!scanf("%d", xpos))
			{
				fseek(stdin, 0, SEEK_END);
				incorrect = true;
			}
			if (!scanf("%d", ypos))
			{
				fseek(stdin, 0, SEEK_END);
				incorrect = true;
			}
		}
		for (int i = 0; i < 12; i++)
		{
			if (pieces[i].xpos == *xpos && pieces[i].ypos == *ypos && (pieces[i].colour == colour || pieces[i].colour == colour - 32))
			{
				found = true;
				foundPiece = &pieces[i];
			}
		}
		if (foundPiece == NULL)
			found = false;
	} while (found == false);

	if (foundPiece != NULL)
	{
		bool canMoveRight = true, canMoveLeft = true;
		bool canMovePreRight = true, canMovePreLeft = true;
		if (foundPiece->colour == 'b')
		{
			for (int i = 0; i < 12; i++)
			{
				if ((enemyPieces[i].xpos == foundPiece->xpos - 1 && enemyPieces[i].ypos == foundPiece->ypos - 1))
					canMovePreLeft = false;
				else if ((enemyPieces[i].xpos == foundPiece->xpos + 1 && enemyPieces[i].ypos == foundPiece->ypos - 1))
					canMovePreRight = false;
			}
			for (int i = 0; i < 12; i++)
			{
				if ((pieces[i].xpos == foundPiece->xpos - 1 && pieces[i].ypos == foundPiece->ypos - 1))
					canMoveLeft = false;

				if ((pieces[i].xpos == foundPiece->xpos + 1 && pieces[i].ypos == foundPiece->ypos - 1))
					canMoveRight = false;


				if (canMovePreLeft == false)
				{
					if ((enemyPieces[i].xpos == foundPiece->xpos - 2 && enemyPieces[i].ypos == foundPiece->ypos - 2))
						canMoveLeft = false;
				}
				if (canMovePreRight == false)
				{
					if ((enemyPieces[i].xpos == foundPiece->xpos + 2 && enemyPieces[i].ypos == foundPiece->ypos - 2))
						canMoveRight = false;
				}
			}

			if (foundPiece->xpos == 0)
				canMoveLeft = false;
			if (foundPiece->xpos == 7)
				canMoveRight = false;

		}
		if (foundPiece->colour == 'w')
		{
			for (int i = 0; i < 12; i++)
			{
				if ((enemyPieces[i].xpos == foundPiece->xpos - 1 && enemyPieces[i].ypos == foundPiece->ypos + 1))
					canMovePreLeft = false;
				else if ((enemyPieces[i].xpos == foundPiece->xpos + 1 && enemyPieces[i].ypos == foundPiece->ypos + 1))
					canMovePreRight = false;
			}
			for (int i = 0; i < 12; i++)
			{
				if ((pieces[i].xpos == foundPiece->xpos - 1 && pieces[i].ypos == foundPiece->ypos + 1))
					canMoveLeft = false;

				if ((pieces[i].xpos == foundPiece->xpos + 1 && pieces[i].ypos == foundPiece->ypos + 1))
					canMoveRight = false;


				if (canMovePreLeft == false)
				{
					if ((enemyPieces[i].xpos == foundPiece->xpos - 2 && enemyPieces[i].ypos == foundPiece->ypos + 2))
						canMoveLeft = false;
				}
				if (canMovePreRight == false)
				{
					if ((enemyPieces[i].xpos == foundPiece->xpos + 2 && enemyPieces[i].ypos == foundPiece->ypos + 2))
						canMoveRight = false;
				}
			}

			if (foundPiece->xpos == 0)
				canMoveLeft = false;
			if (foundPiece->xpos == 7)
				canMoveRight = false;

		}

		if (canMoveRight == false && canMoveLeft == false)
		{ 
			printf("Incorrect Input!");
			return NULL;
		}
			
		else return foundPiece;
	}
}

void movePieces(Piece* pieces, char colour, Piece* enemyPieces)
{
	
	int xpos, ypos;
	bool newIncorrect = false;
	Piece* foundPiece = NULL;

	while (foundPiece == NULL)
	{
		foundPiece = InputFindPiece(pieces, &xpos, &ypos, colour, enemyPieces);
	}


	int newxpos, newypos;
	printf("%s", "Where would you like to move to? xpos first, then ypos.");
	//scanf("%d", &newxpos);
	//scanf("%d", &newypos);
	if (!scanf("%d", &newxpos))
	{
		fseek(stdin, 0, SEEK_END);
		newIncorrect = true;
	}
	if (!scanf("%d", &newypos))
	{
		fseek(stdin, 0, SEEK_END);
		newIncorrect = true;
	}

//	bool newIncorrect = false;
	if (newxpos < 0 || newypos < 0 || newxpos>7 || newypos>7)
		newIncorrect = true;
	do
	{
		if (newIncorrect)
		{
			newIncorrect = false;
			printf("%s", "Incorrect input!");
			//scanf("%d", &newxpos);
			//scanf("%d", &newypos);
			if (!scanf("%d", &newxpos))
			{
				fseek(stdin, 0, SEEK_END);
				newIncorrect = true;
			}
			if (!scanf("%d", &newypos))
			{
				fseek(stdin, 0, SEEK_END);
				newIncorrect = true;
			}
		}
		
		if (newxpos < 0 || newypos < 0 || newxpos>7 || newypos>7)
			newIncorrect = true;

		bool canBeatToRight = true;
		bool canBeatToLeft = true;
		char dir = 'z';
		bool dirCorrect = false;

		//TO ADD : Moving as a queen + beating enemies
		if (foundPiece->colour == 'b' || foundPiece->colour == 'B')
		{

			if (foundPiece->isQueen == false)
			{
				if (newxpos == xpos + 1 || newxpos == xpos - 1)
					newIncorrect = false;
				if (newypos != ypos - 1)
					newIncorrect = true;
			}

			else if (foundPiece->isQueen == true)
			{
				if (newxpos == xpos + 1 || newxpos == xpos - 1)
					newIncorrect = false;
				if (newypos != ypos - 1 && newypos != ypos + 1)
						newIncorrect = true;
			}
			
			//No two pieces of the same colour at the same tile!
			for (int i = 0; i < 12; i++)
			{
				if (pieces[i].xpos == newxpos && pieces[i].ypos == newypos)
				{
					newIncorrect = true;
					break;
				}
			}
			//checking for enemies to beat
			if (newIncorrect == false && foundPiece->isQueen == false)
				newIncorrect = checkForEnemiesAsNotQueenBlack(foundPiece, enemyPieces, pieces, &newxpos, &newypos);
			else if (newIncorrect == false && foundPiece->isQueen == true)
				newIncorrect = checkForEnemiesAsQueen(foundPiece, enemyPieces, pieces, &newxpos, &newypos);
		}


		else if (foundPiece->colour == 'w' || foundPiece->colour == 'W')
		{

			if (foundPiece->isQueen == false)
			{
				if (newxpos != xpos + 1 && newxpos != xpos - 1)
					newIncorrect = true;
				if (newypos != ypos + 1)
					newIncorrect = true;
			}

			else if (foundPiece->isQueen == true)
			{
				if (newxpos == xpos + 1 || newxpos == xpos - 1)
					newIncorrect = false;
				if (newypos != ypos - 1 && newypos != ypos + 1)
					newIncorrect = true;
			}

			for (int i = 0; i < 12; i++)
			{
				if (pieces[i].xpos == newxpos && pieces[i].ypos == newypos)
				{
					newIncorrect = true;
					break;
				}
			}
			//checking for enemies to beat
			if(newIncorrect == false && foundPiece->isQueen == false)
			newIncorrect = checkForEnemiesAsNotQueenWhite(foundPiece, enemyPieces, pieces, &newxpos, &newypos);
			else if (newIncorrect == false && foundPiece->isQueen == true)
				newIncorrect = checkForEnemiesAsQueen(foundPiece, enemyPieces, pieces, &newxpos, &newypos);
		}
		//TO ADD: checking whether the piece has become a queen
	} while (newIncorrect);

	foundPiece->xpos = newxpos;
	foundPiece->ypos = newypos;
	if(foundPiece->isQueen == false)
	checkIfBecameQueen(foundPiece);
}

bool checkForEnemiesAsNotQueenBlack(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos)
{
	bool hasBeaten = false;
	bool newIncorrect = false;
	bool canBeatToLeft = true;
	bool canBeatToRight = true;
	char dir = 'z';


	for (int i = 0; i < 12; i++)
	{
		if (enemyPieces[i].xpos == *newxpos && enemyPieces[i].ypos == *newypos)
		{
			if (enemyPieces[i].ypos == 0 || enemyPieces[i].xpos == 0 || enemyPieces[i].xpos == 7)
			{
				newIncorrect = true;
				break;
			}
			//Now we are checking for the pieces behind the enemy

			for (int y = 0; y < 12; y++)
			{
				if ((enemyPieces[y].xpos == enemyPieces[i].xpos + 1 && enemyPieces[y].ypos == enemyPieces[i].ypos - 1) || (ownPieces[y].xpos == enemyPieces[i].xpos + 1 && ownPieces[y].ypos == enemyPieces[i].ypos - 1))
				{
					canBeatToRight = false;
				}
				if ((enemyPieces[y].xpos == enemyPieces[i].xpos - 1 && enemyPieces[y].ypos == enemyPieces[i].ypos - 1) || (ownPieces[y].xpos == enemyPieces[i].xpos - 1 && ownPieces[y].ypos == enemyPieces[i].ypos - 1))
				{
					canBeatToLeft = false;
				}

			}

			if (canBeatToLeft == false && canBeatToRight == false)
			{
				newIncorrect = true;

				break;
			}

			else if (canBeatToLeft == false && canBeatToRight == true)
			{
				printf("%s", "prawo");
				*newxpos = enemyPieces[i].xpos + 1;
				*newypos = enemyPieces[i].ypos - 1;
				enemyPieces[i].active = false;
				//test
				enemyPieces[i].ypos = 999;
				enemyPieces[i].xpos = 999;
				hasBeaten = true;
				break;
			}

			else if (canBeatToLeft == true && canBeatToRight == false)
			{
				printf("%s", "lewo");
				*newxpos = enemyPieces[i].xpos - 1;
				*newypos = enemyPieces[i].ypos - 1;
				enemyPieces[i].active = false;
				//test
				enemyPieces[i].ypos = 999;
				enemyPieces[i].xpos = 999;
				hasBeaten = true;
				break;
			}

			//ADD THE CHOICE
			else if (canBeatToLeft == true && canBeatToRight == true)
			{
				if (enemyPieces[i].xpos > foundPiece->xpos)
					dir = 'r';
				else
					dir = 'l';

				if (dir == 'r')
				{
					printf("%s", "prawo");
					*newxpos = enemyPieces[i].xpos + 1;
					*newypos = enemyPieces[i].ypos - 1;
					enemyPieces[i].active = false;
					//test
					enemyPieces[i].ypos = 999;
					enemyPieces[i].xpos = 999;
					hasBeaten = true;
					break;
				}

				else if (dir == 'l')
				{
					printf("%s", "lewo");
					*newxpos = enemyPieces[i].xpos - 1;
					*newypos = enemyPieces[i].ypos - 1;
					enemyPieces[i].active = false;
					//test
					enemyPieces[i].ypos = 999;
					enemyPieces[i].xpos = 999;
					hasBeaten = true;	
					break;
				}

			}


		}
			
	}
	while (hasBeaten)
		hasBeaten = checkForFurtherEnemiesAsNotQueenBlack(foundPiece, enemyPieces, ownPieces, newxpos, newypos);
	return newIncorrect;
}

bool checkForEnemiesAsNotQueenWhite(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos)
{
	bool hasBeaten = false;
	bool newIncorrect = false;
	bool canBeatToLeft = true;
	bool canBeatToRight = true;
	char dir = 'z';

	for (int i = 0; i < 12; i++)
	{
		if (enemyPieces[i].xpos == *newxpos && enemyPieces[i].ypos == *newypos)
		{
			//black is enemy
			if (enemyPieces[i].ypos == 0 || enemyPieces[i].xpos == 0 || enemyPieces[i].xpos == 7)
			{
				newIncorrect = true;
				break;
			}
			//Now we are checking for the pieces behind the enemy

			for (int y = 0; y < 12; y++)
			{
				if ((enemyPieces[y].xpos == enemyPieces[i].xpos + 1 && enemyPieces[y].ypos == enemyPieces[i].ypos + 1) || (ownPieces[y].xpos == enemyPieces[i].xpos + 1 && ownPieces[y].ypos == enemyPieces[i].ypos + 1))
				{
					canBeatToRight = false;
				}
				if ((enemyPieces[y].xpos == enemyPieces[i].xpos - 1 && enemyPieces[y].ypos == enemyPieces[i].ypos + 1) || (ownPieces[y].xpos == enemyPieces[i].xpos - 1 && ownPieces[y].ypos == enemyPieces[i].ypos + 1))
				{
					canBeatToLeft = false;
				}

			}

			if (canBeatToLeft == false && enemyPieces[i].xpos < foundPiece->xpos)
				canBeatToRight = false;
			else if (canBeatToRight == false && enemyPieces[i].xpos > foundPiece->xpos)
				canBeatToLeft = false;

			if (canBeatToLeft == false && canBeatToRight == false)
			{
				newIncorrect = true;

				break;
			}

			else if (canBeatToLeft == false && canBeatToRight == true)
			{
				printf("%s", "prawo");
				*newxpos = enemyPieces[i].xpos + 1;
				*newypos = enemyPieces[i].ypos + 1;
				enemyPieces[i].active = false;
				//test
				enemyPieces[i].ypos = 999;
				enemyPieces[i].xpos = 999;
				hasBeaten = true;
				break;
			}

			else if (canBeatToLeft == true && canBeatToRight == false)
			{
				printf("%s", "lewo");
				*newxpos = enemyPieces[i].xpos - 1;
				*newypos = enemyPieces[i].ypos + 1;
				enemyPieces[i].active = false;
				//test
				enemyPieces[i].ypos = 999;
				enemyPieces[i].xpos = 999;
				hasBeaten = true;
				break;
			}

			//ADD THE CHOICE
			else if (canBeatToLeft == true && canBeatToRight == true)
			{
				if (enemyPieces[i].xpos > foundPiece->xpos)
					dir = 'r';
				else
					dir = 'l';

				if (dir == 'r')
				{
					printf("%s", "prawo");
					*newxpos = enemyPieces[i].xpos + 1;
					*newypos = enemyPieces[i].ypos + 1;
					enemyPieces[i].active = false;
					//test
					enemyPieces[i].ypos = 999;
					enemyPieces[i].xpos = 999;
					hasBeaten = true;
					break;
				}

				else if (dir == 'l')
				{
					printf("%s", "lewo");
					*newxpos = enemyPieces[i].xpos - 1;
					*newypos = enemyPieces[i].ypos + 1;
					enemyPieces[i].active = false;
					//test
					enemyPieces[i].ypos = 999;
					enemyPieces[i].xpos = 999;
					hasBeaten = true;
					break;
				}

			}

		}
	}
	while (hasBeaten)
		hasBeaten = checkForFurtherEnemiesAsNotQueenWhite(foundPiece, enemyPieces, ownPieces, newxpos, newypos);
	return newIncorrect;
}

bool checkForFurtherEnemiesAsNotQueenBlack(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos)
{
	Piece* leftEnemy = NULL;
	Piece* rightEnemy = NULL;
	char dir = 'z';
	bool canBeatRight = false;
	bool canBeatLeft = false;
	
	for (int i = 0; i < 12; i++)
	{
		if (enemyPieces[i].xpos == *newxpos + 1 && enemyPieces[i].ypos == *newypos - 1)
		{
			rightEnemy = &enemyPieces[i];
			canBeatRight = true;
		}
		else if (enemyPieces[i].xpos == *newxpos - 1 && enemyPieces[i].ypos == *newypos - 1)
		{
			leftEnemy = &enemyPieces[i];
			canBeatLeft = true;
		}
	}

	//Checking for pieces behind the enemies
	//Leftenemy can only be beaten to the left
	if (leftEnemy)
	{
		if (leftEnemy->active == false)
			canBeatLeft = false;
		for (int i = 0; i < 12; i++)
		{
			if (enemyPieces[i].xpos == leftEnemy->xpos - 1 && enemyPieces[i].ypos == leftEnemy->ypos - 1)
				canBeatLeft = false;
		}
	}

	//Leftenemy can only be beaten to the right
	if (rightEnemy)
	{
		if (rightEnemy->active == false)
			canBeatRight = false;
		for (int i = 0; i < 12; i++)
		{
			if (enemyPieces[i].xpos == rightEnemy->xpos + 1 && enemyPieces[i].ypos == rightEnemy->ypos - 1)
				canBeatRight = false;
		}
	}

	//If its impossible to move, end the sequence
	if (leftEnemy == NULL && rightEnemy == NULL)
		return false;

	//Condition so it doesnt jump out of the board
	if (leftEnemy != NULL)
	{
		if (leftEnemy->ypos == 0 || leftEnemy->xpos == 0)
			canBeatLeft = false;
	}
	if (rightEnemy != NULL)
	{
		if (rightEnemy->ypos == 0 || rightEnemy->xpos == 7)
			canBeatRight = false;
	}

	if (canBeatLeft == false && canBeatRight == false)
	{
		return false;
	}

	//checking all the cases
	else if (canBeatLeft == true && canBeatRight == false)
	{
		*newxpos = leftEnemy->xpos - 1;
		*newypos = leftEnemy->ypos - 1;
		leftEnemy->active = false;
		//test
		leftEnemy->xpos = 999;
		leftEnemy->ypos = 999;
		return true;
	}

	else if (canBeatLeft == false && canBeatRight == true)
	{
		*newxpos = rightEnemy->xpos + 1;
		*newypos = rightEnemy->ypos - 1;
		rightEnemy->active = false;
		//test
		rightEnemy->xpos = 999;
		rightEnemy->ypos = 999;
		return true;
	}

	else if (canBeatLeft == true && canBeatRight == true)
	{
		printf("%s", "(L)eft or (R)ight?");
		while (dir != 'l' && dir != 'r')
		{
			scanf("%c", dir);
		}
		if (dir == 'l')
		{
			*newxpos = leftEnemy->xpos - 1;
			*newypos = leftEnemy->ypos - 1;
			leftEnemy->active = false;
			//test
			leftEnemy->xpos = 999;
			leftEnemy->ypos = 999;
			return true;
		}
		else if (dir == 'r')
		{
			*newxpos = leftEnemy->xpos + 1;
			*newypos = leftEnemy->ypos - 1;
			rightEnemy->active = false;
			//test
			rightEnemy->xpos = 999;
			rightEnemy->ypos = 999;
			return true;
		}
	}
}

bool checkForFurtherEnemiesAsNotQueenWhite(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos)
{
	Piece* leftEnemy = NULL;
	Piece* rightEnemy = NULL;
	char dir = 'z';
	bool canBeatRight = false;
	bool canBeatLeft = false;

	for (int i = 0; i < 12; i++)
	{
		if (enemyPieces[i].xpos == *newxpos + 1 && enemyPieces[i].ypos == *newypos + 1)
		{
			rightEnemy = &enemyPieces[i];
			canBeatRight = true;
		}
		else if (enemyPieces[i].xpos == *newxpos - 1 && enemyPieces[i].ypos == *newypos + 1)
		{
			leftEnemy = &enemyPieces[i];
			canBeatLeft = true;
		}
	}

	//Checking for pieces behind the enemies
	//Leftenemy can only be beaten to the left
	if (leftEnemy)
	{
		if (leftEnemy->active == false)
			canBeatLeft = false;
		for (int i = 0; i < 12; i++)
		{
			if (enemyPieces[i].xpos == leftEnemy->xpos - 1 && enemyPieces[i].ypos == leftEnemy->ypos + 1)
				canBeatLeft = false;
		}
	}

	//Leftenemy can only be beaten to the right
	if (rightEnemy)
	{
		if (rightEnemy->active == false)
			canBeatRight = false;
		for (int i = 0; i < 12; i++)
		{
			if (enemyPieces[i].xpos == rightEnemy->xpos + 1 && enemyPieces[i].ypos == rightEnemy->ypos + 1)
				canBeatRight = false;
		}
	}

	//If its impossible to move, end the sequence
	if (leftEnemy == NULL && rightEnemy == NULL)
		return false;

	//Condition so it doesnt jump out of the board
	if (leftEnemy != NULL)
	{
		if (leftEnemy->ypos == 7 || leftEnemy->xpos == 0)
			canBeatLeft = false;
	}
	if (rightEnemy != NULL)
	{
		if (rightEnemy->ypos == 7 || rightEnemy->xpos == 7)
			canBeatRight = false;
	}

	if (canBeatLeft == false && canBeatRight == false)
	{
		return false;
	}

	//checking all the cases
	else if (canBeatLeft == true && canBeatRight == false)
	{
		*newxpos = leftEnemy->xpos - 1;
		*newypos = leftEnemy->ypos + 1;
		leftEnemy->active = false;
		//test
		leftEnemy->xpos = 999;
		leftEnemy->ypos = 999;
		return true;
	}

	else if (canBeatLeft == false && canBeatRight == true)
	{
		*newxpos = rightEnemy->xpos + 1;
		*newypos = rightEnemy->ypos + 1;
		rightEnemy->active = false;
		//test
		rightEnemy->xpos = 999;
		rightEnemy->ypos = 999;
		return true;
	}

	else if (canBeatLeft == true && canBeatRight == true)
	{
		printf("%s", "(L)eft or (R)ight?");
		while (dir != 'l' && dir != 'r')
		{
			scanf("%c", &dir);
		}
		if (dir == 'l')
		{
			*newxpos = leftEnemy->xpos - 1;
			*newypos = leftEnemy->ypos + 1;
			leftEnemy->active = false;
			//test
			leftEnemy->xpos = 999;
			leftEnemy->ypos = 999;
			return true;
		}
		else if (dir == 'r')
		{
			*newxpos = rightEnemy->xpos + 1;
			*newypos = rightEnemy->ypos + 1;
			rightEnemy->active = false;
			//test
			rightEnemy->xpos = 999;
			rightEnemy->ypos = 999;
			return true;
		}
	}
}

bool checkForEnemiesAsQueen(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos)
{
	bool hasBeaten = false;
	bool newIncorrect = false;
	bool canBeatToLeftUp = true;
	bool canBeatToRightUp = true;
	bool canBeatToLeftDown = true;
	bool canBeatToRightDown = true;
	
	char dir = 'z';

	for (int i = 0; i < 12; i++)
	{
		if (enemyPieces[i].xpos == *newxpos && enemyPieces[i].ypos == *newypos)
		{
			if (enemyPieces[i].ypos == 0 || enemyPieces[i].xpos == 0 || enemyPieces[i].xpos == 7 || enemyPieces[i].ypos == 7)
			{
				newIncorrect = true;
				break;
			}
			
			if (foundPiece->ypos > enemyPieces[i].ypos) //BEATING UP!
			{
				canBeatToRightDown = false;
				canBeatToLeftDown = false;
				for (int y = 0; y < 12; y++)
				{
					if ((enemyPieces[y].xpos == enemyPieces[i].xpos + 1 && enemyPieces[y].ypos == enemyPieces[i].ypos - 1) || (ownPieces[y].xpos == enemyPieces[i].xpos + 1 && ownPieces[y].ypos == enemyPieces[i].ypos - 1))
					{
						canBeatToRightUp = false;
					}
					if ((enemyPieces[y].xpos == enemyPieces[i].xpos - 1 && enemyPieces[y].ypos == enemyPieces[i].ypos - 1) || (ownPieces[y].xpos == enemyPieces[i].xpos - 1 && ownPieces[y].ypos == enemyPieces[i].ypos - 1))
					{
						canBeatToLeftUp = false;
					}
				}

				if (canBeatToLeftUp == false && canBeatToRightUp == false)
				{
					newIncorrect = true;

					break;
				}

				else if (canBeatToLeftUp == false && canBeatToRightUp == true)
				{
					printf("%s", "prawo");
					*newxpos = enemyPieces[i].xpos + 1;
					*newypos = enemyPieces[i].ypos - 1;
					enemyPieces[i].active = false;
					//test
					enemyPieces[i].xpos = 999;
					enemyPieces[i].ypos = 999;
					hasBeaten = true;
					break;
				}

				else if (canBeatToLeftUp == true && canBeatToRightUp == false)
				{
					printf("%s", "lewo");
					*newxpos = enemyPieces[i].xpos - 1;
					*newypos = enemyPieces[i].ypos - 1;
					enemyPieces[i].active = false;
					//test
					enemyPieces[i].xpos = 999;
					enemyPieces[i].ypos = 999;
					hasBeaten = true;
					break;
				}

				else if (canBeatToLeftUp == true && canBeatToRightUp == true)
				{
					if (enemyPieces[i].xpos > foundPiece->xpos)
						dir = 'r';
					else
						dir = 'l';

					if (dir == 'r')
					{
						printf("%s", "prawo");
						*newxpos = enemyPieces[i].xpos + 1;
						*newypos = enemyPieces[i].ypos - 1;
						enemyPieces[i].active = false;
						//test
						enemyPieces[i].xpos = 999;
						enemyPieces[i].ypos = 999;
						hasBeaten = true;
						break;
					}

					else if (dir == 'l')
					{
						printf("%s", "lewo");
						*newxpos = enemyPieces[i].xpos - 1;
						*newypos = enemyPieces[i].ypos - 1;
						enemyPieces[i].active = false;
						//test
						enemyPieces[i].xpos = 999;
						enemyPieces[i].ypos = 999;
						hasBeaten = true;
						break;
					}

				}

			}
			else if (foundPiece->ypos < enemyPieces[i].ypos) //BEATING DOWN
			{
				canBeatToRightUp = false;
				canBeatToLeftUp = false;
				for (int y = 0; y < 12; y++)
				{
					if ((enemyPieces[y].xpos == enemyPieces[i].xpos + 1 && enemyPieces[y].ypos == enemyPieces[i].ypos + 1) || (ownPieces[y].xpos == enemyPieces[i].xpos + 1 && ownPieces[y].ypos == enemyPieces[i].ypos + 1))
					{
						canBeatToRightDown = false;
					}
					if ((enemyPieces[y].xpos == enemyPieces[i].xpos - 1 && enemyPieces[y].ypos == enemyPieces[i].ypos + 1) || (ownPieces[y].xpos == enemyPieces[i].xpos - 1 && ownPieces[y].ypos == enemyPieces[i].ypos + 1))
					{
						canBeatToLeftDown = false;
					}
				}

				if (canBeatToLeftDown == false && canBeatToRightDown == false)
				{
					newIncorrect = true;

					break;
				}

				else if (canBeatToLeftDown == false && canBeatToRightDown == true)
				{
					printf("%s", "prawo");
					*newxpos = enemyPieces[i].xpos + 1;
					*newypos = enemyPieces[i].ypos + 1;
					enemyPieces[i].active = false;
					//test
					enemyPieces[i].xpos = 999;
					enemyPieces[i].ypos = 999;
					hasBeaten = true;
					break;
				}

				else if (canBeatToLeftDown == true && canBeatToRightDown == false)
				{
					printf("%s", "lewo");
					*newxpos = enemyPieces[i].xpos - 1;
					*newypos = enemyPieces[i].ypos + 1;
					enemyPieces[i].active = false;
					//test
					enemyPieces[i].xpos = 999;
					enemyPieces[i].ypos = 999;
					hasBeaten = true;
					break;
				}

				else if (canBeatToLeftDown == true && canBeatToRightDown == true)
				{
					if (enemyPieces[i].xpos > foundPiece->xpos)
						dir = 'r';
					else
						dir = 'l';

					if (dir == 'r')
					{
						printf("%s", "prawo");
						*newxpos = enemyPieces[i].xpos + 1;
						*newypos = enemyPieces[i].ypos + 1;
						enemyPieces[i].active = false;
						//test
						enemyPieces[i].xpos = 999;
						enemyPieces[i].ypos = 999;
						hasBeaten = true;
						break;
					}

					else if (dir == 'l')
					{
						printf("%s", "lewo");
						*newxpos = enemyPieces[i].xpos - 1;
						*newypos = enemyPieces[i].ypos + 1;
						enemyPieces[i].active = false;
						//test
						enemyPieces[i].xpos = 999;
						enemyPieces[i].ypos = 999;
						hasBeaten = true;
						break;
					}

				}
			}
		}

		
	}
	while (hasBeaten)
	hasBeaten = checkForFurtherEnemiesAsQueen(foundPiece, enemyPieces, ownPieces, newxpos, newypos);
	return newIncorrect;
}

bool checkForFurtherEnemiesAsQueen(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos)
{
	Piece* leftEnemyUp = NULL;
	Piece* rightEnemyUp = NULL;
	Piece* leftEnemyDown = NULL;
	Piece* rightEnemyDown = NULL;
	char dir = 'z';
	bool canBeatRightUp = false;
	bool canBeatLeftUp = false;
	bool canBeatRightDown = false;
	bool canBeatLeftDown = false;

	for (int i = 0; i < 12; i++)
	{
		if (enemyPieces[i].xpos == *newxpos + 1 && enemyPieces[i].ypos == *newypos - 1)
		{
			rightEnemyUp = &enemyPieces[i];
			canBeatRightUp = true;
		}
		else if (enemyPieces[i].xpos == *newxpos - 1 && enemyPieces[i].ypos == *newypos - 1)
		{
			leftEnemyUp = &enemyPieces[i];
			canBeatLeftUp = true;
		}

		else if (enemyPieces[i].xpos == *newxpos + 1 && enemyPieces[i].ypos == *newypos + 1)
		{
			rightEnemyDown = &enemyPieces[i];
			canBeatRightDown = true;
		}
		else if (enemyPieces[i].xpos == *newxpos - 1 && enemyPieces[i].ypos == *newypos + 1)
		{
			leftEnemyDown = &enemyPieces[i];
			canBeatLeftDown = true;
		}
	}

	//Checking for pieces behind the enemies
	//Leftenemy can only be beaten to the left
	if (leftEnemyUp)
	{
		if (leftEnemyUp->active == false)
			canBeatLeftUp = false;
		for (int i = 0; i < 12; i++)
		{
			if ((enemyPieces[i].xpos == leftEnemyUp->xpos - 1 && enemyPieces[i].ypos == leftEnemyUp->ypos - 1 ) || (ownPieces[i].xpos == leftEnemyUp->xpos - 1 && ownPieces[i].ypos == leftEnemyUp->ypos - 1))
				canBeatLeftUp = false;
		}
	}

	//Leftenemy can only be beaten to the right
	if (rightEnemyUp)
	{
		if (rightEnemyUp->active == false)
			canBeatRightUp = false;
		for (int i = 0; i < 12; i++)
		{
			if ((enemyPieces[i].xpos == rightEnemyUp->xpos + 1 && enemyPieces[i].ypos == rightEnemyUp->ypos - 1) || (ownPieces[i].xpos == rightEnemyUp->xpos + 1 && ownPieces[i].ypos == rightEnemyUp->ypos - 1))
				canBeatRightUp = false;
		}
	}

	if (leftEnemyDown)
	{
		if (leftEnemyDown->active == false)
			canBeatLeftDown = false;
		for (int i = 0; i < 12; i++)
		{
			if ((enemyPieces[i].xpos == leftEnemyDown->xpos - 1 && enemyPieces[i].ypos == leftEnemyDown->ypos + 1) || (ownPieces[i].xpos == leftEnemyDown->xpos - 1 && ownPieces[i].ypos == leftEnemyDown->ypos + 1))
				canBeatLeftDown = false;
		}
	}

	//Leftenemy can only be beaten to the right
	if (rightEnemyDown)
	{
		if (rightEnemyDown->active == false)
			canBeatRightDown = false;
		for (int i = 0; i < 12; i++)
		{
			if ((enemyPieces[i].xpos == rightEnemyDown->xpos + 1 && enemyPieces[i].ypos == rightEnemyDown->ypos + 1) || (ownPieces[i].xpos == rightEnemyDown->xpos + 1 && ownPieces[i].ypos == rightEnemyDown->ypos + 1))
				canBeatRightDown = false;
		}
	}

	//If its impossible to move, end the sequence
	if (leftEnemyUp == NULL && rightEnemyUp == NULL && leftEnemyDown == NULL && rightEnemyDown == NULL)
		return false;

	//Condition so it doesnt jump out of the board
	if (leftEnemyUp != NULL)
	{
		if (leftEnemyUp->ypos == 0 || leftEnemyUp->xpos == 0)
			canBeatLeftUp = false;
	}
	if (rightEnemyUp != NULL)
	{
		if (rightEnemyUp->ypos == 0 || rightEnemyUp->xpos == 7)
			canBeatRightUp = false;
	}

	if (leftEnemyDown != NULL)
	{
		if (leftEnemyDown->ypos == 7 || leftEnemyDown->xpos == 0)
			canBeatLeftDown = false;
	}
	if (rightEnemyDown != NULL)
	{
		if (rightEnemyDown->ypos == 7 || rightEnemyDown->xpos == 7)
			canBeatRightDown = false;
	}

	if (canBeatLeftUp == false && canBeatRightUp == false && canBeatLeftDown == false && canBeatRightDown == false)
	{
		return false;
	}


	
	if (canBeatLeftDown == true && canBeatRightDown == false && canBeatLeftUp == false && canBeatRightUp == false)
	{
		*newxpos = leftEnemyDown->xpos - 1;
		*newypos = leftEnemyDown->ypos + 1;
		leftEnemyDown->active = false;
		//test
		leftEnemyDown->xpos = 999;
		leftEnemyDown->ypos = 999;
		return true;
	}
	else if (canBeatLeftDown == false && canBeatRightDown == true && canBeatLeftUp == false && canBeatRightUp == false)
	{
		*newxpos = rightEnemyDown->xpos + 1;
		*newypos = rightEnemyDown->ypos + 1;
		rightEnemyDown->active = false;
		//test
		rightEnemyDown->xpos = 999;
		rightEnemyDown->ypos = 999;
		return true;
	}
	else if (canBeatLeftDown == false && canBeatRightDown == false && canBeatLeftUp == true && canBeatRightUp == false)
	{
		*newxpos = leftEnemyUp->xpos - 1;
		*newypos = leftEnemyUp->ypos - 1;
		leftEnemyUp->active = false;
		//test
		leftEnemyUp->xpos = 999;
		leftEnemyUp->ypos = 999;
		return true;
	}
	else if (canBeatLeftDown == false && canBeatRightDown == false && canBeatLeftUp == false && canBeatRightUp == true)
	{
		*newxpos = rightEnemyUp->xpos + 1;
		*newypos = rightEnemyUp->ypos - 1;
		rightEnemyUp->active = false;
		//test
		rightEnemyUp->xpos = 999;
		rightEnemyUp->ypos = 999;
		return true;
	}
	//ADDING CHOICE!
	else
	{
		printf("%s", "MAKE A CHOICE!\n");
		if (canBeatLeftUp)
			printf("%s", " (Q) For LeftUp. ");
		if (canBeatRightUp)
			printf("%s", " (W) For RightUp. ");
		if (canBeatLeftDown)
			printf("%s", " (A) For LeftDown. ");
		if (canBeatRightDown)
			printf("%s", " (S) For RightDown. ");

		while (dir != 'q' && dir != 'w' && dir != 'a' && dir != 's')
		{
			scanf("%c", &dir);
		}
		bool incMove = false;
		do
		{
			if(incMove)
				scanf("%c", &dir);

			if (dir == 'q' && canBeatLeftUp == false)
				incMove = true;
			else if (dir == 'w' && canBeatRightUp == false)
				incMove = true;
			else if (dir == 'a' && canBeatLeftDown == false)
				incMove = true;
			else if (dir == 'w' && canBeatRightDown == false)
				incMove = true;
		} while (incMove);
		
		if (dir == 'q')
		{
			*newxpos = leftEnemyUp->xpos - 1;
			*newypos = leftEnemyUp->ypos - 1;
			leftEnemyUp->active = false;
			//test
			leftEnemyUp->xpos = 999;
			leftEnemyUp->ypos = 999;
			return true;
		}
		else if (dir == 'w')
		{
			*newxpos = rightEnemyUp->xpos + 1;
			*newypos = rightEnemyUp->ypos - 1;
			rightEnemyUp->active = false;
			//test
			rightEnemyUp->xpos = 999;
			rightEnemyUp->ypos = 999;
			return true;
		}
		else if (dir == 'a')
		{
			*newxpos = leftEnemyDown->xpos - 1;
			*newypos = leftEnemyDown->ypos + 1;
			leftEnemyDown->active = false;
			//test
			leftEnemyDown->xpos = 999;
			leftEnemyDown->ypos = 999;
			return true;
		}
		else if (dir == 's')
		{
			*newxpos = rightEnemyDown->xpos + 1;
			*newypos = rightEnemyDown->ypos + 1;
			rightEnemyDown->active = false;
			//test
			rightEnemyDown->xpos = 999;
			rightEnemyDown->ypos = 999;
			return true;
		}
	}

}



void checkIfBecameQueen(Piece* foundpiece)
{
	if (foundpiece->colour == 'b' && foundpiece->ypos == 0)
	{
		foundpiece->isQueen = true;
		foundpiece->colour = 'B';
	}
	else if (foundpiece->colour == 'w' && foundpiece->ypos == 7)
	{
		foundpiece->isQueen = true;
		foundpiece->colour = 'W';
	}

}

void initializeBoard(GameBoard* board)
{
	*board = (char**)malloc(9 * sizeof(char*));
	for (int i = 0; i < 9; i++)
	{	
		(*board)[i] = (char*)malloc(9 * sizeof(char));
	}

	for (int i = 0; i < 8; i++)
	{
		for (int y = 0; y < 8; y++)
		{
			//(*board)[i][y] = defaultGameBoard[i][y];
			(*board)[i][y] = '0';
		}
	}

	(*board)[8][0] = '0';
	(*board)[8][1] = '1';
	(*board)[8][2] = '2';
	(*board)[8][3] = '3';
	(*board)[8][4] = '4';
	(*board)[8][5] = '5';
	(*board)[8][6] = '6';
	(*board)[8][7] = '7';

	(*board)[0][8] = '0';
	(*board)[1][8] = '1';
	(*board)[2][8] = '2';
	(*board)[3][8] = '3';
	(*board)[4][8] = '4';
	(*board)[5][8] = '5';
	(*board)[6][8] = '6';
	(*board)[7][8] = '7';
	(*board)[8][8] = '.';



}

void updateBoard(Piece* blacks, Piece* whites, GameBoard* board)
{
	for (int i = 0; i < 8; i++)
	{
		for (int y = 0; y < 8; y++)
		{
			(*board)[i][y] = '0';
		}
	}
		for (int i = 0; i < 12; i++)
		{
			if (blacks[i].active)
			{
				(*board)[blacks[i].ypos][blacks[i].xpos] = blacks[i].colour;
			}
			if (whites[i].active)
			{
				(*board)[whites[i].ypos][whites[i].xpos] = whites[i].colour;
			}
		}
	
}



void displayBoard(GameBoard board)
{
	for (int i = 0; i < 9; i++)
	{
		for (int y = 0; y < 9; y++)
		{
			printf("%c", (int)board[i][y]);
		}
		printf("\n");
	}
}

bool checkIfFinish(Piece* blacks, Piece* whites)
{
	int w = 0;
	for (int i = 0; i < 12; i++)
	{
		if (whites[i].active)
			w++;
	}

	if (w == 0)
	{
		printf("BLACKS WON!");
		return true;
	}

	int b = 0;
	for (int i = 0; i < 12; i++)
	{
		if (blacks[i].active)
			b++;
	}
	if (b == 0)
	{
		printf("WHITES WON!");
		return true;
	}

	return false;
}