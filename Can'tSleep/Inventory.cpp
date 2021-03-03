#include "Inventory.h"

Inventory::Inventory() {
	m_toolBarTexture = TextureLoader::GetInstance()->getTexture("ToolBar");
	m_inventoryTexture = TextureLoader::GetInstance()->getTexture("Inventory");

	for (int i = 0; i < INVENTORY_SIZE; i++) {
		m_items.push_back(nullptr);
	}
	m_items[0] = new Axe();
	//m_items[5] = new Axe();
}

void Inventory::drawToolBar(sf::RenderWindow& window){
	sf::Sprite toolBar;
	float offsetY = 40.0f;
	toolBar.setTexture(m_toolBarTexture);
	toolBar.setPosition(window.getView().getCenter().x - m_toolBarTexture.getSize().x / 2, offsetY);
	window.draw(toolBar);

	sf::Vector2f pos(window.getView().getCenter().x - m_toolBarTexture.getSize().x / 2 + 40, offsetY+40);
	//TODO change pos with the different items
	for (int i = 0; i < TOOLBAR_SIZE; i++) {
		sf::Vector2f current(pos.x + i * 190, pos.y);
		if (m_items[i]) {
			m_items[i]->drawIcon(window, current);
		}
	}
}

void Inventory::draw(sf::RenderWindow& window) {
	sf::Sprite inventory;
	float offsetY = 40.0f;
	inventory.setTexture(m_inventoryTexture);
	sf::Vector2f offset(m_inventoryTexture.getSize().x / 2.0f, m_inventoryTexture.getSize().y / 2.0f);
	inventory.setPosition(window.getView().getCenter() - offset);
	window.draw(inventory);

	/*
	sf::Vector2f pos(0.0f, 0.0f);
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
