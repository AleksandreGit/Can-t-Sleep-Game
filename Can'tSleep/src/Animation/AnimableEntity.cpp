#include "./../../header/Animation/AnimableEntity.h"

//TODO remodifier height et width
AnimableEntity::AnimableEntity(sf::Texture &texture, float frameRate,
	int framePerCol, int totalFrame, int width, int height) :
	m_texture(texture), m_frameRate(frameRate), m_framePerCol(framePerCol),
	m_totalFrame(totalFrame), m_currentFrame(0), m_elapsedTime(0.0f) ,
	m_spriteSize(width, height) {
	m_currentSprite.setTexture(m_texture);
	m_currentSprite.setPosition(100, 30);
	m_currentSprite.setOrigin(m_spriteSize.x / 2, m_spriteSize.y);
	m_currentSprite.setTextureRect(sf::IntRect(0,0,
		m_spriteSize.x,
		m_spriteSize.y));
}

void AnimableEntity::animate(float deltaTime) {
	m_elapsedTime += deltaTime;
	if (m_totalFrame > 0) {
		m_currentFrame = ((int)(m_frameRate * m_elapsedTime)) % m_totalFrame;
		m_currentSprite.setTextureRect(sf::IntRect(
			(m_currentFrame % m_framePerCol) * m_spriteSize.x,
			(m_currentFrame / m_framePerCol) * m_spriteSize.y,
			m_spriteSize.x,
			m_spriteSize.y));
	}
	else {
		m_currentFrame = 0;
	}
}

void AnimableEntity::draw(sf::RenderWindow& window, bool drawFilter) const {
	window.draw(m_currentSprite);
}

void AnimableEntity::reset() {
	m_currentFrame = 0;
	m_elapsedTime = 0;
}

