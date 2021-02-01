#pragma once
#include "Interactable.h"

using namespace std;

class Entity : public Interactable
{
public:
	inline Entity() : Interactable(), m_health(100) {};
	
	virtual void draw(sf::RenderWindow& window) const = 0;

	inline void setHealth(float health) { m_health = health; };

protected:
	float m_health;

};

