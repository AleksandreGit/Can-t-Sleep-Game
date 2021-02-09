#include "EnvironmentElement.h"

EnvironmentElement::EnvironmentElement(sf::Texture& texture, int width, int position) :
	m_texture(texture),
	m_width(width), 
	m_health(100)
{
	m_worldPosition = position;
	m_realPosition = TILE_WIDTH * m_worldPosition + TILE_WIDTH * 0.5f;
}


EnvironmentElement::~EnvironmentElement() {
	
}

void EnvironmentElement::animate(float deltaTime) {
	// TODO lorsque les elements seront créés en Animable
}

void EnvironmentElement::draw(sf::RenderWindow& window) const {
	sf::Sprite sprite;
	sprite.setTexture(m_texture);
	int height = m_texture.getSize().y;
	sprite.setTextureRect(sf::IntRect(0, 0, TILE_WIDTH * m_width, height));
	sprite.setPosition(m_realPosition, 10);
	sprite.setOrigin(TILE_WIDTH / 2, height);
	window.draw(sprite);
}

void EnvironmentElement::reset() {

}

void EnvironmentElement::remove() {
	this->~EnvironmentElement();
}

void EnvironmentElement::defend(Entity* attacker) {
	if (dynamic_cast<MovingEntity*>(attacker)) {
		this->m_health -= dynamic_cast<MovingEntity*>(attacker)->getStrength();
		std::cout << "Vie restante : " << std::endl;
		if (m_health < 0) {
			this->remove();
		}
	}
}

