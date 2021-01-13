#include "DefaultAnimableBuilder.h"

DefaultAnimableBuilder::DefaultAnimableBuilder() : frameRate(1.0f), totalFrame(0) {}

AnimableEntity& DefaultAnimableBuilder::build() {
	const int nbCol = texture.getSize().x / DEFAULT_WIDTH;
	const int nbRow = texture.getSize().y / DEFAULT_HEIGHT;
	return *(new AnimableEntity(texture, frameRate, nbCol, nbRow, totalFrame));
}

DefaultAnimableBuilder DefaultAnimableBuilder::setTexture(string path) {
	if (!texture.loadFromFile(path)) {
		cout << "Erreur de chargement de la texture !" << endl;
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