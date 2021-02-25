#pragma once
#include "Craftable.h"
#include "Map.h"

class ConstructionItem
{
public:
	ConstructionItem();
	bool placingDraw(sf::RenderWindow& window, int pos);
	bool placeOnMap(Map& map);

protected:
	Constructible m_constructible;
};

