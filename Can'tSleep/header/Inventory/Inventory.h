#pragma once
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "./../Utils.h"

class Inventory
{
public:
	Inventory();
	void drawToolBar(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	bool addItem(Item* item);
	bool canAddItem();
	void dropItem(int id);
	void dropCurrentItem();
	void deleteItem(int id);
	void craftItem(std::string name);
	inline bool changeSelectedItem(int index) { 
		if (0 < m_currentItemIndex < TOOLBAR_SIZE) {
			m_currentItemIndex = index;
			return true;
		}
		return false;
	}
	inline Item* getSelectedItem() { return m_items[m_currentItemIndex][0]; };

private:
	std::vector< std::vector<Item* > > m_items;
	sf::Texture m_toolBarTexture;
	sf::Texture m_inventoryTexture;
	int m_nbItem;
	int m_currentItemIndex;
	sf::Font m_font;
	sf::Text m_inventoryText;
};

