#pragma once
#include <SFML/Graphics.hpp>
#include "MovingEntity.h"
#include "./../Animation/AnimableEntity.h"
#include "./../Animation/PlayerIdle.h"
#include "./../Animation/PlayerWalk.h"
#include "./../Animation/PlayerInteract.h"
#include "./../Animation/PlayerAttack.h"
#include "./../Animation/PlayerWoodAxeAttack.h"
#include "./../Animation/PlayerWoodAxeIdle.h"
#include "./../Animation/PlayerWoodAxeWalk.h"
#include "./../Inventory/DropedItem.h"
#include "./../Inventory/Inventory.h"
#include "./../Inventory/Axe.h"
#include "./../Inventory/TrapItem.h"
#include "./../Utils.h"
#include <vector>
#include <iostream>

using namespace std;


class Player : public MovingEntity
{
public:
	Player();
	Player(float speed);

	virtual void move(float deltaTime);
	virtual void draw(sf::RenderWindow& window, bool showFilter = false);
	virtual void useObject();
	virtual void attack();
	bool checkInteraction(Entity& hitBox);
	inline void toggleInventory() { m_isInventoryOpen = !m_isInventoryOpen; }
	inline bool isInventoryOpen() { return m_isInventoryOpen; };
	virtual void setState(State state);
	virtual void setDirection(Direction dir);
	virtual inline void debugCollision(sf::RenderWindow& window) { 
		m_hitBox.setColor(255, 0, 0, 100); 
		m_fieldOfAction.setColor(255, 255, 255, 100);
		m_hitBox.draw(window);
		m_fieldOfAction.draw(window);
	};

	// Inventory elements : TODO --> make them work another way !
	bool canPickUpItem(DropedItem* dropedItem);

private:
	vector<AnimablePlayer*> m_animations;
	bool m_isInventoryOpen;

public:
	Inventory m_inventory;

};

