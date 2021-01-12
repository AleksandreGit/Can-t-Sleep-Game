#pragma once
#include "AnimableEntity.h"

class AnimableBuilder {
public:
	virtual AnimableEntity build() = 0;
};
