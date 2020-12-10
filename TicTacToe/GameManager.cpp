#include "GameManager.h"
#include <iostream>
#include <time.h>
#include <SDL_image.h>
#include "Managers.h"
#include "Sprite.h"
#include "Symbol.h"
#include "globals.h"

using namespace globals;

GameManager::GameManager(ManagerName) : ManagerBase(name)
{
	srand(time(NULL));

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

	gameBoard = new GameBoard();
	minimax = new Minimax();
	currentPlayer = (SymbolType)(rand() % 2);
	std::cout << (int)currentPlayer << std::endl;
}

void GameManager::Start()
{
	gameRunning = true;

	if (currentPlayer == SymbolType::Cross)
	{
		RunAI();
		std::cout << "Cross" << std::endl;
	}
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
			Vector2D newPos = { (x / SPRITE_SIZE) * SPRITE_SIZE ,(y / SPRITE_SIZE) * SPRITE_SIZE };

			std::cout << (x / SPRITE_SIZE) * SPRITE_SIZE << std::endl;

			if (event.button.button == 1)
			{
				if (gameBoard->AddPosition(newPos, currentPlayer))
				{
					Symbol* symbol = nullptr;
					if (currentPlayer == SymbolType::Circle)
					{
						symbol = new Symbol((Sprite*)spriteManager->GetObjectByName("Circle"),
								            currentPlayer, "Circle",
							                Vector2D{ (x / SPRITE_SIZE) * SPRITE_SIZE,(y / SPRITE_SIZE) * SPRITE_SIZE },
							                Vector2D{ SPRITE_SIZE,SPRITE_SIZE });
						currentPlayer = SymbolType::Cross;
						symbolManager->AddObject(symbol);
					}
					else if (currentPlayer == SymbolType::Cross)
					{
						//symbol = new Symbol((Sprite*)spriteManager->GetObjectByName("Cross"),
						//	                currentPlayer, "Cross", 
						//	                Vector2D{ (x / SPRITE_SIZE) * SPRITE_SIZE,(y / SPRITE_SIZE) * SPRITE_SIZE },
						//	                Vector2D{ SPRITE_SIZE,SPRITE_SIZE });
						RunAI();
					}
				}
			}
		}
	}
	if (gameBoard->Evaluate())
	{
		if (currentPlayer == SymbolType::Circle)
		{
			std::cout << "Game Over. Cross Wins!" << std::endl;
		}
		else if (currentPlayer == SymbolType::Cross)
		{
			std::cout << "Game Over. Circle Wins!" << std::endl;
		}
		gameRunning = false;
	}
	else if(gameBoard->isMovesLeft() == false)
	{
		std::cout << "Game Over. It's a draw!" << std::endl;
		gameRunning = false;
	}
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

void GameManager::RunAI()
{
	Symbol* symbol = new Symbol((Sprite*)spriteManager->GetObjectByName("Cross"), 
								currentPlayer, "Cross",
								minimax->FindBestMove(gameBoard),
								Vector2D{ SPRITE_SIZE,SPRITE_SIZE });
	symbolManager->AddObject(symbol);
	currentPlayer = SymbolType::Circle;
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