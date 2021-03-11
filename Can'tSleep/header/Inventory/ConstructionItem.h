#pragma once
#include "Craftable.h"
#include "./../Map.h"

class ConstructionItem : public Craftable
{
public:
	ConstructionItem() = default;
	void placingDraw(sf::RenderWindow& window, int pos);
	bool construct(int pos);

protected:
	Constructible* m_constructible;
};

