#include "./../../header/Entities/DefaultEnvironmentElementBuilder.h"


DefaultEnvironmentElementBuilder::DefaultEnvironmentElementBuilder() : position(0), width(1) {}

DefaultEnvironmentElementBuilder DefaultEnvironmentElementBuilder::setWidth(int width) {
	this->width = width;
	return (*this);
}

DefaultEnvironmentElementBuilder DefaultEnvironmentElementBuilder::setPosition(int position) {
	this->position = position;
	return (*this);
}

DefaultEnvironmentElementBuilder DefaultEnvironmentElementBuilder::setTexture(std::string id) {
	this->texture = TextureLoader::GetInstance()->getTexture(id);
	return (*this);
}

EnvironmentElement& DefaultEnvironmentElementBuilder::build() {
	return *(new EnvironmentElement(texture, width, position));
}

