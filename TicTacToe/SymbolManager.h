#pragma once
#include "ManagerBase.h"
#include "IRender.h"
#include "Symbol.h"

class SymbolManager : public ManagerBase, public IRender
{
public:
	SymbolManager(ManagerName name);

	void Render() override;

	Symbol* GetSymbolAtPosition(Vector2D position);
};