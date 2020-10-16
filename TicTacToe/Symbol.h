#pragma once
#include <SDL.h>
#include <iostream>
#include "Enums.h"
#include "ObjectBase.h"
#include "Sprite.h"
#include "Vector2D.h"

class Symbol : public ObjectBase
{
private:
	Sprite* sprite = nullptr;
	SDL_Rect rect = { 0,0,0,0 };
	SymbolType symbolType = SymbolType::NONE;

public:
	Symbol(Sprite* sprite, SymbolType symbolType, std::string name , Vector2D position, Vector2D scale);

	void Start() override;
	void Render() override;
	void Quit() override;

	SymbolType GetSymbolType() { return symbolType; }
};