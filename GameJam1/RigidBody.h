#pragma once
#include "Direction.h"

class RigidBody
{
public:
	virtual bool checkCollisions() const = 0;
	virtual bool checkCollision(Direction dir) const = 0;
	virtual Direction getCollisionDirection() const = 0;

};

