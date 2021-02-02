#include "RigidElement.h"

bool RigidElement::checkCollisions() const {
	return false;
}

bool RigidElement::checkCollision(Direction dir) const {
	return false;
}

Direction RigidElement::getCollisionDirection() const {
	return LEFT;
}

void RigidElement::drawColliderBox(sf::RenderWindow& window) const {
	sf::RectangleShape rectangle(m_size);
	rectangle.setOrigin(m_size.x / 2, m_size.y);
	rectangle.setPosition(m_realPosition, 30);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(sf::Color(255, 0, 0));
	window.draw(rectangle);
}

