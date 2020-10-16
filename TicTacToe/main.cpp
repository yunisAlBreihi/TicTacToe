#include "GameManager.h"
#include "SpriteManager.h"
#include "Managers.h"
#include "Enums.h"


int main(int argc, char* argv[])
{
	GameManager* gameManager = new GameManager(ManagerName::GAMEMANAGER);
	Managers::GetInstance()->AddManager(gameManager);

	gameManager->Start();

	while (gameManager->GameRunning() == true)
	{
		gameManager->EventHandler();
		gameManager->Render();
	}

	gameManager->Quit();
	delete gameManager;
	gameManager = nullptr;

	return 0;
}