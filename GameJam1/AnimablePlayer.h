#pragma once
#include "AnimableEntity.h"
class AnimablePlayer : public AnimableEntity
{
public:
	void flipOrientation();

protected: 
	bool m_orientation;
};

