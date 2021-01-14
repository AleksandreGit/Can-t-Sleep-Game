#include "PlayerInteract.h"

PlayerInteract::PlayerInteract() : AnimablePlayer(DefaultAnimableBuilder().setFrameRate(30.0f)
	.setTotalFrame(56)
	.setTexture("./Assets/interact.png")
	.build()) {}