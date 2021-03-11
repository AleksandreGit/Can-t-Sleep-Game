#include "./../../header/Entities/Player.h"


Player::Player() : MovingEntity() {
	m_animations.push_back(new PlayerIdle());
	m_animations.push_back(new PlayerWalk());
	m_animations.push_back(new PlayerAttack());
	m_animations.push_back(new PlayerInteract());
	m_animations.push_back(new PlayerWoodAxeIdle());
	m_animations.push_back(new PlayerWoodAxeWalk());
	m_animations.push_back(new PlayerWoodAxeAttack());

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
	for (int i = 0; i < 15; i++) {
		m_inventory.addItem(new Axe());
	}
	m_inventory.deleteItem(0);
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
		case ATTACK:
			anim = 2;
			break;
		case INTERACT:
			anim = 3;
			break;
	}
	if (dynamic_cast<Axe*>(m_inventory.getSelectedItem()) && m_currentState != INTERACT) {
		anim += 4;
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
		case ATTACK:
			anim = 2;
			break;
		case INTERACT:
			anim = 3;
			break;
	}
	if (dynamic_cast<Axe*>(m_inventory.getSelectedItem()) && m_currentState != INTERACT) {
		anim += 4;
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

void Player::useObject() {
	Tool* tool = dynamic_cast<Tool*>(m_inventory.getSelectedItem());
	if (tool) {
		m_strength = m_baseStrength + tool->getEfficacity();
		this->setState(ATTACK);
		this->attack();
	}
	else if (!m_inventory.getSelectedItem()) {
		m_strength = m_baseStrength;
		this->setState(ATTACK);
		this->attack();
	}
	std::cout << m_strength << std::endl;
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

void Player::changeFocusTool(int value) {
	Item* lastItem = m_inventory.getSelectedItem();
	m_inventory.changeSelectedItem(value);
};

Item* Player::dropCurrentItem(){
	Item* dropedItem = m_inventory.getSelectedItem();
	m_inventory.dropCurrentItem();
	return dropedItem;
}

bool Player::canPickUpItem(DropedItem* dropedItem) {
	return dropedItem->collide(m_fieldOfAction) && m_inventory.canAddItem();
}

void Player::pickUpItem(DropedItem* dropedItem) {
	m_inventory.addItem(dropedItem->getItem());
}