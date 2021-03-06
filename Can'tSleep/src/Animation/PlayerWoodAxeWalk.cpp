#include "./../../header/Animation/PlayerWoodAxeWalk.h"

PlayerWoodAxeWalk::PlayerWoodAxeWalk() : AnimablePlayer(DefaultAnimableBuilder(298, 421).setFrameRate(31.0f)
	.setTotalFrame(37)
	.setTexture("PlayWoodAxeWalk")
	.build()) {}