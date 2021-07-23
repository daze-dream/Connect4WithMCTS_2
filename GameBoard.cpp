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

bool GameBoard::isValidColumn(char pos)
{
	
	if (!isdigit(pos))
		return false;
	if (pos - '0' > column || pos - '0' <= 0)
		return false;
	return true;
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
	//means the index in the vector, as opposed to the real column value
	int indexPos = pos - 1;
	pair<int, bool> result = placePiece(indexPos);
	if (result.second)
	{
		//checks if game is over, and changes terminal bool
		terminal = checkWinAtPos(result.first, indexPos);
		switchActivePlayer();
		moves++;
		//check for draws
		if (moves >= 42)
			draw = true;
		return true;
	}
	else
	{
		return false;
	}
}

pair<int, bool> GameBoard::placePiece(int pos)
{
	bool success = false, turnOver = false;
	int depth = row - 1 ;
	pair<int, bool> toReturn = make_pair(0, false);
	for (int i = depth; i >= 0; i--)
	{
		if (board[i][pos] == 0)
		{
			board[i][pos] = playerID;
			success = true;
			toReturn.first = i;
			toReturn.second = success;
			break;
		}
	}

	return toReturn;
}

void GameBoard::placePieceRaw(int row, int column, int id)
{
	board[row][column] = id;
}

bool GameBoard::isLinearMatch(int r, int c, int stepX, int stepY)
{
	const int startValue = this->board[r][c];
	bool is4Match = true;

	/* Confirm the two values after it match. */
	for (int i = 1; i < 4; ++i) // forward and downward
	{
		int columnStep = c + i * stepX;
		int rowStep = r + i * stepY;
		//cout << "row " << rowStep + 1 << " column " << columnStep + 1 << ": ";
		if (rowStep > 5 || rowStep < 0)
		{
			//cout << "row out of range";
			return false;
		}
		if (columnStep > 6 || columnStep < 0)
		{
			//cout << "column out of range";
			return false;
		}
		//cout << this->board[rowStep][columnStep] << " ";
		if (this->board[rowStep][columnStep] != startValue)
		{
			is4Match = false;
			break;
		}
	}
	/* If we got here, then they all match! */
	return is4Match;

}

bool GameBoard::checkWinAtPos(int r, int c)
{
	return (isLinearMatch(r, c, 1, 0) ||  // Horizontal forward
		isLinearMatch(r, c, -1, 0) || // Horizontal backward
		isLinearMatch(r, c, 0, -1) ||	//Vertical up
		isLinearMatch(r, c, 0, 1) ||  // Vertical down
		isLinearMatch(r, c, 1, 1) ||  // diagonal forward->down
		isLinearMatch(r, c, -1, -1) || //diagonal back->up
		isLinearMatch(r, c, 1, -1) || // diagonal forward->up
		isLinearMatch(r, c, -1, 1)); //diagonal back->down
}

void GameBoard::startGame()
{
	displayBoard();
	while (!terminal)
	{
		char input = ' ';
		int pos = 0;
		cout << "Enter column: ";
		cin >> input;
		while (!isValidColumn(input)) 
		{
			cout << "Invalid input.  Try again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> input;
		}
		pos = input - '0';
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
	if (terminal && !draw)
	{
		cout << "Player " << getOpponentID() << " won in " << moves << " moves!" << endl;
	}
	else
	{
		cout << "42 moves made and no winner. It's a draw!" << endl;
	}
}
