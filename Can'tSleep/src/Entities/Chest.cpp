#include "./../../header/Entities/Chest.h"

Chest::Chest(int position) : Constructible(DefaultEnvironmentElementBuilder()
	.setPosition(position)
	.setWidth(1)
	.setTexture("Chest")
	.build())
{
	m_animation = &DefaultAnimableBuilder()
		.setFrameRate(1.0f)
		.setTotalFrame(1)
		.setTexture("Chest")
		.setHeight(235)
		.setWidth(270)
		.build();
	m_animation->moveTo(m_realPosition);
	m_animation->setOffsetY(10);
	m_hitBox.setSize(250, 200);
	m_hitBox.setPosition(m_realPosition - m_hitBox.getWidth() / 2, -m_hitBox.getHeight());
};


void Chest::draw(sf::RenderWindow& window) {
	EnvironmentElement::draw(window);
	//debugCollision(window);
}
