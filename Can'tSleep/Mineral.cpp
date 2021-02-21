#include "Mineral.h"

Mineral::Mineral(MineralType mineralType, int position) : Natural(DefaultEnvironmentElementBuilder()
	.setPosition(position)
	.setWidth(1)
	.setTexture("./Assets/rock.png")
	.build()), m_type(mineralType)
{
	m_animation = &DefaultAnimableBuilder()
		.setFrameRate(1.0f)
		.setTotalFrame(1)
		.setTexture("./Assets/rock.png")
		.setHeight(241)
		.setWidth(300)
		.build();
	m_animation->moveTo(m_realPosition);
	m_animation->setOffsetY(10);
	m_hitBox.setSize(230, 210);
	m_hitBox.setPosition(m_realPosition - m_hitBox.getWidth() / 2, -m_hitBox.getHeight());
};


void Mineral::draw(sf::RenderWindow& window) {
	EnvironmentElement::draw(window);
	//debugCollision(window);
}
