#pragma once
#include "SDL.h"

class GameManager
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event event;
	
	bool gameRunning = false;

	//TODO: Remove these when creating player class
	SDL_Surface* circleSurface = nullptr;
	SDL_Texture* circleTexture = nullptr;
	SDL_Rect circleRect =
	{
		0,
		0,
		64,
		64,
	};

	SDL_Surface* crossSurface = nullptr;
	SDL_Texture* crossTexture = nullptr;
	SDL_Rect crossRect =
	{
		64,
		0,
		64,
		64,
	};

private:
	void CreateWindow();

public:

	GameManager();

	void Start();
	void EventHandler();
	void Update();
	void Render();
	void Quit();

	bool GameRunning() { return gameRunning; }
};

