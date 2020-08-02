#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*!
* \file
* \brief Plik z deklaracjami funkcji
*
* Plik nag≥Ûwkowy zawierajπcy deklaracje wszystkich funkcji i struktur uøywanych w programie
*/

extern  const char defaultGameBoard[9][9];

/**
Nazwanie wskaünika na wskaünik charÛw(potrzebny do opisu dwuwymiarowej tablicy) gameBoard
*/
typedef char** GameBoard;

/** Struktura opisujπca pionek
*/
typedef struct
{
	bool active; ///< mÛwi czy jest aktywne
	char colour; ///< opisuje kolor w - bia≥y, W - bia≥a krÛlowa, b - czarny, B - czarna krÛlowa
	bool isQueen; ///< mÛwi czy jest krÛlowπ
	int ypos; ///< opisuje pozycje y
	int xpos; ///< opisuje pozycje x
} Piece;

/** Struktura opisujπca grÍ
*/
typedef struct
{
	GameBoard board; ///< dwuwymiarowa tablica opisujπce pole gry

	int activeWhite; ///< IloúÊ aktywnych bia≥ych pionkÛw
	int activeBlack; ///< IloúÊ aktywnych czarnych pionkÛw
	bool running; ///< Sprawdzanie czy pÍtla gry winna siÍ odbywaÊ
} Game;
/** Funkcja odpowiedzialna za ustawienie czarnych pionkÛw
@param pieces wskaünik do czarnych pionkÛw
*/
void initializeBlackPieces(Piece* pieces);
/** Funkcja odpowiedzialna za ustawienie bia≥ych pionkÛw
@param pieces wskaünik do bia≥ych pionkÛw
*/
void initializeWhitePieces(Piece* pieces);
/** Funkcja odpowiedzialna za wykonywanie ruchu pionkÛw
@param pieces wskaünik do pionkÛw
@param colour kololor pionka
@param enemyPieces wskaünik do pionkÛw przeciwnika
*/
void movePieces(Piece* pieces, char colour,Piece* enemyPieces);
/** Funkcja odpowiedzialna za odúwieøenie wyúwietlanej planszy
@param black wskaünik do czarnych pionkÛw
@param whites wskaünik do bia≥ych pionkÛw
@param Gameboard wskaünik na planszÍ gry
*/
void updateBoard(Piece* blacks, Piece* whites, GameBoard* board);
/** Funkcja odpowiedzialna za inicjalizacjÍ gry
@param game wskaünik na strukturÍ odpowiedzialnπ "nadzorowanie" gry
*/
void initializeGame(Game* game);
/** Funkcja odpowiedzialna za inicjalizacjÍ planszy
@param game wskaünik na planszÍ
*/
void initializeBoard(GameBoard* board);
/** Funkcja odpowiedzialna za wyúwietlanie planszy
@param board wskaünik na planszÍ
*/
void displayBoard(GameBoard board);
/** Funkcja odpowiedzialna za szukanie przeciwnikÛw jako czarna nie-krÛlowa
@param foundPiece pionek dla ktÛrego rozpatrujemy sytuacje
@param enemyPieces wskaünik na pionki przeciwnika
@param ownPieces wskaünik na w≥asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForEnemiesAsNotQueenBlack(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie dalszych (po zbiciu) przeciwnikÛw jako czarna nie-krÛlowa
@param foundPiece pionek dla ktÛrego rozpatrujemy sytuacje
@param enemyPieces wskaünik na pionki przeciwnika
@param ownPieces wskaünik na w≥asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForFurtherEnemiesAsNotQueenBlack(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie przeciwnikÛw jako bia≥a nie-krÛlowa
@param foundPiece pionek dla ktÛrego rozpatrujemy sytuacje
@param enemyPieces wskaünik na pionki przeciwnika
@param ownPieces wskaünik na w≥asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForEnemiesAsNotQueenWhite(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie dalszych (po zbiciu) przeciwnikÛw jako bia≥a nie-krÛlowa
@param foundPiece pionek dla ktÛrego rozpatrujemy sytuacje
@param enemyPieces wskaünik na pionki przeciwnika
@param ownPieces wskaünik na w≥asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForFurtherEnemiesAsNotQueenWhite(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie przeciwnikÛw jako krÛlowa dowolnego koloru
@param foundPiece pionek dla ktÛrego rozpatrujemy sytuacje
@param enemyPieces wskaünik na pionki przeciwnika
@param ownPieces wskaünik na w≥asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForEnemiesAsQueen(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie dalszych (po zbiciu) przeciwnikÛw jako krÛlowa dowolnego koloru
@param foundPiece pionek dla ktÛrego rozpatrujemy sytuacje
@param enemyPieces wskaünik na pionki przeciwnika
@param ownPieces wskaünik na w≥asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForFurtherEnemiesAsQueen(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za sprawdzenie czy dany pionek koÒczπcy swπ turÍ zosta≥ krÛlowπ
@param foundpiece pionek dla ktÛrego rozpatrujemy sytuacje
*/
void checkIfBecameQueen(Piece* foundpiece);
/** Funkcja odpowiedzialna za znajdywanie pionka ktÛrym chcemy ruszyÊ
@param pieces wskaünik na pionki ktÛrych jest tura
@param xpos pozycja na osi x
@param ypos pozycja na osi y
@param colour kolor pionka
*/
Piece* InputFindPiece(Piece* pieces, int xpos, int ypos, char colour, Piece* enemyPieces);
/** Funkcja odpowiedzialna za sprawdzenie czy gra siÍ zakoÒczy≥a
@param blacks wskaünik na czarne pionki
@param whites wskaünik na bia≥e pionki
*/
bool checkIfFinish(Piece* blacks, Piece* whites);

void startGamesPlayed();
