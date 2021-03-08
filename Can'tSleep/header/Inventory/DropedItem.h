#pragma once
#include "./../../header/Inventory/Item.h"
#include "./../../header/Interaction/HitBox.h"
#include "./../../header/Utils.h"

class DropedItem
{
public:
	DropedItem() = default;
	DropedItem(Item* item, float currentPosition);
	void draw(sf::RenderWindow& window);
	bool collide(const HitBox& hB) const;
	inline float getCurrentPosition() { return m_currentPosition; };
	inline Item* getItem() { return m_linkedItem; };
private:
	Item* m_linkedItem;
	HitBox m_hitbox;
	float m_currentPosition;
};

