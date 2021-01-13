#pragma once
#include "AnimablePlayer.h"
#include "DefaultAnimableBuilder.h"

class PlayerWalk : public AnimablePlayer
{
public:
	PlayerWalk();
	virtual void flipOrientation();
};

