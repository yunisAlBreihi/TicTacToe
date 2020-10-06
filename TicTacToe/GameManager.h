#pragma once
#include <SDL.h>
#include "ManagerBase.h"
#include "SpriteManager.h"
#include "SymbolManager.h"
#include "GameBoard.h"

class GameManager : public ManagerBase
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event event;

	//Managers
	SpriteManager* spriteManager = nullptr;
	SymbolManager* symbolManager = nullptr;

	GameBoard* gameBoard = nullptr;
	
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
	void Update();
	void Render();
	void Quit();

	bool GameRunning() { return gameRunning; }
};

