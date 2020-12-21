#include "Player.h"

Player::Player() {
	this->loadTextures();
	m_numbersOfFrames.x = m_textures[0].getSize().x / FRAME_SIZE;
	m_numbersOfFrames.y = m_textures[0].getSize().y / FRAME_SIZE;
	m_currentTotalFrames = m_numbersOfFrames.x * m_numbersOfFrames.y;

	m_currentState = PlayerState::IDLE;
	m_nextFrame = FRAMERATE_LIMIT;

	m_sprite.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
	m_sprite.setPosition(200, 200);
	m_sprite.setScale(SCALE_VAL, SCALE_VAL);
	m_sprite.setTexture(m_textures[0]);

	m_isPlayerMoving = false;
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

	if (isPlayerMoving()) {
		sf::Vector2f pos = m_sprite.getPosition();
		switch (m_movementDirection){
			case MovementDirection::LEFT:
				pos.x -= deltaTime * SPEED;
				m_sprite.setPosition(pos);
				break;
			case MovementDirection::RIGHT:
				pos.x += deltaTime * SPEED;
				m_sprite.setPosition(pos);
				break;
			case MovementDirection::UP:
				std::cout << "JUMP" << std::endl;
				break;
		}

	}
}

void Player::updateSprite() {
	switch (m_currentState) {
		case PlayerState::IDLE:
			m_sprite.setTexture(m_textures[0]);
			m_numbersOfFrames.x = m_textures[0].getSize().x / FRAME_SIZE;
			m_numbersOfFrames.y = m_textures[0].getSize().y / FRAME_SIZE;
			break;
		case PlayerState::WALK:
			m_sprite.setTexture(m_textures[1]);
			m_numbersOfFrames.x = m_textures[1].getSize().x / FRAME_SIZE;
			m_numbersOfFrames.y = m_textures[1].getSize().y / FRAME_SIZE;
			break;
		case PlayerState::ATTACK:
			m_sprite.setTexture(m_textures[2]);
			m_numbersOfFrames.x = m_textures[2].getSize().x / FRAME_SIZE;
			m_numbersOfFrames.y = m_textures[2].getSize().y / FRAME_SIZE;
			break;
		case PlayerState::JUMP:
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

void Player::toggleMovement(unsigned int direction) {
	m_isPlayerMoving = !m_isPlayerMoving;
	switch (direction) {
		case 0:
			m_movementDirection = MovementDirection::LEFT;
			break;
		case 1:
			m_movementDirection = MovementDirection::RIGHT;
			break;
		case 2:
			m_movementDirection = MovementDirection::UP;
			break;
		default:
			m_movementDirection = MovementDirection::NOT;
			break;
	}
}

void Player::setState(unsigned int state) {
	switch (state) {
		case 0:
			m_currentState = PlayerState::IDLE;
			break;
		case 1:
			m_currentState = PlayerState::WALK;
			break;
		case 2:
			m_currentState = PlayerState::ATTACK;
			break;
		default:
			m_currentState = PlayerState::JUMP;
			break;
	}
	updateSprite();
}

bool Player::isPlayerMoving() {
	return m_isPlayerMoving;
}