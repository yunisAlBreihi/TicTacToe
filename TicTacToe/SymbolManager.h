#pragma once
#include "ManagerBase.h"
#include "IRender.h"

class SymbolManager : public ManagerBase, public IRender
{
public:
	SymbolManager(ManagerName name);

	void Start() override;
	void Render() override;
	void Quit() override;
};