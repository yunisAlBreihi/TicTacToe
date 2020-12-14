#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
}

ObjectBase::ObjectBase(std::string name, Vector2D position, Vector2D scale) : name(name), position(position), scale(scale)
{
}
