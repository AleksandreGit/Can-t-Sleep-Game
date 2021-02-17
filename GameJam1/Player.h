#pragma once
#include <SFML/Graphics.hpp>
#include "MovingEntity.h"
#include "AnimablePlayer.h"
#include "PlayerIdle.h"
#include "PlayerWalk.h"
#include "PlayerInteract.h"
#include "PlayerAttack.h"
#include "Utils.h"
#include <vector>
#include <iostream>

using namespace std;


class Player : public MovingEntity
{
public:
	inline Player() = default;
	Player(b2World* world);

	virtual void move(float deltaTime);
	virtual void draw(sf::RenderWindow& window) const;
	virtual void attack();

	//virtual Direction getCollisionDirection() const;
	virtual void setState(State state);
	virtual void setDirection(Direction dir);
	virtual  void setRealPosition(float pos);

	inline void setTarget(Entity* target) { m_target = target; };

private:
	vector<AnimablePlayer*> m_animations;
	Entity* m_target;

	// Box2D Collisions body
	b2Body* m_body;


};

