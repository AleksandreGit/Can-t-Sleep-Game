#pragma once
#include "AnimableEntity.h"

/**
	Interface that defines a builder to create an AnimableEntity
*/
class AnimableBuilder {
public:
	virtual AnimableEntity& build() = 0;
	const static int DEFAULT_WIDTH = 298;
	const static int DEFAULT_HEIGHT = 421;
};
