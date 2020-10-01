#pragma once
#include <SDL.h>
#include "ManagerBase.h"
#include "SpriteManager.h"
#include "SymbolManager.h"

class GameManager : public ManagerBase
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event event;

	//Managers
	SpriteManager* spriteManager = nullptr;
	SymbolManager* symbolManager = nullptr;
	
	bool gameRunning = false;
	bool boardIsDrawn = false;

	float debugTimer = 0;

private:
	void CreateWindow();

public:

	GameManager(ManagerName name);

	void Start();
	void EventHandler();
	void Update();
	void Render();
	void Quit();
	void DrawBoard();

	bool GameRunning() { return gameRunning; }
};

