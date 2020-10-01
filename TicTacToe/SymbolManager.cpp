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
