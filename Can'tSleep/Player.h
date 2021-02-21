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
	Player();

	virtual void move(float deltaTime);
	virtual void draw(sf::RenderWindow& window);
	virtual void attack();
	bool checkInteraction(Entity& hitBox);

	//virtual Direction getCollisionDirection() const;
	virtual void setState(State state);
	virtual void setDirection(Direction dir);
	virtual  void setRealPosition(float pos);

	inline void setTarget(Entity* target) { m_target = target; };
	virtual inline void debugCollision(sf::RenderWindow& window) { 
		m_hitBox.setColor(255, 0, 0, 100); 
		m_fieldOfAction.setColor(255, 255, 255, 100);
		m_hitBox.draw(window);
		m_fieldOfAction.draw(window);
	};

private:
	vector<AnimablePlayer*> m_animations;

};

