#include "./../../header/Animation/PlayerAttack.h"

PlayerAttack::PlayerAttack() : AnimablePlayer(DefaultAnimableBuilder(430, 423).setFrameRate(30.0f)
	.setTotalFrame(26)
	.setTexture("PlayAttack")
	.build()) {}
