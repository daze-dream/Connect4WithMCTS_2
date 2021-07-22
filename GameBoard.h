#pragma once
#include <array>
#include <iostream>
#include <vector>
using namespace std;

class GameBoard
{
public:
	GameBoard(int r, int c);
	~GameBoard();
	int getPlayerID() { return this->playerID; };
	auto getBoard() { return this->board; };
	//display board to console
	void displayBoard();
	// master game manager to be called from main.
	void startGame();

	//these should be private later

	void switchActivePlayer() { playerID = 3 - playerID; };
	// to do all parts of executing a move: place piece, check win, status, AI move, etc.
	bool doMoveAndChangePlayer(int pos);
	// to only place piece at position. doMove handles the bounds checking for column.
	bool placePiece(int pos);

private:
	//maxmium moves in a game 
	const int maxMoves = 42;
	//by default, constructs regular connect 4.
	int row = 6, column = 7;
	// board representation: 6*7
	vector<vector<int>> board;
	bool draw = false;
	int playerID = 1; //default
	// if there is a winner
	bool terminal = false;
	// to track how many moves have been made
	int moves = 0;
	// checking to see if there is a win
	//bool IsLinearMatch(int column, int row, int stepX, int stepY);
	

	string tab = "                         ";



};

