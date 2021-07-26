#include "GameState.h"

GameState::GameState()
{

}

GameState::GameState(GameBoardMCTS incBoard)
{
	this->stateBoard = incBoard;
}

bool GameState::doMoveForBoard(int pos)
{
	return this->stateBoard.doMoveAndChangePlayer(pos);
}

vector<GameState> GameState::getPossibleStates()
{
	return possibleStates;
}

void GameState::fillUpPossibleStates()
{
	vector<int> movesToDo = stateBoard.possibleMoves();
	// needed because when we push directly to the state vector, each new state was getting a copy as well.
	vector<GameState> tempStates;
	while (!movesToDo.empty())
	{
		GameState newState = *this;
		newState.getBoard().doMoveAndChangePlayer(movesToDo.back() + 1);
		//if the move actually works aka column not filled...
		if (newState.doMoveForBoard(movesToDo.back() + 1))
		{
			//then push back that state.
			tempStates.push_back(newState);
		}
		movesToDo.pop_back();
	}
	possibleStates = tempStates;

}

vector<GameState> GameState::fillThenReturnPossibleStates()
{
	vector<int> movesToDo = stateBoard.possibleMoves();
	// needed because when we push directly to the state vector, each new state was getting a copy as well.
	vector<GameState> tempStates;
	while (!movesToDo.empty())
	{
		GameState newState = *this;
		newState.getBoard().doMoveAndChangePlayer(movesToDo.back() + 1);
		//if the move actually works aka column not filled...
		if (newState.doMoveForBoard(movesToDo.back() + 1))
		{
			//then push back that state.
			tempStates.push_back(newState);
		}
		movesToDo.pop_back();
	}
	possibleStates = tempStates;
	return possibleStates;
}

GameState::~GameState()
{
}
