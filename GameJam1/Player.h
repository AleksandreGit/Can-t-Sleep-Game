#pragma once
#include <SFML/Graphics.hpp>
#include "MovingEntity.h"
#include "AnimablePlayer.h"
#include "PlayerIdle.h"
#include "PlayerWalk.h"
#include "PlayerInteract.h"
#include "PlayerAttack.h"
#include "Map.h"
#include <vector>
#include <iostream>

using namespace std;


class Player : public MovingEntity
{
public:
	Player();

	virtual void move(float deltaTime);
	virtual void draw(sf::RenderWindow& window) const;
	virtual void attack(Entity& target) const;
	virtual void defend(Entity& attacker); 
	virtual void setState(State state);
	virtual void setDirection(Direction dir);
	virtual  void setRealPosition(float pos);

private:
	vector<AnimablePlayer*> m_animations;
};

