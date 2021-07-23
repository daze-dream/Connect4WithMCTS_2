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
	int getOpponentID() { return 3 - playerID; };
	bool getIfGameIsOver() { return terminal; };
	bool getIfGameIsDraw() { return draw; };
	bool getIfGameIsOverAndDraw() { return (terminal && draw); };
	auto getBoard() { return this->board; };
	bool isValidColumn(char pos);
	//display board to console
	void displayBoard();
	// master game manager to be called from main.
	void startGame();

	//these should be private later

	void switchActivePlayer() { playerID = 3 - playerID; };
	/// <summary>
	/// Currently checks validity, places a piece, checks win condition
	/// </summary>
	/// <param name="pos">: the raw row value. Converts into proper index inside function</param>
	/// <returns></returns>
	bool doMoveAndChangePlayer(int pos);
	/// <summary>
	/// used to place a piece at the selected column position only.
	/// </summary>
	/// <param name="pos">: the index of the vector. Higher level functions change real column to index value.</param>
	/// <returns>a pair: first value is the depth, second value is bool for successful placement</returns>
	pair<int, bool> placePiece(int pos);
	// for testing purposes, places a value at any part of th 2D array.
	void placePieceRaw(int row, int column, int id);
	bool isLinearMatch(int r, int c, int stepX, int stepY);
	bool checkWinAtPos(int r, int c);
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

	string tab = "                         ";



};

