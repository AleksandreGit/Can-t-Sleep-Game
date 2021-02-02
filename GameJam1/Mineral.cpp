#include "Mineral.h"

Mineral::Mineral(MineralType mineralType, int position) : Natural(DefaultEnvironmentElementBuilder()
	.setPosition(position)
	.setWidth(1)
	.setTexture("./Assets/rock.png")
	.build()), m_type(mineralType)
{
	this->setSize(TILE_WIDTH, TILE_HEIGHT);
};


void Mineral::draw(sf::RenderWindow& window) const {
	EnvironmentElement::draw(window);
	this->drawColliderBox(window);
}


