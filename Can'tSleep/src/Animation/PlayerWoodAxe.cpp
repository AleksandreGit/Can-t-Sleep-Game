#include "./../../header/Animation/PlayerWoodAxe.h"

PlayerWoodAxe::PlayerWoodAxe() : AnimablePlayer(DefaultAnimableBuilder(432, 423).setFrameRate(31.0f)
	.setTotalFrame(26)
	.setTexture("PlayWoodAxe")
	.build()) {}