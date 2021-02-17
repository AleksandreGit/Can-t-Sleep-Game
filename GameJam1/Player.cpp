#include "Player.h"


Player::Player(b2World* world) : MovingEntity() {
	m_animations.push_back(new PlayerIdle());
	m_animations.push_back(new PlayerWalk());
	m_animations.push_back(new PlayerInteract());
	m_animations.push_back(new PlayerAttack());

	// We place the player at the center of the map
	m_realPosition = TILE_WIDTH * MAP_SIZE / 2;
	for (int i = 0; i < m_animations.size(); i++) {
		m_animations[i]->moveTo(m_realPosition);
	}
	setWorldPosition((int)(m_realPosition / TILE_WIDTH));
	sf::FloatRect rectBounds = m_animations[0]->getCurrentSprite().getGlobalBounds();


	// CREATING THE BODY
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody; //this will be a dynamic body
	bodyDef.position.Set(m_realPosition/TILE_WIDTH - TILE_WIDTH/2, TILE_HEIGHT); //set the starting position
	bodyDef.angle = 0; //set the starting angle

	m_body = world->CreateBody(&bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(1, 2);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;

	m_body->CreateFixture(&boxFixtureDef);
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
			m_body->SetTransform(b2Vec2(m_realPosition/TILE_WIDTH, 0), m_body->GetAngle());
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
	setWorldPosition((int)(m_realPosition / TILE_WIDTH));
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
	sf::Vector2f pos(m_body->GetPosition().x*TILE_WIDTH, m_body->GetPosition().y*TILE_WIDTH);
}

void Player::attack() {
	if (m_target != nullptr) {
		m_target->defend(this);
	}
}