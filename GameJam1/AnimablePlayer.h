#pragma once
#include "AnimableEntity.h"
class AnimablePlayer : public AnimableEntity
{
public:
	virtual void flipOrientation() = 0;

protected: 
	bool m_orientation;
};

