#include "DefaultEnvironmentElementBuilder.h"


DefaultEnvironmentElementBuilder::DefaultEnvironmentElementBuilder() : position(0), width(1) {}

DefaultEnvironmentElementBuilder DefaultEnvironmentElementBuilder::setWidth(int width) {
	this->width = width;
	return (*this);
}

DefaultEnvironmentElementBuilder DefaultEnvironmentElementBuilder::setPosition(int position) {
	this->position = position;
	return (*this);
}

DefaultEnvironmentElementBuilder DefaultEnvironmentElementBuilder::setTexture(std::string path) {
	if (!texture.loadFromFile(path)) {
		std::cout << "Erreur de chargement de la texture !" << std::endl;
	}
	return (*this);
}

EnvironmentElement& DefaultEnvironmentElementBuilder::build() {
	return *(new EnvironmentElement(texture, width, position));
}

