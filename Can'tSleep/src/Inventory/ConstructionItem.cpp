#include "./../../header/Inventory/ConstructionItem.h"

void ConstructionItem::placingDraw(sf::RenderWindow& window, int pos) {
	sf::Color color;
	//std::vector<EnvironmentElement*> elements = map.getCurrentElements(pos);

	// Set the color to red or green depending on if we can construct
	bool elementOnPos = false;
	for (EnvironmentElement* elem : elements) {
		if (elem->getWorldPosition() == pos) {
			color = sf::Color(255, 0, 0, 100);
			elementOnPos = true;
			break;
		}
	}
	if (!elementOnPos) {
		color = sf::Color(0, 255, 0, 100);
	}
	m_constructible->setFilter(color);
	m_constructible->setWorldPosition(pos);
	m_constructible->draw(window, true);
}

bool ConstructionItem::construct(int pos) {
	return false;
}