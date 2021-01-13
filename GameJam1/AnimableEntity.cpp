#include "AnimableEntity.h"


AnimableEntity::AnimableEntity(sf::Texture &texture, vector<sf::Sprite> spriteSheet, int frameRate,
	int framePerCol, int framePerLig, int totalFrame) :
	m_texture(texture), m_spriteSheet(spriteSheet), m_frameRate(frameRate), m_framePerCol(framePerCol),
	m_framePerLig(framePerLig), m_totalFrame(totalFrame), m_currentFrame(0), m_elapsedTime(0.0f) {}

void AnimableEntity::animate(float deltaTime) {
	// TODO avancer à la frame suivante en fonction du nombre de frames et du temsp
}

void AnimableEntity::draw(sf::RenderWindow& window) const {
	window.draw(m_spriteSheet[m_currentFrame]);
}