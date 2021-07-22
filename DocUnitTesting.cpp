#include "doctest.h"
#include "GameBoard.h"

TEST_CASE("Testing doctest")
{
	CHECK(1 == 1);
}

TEST_CASE("Checking piece placement")
{
	GameBoard c4(6, 7);
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
		c4.displayBoard();
		CHECK(c4.doMoveAndChangePlayer(pos) == false);
		CHECK(c4.getPlayerID() == 1);
	}
}