#pragma once
#include <vector>
#include <iostream>
#include "ObjectBase.h"
#include "Enums.h"

class ManagerBase
{
protected:
	std::vector<ObjectBase*> objects;
	ManagerName name = ManagerName::NONE;

protected:
	ManagerBase(ManagerName name);
public:

	void AddObject(ObjectBase* object);

	ObjectBase* GetObjectByName(std::string name);
	ManagerName GetName() { return name; }
};