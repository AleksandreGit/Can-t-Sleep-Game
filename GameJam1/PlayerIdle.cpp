#include "PlayerIdle.h"

PlayerIdle::PlayerIdle() {
	DefaultAnimableBuilder builder;
	AnimableEntity(builder.setFrameRate(0.5f)
		.setTotalFrame(48)
		.setSpriteSheet("./Assets/idle2.png")
		.build());
}

void PlayerIdle::flipOrientation() {
	this->m_orientation = !this->m_orientation;
}