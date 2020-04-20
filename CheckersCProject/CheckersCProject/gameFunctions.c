#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameFunctions.h"

//NO LONGER NEEDED.
 const char defaultGameBoard[8][8] =
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

	pieces[1].ypos = 5;
	pieces[1].xpos = 2;

	pieces[2].ypos = 5;
	pieces[2].xpos = 4;

	pieces[3].ypos = 5;
	pieces[3].xpos = 6;

	pieces[4].ypos = 6;
	pieces[4].xpos = 1;

	pieces[5].ypos = 6;
	pieces[5].xpos = 3;

	pieces[6].ypos = 6;
	pieces[6].xpos = 5;

	pieces[7].ypos = 6;
	pieces[7].xpos = 7;

	pieces[8].ypos = 7;
	pieces[8].xpos = 0;

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

	pieces[3].ypos = 0;
	pieces[3].xpos = 7;

	pieces[4].ypos = 1;
	pieces[4].xpos = 0;

	pieces[5].ypos = 1;
	pieces[5].xpos = 2;

	pieces[6].ypos = 1;
	pieces[6].xpos = 4;

	pieces[7].ypos = 1;
	pieces[7].xpos = 6;

	pieces[8].ypos = 2;
	pieces[8].xpos = 1;

	pieces[9].ypos = 2;
	pieces[9].xpos = 3;

	pieces[10].ypos = 2;
	pieces[10].xpos = 5;

	pieces[11].ypos = 2;
	pieces[11].xpos = 7;




}

