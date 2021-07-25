#include "GameBoardMCTS.h"

GameBoardMCTS::GameBoardMCTS(const GameBoardMCTS& orig)
{
	this->board = orig.board;
	this->column = orig.column;
	this->row = orig.row;
	this->playerID = orig.playerID;
	this->terminal = orig.terminal;
	this->draw = orig.draw;
	this->moves = orig.moves;
}

vector<int> GameBoardMCTS::possibleMoves()
{
	vector<int> toReturn;
	for (int i = 0; i < column; i++)
	{
		if (board[0][i] == 0)
			toReturn.push_back(i);
	}
	return toReturn;
}
