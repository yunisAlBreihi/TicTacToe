#include "SymbolManager.h"

SymbolManager::SymbolManager(ManagerName name) : ManagerBase(name)
{
	renderable = true;
}

void SymbolManager::Start()
{
}

void SymbolManager::Render()
{
	if (renderable)
	{
		for(const auto& symbol : objects)
		{
			symbol->Render();
		}
	}
}

void SymbolManager::Quit()
{
}

Symbol* SymbolManager::GetSymbolAtPosition(Vector2D position)
{
	for (const auto& obj : objects)
	{
		if (position == obj->GetPosition())
		{
			return (Symbol*)obj;
		}
	}
	std::cout << "Could not find symbol at the position, returning nullptr" << std::endl;
	return nullptr;
}
