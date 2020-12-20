#include "Player.h"

Player::Player() {
	this->loadTextures();
	m_numbersOfFrames.x = m_textures[0].getSize().x / FRAME_SIZE;
	m_numbersOfFrames.y = m_textures[0].getSize().y / FRAME_SIZE;
	m_currentTotalFrames = m_numbersOfFrames.x * m_numbersOfFrames.y;

	m_currentState = IDLE;
	m_nextFrame = FRAMERATE_LIMIT;

	m_sprite.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
	m_sprite.setPosition(200, 200);
	m_sprite.setScale(SCALE_VAL, SCALE_VAL);
	m_sprite.setTexture(m_textures[0]);
}

Player::~Player() {

}

void Player::loadTextures() {
	sf::Texture texture;
	if (!texture.loadFromFile(ASSETS_PATH + "idle.png")) {
		std::cout << "Error while loading player texture" << std::endl;
	}

	m_textures.push_back(texture); // Contains all the player textures : IDLE, WALK, ATTACK, ...

	if (!texture.loadFromFile(ASSETS_PATH + "walk.png")) {
		std::cout << "Error while loading player texture" << std::endl;
	}

	m_textures.push_back(texture);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}

void Player::animate(float deltaTime) {
	m_currentTime += deltaTime;
	if (m_currentTime > m_currentTotalFrames*FRAMERATE_LIMIT) {
		m_currentTime = 0;
		m_nextFrame = FRAMERATE_LIMIT;
		m_currentFrame = 0;
	}
	if (m_currentTime > m_nextFrame) {
		m_nextFrame += FRAMERATE_LIMIT;
		m_currentFrame++;
	}
	int xIndex(m_currentFrame % m_numbersOfFrames.x), yIndex(m_currentFrame / m_numbersOfFrames.x);
	m_sprite.setTextureRect(sf::IntRect(xIndex*FRAME_SIZE, yIndex*FRAME_SIZE, FRAME_SIZE, FRAME_SIZE));
}

void Player::updateSprite() {
	switch (m_currentState) {
		case IDLE:
			m_sprite.setTexture(m_textures[0]);
			m_numbersOfFrames.x = m_textures[0].getSize().x / FRAME_SIZE;
			m_numbersOfFrames.y = m_textures[0].getSize().y / FRAME_SIZE;
			break;
		case WALK:
			m_sprite.setTexture(m_textures[1]);
			m_numbersOfFrames.x = m_textures[1].getSize().x / FRAME_SIZE;
			m_numbersOfFrames.y = m_textures[1].getSize().y / FRAME_SIZE;
			break;
		case ATTACK:
			m_sprite.setTexture(m_textures[2]);
			m_numbersOfFrames.x = m_textures[2].getSize().x / FRAME_SIZE;
			m_numbersOfFrames.y = m_textures[2].getSize().y / FRAME_SIZE;
			break;
		case JUMP:
			m_sprite.setTexture(m_textures[3]);
			m_numbersOfFrames.x = m_textures[3].getSize().x / FRAME_SIZE;
			m_numbersOfFrames.y = m_textures[3].getSize().y / FRAME_SIZE;
			break;
	}
	m_currentTotalFrames = m_numbersOfFrames.x * m_numbersOfFrames.y;
	m_currentTime = 0;
	m_nextFrame = FRAMERATE_LIMIT;
	m_currentFrame = 0;
}
