#pragma once
#include <array>
#include <iostream>
#include <vector>

using namespace std;
//Base game board class for connect 4.
class GameBoard
{
public:
	GameBoard();
	GameBoard(int r, int c);
	~GameBoard();
	int getPlayerID() { return this->playerID; };
	int getOpponentID() { return 3 - playerID; };
	bool getIfGameIsOver() { return terminal; };
	bool getIfGameIsDraw() { return draw; };
	bool getIfGameIsOverAndDraw() { return (terminal && draw); };
	auto getBoard() { return this->board; };
	// to check if the input to the stream is a number, and within bounds
	bool isValidColumn(char pos);
	//display board to console
	void displayBoard();
	// master game manager to be called from main.
	void startGame();
	//these should be private later

	// to quickly change board active player.
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
	/// <summary>
	/// sub function to check if there are 4 in a row in a linear direction. Parameters determine the direction: up, down, backwards, etc.
	/// </summary>
	/// <param name="r">: row to check</param>
	/// <param name="c">: the column to check</param>
	/// <param name="stepX">: steps in the "x" to take</param>
	/// <param name="stepY">: steps in the "y" to take </param>
	/// <returns>bool if there are 4 in a row or not</returns>
	bool isLinearMatch(int r, int c, int stepX, int stepY);
	/// <summary>
	/// To check for a win at the given position. For now, called in doMoveAndChangePlayer().
	/// </summary>
	/// <param name="r">: the row to check</param>
	/// <param name="c">: the column to check</param>
	/// <returns>bool if there are 4 in a row or not</returns>
	bool checkWinAtPos(int r, int c);
protected:
	//maxmium moves in a game 
	int maxMoves = 42;
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
	

	string tab = "                         ";



};

