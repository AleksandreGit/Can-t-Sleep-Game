#pragma once
#include "Craftable.h"
#include "./../../header/Entities/EnvironmentElement.h"

class Tool : public Craftable
{
public:
	Tool() = default;
	virtual void use(EnvironmentElement* target) = 0;
	int getEfficacity() { return m_efficacity; };

protected:
	int m_efficacity;
};

