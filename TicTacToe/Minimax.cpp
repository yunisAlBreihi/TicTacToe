#include "Minimax.h"
#include <vector>
#include "globals.h"

using namespace globals;

int Minimax::GetMinimax(GameBoard* gameboard, int depth, bool isMax)
{
	int score = gameboard->Evaluate();
	std::vector<Position> positions = gameboard->GetPositions();

	if (score == 10)
	{
		return score;
	}
	if (score == -10)
	{
		return score;
	}
	if (gameboard->isMovesLeft() == false)
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
				if (positions[j + i].symbol == SymbolType::NONE)
				{
					positions[j + i].symbol == SymbolType::Circle;
					best = std::max(best, GetMinimax(gameboard, depth + 1, !isMax));

					positions[j + i].symbol = SymbolType::NONE;
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
				if (positions[j + i].symbol == SymbolType::NONE)
				{
					positions[j + i].symbol == SymbolType::Circle;
					best = std::min(best, GetMinimax(gameboard, depth + 1, !isMax));
					positions[j + i].symbol = SymbolType::NONE;
				}
			}
		}
		return best;
	}
	return 0;
}

Vector2D Minimax::FindBestMove(GameBoard* gameBoard)
{
	int bestVal = -1000;
	std::vector<Position> positions = gameBoard->GetPositions();
	Vector2D bestPosition = { -1, -1 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (positions[j + i].symbol == SymbolType::NONE)
			{
				positions[j + i].symbol == SymbolType::Circle;
				int moveVal = GetMinimax(gameBoard, 0, false);
				positions[j + i].symbol = SymbolType::NONE;

				if (moveVal > bestVal)
				{
					bestPosition.x = i * SPRITE_SIZE;
					bestPosition.y = j * SPRITE_SIZE;
					bestVal = moveVal;
				}
			}
		}
	}
	return bestPosition;
}