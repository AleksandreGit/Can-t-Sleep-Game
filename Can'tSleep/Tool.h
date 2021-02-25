#pragma once
#include "Craftable.h"
#include "EnvironmentElement.h"

class Tool : public Craftable
{
public:
	Tool();
	void use(EnvironmentElement* target);

protected:
	int m_efficacity;
};

