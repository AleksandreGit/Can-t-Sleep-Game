#pragma once
#include "Constructible.h"
#include "DefaultEnvironmentElementBuilder.h"
#include "./../Inventory/TrapItem.h"

class Trap : public Constructible
{
public:
	Trap() = default;
	Trap(int position);
};

