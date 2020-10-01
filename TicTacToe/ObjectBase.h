#pragma once
#include "IRender.h"

class ObjectBase : public IRender
{
protected:
	const char* name;

public:
	const char* GetName() { return name; }
};