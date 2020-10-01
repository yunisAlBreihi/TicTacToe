#include "Symbol.h"
#include "Managers.h"

Symbol::Symbol(Sprite* sprite, std::string name, Vector2D position, Vector2D scale) :
	sprite(sprite), name(name), position(position), scale(scale)
{
	rect = { this->position.x, this->position.y, this->scale.x, this->scale.y };
	renderable = true;
}

void Symbol::Start()
{
}

void Symbol::Render()
{
	if (renderable == true)
	{
		SDL_RenderCopy(Managers::GetInstance()->GetRenderer(), sprite->GetTexture(), NULL, &rect);
		renderable = false;
	}
}

void Symbol::Quit()
{
}

void Symbol::SetPosition(Vector2D position)
{
	this->position = position;
	rect.x = this->position.x;
	rect.y = this->position.y;
}