#pragma once
#include "EnvironmentElement.h"

class Constructible : public EnvironmentElement {
public:
	Constructible() = default;
	inline Constructible(EnvironmentElement e) : EnvironmentElement(e) {};
	inline Constructible(sf::Texture& texture, int width, int position) : EnvironmentElement(texture, width, position) {};
};

#pragma once
