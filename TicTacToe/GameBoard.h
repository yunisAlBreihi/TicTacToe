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
	std::vector<Position> positions;
	SDL_Renderer* renderer = nullptr;
	SymbolManager* symbolManager = nullptr;
	bool boardIsDrawn = false;

public:
	GameBoard();

	void Start() override;
	void Render() override;
	void Quit() override;

	std::vector<Position> GetPositions();
	bool AddPosition(Vector2D position, SymbolType symbolType);
	bool isMovesLeft();
	int OccupiedPositions();
	int Evaluate();
	void DrawBoard();
};

