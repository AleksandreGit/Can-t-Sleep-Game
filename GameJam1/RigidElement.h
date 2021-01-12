#pragma once
#include "RigidBody.h"
#include <SFML/Graphics.hpp>

class RigidElement : public RigidBody
{
public:
	RigidElement();

	virtual bool checkCollisions() const;
	virtual bool checkCollision(Direction dir) const;
	virtual Direction getCollisionDirection() const;

protected:
	sf::Vector2<int> m_size;

};

