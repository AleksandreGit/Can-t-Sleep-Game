#include "./../../header/Animation/PlayerWoodAxeIdle.h"

PlayerWoodAxeIdle::PlayerWoodAxeIdle() : AnimablePlayer(DefaultAnimableBuilder(298, 421).setFrameRate(31.0f)
	.setTotalFrame(44)
	.setTexture("PlayWoodAxeIdle")
	.build()) {}