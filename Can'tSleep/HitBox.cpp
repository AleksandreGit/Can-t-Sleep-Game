#include "HitBox.h"

bool HitBox::collide(const HitBox& hB) const{
	sf::FloatRect b1 = hB.getBoundingBox();
	sf::FloatRect b2 = this->getBoundingBox();

	return b1.intersects(b2);
}