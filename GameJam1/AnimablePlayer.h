#pragma once
#include "AnimableEntity.h"
class AnimablePlayer : public AnimableEntity
{
public:
	AnimablePlayer() = default;
	inline AnimablePlayer(AnimableEntity e) : AnimableEntity(e), m_orientation(false) {};
	inline void flipOrientation() { this->m_orientation = !this->m_orientation; };

protected: 
	bool m_orientation;
};

