#include "Sprite.h"
#include <SDL_image.h>
#include "Managers.h"

Sprite::Sprite(const char* name, const char* filePath) : filePath(filePath)
{
	this->name = name;

	surface = IMG_Load(filePath);
	texture = SDL_CreateTextureFromSurface(Managers::GetInstance()->GetRenderer(), surface);
}

void Sprite::Start()
{
}

void Sprite::Render()
{
}

void Sprite::Quit()
{
}
