#include "Player.h"


Player::Player() : Entity() {
	m_currentAnimation = new PlayerIdle();
}

// TODO Add delta time
void Player::move(float deltaTime) {
	switch (m_currentState) {
		case IDLE:
			// NOTHING HAPPEND
			break;
		case WALK:
			switch (m_dir) {
			case LEFT:
				m_position += m_speed * deltaTime;
				break;
			case RIGHT:
				m_position += m_speed * deltaTime;
				break;
			default:
				break;
			}
			break;
		default:
			break;
	}
	m_currentAnimation->animate(deltaTime);
}

void Player::setState(State state) {
	m_currentState = state;
	switch (state) {
		case IDLE:
			m_currentAnimation = new PlayerIdle();
			break;
		case WALK:
			m_currentAnimation = new PlayerWalk();
			break;
		default:
			break;
	}
}

void Player::setDirection(Direction dir) {
	if (m_dir == LEFT && dir == RIGHT) {
		m_currentAnimation->flipOrientation();
	}
	else if (m_dir == RIGHT && dir == LEFT) {
		m_currentAnimation->flipOrientation();
	}
	m_dir = dir;
}

void Player::draw(sf::RenderWindow& window) const {
	m_currentAnimation->draw(window);
}

void Player::attack(Entity& target) const {

}

void Player::defend(Entity& attacker) {

}