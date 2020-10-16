#include "ManagerBase.h"

ManagerBase::ManagerBase(ManagerName name) : name(name)
{
}

void ManagerBase::AddObject(ObjectBase* object)
{
	for(const auto& obj : objects)
	{
		if (object == obj)
		{
			std::cout << "Object already in manager!" << std::endl;
			return;
		}
	}
	objects.push_back(object);
}

ObjectBase* ManagerBase::GetObjectByName(std::string name)
{
	for(const auto& obj : objects)
	{
		if (obj->GetName() == name)
		{
			return obj;
		}

	}
	return nullptr;
}
