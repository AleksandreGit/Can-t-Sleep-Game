#include "./../../header/Inventory/DropedItem.h"

DropedItem::DropedItem(Item* item, float currentPosition): 
	m_hitbox(currentPosition, -ICON_ITEM_SIZE + 30, ICON_ITEM_SIZE, ICON_ITEM_SIZE),
	m_linkedItem(item),
	m_currentPosition(currentPosition) {
	m_hitbox.setColor(255, 0, 0, 120);
}


void DropedItem::draw(sf::RenderWindow& window) {
	m_linkedItem->drawIcon(window, sf::Vector2f(m_currentPosition, -ICON_ITEM_SIZE + 30));
}


bool DropedItem::collide(const HitBox& hB) const {
	return this->m_hitbox.collide(hB);
}