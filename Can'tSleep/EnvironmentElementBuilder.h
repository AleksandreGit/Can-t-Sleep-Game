#pragma once
#include "EnvironmentElement.h"

class EnvironmentElementBuilder {
public:
	virtual EnvironmentElement& build() =0;
};

