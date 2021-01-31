#pragma once
#include "Interactable.h"

using namespace std;

class Entity : public Interactable
{
public:
	inline Entity() : m_health(100), m_realPosition(0), m_worldPosition(1) {};
	
	virtual void draw(sf::RenderWindow& window) const = 0;

	inline void setHealth(float health) { m_health = health; };
	inline void setWorldPosition(int pos) { m_worldPosition = pos; };
	virtual inline void setRealPosition(float pos) { m_realPosition = pos; };

	inline float getRealPosition() const { return m_realPosition; };
	inline int  getWorldPosition() const { return m_worldPosition; };
	

protected:
	float m_health;
	float m_realPosition;
	int m_worldPosition;

};

