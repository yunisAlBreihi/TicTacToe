#pragma once
#include <SDL.h>
#include <vector>
#include "IRender.h"
#include "Vector2D.h"
#include "SymbolManager.h"

struct Position
{
	Vector2D position;
	SymbolType symbol = SymbolType::NONE;
};

class GameBoard : public IRender
{
private:
	SDL_Renderer* renderer = nullptr;
	SymbolManager* symbolManager = nullptr;
	bool boardIsDrawn = false;

public:
	std::vector<Position> positions;

public:
	GameBoard();

	void Render() override;

	std::vector<Position> GetPositions();
	void SetPositions(std::vector<Position> newPositions);
	bool AddPosition(Vector2D position, SymbolType symbolType);
	bool isMovesLeft();
	int Evaluate();
	void DrawBoard();
};

