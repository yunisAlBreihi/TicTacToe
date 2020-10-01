#include "GameManager.h"

int main(int argc, char* argv[])
{
	GameManager* gameManager = new GameManager();

	gameManager->Start();

	while (gameManager->GameRunning() == true)
	{
		gameManager->EventHandler();
		gameManager->Update();
		gameManager->Render();
	}

	gameManager->Quit();
	delete gameManager;
	gameManager = nullptr;

	return 0;
}