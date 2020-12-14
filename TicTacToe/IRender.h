#pragma once

class IRender
{
protected:
	bool renderable = false;

public:
	virtual void Start() {};
	virtual void Render() {};
	virtual void Quit() {};
};