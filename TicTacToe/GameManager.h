#pragma once
#include <SDL.h>
#include "ManagerBase.h"
#include "SpriteManager.h"
#include "SymbolManager.h"
#include "GameBoard.h"
#include "Minimax.h"

class GameManager : public ManagerBase
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event event;

	//Managers
	SpriteManager* spriteManager = nullptr;
	SymbolManager* symbolManager = nullptr;
	Minimax* minimax = nullptr;
	GameBoard* gameBoard = nullptr;
	
	SymbolType currentPlayer = SymbolType::NONE;

	bool gameRunning = false;
	bool boardIsDrawn = false;

	float debugTimer = 0;

private:
	void CreateWindow();
	void DrawBoard();

public:

	GameManager(ManagerName name);

	void Start();
	void EventHandler();
	void Render();
	void Quit();
	void RunAI();

	bool GameRunning() { return gameRunning; }
};

