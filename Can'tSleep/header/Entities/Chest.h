#pragma once
#include "Constructible.h"
#include "DefaultEnvironmentElementBuilder.h"

class Chest : public Constructible {
public:
	Chest() = default;
	Chest(int position);

	virtual void draw(sf::RenderWindow& window);
	virtual inline void debugCollision(sf::RenderWindow& window) { m_hitBox.setColor(0, 0, 255, 100); m_hitBox.draw(window); };
};
