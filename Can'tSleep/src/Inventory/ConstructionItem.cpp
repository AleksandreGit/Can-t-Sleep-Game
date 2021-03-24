#include "./../../header/Inventory/ConstructionItem.h"

void ConstructionItem::placingDraw(sf::RenderWindow& window, int pos, std::vector< EnvironmentElement*> envElements, Direction dir) {
	if (m_constructible) {
		// Set the color to red or green depending on if we can construct
		bool elementOnPos = false;
		//m_constructible->setFilter(color);
		if (dir == LEFT) {
			m_constructible->setWorldPosition(pos - 2);
			pos -= 2;
		}
		else {
			m_constructible->setWorldPosition(pos + 3);
			pos += 3;
		}
		for (EnvironmentElement* elem : envElements) {
			if (elem->getWorldPosition() == pos) {
				elementOnPos = true;
				break;
			}
		}
		m_constructible->draw(window, elementOnPos);
	}
}

int ConstructionItem::getDrawingPos(int pos, Direction dir) {
	if (dir == LEFT) {
		m_constructible->setWorldPosition(pos - 2);
		pos -= 2;
	}
	else {
		m_constructible->setWorldPosition(pos + 3);
		pos += 3;
	}
	return pos;
}