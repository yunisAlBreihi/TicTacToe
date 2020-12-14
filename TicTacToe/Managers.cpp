#include "Managers.h"

Managers* Managers::instance = nullptr;

Managers::Managers() 
{
}

Managers* Managers::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new Managers();
    }
    return instance;
}

void Managers::AddManager(ManagerBase* manager)
{
    for (const auto& mngr : managers)
    {
        if (manager == mngr)
        {
			std::cout << "Manager already in managers!" << std::endl;
            return;
        }
    }
    managers.push_back(manager);
}

void Managers::SetRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

ManagerBase* Managers::GetManagerByName(ManagerName name)
{
    for (const auto& mngr : managers)
    {
        if (mngr->GetName() == name)
        {
            return mngr;
        }
    }
    std::cout << "Could not find manager with the specified name, returning nullptr" << std::endl;
    return nullptr;
}
