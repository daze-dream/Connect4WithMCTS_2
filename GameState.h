#pragma once
#include "GameBoardMCTS.h"
#include <vector>



class GameState
{
public: 
	GameState();
	//constructor that takes a gameboard. default constructor for GameBoardMCTS taken care of in base class
	GameState(GameBoardMCTS incBoard);
	void setBoard(GameBoardMCTS incBoard) { stateBoard = incBoard; };
	auto getBoard() { return stateBoard; };
	// simple getter, does not fill up states. See fillUpPossibleStates
	vector<GameState> getPossibleStates();
	// much safer than returning board by reference. does a move in the internal board
	bool doMoveForBoard(int);
	int getVisitCount() { return visitCount; };
	double getWinScore() { return winScore; };
	// fills up the internal possibleStates vector
	void fillUpPossibleStates();
	// fills up and then returns the possibleStates vector.
	vector<GameState> fillThenReturnPossibleStates();
	~GameState();
private:
	GameBoardMCTS stateBoard;
	int visitCount = 0;
	double winScore = 0;
	vector<GameState> possibleStates;
};

