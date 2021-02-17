#pragma once
#include <box2d/box2d.h>
#include "MaskEntities.h"

class CollisionListener : public b2ContactListener
{
public:
	virtual void BeginContact(b2Contact* contact); 
	virtual void EndContact(b2Contact* contact);
};

