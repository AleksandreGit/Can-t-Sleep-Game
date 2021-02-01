#include "Player.h"


Player::Player() : MovingEntity() {
	m_animations.push_back(new PlayerIdle());
	m_animations.push_back(new PlayerWalk());
	m_animations.push_back(new PlayerInteract());
	m_animations.push_back(new PlayerAttack());

	// We place the player at the center of the map
	m_realPosition = Map::TILE_WIDTH * Map::MAP_SIZE / 2;
	for (int i = 0; i < m_animations.size(); i++) {
		m_animations[i]->moveTo(m_realPosition);
	}
	setWorldPosition((int)(m_realPosition / Map::TILE_WIDTH));
	sf::FloatRect rectBounds = m_animations[0]->getCurrentSprite().getGlobalBounds();
	this->setSize(rectBounds.width/1.5, rectBounds.height-60);
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
				// We block the movement if the player is at the left border
				if (m_realPosition > 0) {
					// We move the player
					m_realPosition -= m_speed * deltaTime;
					setWorldPosition((int)(m_realPosition / Map::TILE_WIDTH));
					for (int i = 0; i < m_animations.size(); i++) {
						m_animations[i]->moveTo(m_realPosition);
					}
					break;
				}
			case RIGHT:
				// We block the movement if the player is at the right border
				if (m_realPosition < Map::TILE_WIDTH * Map::MAP_SIZE) {
					// We move the player
					m_realPosition += m_speed * deltaTime;
					for (int i = 0; i < m_animations.size(); i++) {
						m_animations[i]->moveTo(m_realPosition);
					}
					break;
				}
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
	// Update the position of the player in the world according to his sprite position
	setWorldPosition((int)(m_realPosition / Map::TILE_WIDTH));
	// Animation of the current state
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

void Player::setRealPosition(float pos) {
	m_realPosition = pos;
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
	sf::FloatRect rectBounds = m_animations[anim]->getCurrentSprite().getGlobalBounds();
	this->drawColliderBox(window);
}

void Player::attack(Entity& target) const {

}

void Player::defend(Entity& attacker) {

}