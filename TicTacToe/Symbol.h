#pragma once
#include <SDL.h>
#include <iostream>
#include "ObjectBase.h"
#include "Sprite.h"
#include "Vector2D.h"

class Symbol : public ObjectBase
{
private:
	Sprite* sprite = nullptr;
	SDL_Rect rect = { 0,0,0,0 };

	std::string name = "";
	Vector2D position = { 0,0 };
	Vector2D scale = { 0,0 };

public:
	Symbol(Sprite* sprite, std::string name, Vector2D position, Vector2D scale);

	void Start() override;
	void Render() override;
	void Quit() override;

	void SetPosition(Vector2D position);
	Vector2D GetPosition() { return position; }
};