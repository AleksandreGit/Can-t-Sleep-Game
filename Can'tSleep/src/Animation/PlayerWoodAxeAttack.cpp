#include "./../../header/Animation/PlayerWoodAxeAttack.h"

PlayerWoodAxeAttack::PlayerWoodAxeAttack() : AnimablePlayer(DefaultAnimableBuilder(430, 423).setFrameRate(31.0f)
	.setTotalFrame(26)
	.setTexture("PlayWoodAxeAttack")
	.build()) {}