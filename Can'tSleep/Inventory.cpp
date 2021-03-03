#include "Inventory.h"

Inventory::Inventory() {
	m_toolBarTexture = TextureLoader::GetInstance()->getTexture("ToolBar");
	m_inventoryTexture = TextureLoader::GetInstance()->getTexture("Inventory");
	m_nbItem = 0; 
	m_currentItemIndex = 0;
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		m_items.push_back(nullptr);
	}
}

void Inventory::drawToolBar(sf::RenderWindow& window){
	sf::Sprite toolBar;
	sf::Sprite selectedItem;
	float offsetY = 40.0f;
	toolBar.setTexture(m_toolBarTexture);
	selectedItem.setTexture(TextureLoader::GetInstance()->getTexture("SelectedItem"));
	toolBar.setPosition(window.getView().getCenter().x - m_toolBarTexture.getSize().x / 2, offsetY);
	window.draw(toolBar);

	sf::Vector2f posIcon(toolBar.getPosition().x + 40.0f, toolBar.getPosition().y + 40.0f);
	sf::Vector2f posItem(toolBar.getPosition().x + 10.0f, toolBar.getPosition().y + 10.0f);
	for (int i = 0; i < TOOLBAR_SIZE; i++) {
		if (i == m_currentItemIndex) {
			sf::Vector2f current(posItem.x + i * 190, posItem.y);
			selectedItem.setPosition(current);
			window.draw(selectedItem);
		}
		if (m_items[i]) {
			sf::Vector2f current(posIcon.x + i * 190, posIcon.y);
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

	sf::Vector2f pos(inventory.getPosition().x + 40.0f, inventory.getPosition().y + 40.0f);
	//TODO change pos with the different items
	int total = INVENTORY_SIZE - TOOLBAR_SIZE;
	int colNumber = total / 4;

	int index = TOOLBAR_SIZE;
	for (int i = 0; i < total; i++) {
		if (m_items[index]) {
			sf::Vector2f current(pos.x + (i % colNumber) * 190, pos.y + floor(i / colNumber) * 190);
			m_items[index]->drawIcon(window, current);
		}
		index++;
	}
}

bool Inventory::addItem(Item* item) {
	if (canAddItem()) {
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (!m_items[i]) {
				m_items[i] = item;
				m_nbItem++;
				return true;
			}
		}
	}
	return false;
}

bool Inventory::canAddItem() {
	return m_nbItem < INVENTORY_SIZE;
}

void Inventory::dropItem(int id) {
	if (m_items[id]) {
		Item* item = m_items[id];
		//TODO: make this items drop to the floor
		m_items.erase(m_items.begin() + id);
		m_nbItem--;
	}
}

void Inventory::deleteItem(int id) {
	if (m_items[id]) {
		m_items.erase(m_items.begin() + id);
		m_nbItem--;
	}
}

void Inventory::craftItem(std::string name) {
	// TODO: make a JSON containing the necessary elements for each craft
	// depending on the name find the right element and the craft that are necessary
}
