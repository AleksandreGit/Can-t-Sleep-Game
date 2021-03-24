#include "./../../header/Entities/EnvironmentElement.h"

EnvironmentElement::EnvironmentElement(sf::Texture& texture, int width, int position) :
	Entity(),
	m_width(width)
{
	m_worldPosition = position;
	m_realPosition = TILE_WIDTH * m_worldPosition + TILE_WIDTH * 0.5f;
	m_animation = &DefaultAnimableBuilder().setFrameRate(1.0f).setTotalFrame(1).setTexture("./Assets/tree.png").build();
	m_animation->moveTo(m_realPosition);
}

EnvironmentElement::~EnvironmentElement() {
	delete m_animation;
}

void EnvironmentElement::animate(float deltaTime) {
	m_animation->animate(deltaTime);
}

void EnvironmentElement::draw(sf::RenderWindow& window, bool showFilter) {
	m_animation->draw(window, showFilter);
}

void EnvironmentElement::remove() {
	this->~EnvironmentElement();
}

void EnvironmentElement::defend(Entity* attacker) {
	if (dynamic_cast<MovingEntity*>(attacker)) {
		this->m_health -= dynamic_cast<MovingEntity*>(attacker)->getStrength();
		std::cout << "Point de vie : " << m_health << std::endl;
		if (m_health <= 0) {
			m_health = 0;
		}
	}
}

