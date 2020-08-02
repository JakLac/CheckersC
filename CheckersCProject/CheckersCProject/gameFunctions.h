#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*!
* \file
* \brief Plik z deklaracjami funkcji
*
* Plik nag��wkowy zawieraj�cy deklaracje wszystkich funkcji i struktur u�ywanych w programie
*/

extern  const char defaultGameBoard[9][9];

/**
Nazwanie wska�nika na wska�nik char�w(potrzebny do opisu dwuwymiarowej tablicy) gameBoard
*/
typedef char** GameBoard;

/** Struktura opisuj�ca pionek
*/
typedef struct
{
	bool active; ///< m�wi czy jest aktywne
	char colour; ///< opisuje kolor w - bia�y, W - bia�a kr�lowa, b - czarny, B - czarna kr�lowa
	bool isQueen; ///< m�wi czy jest kr�low�
	int ypos; ///< opisuje pozycje y
	int xpos; ///< opisuje pozycje x
} Piece;

/** Struktura opisuj�ca gr�
*/
typedef struct
{
	GameBoard board; ///< dwuwymiarowa tablica opisuj�ce pole gry

	int activeWhite; ///< Ilo�� aktywnych bia�ych pionk�w
	int activeBlack; ///< Ilo�� aktywnych czarnych pionk�w
	bool running; ///< Sprawdzanie czy p�tla gry winna si� odbywa�
} Game;
/** Funkcja odpowiedzialna za ustawienie czarnych pionk�w
@param pieces wska�nik do czarnych pionk�w
*/
void initializeBlackPieces(Piece* pieces);
/** Funkcja odpowiedzialna za ustawienie bia�ych pionk�w
@param pieces wska�nik do bia�ych pionk�w
*/
void initializeWhitePieces(Piece* pieces);
/** Funkcja odpowiedzialna za wykonywanie ruchu pionk�w
@param pieces wska�nik do pionk�w
@param colour kololor pionka
@param enemyPieces wska�nik do pionk�w przeciwnika
*/
void movePieces(Piece* pieces, char colour,Piece* enemyPieces);
/** Funkcja odpowiedzialna za od�wie�enie wy�wietlanej planszy
@param black wska�nik do czarnych pionk�w
@param whites wska�nik do bia�ych pionk�w
@param Gameboard wska�nik na plansz� gry
*/
void updateBoard(Piece* blacks, Piece* whites, GameBoard* board);
/** Funkcja odpowiedzialna za inicjalizacj� gry
@param game wska�nik na struktur� odpowiedzialn� "nadzorowanie" gry
*/
void initializeGame(Game* game);
/** Funkcja odpowiedzialna za inicjalizacj� planszy
@param game wska�nik na plansz�
*/
void initializeBoard(GameBoard* board);
/** Funkcja odpowiedzialna za wy�wietlanie planszy
@param board wska�nik na plansz�
*/
void displayBoard(GameBoard board);
/** Funkcja odpowiedzialna za szukanie przeciwnik�w jako czarna nie-kr�lowa
@param foundPiece pionek dla kt�rego rozpatrujemy sytuacje
@param enemyPieces wska�nik na pionki przeciwnika
@param ownPieces wska�nik na w�asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForEnemiesAsNotQueenBlack(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie dalszych (po zbiciu) przeciwnik�w jako czarna nie-kr�lowa
@param foundPiece pionek dla kt�rego rozpatrujemy sytuacje
@param enemyPieces wska�nik na pionki przeciwnika
@param ownPieces wska�nik na w�asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForFurtherEnemiesAsNotQueenBlack(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie przeciwnik�w jako bia�a nie-kr�lowa
@param foundPiece pionek dla kt�rego rozpatrujemy sytuacje
@param enemyPieces wska�nik na pionki przeciwnika
@param ownPieces wska�nik na w�asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForEnemiesAsNotQueenWhite(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie dalszych (po zbiciu) przeciwnik�w jako bia�a nie-kr�lowa
@param foundPiece pionek dla kt�rego rozpatrujemy sytuacje
@param enemyPieces wska�nik na pionki przeciwnika
@param ownPieces wska�nik na w�asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForFurtherEnemiesAsNotQueenWhite(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie przeciwnik�w jako kr�lowa dowolnego koloru
@param foundPiece pionek dla kt�rego rozpatrujemy sytuacje
@param enemyPieces wska�nik na pionki przeciwnika
@param ownPieces wska�nik na w�asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForEnemiesAsQueen(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za szukanie dalszych (po zbiciu) przeciwnik�w jako kr�lowa dowolnego koloru
@param foundPiece pionek dla kt�rego rozpatrujemy sytuacje
@param enemyPieces wska�nik na pionki przeciwnika
@param ownPieces wska�nik na w�asne pionki
@param newxpos nowa pozycja na osi x
@param newypos nowa pozycja na osi y
*/
bool checkForFurtherEnemiesAsQueen(Piece* foundPiece, Piece* enemyPieces, Piece* ownPieces, int* newxpos, int* newypos);
/** Funkcja odpowiedzialna za sprawdzenie czy dany pionek ko�cz�cy sw� tur� zosta� kr�low�
@param foundpiece pionek dla kt�rego rozpatrujemy sytuacje
*/
void checkIfBecameQueen(Piece* foundpiece);
/** Funkcja odpowiedzialna za znajdywanie pionka kt�rym chcemy ruszy�
@param pieces wska�nik na pionki kt�rych jest tura
@param xpos pozycja na osi x
@param ypos pozycja na osi y
@param colour kolor pionka
*/
Piece* InputFindPiece(Piece* pieces, int xpos, int ypos, char colour, Piece* enemyPieces);
/** Funkcja odpowiedzialna za sprawdzenie czy gra si� zako�czy�a
@param blacks wska�nik na czarne pionki
@param whites wska�nik na bia�e pionki
*/
bool checkIfFinish(Piece* blacks, Piece* whites);

void startGamesPlayed();
