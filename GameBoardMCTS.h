#pragma once
#include "GameBoard.h"
// Inherits GameBoard. Used for MCTS, containing utilities
class GameBoardMCTS :
    public GameBoard
{
public:
    GameBoardMCTS(int r, int c) : GameBoard(r, c) {};
    // returns possible moves, aka columns that aren't filled up
    vector<int> possibleMoves();


};

