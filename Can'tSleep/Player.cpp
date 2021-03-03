#include "Player.h"


Player::Player() : MovingEntity() {
	m_animations.push_back(new PlayerIdle());
	m_animations.push_back(new PlayerWalk());
	m_animations.push_back(new PlayerInteract());
	m_animations.push_back(new PlayerAttack());
	m_animations.push_back(new PlayerWoodAxe());

	// We place the player at the center of the map
	m_realPosition = TILE_WIDTH * MAP_SIZE / 2;
	for (int i = 0; i < m_animations.size(); i++) {
		m_animations[i]->moveTo(m_realPosition);
	}
	setWorldPosition((int)(m_realPosition / TILE_WIDTH));
	m_hitBox.setSize(150, 300);
	m_hitBox.setPosition(m_realPosition - m_hitBox.getWidth() / 2, -m_hitBox.getHeight());
	m_fieldOfAction.setSize(100, 300);
	m_fieldOfAction.setPosition(m_realPosition+75, -m_fieldOfAction.getHeight());

	// INVENTORY
	m_isInventoryOpen = false;
	m_inventory.addItem(new Axe());
	m_inventory.addItem(new Axe());
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
					setWorldPosition((int)(m_realPosition / TILE_WIDTH));
					for (int i = 0; i < m_animations.size(); i++) {
						m_animations[i]->moveTo(m_realPosition);
					}
					break;
				}
			case RIGHT:
				// We block the movement if the player is at the right border
				if (m_realPosition < TILE_WIDTH * MAP_SIZE) {
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
			m_hitBox.setPosition(m_realPosition - m_hitBox.getWidth() / 2, -m_hitBox.getHeight());
			m_fieldOfAction.setPosition(m_realPosition + (m_dir*m_hitBox.getWidth()  + (m_dir - 1)*m_fieldOfAction.getWidth()) / 2, -m_fieldOfAction.getHeight());
			// Update the position of the player in the world according to his sprite position
			setWorldPosition((int)(m_realPosition / TILE_WIDTH));
			break;
		case INTERACT:
			anim = 2;
			if (m_animations[anim]->isAnimationFinished()) {
				this->setState(IDLE);
			}
			break;
		case ATTACK:
			anim = 4;
			break;
		default:
			break;
	}
	m_attackTimer += deltaTime;
	// Animation of the current state
	m_animations[anim]->animate(deltaTime);
}

void Player::setState(State state) {
	if (m_currentState != state) {
		for (int i = 0; i < m_animations.size(); i++) {
			m_animations[i]->reset();
		}
		m_currentState = state;
		m_attackTimer = 0.0f;
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

void Player::draw(sf::RenderWindow& window) {
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
			anim = 4;
			break;
	}
	m_animations[anim]->draw(window);
	this->m_inventory.drawToolBar(window);
	//this->debugCollision(window);
}

void Player::drawInventory(sf::RenderWindow& window) {
	m_inventory.draw(window);
}

void Player::attack() {
	if (m_target != nullptr) {
		if (m_attackTimer > m_attackInterval) {
			m_target->defend(this); 
			m_attackTimer = 0.0f;
		}
	}
}

bool Player::checkInteraction(Entity& entity) {
	if (m_target) {
		if (m_target->getHealth() <= 0) {
			m_target = nullptr;
			return false;
		}
	}
	if (m_fieldOfAction.collide(entity.getHitBox())) {
		m_target = &entity;
		return true;
	}
	return false;
}