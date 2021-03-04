#pragma once
#include "EnvironmentElement.h"
#include "./../TextureLoader.h"

class EnvironmentElementBuilder {
public:
	virtual EnvironmentElement& build() =0;
};

