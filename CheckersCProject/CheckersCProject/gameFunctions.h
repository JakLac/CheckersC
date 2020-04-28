#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

extern  const char defaultGameBoard[8][8];


typedef char** GameBoard;

typedef struct
{
	bool active;
	char colour;
	bool isQueen;
	int ypos;
	int xpos;
} Piece;

typedef struct
{
	GameBoard board;

	int activeWhite;
	int activeBlack;
	bool running;
} Game;

void initializeBlackPieces(Piece* pieces);
void initializeWhitePieces(Piece* pieces);
void movePieces(Piece* pieces, char colour,Piece* enemyPieces);
void moveWhitePieces(Piece* pieces);
void updateBoard(Piece* blacks, Piece* whites, GameBoard* board);
void initializeGame(Game* game);
void initializeBoard(GameBoard board);
void displayBoard(GameBoard*board);
bool checkForEnemiesAsNotQueenBlack(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
bool checkForEnemiesAsNotQueenWhite(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
Piece* InputFindPiece(Piece* pieces, int xpos, int ypos, char colour);


