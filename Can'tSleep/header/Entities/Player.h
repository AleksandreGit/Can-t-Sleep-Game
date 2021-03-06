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
#include "./../Inventory/Inventory.h"
#include "./../Inventory/Axe.h"
#include "./../Utils.h"
#include <vector>
#include <iostream>

using namespace std;


class Player : public MovingEntity
{
public:
	Player();

	virtual void move(float deltaTime);
	virtual void draw(sf::RenderWindow& window);
	virtual void useObject();
	virtual void attack();
	void drawInventory(sf::RenderWindow& window);
	bool checkInteraction(Entity& hitBox);
	inline void changeFocusTool(int value) { 
		Item* lastItem = m_inventory.getSelectedItem();
		m_inventory.changeSelectedItem(value); 

		// If the selected item is a tool
		if (dynamic_cast<Tool*>(m_inventory.getSelectedItem())) {
			// If the last item was a tool we update the strength of the player
			if (lastItem && dynamic_cast<Tool*>(lastItem)) {
				m_strength -= dynamic_cast<Tool*>(lastItem)->getEfficacity();
				m_strength += dynamic_cast<Tool*>(m_inventory.getSelectedItem())->getEfficacity();
			}
			else {
				m_strength += dynamic_cast<Tool*>(m_inventory.getSelectedItem())->getEfficacity();
			}
		}
		// If the selected item isn't a tool
		else {
			if (lastItem && dynamic_cast<Tool*>(lastItem)) {
				m_strength -= dynamic_cast<Tool*>(lastItem)->getEfficacity();
			}
		}
		std::cout << "New strength = " << m_strength << std::endl;
	};
	inline void toggleInventory() { m_isInventoryOpen = !m_isInventoryOpen; }
	inline bool isInventoryOpen() { return m_isInventoryOpen; };

	virtual void setState(State state);
	virtual void setDirection(Direction dir);
	virtual  void setRealPosition(float pos);

	inline void setTarget(Entity* target) { m_target = target; };
	virtual inline void debugCollision(sf::RenderWindow& window) { 
		m_hitBox.setColor(255, 0, 0, 100); 
		m_fieldOfAction.setColor(255, 255, 255, 100);
		m_hitBox.draw(window);
		m_fieldOfAction.draw(window);
	};

private:
	vector<AnimablePlayer*> m_animations;

	Inventory m_inventory;
	bool m_isInventoryOpen;

};

