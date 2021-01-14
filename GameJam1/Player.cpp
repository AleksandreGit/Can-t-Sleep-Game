#include "Player.h"


Player::Player() : Entity() {
	m_animations.push_back(new PlayerIdle());
	m_animations.push_back(new PlayerWalk());
	m_animations.push_back(new PlayerInteract());
	m_animations.push_back(new PlayerAttack());
	m_position = m_animations[1]->getPosition();
}

void Player::move(float deltaTime) {
	int anim = 0;
	switch (m_currentState) {
		case IDLE:
			anim = 0;
			break;
		case WALK:
			anim = 1;
			switch (m_dir) {
			case LEFT:
				m_position -= m_speed * deltaTime;
				for (int i = 0; i < m_animations.size(); i++) {
					m_animations[i]->moveTo(m_position);
				}
				break;
			case RIGHT:
				m_position += m_speed * deltaTime;
				for (int i = 0; i < m_animations.size(); i++) {
					m_animations[i]->moveTo(m_position);
				}
				break;
			default:
				break;
			}
			break;
		case INTERACT:
			anim = 2;
			if (m_animations[anim]->isAnimationFinished()) {
				this->setState(IDLE);
			}
			break;
		case ATTACK:
			anim = 3;
			break;
		default:
			break;
	}
	m_animations[anim]->animate(deltaTime);
}

void Player::setState(State state) {
	if (m_currentState != state) {
		for (int i = 0; i < m_animations.size(); i++) {
			m_animations[i]->reset();
		}
		m_currentState = state;
	}
}

void Player::setDirection(Direction dir) {
	if ((m_dir == LEFT && dir == RIGHT) || (m_dir == RIGHT && dir == LEFT)) {
		for (int i = 0; i < m_animations.size(); i++) {
			m_animations[i]->flipOrientation();
		}
		m_dir = dir;
	}
}

void Player::draw(sf::RenderWindow& window) const {
	int anim = 0;
	switch (m_currentState) {
		case IDLE:
			anim = 0;
			break;
		case WALK:
			anim = 1;
			break;
		case INTERACT:
			anim = 2;
			break;
		case ATTACK:
			anim = 3;
			break;
	}
	m_animations[anim]->draw(window);
}

void Player::attack(Entity& target) const {

}

void Player::defend(Entity& attacker) {

}