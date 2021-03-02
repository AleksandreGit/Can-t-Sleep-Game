#pragma once
#include "Tool.h"

class Axe : public Tool
{
public:
	Axe();
	virtual void use(EnvironmentElement* target);
	virtual void drawIcon(sf::RenderWindow& window, sf::Vector2f pos);
};

