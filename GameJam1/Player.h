#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "AnimablePlayer.h"
#include <vector>
#include <iostream>

using namespace std;


class Player : public Entity
{
public:
	Player();

	virtual void move();
	virtual void draw() const;
	virtual void attack(Entity target) const;
	virtual void defend(Entity attacker);

private:
	AnimablePlayer m_currentAnimation;
};

