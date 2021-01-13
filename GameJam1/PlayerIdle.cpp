#include "PlayerIdle.h"

PlayerIdle::PlayerIdle() {
	DefaultAnimableBuilder builder;
	AnimablePlayer(builder.setFrameRate(0.5f)
		.setTotalFrame(48)
		.setSpriteSheet("./Assets/idle2.png")
		.build());
}