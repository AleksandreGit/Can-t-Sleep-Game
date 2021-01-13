#include "AnimableEntity.h"

AnimableEntity::AnimableEntity(sf::Texture &texture, float frameRate,
	int framePerCol, int framePerLig, int totalFrame) :
	m_texture(texture), m_frameRate(frameRate), m_framePerCol(framePerCol),
	m_framePerLig(framePerLig), m_totalFrame(totalFrame), m_currentFrame(0), m_elapsedTime(0.0f) {
	m_currentSprite.setTexture(m_texture);
}

void AnimableEntity::animate(float deltaTime) {
	m_elapsedTime += deltaTime;
	if (m_totalFrame > 0) {
		m_currentFrame = ((int)(m_frameRate * m_elapsedTime)) % m_totalFrame;
		m_currentSprite.setTextureRect(sf::IntRect(
			(m_currentFrame % m_framePerCol) * DEFAULT_WIDTH,
			(m_currentFrame / m_framePerCol) * DEFAULT_HEIGHT,
			DEFAULT_WIDTH,
			DEFAULT_HEIGHT));
	}
	else {
		m_currentFrame = 0;
	}
}

void AnimableEntity::draw(sf::RenderWindow& window) const {
	window.draw(m_currentSprite);
}

void AnimableEntity::reset() {
	m_currentFrame = 0;
	m_elapsedTime = 0;
}

