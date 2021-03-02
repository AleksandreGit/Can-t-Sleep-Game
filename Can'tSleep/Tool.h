#pragma once
#include "Craftable.h"
#include "EnvironmentElement.h"

class Tool : public Craftable
{
public:
	Tool() = default;
	virtual void use(EnvironmentElement* target) = 0;

protected:
	int m_efficacity;
};

