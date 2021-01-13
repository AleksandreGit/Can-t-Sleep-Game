#include "VoidAnimableBuilder.h"

VoidAnimableBuilder::VoidAnimableBuilder() : frameRate(1.0f), totalFrame(0), framePerCol(0), framePerLig(0) {}

AnimableEntity& VoidAnimableBuilder::build() {
	return *(new AnimableEntity(texture, frameRate, framePerCol, framePerLig, totalFrame));
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

VoidAnimableBuilder VoidAnimableBuilder::setFrameRatePerLig(int frameRatePerLig) {
	this->framePerLig = framePerLig;
	return (*this);
}

VoidAnimableBuilder VoidAnimableBuilder::setTotalFrame(int totalFrame) {
	this->totalFrame = totalFrame;
	return (*this);
}

