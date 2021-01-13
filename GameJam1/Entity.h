#pragma once
#include "RigidElement.h"
#include "State.h"
#include "string"

using namespace std;

class Entity : public RigidElement
{
public:
	inline Entity() : m_health(100), m_position(0), m_strength(10),
		m_dir(RIGHT), m_speed(0.5f), m_name("Entity"), m_currentState(IDLE) {};
	virtual void move(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) const = 0;
	virtual void attack(Entity& target) const = 0;
	virtual void defend(Entity& attacker) = 0;

	inline void setHealth(float health) { m_health = health; };
	inline void setPosition(int pos) { m_position = pos; };
	inline void setSpeed(float speed) { m_speed = speed; };
	inline void setName(string name) { m_name = name; };

	virtual void setDirection(Direction dir) { m_dir = dir; };
	virtual void setState(State state) { m_currentState = state; };

protected:
	float m_health;
	int m_position;
	int m_strength;
	Direction m_dir;
	float m_speed;
	string m_name;
	State m_currentState;

};

