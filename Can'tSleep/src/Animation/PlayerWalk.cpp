#include "./../../header/Animation/PlayerWalk.h"

PlayerWalk::PlayerWalk() : AnimablePlayer(DefaultAnimableBuilder().setFrameRate(30.0f)
	.setTotalFrame(37)
	.setTexture("PlayWalk")
	.build()) {}