#pragma once
#include "IRender.h"
#include <SDL.h>

class GameBoard : public IRender
{
private:
	SDL_Renderer* renderer = nullptr;
	bool boardIsDrawn = false;

private:

public:
	GameBoard();

	void Start() override;
	void Render() override;
	void Quit() override;

	void DrawBoard();
};

