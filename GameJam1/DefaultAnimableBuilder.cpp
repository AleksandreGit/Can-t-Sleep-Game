#include "DefaultAnimableBuilder.h"

DefaultAnimableBuilder::DefaultAnimableBuilder() {}

AnimableEntity DefaultAnimableBuilder::build() {
	const int nbCol = texture.getSize().x / DEFAULT_WIDTH;
	const int nbRow = texture.getSize().y / DEFAULT_HEIGHT;
	return AnimableEntity(texture, spriteSheet, frameRate, nbCol, nbRow, totalFrame);
}

DefaultAnimableBuilder DefaultAnimableBuilder::setSpriteSheet(string path) {
	if (!texture.loadFromFile(path)) {
		cout << "Erreur de chargement de la texture !" << endl;
	}
	const int nbCol = texture.getSize().x / DEFAULT_WIDTH;
	const int nbRow = texture.getSize().y / DEFAULT_HEIGHT;
	for (int i = 0; i < totalFrame; i++) {
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect((i % nbCol) * DEFAULT_WIDTH,
			(i / nbCol) * DEFAULT_HEIGHT,
			DEFAULT_WIDTH,
			DEFAULT_HEIGHT));
		spriteSheet.push_back(sprite);
	}
	return (*this);

}
DefaultAnimableBuilder DefaultAnimableBuilder::setFrameRate(float frameRate) {
	this->frameRate = frameRate;
	return (*this);
}

DefaultAnimableBuilder DefaultAnimableBuilder::setTotalFrame(int totalFrame) {
	this->totalFrame = totalFrame;
	return (*this);
}