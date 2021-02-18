#pragma once

#include "EnvironmentElementBuilder.h"
#include <iostream>

class DefaultEnvironmentElementBuilder : public EnvironmentElementBuilder {

public:
	DefaultEnvironmentElementBuilder();
	virtual EnvironmentElement& build();

	DefaultEnvironmentElementBuilder setWidth(int width);
	DefaultEnvironmentElementBuilder setPosition(int position);
	DefaultEnvironmentElementBuilder setTexture(std::string path);

private:
	int width;
	int position;
	sf::Texture texture;
};

