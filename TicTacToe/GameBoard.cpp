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

bool GameBoard::AddPosition(Vector2D position, SymbolType symbolType)
{
	if (position.x > 2 * SPRITE_SIZE || position.y > 2 * SPRITE_SIZE || position.x < 0 || position.y < 0)
	{
		return false;
	}

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
	if (OccupiedPositions() >= 9)
	{
		return false;
	}
	return true;
}

int GameBoard::OccupiedPositions()
{
	int occupedPositions = 0;
	for (const auto& pos : positions)
	{
		if (pos.symbol != SymbolType::NONE)
		{
			occupedPositions++;
		}
	}
	return occupedPositions;
}

int GameBoard::Evaluate()
{
	if (OccupiedPositions() < 3)
	{
		return false;
	}
	else
	{
		//first col
		if (positions[0].symbol != SymbolType::NONE && positions[3].symbol != SymbolType::NONE && positions[6].symbol != SymbolType::NONE &&
			symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[3].position)->GetSymbolType() &&
			symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[6].position)->GetSymbolType())
		{
			if (symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == SymbolType::Circle)
				return -10;
			else if (symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == SymbolType::Cross)
				return 10;
		}
		//second col
		else if (positions[1].symbol != SymbolType::NONE && positions[4].symbol != SymbolType::NONE && positions[7].symbol != SymbolType::NONE &&
			symbolManager->GetSymbolAtPosition(positions[1].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[4].position)->GetSymbolType() &&
			symbolManager->GetSymbolAtPosition(positions[1].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[7].position)->GetSymbolType())
		{
			if (symbolManager->GetSymbolAtPosition(positions[1].position)->GetSymbolType() == SymbolType::Circle)
				return -10;
			else if (symbolManager->GetSymbolAtPosition(positions[1].position)->GetSymbolType() == SymbolType::Cross)
				return 10;
		}
		//third col
		else if (positions[2].symbol != SymbolType::NONE && positions[5].symbol != SymbolType::NONE && positions[8].symbol != SymbolType::NONE &&
			symbolManager->GetSymbolAtPosition(positions[2].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[5].position)->GetSymbolType() &&
			symbolManager->GetSymbolAtPosition(positions[2].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[8].position)->GetSymbolType())
		{
			if (symbolManager->GetSymbolAtPosition(positions[2].position)->GetSymbolType() == SymbolType::Circle)
				return -10;
			else if(symbolManager->GetSymbolAtPosition(positions[2].position)->GetSymbolType() == SymbolType::Cross)
				return 10;
		}
		//first row
		else if (positions[0].symbol != SymbolType::NONE && positions[1].symbol != SymbolType::NONE && positions[2].symbol != SymbolType::NONE &&
			symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[1].position)->GetSymbolType() &&
			symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[2].position)->GetSymbolType())
		{
			if (symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == SymbolType::Circle)
				return -10;
			else if (symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == SymbolType::Cross)
				return 10;
		}
		//second row
		else if (positions[3].symbol != SymbolType::NONE && positions[4].symbol != SymbolType::NONE && positions[5].symbol != SymbolType::NONE &&
			symbolManager->GetSymbolAtPosition(positions[3].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[4].position)->GetSymbolType() &&
			symbolManager->GetSymbolAtPosition(positions[3].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[5].position)->GetSymbolType())
		{
			if (symbolManager->GetSymbolAtPosition(positions[3].position)->GetSymbolType() == SymbolType::Circle)
				return -10;
			else if (symbolManager->GetSymbolAtPosition(positions[3].position)->GetSymbolType() == SymbolType::Cross)
				return 10;
		}
		//third row
		else if (positions[6].symbol != SymbolType::NONE && positions[7].symbol != SymbolType::NONE && positions[8].symbol != SymbolType::NONE &&
			symbolManager->GetSymbolAtPosition(positions[6].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[7].position)->GetSymbolType() &&
			symbolManager->GetSymbolAtPosition(positions[6].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[8].position)->GetSymbolType())
		{
			if (symbolManager->GetSymbolAtPosition(positions[6].position)->GetSymbolType() == SymbolType::Circle)
				return -10;
			else if (symbolManager->GetSymbolAtPosition(positions[6].position)->GetSymbolType() == SymbolType::Cross)
				return 10;
		}
		//Left diagonal
		else if (positions[2].symbol != SymbolType::NONE && positions[4].symbol != SymbolType::NONE && positions[6].symbol != SymbolType::NONE &&
			symbolManager->GetSymbolAtPosition(positions[2].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[4].position)->GetSymbolType() &&
			symbolManager->GetSymbolAtPosition(positions[2].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[6].position)->GetSymbolType())
		{
			if (symbolManager->GetSymbolAtPosition(positions[2].position)->GetSymbolType() == SymbolType::Circle)
				return -10;
			else if (symbolManager->GetSymbolAtPosition(positions[2].position)->GetSymbolType() == SymbolType::Cross)
				return 10;
		}
		//Right diagonal
		else if (positions[0].symbol != SymbolType::NONE && positions[4].symbol != SymbolType::NONE && positions[8].symbol != SymbolType::NONE &&
			symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[4].position)->GetSymbolType() &&
			symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == symbolManager->GetSymbolAtPosition(positions[8].position)->GetSymbolType())
		{
			if (symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == SymbolType::Circle)
				return -10;
			else if (symbolManager->GetSymbolAtPosition(positions[0].position)->GetSymbolType() == SymbolType::Cross)
				return 10;
		}
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