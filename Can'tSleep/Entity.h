#pragma once
#include "Interactable.h"
#include "HitBox.h"

using namespace std;

class Entity : public Interactable
{
public:
	inline Entity() : Interactable(), m_health(100), m_realPosition(0), m_hitBox(m_realPosition, 0) {};
	
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void debugCollision(sf::RenderWindow& window) = 0;

	inline void setHealth(float health) { m_health = health; };
	inline float getHealth() const { return m_health; };

	virtual void defend(Entity* attacker) = 0;

	inline void setWorldPosition(int pos) { m_worldPosition = pos; };
	virtual inline void setRealPosition(float pos) { m_realPosition = pos; };

	inline float getRealPosition() const { return m_realPosition; };
	inline int  getWorldPosition() const { return m_worldPosition; };
	inline HitBox getHitBox() const { return m_hitBox; };

	inline bool collide(const Entity& entity) { return m_hitBox.collide(entity.getHitBox()); };

protected:
	float m_health;
	float m_realPosition;
	int m_worldPosition;
	HitBox m_hitBox;

};

