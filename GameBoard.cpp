#include "GameBoard.h"

GameBoard::GameBoard(int r, int c)
{
	row = r;
	column = c;
	this->board = vector<vector<int>>(r, vector<int>(c, 0));
}

GameBoard::~GameBoard()
{
}

void GameBoard::displayBoard()
{
	cout << tab
		<< "1 2 3 4 5 6 7" << endl;
	cout << tab
		<< "-------------" << endl;
	for (int i = 0; i < row; ++i)
	{
		//to "center" the board display
		cout << tab;
		for (int j = 0; j <column ; ++j)
		{
			cout << this->board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Current Player: " << playerID << "  ||  "
		<< "Moves: " << moves << endl;
}

bool GameBoard::doMoveAndChangePlayer(int pos)
{
	int realPos = pos - 1;
	if (placePiece(realPos))
	{
		switchActivePlayer();
		moves++;
		return true;
	}
	else
	{
		return false;
	}
}

bool GameBoard::placePiece(int pos)
{
	bool success = false, turnOver = false;
	int depth = row - 1 ;
	for (int i = depth; i >= 0; i--)
	{
		if (board[i][pos] == 0)
		{
			board[i][pos] = playerID;
			success = true;
			break;
		}
	}
	return success;
}

void GameBoard::startGame()
{
	displayBoard();
	while (moves < 42)
	{
		int pos = 0;
		cout << "Enter column: ";
		while (!(cin >>pos) && pos > column) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		cout << "Dropping at: " << pos << "...";
		if (doMoveAndChangePlayer(pos))
		{
			cout << "success!" << endl;
		}
		else
		{
			cout << pos << " is full. Select another column." << endl;
		}
		displayBoard();
	}
}
