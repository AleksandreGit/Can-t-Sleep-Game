#include "DefaultAnimableBuilder.h"

DefaultAnimableBuilder::DefaultAnimableBuilder() : frameRate(1.0f), totalFrame(0), spriteSize(298, 421) {}

AnimableEntity& DefaultAnimableBuilder::build() {
	const int nbCol = texture.getSize().x / DEFAULT_WIDTH;
	return *(new AnimableEntity(texture, frameRate, nbCol, totalFrame, spriteSize.x, spriteSize.y));
}

DefaultAnimableBuilder DefaultAnimableBuilder::setTexture(std::string id) {
	this->texture = TextureLoader::GetInstance()->getTexture(id);
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


DefaultAnimableBuilder DefaultAnimableBuilder::setHeight(int height) {
	this->spriteSize.y = height;
	return (*this);
}

DefaultAnimableBuilder DefaultAnimableBuilder::setWidth(int width) {
	this->spriteSize.x = width;
	return (*this);
}