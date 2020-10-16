#pragma once
#include <string>
#include "IRender.h"
#include "Vector2D.h"

class ObjectBase : public IRender
{
protected:
	std::string name;
	Vector2D position;
	Vector2D scale;

protected:
	ObjectBase();
	ObjectBase(std::string name, Vector2D position, Vector2D scale);

public:
	std::string GetName() { return name; }
	Vector2D GetPosition() { return position; }
	Vector2D GetScale() { return scale; }
};