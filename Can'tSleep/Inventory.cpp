#include "Inventory.h"

void Inventory::draw(sf::RenderWindow& window) {
	sf::RectangleShape background;
	float offsetX = 300.0f;
	float offsetY = 100.0f;
	sf::Vector2f bgSize = window.getView().getSize() - sf::Vector2f(2 * offsetX, 2 * offsetY);
	sf::Vector2f bgPos = window.getView().getCenter() - bgSize / 2.0f;
	background.setSize(bgSize);
	background.setPosition(bgPos);
	background.setFillColor(sf::Color(100, 100, 100, 150));
	window.draw(background);

	/*sf::Vector2f pos(0.0f, 0.0f);
	//TODO change pos with the different items
	for (int i = 0; i < m_items.size(); i++) {
		m_items[i]->drawIcon(window, pos);
	}*/
}

bool Inventory::addItem(Item& item) {
	if (canAddItem()) {
		m_items.push_back(&item);
		return true;
	}
	return false;
}

bool Inventory::canAddItem() {
	return m_items.size() < INVENTORY_SIZE;
}

void Inventory::dropItem(int id) {
	Item* item = m_items[id];
	//TODO: make this items drop to the floor
	m_items.erase(m_items.begin() + id);
}

void Inventory::deleteItem(int id) {
	m_items.erase(m_items.begin() + id);
}

void Inventory::craftItem(std::string name) {
	// TODO: make a JSON containing the necessary elements for each craft
	// depending on the name find the right element and the craft that are necessary
}
