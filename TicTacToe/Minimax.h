#pragma once
#include "GameBoard.h"

class Minimax
{
public:
	int GetMinimax(GameBoard* gameboard, int depth, bool intMax);
	Vector2D FindBestMove(GameBoard* gameBoard);
};