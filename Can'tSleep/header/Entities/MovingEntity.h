#pragma once
#include "Entity.h"
#include "State.h"

class MovingEntity : public Entity
{
public:
	inline MovingEntity() : Entity(), m_strength(10),
		m_dir(RIGHT), m_speed(200.0f), m_name("Entity"), m_currentState(IDLE),
		m_fieldOfAction(m_realPosition + 50, 0), m_target(nullptr), m_attackInterval(0.8f), 
		m_attackTimer(0.0f), m_baseStrength(10) {};

	virtual void move(float deltaTime) = 0;
	virtual void attack() = 0;
	virtual void defend(Entity* attacker);

	inline int getStrength() const { return m_strength; };
	virtual inline Direction getDirection() { return m_dir; };
	inline void setSpeed(float speed) { m_speed = speed; };
	inline void setName(std::string name) { m_name = name; };
	inline void setTarget(Entity* target) { m_target = target; };
	virtual inline void setDirection(Direction dir) { m_dir = dir; };
	virtual inline void setState(State state) { m_currentState = state; };

protected:
	int m_strength;
	int m_baseStrength;
	Direction m_dir;
	float m_speed;
	std::string m_name;
	State m_currentState;
	// TODO : change side of the field of action depending on direction
	HitBox m_fieldOfAction;

	// Attack
	float m_attackInterval;
	float m_attackTimer;
	Entity* m_target;
};

