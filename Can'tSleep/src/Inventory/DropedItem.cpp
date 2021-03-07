#include "./../../header/Inventory/DropedItem.h"

DropedItem::DropedItem(Item* item, float currentPosition): 
	m_hitbox(0, currentPosition, ICON_ITEM_SIZE, ICON_ITEM_SIZE),
	m_linkedItem(item),
	m_currentPosition(currentPosition) {}


void DropedItem::draw(sf::RenderWindow& window) {
	m_linkedItem->drawIcon(window, sf::Vector2f(m_currentPosition, -ICON_ITEM_SIZE+30));
}