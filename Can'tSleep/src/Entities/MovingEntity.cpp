#include "./../../header/Entities/MovingEntity.h"

void MovingEntity::defend(Entity* attacker) {
	if (dynamic_cast<MovingEntity*>(attacker)) {
		this->m_health -= dynamic_cast<MovingEntity*>(attacker)->getStrength();
		if (m_health < 0) {
			m_health = 0;
		}
	}
}