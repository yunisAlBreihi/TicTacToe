#include "GameManager.h"
#include "SDL_image.h"

GameManager::GameManager()
{
	CreateWindow();

	//TODO: Remove these when creating palyer class
	circleSurface = IMG_Load("sprites\\Circle.png");
	circleTexture = SDL_CreateTextureFromSurface(renderer, circleSurface);

	crossSurface = IMG_Load("sprites\\Cross.png");
	crossTexture = SDL_CreateTextureFromSurface(renderer, crossSurface);
}

void GameManager::Start()
{
	gameRunning = true;
}

void GameManager::EventHandler()
{
	if (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			gameRunning = false;
		}
	}
}

void GameManager::Update()
{
}

void GameManager::Render()
{
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, circleTexture, NULL, &circleRect);
	SDL_RenderCopy(renderer, crossTexture, NULL, &crossRect);

	SDL_RenderPresent(renderer);
}

void GameManager::Quit()
{
	SDL_DestroyTexture(circleTexture);
	circleTexture = nullptr;
	SDL_DestroyTexture(crossTexture);
	crossTexture = nullptr;

	SDL_FreeSurface(circleSurface);
	circleSurface = nullptr;
	SDL_FreeSurface(crossSurface);
	crossSurface = nullptr;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}

void GameManager::CreateWindow()
{
	window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, NULL);

	SDL_ShowWindow(window);
}