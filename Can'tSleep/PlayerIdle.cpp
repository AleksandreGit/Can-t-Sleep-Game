#include "PlayerIdle.h"

PlayerIdle::PlayerIdle() : AnimablePlayer(DefaultAnimableBuilder().setFrameRate(30.0f)
	.setTotalFrame(44)
	.setTexture("PlayIdle")
	.build()) {}