#include "VoidAnimableBuilder.h"

VoidAnimableBuilder::VoidAnimableBuilder() {}

AnimableEntity VoidAnimableBuilder::build() {
	return AnimableEntity(texture, spriteSheet, frameRate, framePerCol, framePerLig, totalFrame);
}

void VoidAnimableBuilder::setSpriteSheet(string path) {
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
}

void VoidAnimableBuilder::setFrameRate(int frameRate) {
	this->frameRate = frameRate;
}

void VoidAnimableBuilder::setFrameRatePerCol(int frameRatePerCol) {
	this->framePerCol = framePerCol;
}

void VoidAnimableBuilder::setFrameRatePerLig(int frameRatePerLig) {
	this->framePerLig = framePerLig;
}

void VoidAnimableBuilder::setTotalFrame(int totalFrame) {
	this->totalFrame = totalFrame;
}
