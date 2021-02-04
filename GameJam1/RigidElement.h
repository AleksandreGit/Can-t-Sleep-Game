#pragma once
#include "RigidBody.h"
#include "Utils.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class RigidElement : public RigidBody
{
public:
	inline RigidElement() : m_realPosition(0), m_worldPosition(1) {};

	virtual bool checkCollisions() const;
	virtual bool checkCollision(Direction dir) const;
	virtual Direction getCollisionDirection() const;
	virtual void drawColliderBox(sf::RenderWindow& window) const;

	inline virtual sf::Vector2f getSize() { return m_size; };
	inline virtual void setSize(sf::Vector2f size) { m_size = size; };
	inline virtual void setSize(float x, float y) { m_size = sf::Vector2f(x, y); };
	inline virtual void setSize(float v) { m_size = sf::Vector2f(v, v); };

	inline void setWorldPosition(int pos) { m_worldPosition = pos; };
	virtual inline void setRealPosition(float pos) { m_realPosition = pos; };

	inline float getRealPosition() const { return m_realPosition; };
	inline int  getWorldPosition() const { return m_worldPosition; };

protected:
	sf::Vector2f m_size;
	float m_realPosition;
	int m_worldPosition;

};

