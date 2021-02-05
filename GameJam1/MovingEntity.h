#pragma once
#include "Entity.h"
#include "State.h"

class MovingEntity : public Entity
{
public:
	inline MovingEntity() : Entity(), m_strength(10),
		m_dir(RIGHT), m_speed(200.0f), m_name("Entity"), m_currentState(IDLE) {};

	virtual void move(float deltaTime) = 0;
	virtual void attack() = 0;
	virtual void defend(Entity* attacker);

	inline int getStrength() const { return m_strength; };
	inline void setSpeed(float speed) { m_speed = speed; };
	inline void setName(string name) { m_name = name; };
	virtual inline void setDirection(Direction dir) { m_dir = dir; };
	virtual inline void setState(State state) { m_currentState = state; };

protected:
	int m_strength;
	Direction m_dir;
	float m_speed;
	string m_name;
	State m_currentState;
};

