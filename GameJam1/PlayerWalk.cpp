#include "PlayerWalk.h"

PlayerWalk::PlayerWalk() {
	DefaultAnimableBuilder builder;
	AnimablePlayer(builder.setFrameRate(0.5f)
		.setTotalFrame(37)
		.setSpriteSheet("./Assets/walk2.png")
		.build());
}