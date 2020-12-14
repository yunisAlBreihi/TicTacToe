#include "Symbol.h"
#include "Managers.h"

Symbol::Symbol(Sprite* sprite, SymbolType symbolType, std::string name, Vector2D position, Vector2D scale) :
	ObjectBase(name, position, scale), sprite(sprite), symbolType(symbolType)
{
	rect = { this->position.x, this->position.y, this->scale.x, this->scale.y };
	renderable = true;
}

void Symbol::Render()
{
	if (renderable == true)
	{
		SDL_RenderCopy(Managers::GetInstance()->GetRenderer(), sprite->GetTexture(), NULL, &rect);
		renderable = false;
	}
}