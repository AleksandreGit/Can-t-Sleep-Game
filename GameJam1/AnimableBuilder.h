#pragma once
#include "AnimableEntity.h"

/**
	Interface that defines a builder to create an AnimableEntity
*/
class AnimableBuilder {
public:
	virtual AnimableEntity build() = 0;
};
