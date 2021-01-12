#pragma once
#include "RigidElement.h"
#include "State.h"
#include "string"

using namespace std;

class Entity : public RigidElement
{
public:
	virtual void move() = 0;
	virtual void draw() const = 0;
	virtual void attack(Entity target) const = 0;
	virtual void defend(Entity attacker) = 0;

protected:
	float m_health;
	int m_position;
	int m_strength;
	Direction m_dir;
	int m_speed;
	string m_name;
	State m_currentState;

};

