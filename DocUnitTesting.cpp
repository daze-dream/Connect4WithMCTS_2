#include "doctest.h"
#include "GameBoard.h"
#include "GameBoardMCTS.h"
#include "GameState.h"
#include "Node.h"
#include "Tree.h"

TEST_CASE("Testing doctest")
{
	CHECK(1 == 1);
}

TEST_CASE("Checking piece placement")
{
	GameBoard c4(6, 7);
	SUBCASE("Checking valid input")
	{
		CHECK(c4.isValidColumn('1') == true);
		CHECK(c4.isValidColumn('7') == true);
	}
	SUBCASE("Checking invalid input")
	{
		CHECK(c4.isValidColumn('a') == false);
		CHECK(c4.isValidColumn('8') == false);
		CHECK(c4.isValidColumn('0') == false);
		CHECK(c4.isValidColumn('cat') == false);
	}
	SUBCASE("Checking a valid placement")
	{
		int pos = 1;
		CHECK(c4.doMoveAndChangePlayer(pos) == true);
		CHECK(c4.getBoard()[5][0] == 1);
		CHECK(c4.getPlayerID() == 2);
	}
	SUBCASE("Checking invalid placement aka full column")
	{
		int pos = 1;
		for (int i = 0; i <= 6; i++)
		{
			c4.placePiece(pos - 1);
		}
		//c4.displayBoard();
		CHECK(c4.doMoveAndChangePlayer(pos) == false);
		CHECK(c4.getPlayerID() == 1);
	}

}

TEST_CASE("Checking victory: 4 in a row")
{
	GameBoard c4(6, 7);

	SUBCASE("Checking straight line and board terminal status")
	{
		int pos = 1;
		//set up the win condition, 3 in a row
		for (int i = 0; i <= 2; i++)
		{
			c4.placePiece(pos - 1);
		}
		c4.displayBoard();
		CHECK(c4.checkWinAtPos(6-1, 0) == false);
		c4.doMoveAndChangePlayer(pos);
		CHECK(c4.checkWinAtPos(6 - 1, 0) == true);
		CHECK(c4.getIfGameIsOver() == true);

	}
	SUBCASE("Checking a diagonal. Terminal can't be checked but would be true")
	{
		int pos = 1;
		for (int i = 0; i <= 3; i++)
		{
			c4.placePieceRaw(5 - i , i, 1);
		}
		c4.displayBoard();
		CHECK(c4.checkWinAtPos(3 - 1, 4 - 1) == true);
		//CHECK(c4.getIfGameIsOver() == true);
	}

}

TEST_CASE("Checking GameState Utilities")
{
	GameBoardMCTS c4(6, 7);
	c4.doMoveAndChangePlayer(1);
	SUBCASE("Getting possible moves on turn 2 should give 7")
	{
		GameState newState(c4);
		newState.fillUpPossibleStates();
		CHECK(newState.getPossibleStates().size() == 7);
	}
	SUBCASE("A filled column should mean only 6 valid states")
	{
		for (int i = 0; i < 6; i++)
		{
			c4.placePiece(1-1);
		}
		GameState newState(c4);
		newState.fillUpPossibleStates();
		CHECK(newState.getPossibleStates().size() == 6);

	}
	SUBCASE("Testing out the fillAndReturn for states")
	{
		GameState newState(c4);
		CHECK(newState.fillThenReturnPossibleStates().size() == 7);

	}
}
