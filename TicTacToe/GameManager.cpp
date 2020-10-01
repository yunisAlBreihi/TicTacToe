#include "GameManager.h"
#include <iostream>
#include <SDL_image.h>
#include "Managers.h"
#include "Sprite.h"
#include "Symbol.h"

GameManager::GameManager(ManagerName) : ManagerBase(name)
{
	CreateWindow();
	Managers::GetInstance()->SetRenderer(renderer);

	//Create managers
	spriteManager = new SpriteManager(ManagerName::SPRITEMANAGER);
	symbolManager = new SymbolManager(ManagerName::SYMBOLMANAGER);

	Managers::GetInstance()->AddManager(spriteManager);
	Managers::GetInstance()->AddManager(symbolManager);


	Sprite* circleSprite = new Sprite("Circle", "sprites\\Circle.png");
	Sprite* crossSprite = new Sprite("Cross", "sprites\\Cross.png");

	spriteManager->AddObject(circleSprite);
	spriteManager->AddObject(crossSprite);

	Symbol* circleSymbol = new Symbol(circleSprite, "Circle", Vector2D{ 0,0 }, Vector2D{ 64,64 });
	Symbol* crossSymbol = new Symbol(crossSprite, "Cross", Vector2D{ 64,0 }, Vector2D{ 64,64 });

	symbolManager->AddObject(circleSymbol);
	symbolManager->AddObject(crossSymbol);
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
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			std::cout << "Hello!" << std::endl;
		}
	}
}

void GameManager::Update()
{

}

void GameManager::Render()
{
	//SDL_RenderClear(renderer);

	DrawBoard();
	symbolManager->Render();

	SDL_RenderPresent(renderer);
}

void GameManager::Quit()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}

void GameManager::DrawBoard()
{
	if (boardIsDrawn == false)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, 64, 0, 64, 192);
		SDL_RenderDrawLine(renderer, 128, 0, 128, 192);
		SDL_RenderDrawLine(renderer, 0, 64, 192, 64);
		SDL_RenderDrawLine(renderer, 0, 128, 192, 128);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		boardIsDrawn = true;
	}

}

void GameManager::CreateWindow()
{
	window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, NULL);

	SDL_ShowWindow(window);
}