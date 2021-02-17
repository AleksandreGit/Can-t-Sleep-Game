#include "VoidAnimableBuilder.h"

VoidAnimableBuilder::VoidAnimableBuilder() : frameRate(1.0f), totalFrame(0), framePerCol(0), spriteSize(298, 421) {}

AnimableEntity& VoidAnimableBuilder::build() {
	return *(new AnimableEntity(texture, frameRate, framePerCol, totalFrame, spriteSize.x, spriteSize.y));
}

VoidAnimableBuilder VoidAnimableBuilder::setTexture(string path) {
	if (!texture.loadFromFile(path)) {
		cout << "Erreur de chargement de la texture !" << endl;
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

VoidAnimableBuilder VoidAnimableBuilder::setTotalFrame(int totalFrame) {
	this->totalFrame = totalFrame;
	return (*this);
}


VoidAnimableBuilder VoidAnimableBuilder::setHeight(int height) {
	this->spriteSize.y = height;
	return (*this);
}

VoidAnimableBuilder VoidAnimableBuilder::setWidth(int width) {
	this->spriteSize.x = width;
	return (*this);
}

