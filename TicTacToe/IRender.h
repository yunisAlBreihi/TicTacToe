#pragma once

class IRender
{
protected:
	bool renderable = false;

public:
	virtual void Start() = 0;
	virtual void Render() = 0;
	virtual void Quit() = 0;
};