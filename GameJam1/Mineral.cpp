#include "Mineral.h"

Mineral::Mineral(MineralType mineralType, int position) : Natural(DefaultEnvironmentElementBuilder()
	.setPosition(position)
	.setWidth(1)
	.setTexture("./Assets/rock.png")
	.build()), m_type(mineralType)
{
	this->setSize(200, 200);
	m_animation = &DefaultAnimableBuilder().setFrameRate(1.0f).setTotalFrame(1).setTexture("./Assets/rock.png").build();
	m_animation->moveTo(m_realPosition);
	m_animation->setOffsetY(10);
};


void Mineral::draw(sf::RenderWindow& window) const {
	EnvironmentElement::draw(window);
	this->drawColliderBox(window);
}
