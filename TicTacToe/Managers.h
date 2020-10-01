#pragma once
#include <vector>
#include <SDL.h>
#include "ManagerBase.h"

class Managers
{
private:
	static Managers* instance;

	SDL_Renderer* renderer = nullptr;
	std::vector<ManagerBase*> managers;

private:
	Managers();

public:
	static Managers* GetInstance();

	void AddManager(ManagerBase* manager);

	void SetRenderer(SDL_Renderer* renderer);
	SDL_Renderer* GetRenderer() { return renderer; }
	ManagerBase* GetManagerByName(ManagerName name);
};