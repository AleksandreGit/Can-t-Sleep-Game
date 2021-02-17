#pragma once
#include "Interactable.h"
#include <box2d/box2d.h>

using namespace std;

class Entity : public Interactable
{
public:
	inline Entity() : Interactable(), m_health(100) {};
	
	virtual void draw(sf::RenderWindow& window) const = 0;

	inline void setHealth(float health) { m_health = health; };

	virtual void defend(Entity* attacker) = 0;

	inline void setWorldPosition(int pos) { m_worldPosition = pos; };
	virtual inline void setRealPosition(float pos) { m_realPosition = pos; };

	inline float getRealPosition() const { return m_realPosition; };
	inline int  getWorldPosition() const { return m_worldPosition; };
	

protected:
	float m_health;
	float m_realPosition;
	int m_worldPosition;
	b2Body* m_body;

};

