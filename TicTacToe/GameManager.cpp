#include "GameManager.h"
#include <iostream>
#include <SDL_image.h>
#include "Managers.h"
#include "Sprite.h"
#include "Symbol.h"
#include "globals.h"

using namespace globals;

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

	//Symbol* circleSymbol = new Symbol(circleSprite, "Circle", Vector2D{ 0,0 }, Vector2D{ 64,64 });
	//Symbol* crossSymbol = new Symbol(crossSprite, "Cross", Vector2D{ 64,0 }, Vector2D{ 64,64 });

	//symbolManager->AddObject(circleSymbol);
	//symbolManager->AddObject(crossSymbol);

	gameBoard = new GameBoard();
}

void GameManager::Start()
{
	gameRunning = true;
}

void GameManager::EventHandler()
{
	int x, y;

	if (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			gameRunning = false;
		}
		else if (SDL_GetMouseState(&x, &y) && event.type == SDL_MOUSEBUTTONDOWN)
		{
			std::cout << x << std::endl;
			std::cout << (x / SPRITE_SIZE) * SPRITE_SIZE << std::endl;
			//Symbol* circleSymbol = new Symbol((Sprite*)spriteManager->GetObjectByName("Circle"), "Circle", Vector2D{ x % SPRITE_SIZE,y % SPRITE_SIZE }, Vector2D{ SPRITE_SIZE,SPRITE_SIZE });
		}
	}
}

void GameManager::Update()
{

}

void GameManager::Render()
{
	//SDL_RenderClear(renderer);

	gameBoard->DrawBoard();
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

void GameManager::CreateWindow()
{
	window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, NULL);

	SDL_ShowWindow(window);
}