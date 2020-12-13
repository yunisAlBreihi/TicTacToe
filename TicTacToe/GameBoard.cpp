#include "GameBoard.h"
#include "Managers.h"
#include "globals.h"

using namespace globals;

GameBoard::GameBoard()
{
	renderer = Managers::GetInstance()->GetRenderer();
	symbolManager = (SymbolManager*)Managers::GetInstance()->GetManagerByName(ManagerName::SYMBOLMANAGER);
	renderable = true;

	//Add All positions to grid
	positions = std::vector<Position>();
	for (int y = 0; y <= 2; y++)
	{
		for (int x = 0; x <= 2; x++)
		{
			positions.push_back(Position{ Vector2D{x * SPRITE_SIZE,y * SPRITE_SIZE}, SymbolType::NONE });
		}
	}
}

void GameBoard::Start()
{

}

void GameBoard::Render()
{
	if (renderable == true)
	{
		DrawBoard();
		renderable = false;
	}
}
void GameBoard::Quit()
{
}

std::vector<Position> GameBoard::GetPositions()
{
	return positions;
}

void GameBoard::SetPositions(std::vector<Position> newPositions)
{
	positions = newPositions;
}

bool GameBoard::AddPosition(Vector2D position, SymbolType symbolType)
{
	if (position.x > 2 * SPRITE_SIZE || position.y > 2 * SPRITE_SIZE || position.x < 0 || position.y < 0)
		return false;

	for (auto& pos : positions)
	{
		if (position == pos.position)
		{
			if (pos.symbol != SymbolType::NONE)
			{
				std::cout << "Position is occupied!" << std::endl;
				return false;
			}
			else
			{
				pos.symbol = symbolType;
				return true;
			}
		}
	}
}

bool GameBoard::isMovesLeft()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (positions[i + (j *3)].symbol == SymbolType::NONE)
			{
				return true;
			}
		}
	}
	return false;
}

int GameBoard::Evaluate()
{
	//Columns
	for (int col = 0; col < 3; col++)
	{
		if (positions[col + 0].symbol == positions[col + 3].symbol &&
			positions[col + 3].symbol == positions[col + 6].symbol)
		{
			if (positions[col + 0].symbol == SymbolType::Circle)
				return 10;
			else if (positions[col + 0].symbol == SymbolType::Cross)
				return -10;
		}
	}

	//Rows
	for (int row = 0; row < 3; row++)
	{
		if (positions[(row * 3) + 0].symbol == positions[(row * 3) + 1].symbol &&
			positions[(row * 3) + 1].symbol == positions[(row * 3) + 2].symbol)
		{
			if (positions[row + 0].symbol == SymbolType::Circle)
				return 10;
			else if (positions[row + 0].symbol == SymbolType::Cross)
				return -10;
		}
	}

	//Diagonals
	if (positions[0].symbol == positions[4].symbol &&
		positions[4].symbol == positions[8].symbol)
	{
		if (positions[0].symbol == SymbolType::Circle)
			return 10;
		else if (positions[0].symbol == SymbolType::Cross)
			return -10;
	}
	if (positions[2].symbol == positions[4].symbol &&
		positions[4].symbol == positions[6].symbol)
	{
		if (positions[2].symbol == SymbolType::Circle)
			return 10;
		else if (positions[2].symbol == SymbolType::Cross)
			return -10;
	}

	return 0;
}

void GameBoard::DrawBoard()
{
	if (boardIsDrawn == false)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

		//first vertical line
		SDL_RenderDrawLine(renderer, SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE * 3);
		//second vertical line
		SDL_RenderDrawLine(renderer, SPRITE_SIZE * 2, 0, SPRITE_SIZE * 2, SPRITE_SIZE * 3);
		//first horizontal line
		SDL_RenderDrawLine(renderer, 0, SPRITE_SIZE, SPRITE_SIZE * 3, SPRITE_SIZE);
		//second horizontal line
		SDL_RenderDrawLine(renderer, 0, SPRITE_SIZE * 2, SPRITE_SIZE * 3, SPRITE_SIZE * 2);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		boardIsDrawn = true;
	}
}