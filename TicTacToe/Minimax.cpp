#include "Minimax.h"
#include <vector>
#include "globals.h"

using namespace globals;

int Minimax::GetMinimax(GameBoard* gameBoard, int depth, bool isMax)
{
	int score = gameBoard->Evaluate();
	std::vector<Position> startPositions = gameBoard->GetPositions();

	if (score == 10)
	{
		return score;
	}
	if (score == -10)
	{
		return score;
	}
	if (gameBoard->isMovesLeft() == false)
	{
		return 0;
	}
	if (isMax == true)
	{
		int best = -1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (gameBoard->positions[j + i].symbol == SymbolType::NONE)
				{
					gameBoard->positions[j + i].symbol = SymbolType::Circle;
					best = std::max(best, GetMinimax(gameBoard, depth + 1, !isMax));
					gameBoard->positions[j + i].symbol = SymbolType::NONE;
				}
			}
		}
		//gameBoard->positions = startPositions;
		return best;
	}
	else
	{
		int best = 1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (gameBoard->positions[j + i].symbol == SymbolType::NONE)
				{
					gameBoard->positions[j + i].symbol = SymbolType::Cross;
					best = std::min(best, GetMinimax(gameBoard, depth + 1, !isMax));
					gameBoard->positions[j + i].symbol = SymbolType::NONE;
				}
			}
		}
		//gameBoard->positions = startPositions;
		return best;
	}
	return 0;
}

Vector2D Minimax::FindBestMove(GameBoard* gameBoard)
{
	int bestVal = -1000;
	std::vector<Position> startPositions = gameBoard->GetPositions();
	Vector2D bestPosition = { -1, -1 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gameBoard->positions[j + i].symbol == SymbolType::NONE)
			{
				gameBoard->positions[j + i].symbol = SymbolType::Cross;
				int moveVal = GetMinimax(gameBoard, 0, false);
				gameBoard->positions[j + i].symbol = SymbolType::NONE;

				if (moveVal > bestVal)
				{
					bestPosition.x = i * SPRITE_SIZE;
					bestPosition.y = j * SPRITE_SIZE;
					bestVal = moveVal;
				}
			}
		}
	}
	//gameBoard->positions = startPositions;
	return bestPosition;
}