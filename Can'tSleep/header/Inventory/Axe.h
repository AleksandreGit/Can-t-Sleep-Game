#pragma once
#include "Tool.h"

class Axe : public Tool
{
public:
	Axe();
	virtual void use(EnvironmentElement* target);
};

