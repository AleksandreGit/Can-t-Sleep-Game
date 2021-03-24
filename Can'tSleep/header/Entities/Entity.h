#pragma once
#include "./../Interaction/HitBox.h"
#include "./../Inventory/DropedItem.h"
#include "./Direction.h"

class Entity
{
public:
	inline Entity() : m_health(100), m_realPosition(0), m_hitBox(m_realPosition, 0) {};
	
	// TODO : add a variable that check if we add the debug function
	virtual void draw(sf::RenderWindow& window, bool showFilter = false) = 0;
	virtual void debugCollision(sf::RenderWindow& window) = 0;

	inline void setHealth(float health) { m_health = health; };
	inline float getHealth() const { return m_health; };

	virtual void defend(Entity* attacker) = 0;

	virtual inline void setWorldPosition(int pos) { 
		m_worldPosition = pos;
		m_hitBox.setXPos(m_worldPosition * TILE_WIDTH);
		for (DropedItem* item : m_dropedItem) {
			item->setCurrentPosition((m_worldPosition + 0.5f) * TILE_WIDTH);
		}
	};
	virtual inline void setRealPosition(float pos) {
		m_realPosition = pos;
		m_hitBox.setXPos(m_realPosition);
		for (DropedItem* item : m_dropedItem) {
			item->setCurrentPosition(m_realPosition - 0.5f* TILE_WIDTH);
		}
	};

	inline float getRealPosition() const { return m_realPosition; };
	inline int  getWorldPosition() const { return m_worldPosition; };
	inline HitBox getHitBox() const { return m_hitBox; };

	inline bool collide(const Entity& entity) { return m_hitBox.collide(entity.getHitBox()); };
	inline std::vector<DropedItem* > getDropedItems() { return m_dropedItem; };

protected:
	float m_health;
	float m_realPosition;
	int m_worldPosition;
	HitBox m_hitBox;
	// Item droped when death or destroyed
	std::vector<DropedItem*> m_dropedItem;

};

