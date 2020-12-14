#include "Minimax.h"
#include <vector>
#include "globals.h"

using namespace globals;

int Minimax::GetMinimax(GameBoard* gameBoard, int depth, bool isMax)
{
	int score = gameBoard->Evaluate();

	if (score == 10)
		return score;

	if (score == -10)
		return score;

	if (gameBoard->isMovesLeft() == false)
		return 0;

	if (isMax == true)
	{
		int best = -1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (gameBoard->positions[(i * 3) + j].symbol == SymbolType::NONE)
				{
					gameBoard->positions[(i * 3) + j].symbol = SymbolType::Circle;
					best = std::max(best, GetMinimax(gameBoard, depth + 1, !isMax));
					gameBoard->positions[(i * 3) + j].symbol = SymbolType::NONE;
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (gameBoard->positions[(i * 3) + j].symbol == SymbolType::NONE)
				{
					gameBoard->positions[(i * 3) + j].symbol = SymbolType::Cross;
					best = std::min(best, GetMinimax(gameBoard, depth + 1, !isMax));
					gameBoard->positions[(i * 3) + j].symbol = SymbolType::NONE;
				}
			}
		}
		return best;
	}
}

Vector2D Minimax::FindBestMove(GameBoard* gameBoard)
{
	int bestVal = -1000;
	Vector2D bestPosition = { -1, -1 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gameBoard->positions[(i * 3) + j].symbol == SymbolType::NONE)
			{
				gameBoard->positions[(i * 3) + j].symbol = SymbolType::Circle;
				int moveVal = GetMinimax(gameBoard, 0, false);
				gameBoard->positions[(i * 3) + j].symbol = SymbolType::NONE;

				if (moveVal > bestVal)
				{
					bestPosition.x = j * SPRITE_SIZE;
					bestPosition.y = i * SPRITE_SIZE;
					bestVal = moveVal;
				}
			}
		}
	}
	return bestPosition;
}