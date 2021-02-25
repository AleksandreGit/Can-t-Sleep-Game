#pragma once
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Utils.h"

class Inventory
{
public:
	Inventory() = default;
	void draw(sf::RenderWindow& window);
	bool addItem(Item& item);
	bool canAddItem();
	void dropItem(int id);
	void deleteItem(int id);
	void craftItem(std::string name);

private:
	std::vector<Item*> m_items;
};

