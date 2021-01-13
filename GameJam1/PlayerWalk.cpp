#include "PlayerWalk.h"

PlayerWalk::PlayerWalk() {
	DefaultAnimableBuilder builder;
	AnimableEntity(builder.setFrameRate(0.5f)
		.setTotalFrame(37)
		.setSpriteSheet("./Assets/walk2.png")
		.build());
}

void PlayerWalk::flipOrientation() {
	this->m_orientation = !this->m_orientation;
}