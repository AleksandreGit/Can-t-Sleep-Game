#include "./../../header/Inventory/Inventory.h"

Inventory::Inventory() {
	m_toolBarTexture = TextureLoader::GetInstance()->getTexture("ToolBar");
	m_inventoryTexture = TextureLoader::GetInstance()->getTexture("Inventory");
	m_nbItem = 0; 
	m_currentItemIndex = 0;
	std::vector<Item*> item;
	item.push_back(nullptr);
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		m_items.push_back(item);
	}
	if (!m_font.loadFromFile("./Assets/Fonts/arial.ttf")) {
		std::cout << "Can't load inventory font correctly" << std::endl;
	}
	m_lastClicked = -1;
}

void Inventory::drawToolBar(sf::RenderWindow& window){
	sf::Sprite toolBar;
	sf::Sprite selectedItem;
	float offsetY = 40.0f;
	toolBar.setTexture(m_toolBarTexture);
	selectedItem.setTexture(TextureLoader::GetInstance()->getTexture("SelectedItem"));
	toolBar.setPosition(window.getView().getCenter().x - m_toolBarTexture.getSize().x / 2, offsetY);
	window.draw(toolBar);

	sf::Vector2f posIcon(toolBar.getPosition().x + 30.0f, toolBar.getPosition().y + 40.0f);
	sf::Vector2f posItem(toolBar.getPosition().x + 10.0f, toolBar.getPosition().y + 10.0f);
	for (int i = 0; i < TOOLBAR_SIZE; i++) {
		if (i == m_currentItemIndex) {
			sf::Vector2f current(posItem.x + i * 190, posItem.y);
			selectedItem.setPosition(current);
			window.draw(selectedItem);
		}
		if (m_items[i][0]) {
			sf::Vector2f current(posIcon.x + i * 190, posIcon.y);
			m_items[i][0]->drawIcon(window, current);
			if (m_items[i].size() > 1) {
				sf::CircleShape circle;
				circle.setFillColor(sf::Color(255, 255, 255, 200));
				float radius = 20;
				circle.setRadius(radius);
				circle.setOrigin(radius/2, radius/2);
				circle.setPosition(sf::Vector2f(current.x + 110 + radius/2, current.y + 100 + radius/2));
				window.draw(circle);
				sf::Text text;
				text.setString(std::to_string(m_items[i].size()));
				text.setFont(m_font);
				text.setCharacterSize(35);
				text.setFillColor(sf::Color::Black);
				text.setStyle(sf::Text::Bold);
				text.setPosition(sf::Vector2f(current.x + 120, current.y + 100));
				window.draw(text);
			}
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

	sf::Vector2f pos(inventory.getPosition().x + 30.0f, inventory.getPosition().y + 40.0f);
	//TODO change pos with the different items
	int total = INVENTORY_SIZE - TOOLBAR_SIZE;
	int colNumber = total / 4;

	int index = TOOLBAR_SIZE;
	for (int i = 0; i < total; i++) {
		if (m_items[index][0]) {
			sf::Vector2f current(pos.x + (i % colNumber) * 190, pos.y + floor(i / colNumber) * 190);
			m_items[index][0]->drawIcon(window, current);
			if (m_items[index].size() > 1) {
				sf::CircleShape circle;
				circle.setFillColor(sf::Color(255, 255, 255, 200));
				float radius = 20;
				circle.setRadius(radius);
				circle.setOrigin(radius / 2, radius / 2);
				circle.setPosition(sf::Vector2f(current.x + 110 + radius / 2, current.y + 100 + radius / 2));
				window.draw(circle);
				sf::Text text;
				text.setString(std::to_string(m_items[index].size()));
				text.setFont(m_font);
				text.setCharacterSize(35);
				text.setFillColor(sf::Color::Black);
				text.setStyle(sf::Text::Bold);
				text.setPosition(sf::Vector2f(current.x + 120, current.y + 100));
				window.draw(text);
			}
		}
		index++;
	}
}


int Inventory::getItemIndexWithPos(int xPos, int yPos, sf::RenderWindow &window, bool mousePressed) {
	float offsetY = 40.0f;
	sf::Vector2f offset(m_inventoryTexture.getSize().x / 2.0f, m_inventoryTexture.getSize().y / 2.0f);
	sf::Vector2f posCenter = window.getView().getCenter() - offset;

	sf::Vector2f pos(posCenter.x + 10.0f, posCenter.y + 10.0f);
	//TODO change pos with the different items
	int total = INVENTORY_SIZE - TOOLBAR_SIZE;
	int colNumber = total / 4;

	int index = TOOLBAR_SIZE;
	for (int i = 0; i < total; i++) {
		sf::Vector2f current(pos.x + (i % colNumber) * 190, pos.y + floor(i / colNumber) * 190);
		if (xPos > current.x && xPos < current.x + 180) {
			if (yPos > current.y && yPos < current.y + 180) {
				if(mousePressed)
					m_lastClicked = TOOLBAR_SIZE + i;
				return TOOLBAR_SIZE + i;
			}
		}
		index++;
	}
	if(mousePressed)
		m_lastClicked = -1;
	return -1;
}

bool Inventory::addItem(Item* item) {
	// We had the item to a stack
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (m_items[i][0]) {
			if (m_items[i][0]->getName() == item->getName()) {
				if (m_items[i].size() < item->getStackSize()) {
					m_items[i].push_back(item);
					return true;
				}
			}
		}
	}
	// Or if all stacks are full we had the item to 
	if (canAddItem()) {
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (!m_items[i][0]) {
				m_items[i][0] = item;
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
	if (m_items[id][0]) {
		int index = m_items[id].size()-1;
		if (index > 0) {
			m_items[id].erase(m_items[id].begin() + index);
		}
		else {
			m_items[id][index] = nullptr;
			m_nbItem--;
		}
	}
}

void Inventory::dropCurrentItem() {
	this->dropItem(m_currentItemIndex);
}

void Inventory::deleteItem(int id) {
	if (m_items[id][0]) {
		std::vector<Item*> item;
		item.push_back(nullptr);
		m_items[id] = item;
		m_nbItem--;
	}
}

void Inventory::craftItem(std::string name) {
	// TODO: make a JSON containing the necessary elements for each craft
	// depending on the name find the right element and the craft that are necessary
}

Item* Inventory::switchPosition(int firstId, int secondId) {
	if (firstId >= 0) {
		if (secondId >= 0) {
			if (m_items[firstId][0]) {
				if (m_items[secondId][0]) {
					std::vector<Item*> temp = m_items[secondId];
					m_items[secondId] = m_items[firstId];
					m_items[firstId] = temp;
					return nullptr;
				}
				else {
					m_items[secondId] = m_items[firstId];
					std::vector<Item*> nullItem;
					nullItem.push_back(nullptr);
					m_items[firstId] = nullItem;
					return nullptr;
				}
			}
		}
		else {
			// TODO : make possible to drop all items at once !
			Item* item = m_items[firstId][0];
			dropItem(firstId);
			return item;
		}
	}
}
