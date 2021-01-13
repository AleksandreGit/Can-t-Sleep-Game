#include "VoidAnimableBuilder.h"

VoidAnimableBuilder::VoidAnimableBuilder() {}

AnimableEntity VoidAnimableBuilder::build() {
	return AnimableEntity(texture, spriteSheet, frameRate, framePerCol, framePerLig, totalFrame);
}

VoidAnimableBuilder VoidAnimableBuilder::setSpriteSheet(string path) {
	if (!texture.loadFromFile(path)) {
		cout << "Erreur de chargement de la texture !" << endl;
	}
	const int width = texture.getSize().x / framePerCol;
	const int height = texture.getSize().y / framePerLig;
	for (int i = 0; i < totalFrame; i++) {
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect((i % framePerCol) * width,
			(i / framePerLig) * height,
			width,
			height));
		spriteSheet.push_back(sprite);
	}
	return (*this);
}

VoidAnimableBuilder VoidAnimableBuilder::setFrameRate(float frameRate) {
	this->frameRate = frameRate;
	return (*this);
}

VoidAnimableBuilder VoidAnimableBuilder::setFrameRatePerCol(int frameRatePerCol) {
	this->framePerCol = framePerCol;
	return (*this);
}

VoidAnimableBuilder VoidAnimableBuilder::setFrameRatePerLig(int frameRatePerLig) {
	this->framePerLig = framePerLig;
	return (*this);
}

VoidAnimableBuilder VoidAnimableBuilder::setTotalFrame(int totalFrame) {
	this->totalFrame = totalFrame;
	return (*this);
}

