#pragma once
#include "Craftable.h"
#include "./../Entities/Constructible.h"

class ConstructionItem : public Craftable
{
public:
	ConstructionItem() = default;
	ConstructionItem(Constructible* constructible) : m_constructible(constructible) {};
	void placingDraw(sf::RenderWindow& window, int pos, std::vector< EnvironmentElement*> envElements, Direction dir);
	int getDrawingPos(int pos, Direction dir);
	inline void setConstructible(Constructible* constructible) { m_constructible = constructible;};
	inline Constructible* getConstructible() { return m_constructible; };

protected:
	Constructible* m_constructible;
};

