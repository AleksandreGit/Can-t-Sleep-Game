#pragma once
#include "RigidElement.h"
#include "State.h"
#include "string"

using namespace std;

class Entity : public RigidElement
{
public:
	inline Entity() : m_health(100), m_realPosition(0), m_strength(10),
		m_dir(RIGHT), m_speed(200.0f), m_name("Entity"), m_currentState(IDLE), m_worldPosition(1) {};
	virtual void move(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) const = 0;
	virtual void attack(Entity& target) const = 0;
	virtual void defend(Entity& attacker) = 0;

	inline void setHealth(float health) { m_health = health; };
	inline void setSpeed(float speed) { m_speed = speed; };
	inline void setName(string name) { m_name = name; };
	inline void setWorldPosition(int pos) { m_worldPosition = pos; };

	inline float getRealPosition() const { return m_realPosition; };
	inline int  getWorldPosition() const { return m_worldPosition; };

	virtual inline void setDirection(Direction dir) { m_dir = dir; };
	virtual inline void setState(State state) { m_currentState = state; };
	virtual inline void setRealPosition(float pos) { m_realPosition = pos; };

protected:
	float m_health;
	float m_realPosition;
	int m_worldPosition;
	int m_strength;
	Direction m_dir;
	float m_speed;
	string m_name;
	State m_currentState;

};

