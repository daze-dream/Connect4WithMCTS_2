//  main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Another attempt at making Connect 4 with a MCTS AI.

#define DOCTEST_CONFIG_IMPLEMENT

#include <iostream>
#include "GameBoard.h"
#include "GameBoardMCTS.h"
#include "doctest.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	doctest::Context context;
	int result = context.run();
	//if (context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
		//return result;          // propagate the result of the tests
	//GameBoardMCTS c4(6, 7);
	//c4.startGame();
	cout << endl;
	system("pause");
	return result;
}
