#pragma once
#include "AnimableEntity.h"
class AnimablePlayer : public AnimableEntity
{
public:
	AnimablePlayer() = default;
	inline AnimablePlayer(AnimableEntity e) : AnimableEntity(e), m_orientation(false) {};
	inline void flipOrientation() {
		this->m_orientation = !this->m_orientation;
		if (this->m_currentSprite.getScale().x < 0) {
			this->m_currentSprite.setScale(1.0f, 1.0f);
		} 
		else {
			this->m_currentSprite.setScale(-1.0f, 1.0f);
		}
	};

protected: 
	bool m_orientation;
};

