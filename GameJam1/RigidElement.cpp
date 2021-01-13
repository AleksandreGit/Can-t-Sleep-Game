#include "RigidElement.h"

RigidElement::RigidElement() {

}

bool RigidElement::checkCollisions() const {
	return false;
}

bool RigidElement::checkCollision(Direction dir) const {
	return false;
}

Direction RigidElement::getCollisionDirection() const {
	return LEFT;
}