void movePieces(Piece* pieces, char colour, Piece* enemyPieces)
{
	
	int xpos, ypos;
	printf("%s", "First give xpos, then ypos (0-7)");
	scanf("%d", &xpos);
	scanf("%d", &ypos);
	bool incorrect = false;
	if (xpos < 0 || ypos < 0 || xpos>7 || ypos>7)
		incorrect = true;

	while (incorrect)
	{
		printf("%s", "Incorrect input!");
		scanf("%d", &xpos);
		scanf("%d", &ypos);
		incorrect = false;
		if (xpos < 0 || ypos < 0 || xpos>7 || ypos>7)
			incorrect = true;
	}

	Piece* foundPiece = NULL;


	bool found = false;
	for (int i = 0; i < 12; i++)
	{
		if (pieces[i].xpos == xpos && pieces[i].ypos == ypos && pieces[i].colour == colour)
		{
			found = true;
			foundPiece = &pieces[i];
		}


	}

	while (!found)
	{
		printf("%s", "Piece not there!");
		scanf("%d", &xpos);
		scanf("%d", &ypos);
		for (int i = 0; i < 12; i++)
		{
			if (pieces[i].xpos == xpos && pieces[i].ypos == ypos && pieces[i].colour == colour)
			{
				found = true;
				foundPiece = &pieces[i];
			}
		}
	}

	int newxpos, newypos;
	printf("%s", "Where would you like to move to? xpos first, then ypos");
	scanf("%d", &newxpos);
	scanf("%d", &newypos);

	bool newIncorrect = false;
	if (newxpos < 0 || newypos < 0 || newxpos>7 || newypos>7)
		newIncorrect = true;
	do
	{
		if (newIncorrect)
		{
			printf("%s", "Incorrect input!");
			scanf("%d", &newxpos);
			scanf("%d", &newypos);
		}
		newIncorrect = false;
		if (newxpos < 0 || newypos < 0 || newxpos>7 || newypos>7)
			newIncorrect = true;

		bool canBeatToRight = true;
		bool canBeatToLeft = true;
		char dir = 'z';
		bool dirCorrect = false;

		//TO ADD : Moving as a queen + beating enemies
		if (foundPiece->colour == 'b')
		{

			if (foundPiece->isQueen == false)
			{
				if (newxpos == xpos + 1 || newxpos == xpos - 1)
					newIncorrect = false;
				if (newypos != ypos - 1)
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
			newIncorrect = CheckForEnemiesAsNotQueen(foundPiece, enemyPieces, &newxpos, &newypos);

		}


		else if (foundPiece->colour == 'w')
		{

			if (foundPiece->isQueen == false)
			{
				if (newxpos != xpos + 1 && newxpos != xpos - 1)
					newIncorrect = true;
				if (newypos != ypos + 1)
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
			newIncorrect = CheckForEnemiesAsNotQueen(foundPiece, enemyPieces, &newxpos, &newypos);
		}
		//TO ADD: checking whether the piece has become a queen
	} while (newIncorrect);

	foundPiece->xpos = newxpos;
	foundPiece->ypos = newypos;
}

bool CheckForEnemiesAsNotQueen(Piece* foundPiece, Piece* enemyPieces, int *newxpos, int *newypos)
{
	bool newIncorrect = false;
	bool canBeatToLeft = true;
	bool canBeatToRight = true;
	char dir = 'z';

	newIncorrect = false;
	if (foundPiece->colour == 'b')
	{
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
						if (enemyPieces[y].xpos == enemyPieces[i].xpos + 1 && enemyPieces[y].ypos == enemyPieces[i].ypos - 1)
						{
							canBeatToRight = false;
						}
						if (enemyPieces[y].xpos == enemyPieces[i].xpos - 1 && enemyPieces[y].ypos == enemyPieces[i].ypos - 1)
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
						break;
					}

					else if (canBeatToLeft == true && canBeatToRight == false)
					{
						printf("%s", "lewo");
						*newxpos = enemyPieces[i].xpos - 1;
						*newypos = enemyPieces[i].ypos - 1;
						enemyPieces[i].active = false;
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
							break;
						}

						else if (dir == 'l')
						{
							printf("%s", "lewo");
							*newxpos = enemyPieces[i].xpos - 1;
							*newypos = enemyPieces[i].ypos - 1;
							enemyPieces[i].active = false;
							break;
						}

					}

				
			}
		}
	}

	else if (foundPiece->colour == 'w')
	{
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
						if (enemyPieces[y].xpos == enemyPieces[i].xpos + 1 && enemyPieces[y].ypos == enemyPieces[i].ypos + 1)
						{
							canBeatToRight = false;
						}
						if (enemyPieces[y].xpos == enemyPieces[i].xpos - 1 && enemyPieces[y].ypos == enemyPieces[i].ypos + 1)
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
						break;
					}

					else if (canBeatToLeft == true && canBeatToRight == false)
					{
						printf("%s", "lewo");
						*newxpos = enemyPieces[i].xpos - 1;
						*newypos = enemyPieces[i].ypos + 1;
						enemyPieces[i].active = false;
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
							break;
						}

						else if (dir == 'l')
						{
							printf("%s", "lewo");
							*newxpos = enemyPieces[i].xpos - 1;
							*newypos = enemyPieces[i].ypos + 1;
							enemyPieces[i].active = false;
							break;
						}

					}

			}
		}
	}
	return newIncorrect;
}

void initializeBoard(GameBoard* board)
{
	*board = (char**)malloc(8 * sizeof(char*));
	for (int i = 0; i < 8; i++)
	{	
		(*board)[i] = (char*)malloc(8 * sizeof(char));
	}

	for (int i = 0; i < 8; i++)
	{
		for (int y = 0; y < 8; y++)
		{
			//(*board)[i][y] = defaultGameBoard[i][y];
			(*board)[i][y] = '0';
		}
	}
}

void updateBoard(Piece* blacks, Piece* whites, GameBoard* board)
{
	for (int i = 0; i < 8; i++)
	{
		for (int y = 0; y < 8; y++)
		{
			(*board)[i][y] = '0';
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
}



void displayBoard(GameBoard board)
{
	for (int i = 0; i < 8; i++)
	{
		for (int y = 0; y < 8; y++)
		{
			printf("%c", (int)board[i][y]);
		}
		printf("\n");
	}
}