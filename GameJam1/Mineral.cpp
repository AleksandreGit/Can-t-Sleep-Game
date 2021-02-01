#include "Mineral.h"

Mineral::Mineral(MineralType mineralType, int position) : Natural(DefaultEnvironmentElementBuilder()
	.setPosition(position)
	.setWidth(1)
	.setTexture("./Assets/rock.png")
	.build()), m_type(mineralType)
{
	sf::FloatRect rectBounds = this->m_currentSprite.getGlobalBounds();
	this->m_realPosition = this->m_currentSprite.getPosition().x;
	this->setSize(200, 200);
};


void Mineral::draw(sf::RenderWindow& window) const {
	EnvironmentElement::draw(window);
	this->drawColliderBox(window);
}