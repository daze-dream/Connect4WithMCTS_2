#include "GameBoardMCTS.h"

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
