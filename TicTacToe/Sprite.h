#pragma once
#include <SDL.h>
#include <iostream>
#include "ObjectBase.h"

class Sprite : public ObjectBase
{
private:
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Rect rect = { 0,0,0,0 };

	const char* filePath = "";

public:
	Sprite(const char* name, const char* filePath);

	SDL_Texture* GetTexture() { return texture; }
};

