#pragma once
#include "ManagerBase.h"
#include "IRender.h"
#include "Symbol.h"

class SymbolManager : public ManagerBase, public IRender
{
public:
	SymbolManager(ManagerName name);

	void Start() override;
	void Render() override;
	void Quit() override;

	Symbol* GetSymbolAtPosition(Vector2D position);
};