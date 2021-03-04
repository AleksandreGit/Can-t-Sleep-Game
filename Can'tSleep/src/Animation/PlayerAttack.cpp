#include "./../../header/Animation/PlayerAttack.h"

PlayerAttack::PlayerAttack() : AnimablePlayer(DefaultAnimableBuilder().setFrameRate(30.0f)
	.setTotalFrame(26)
	.setTexture("PlayAttack")
	.build()) {}
