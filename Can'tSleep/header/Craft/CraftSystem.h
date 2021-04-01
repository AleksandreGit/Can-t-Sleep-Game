#pragma once

#include "./../TextureLoader.h"
#include "./../Inventory/Item.h"
#include <fstream>
#include <string>

class Axe;
class WoodLog;
class RockItem;
class TextureLoader;
class Trap;
class Inventory;

class CraftSystem
{
public:
	CraftSystem();
	~CraftSystem() = default;
	void readJSONFile(std::string path);
	std::string getItemNameWithPos(int xPos, int yPos, sf::RenderWindow& window);
	std::vector<std::string> splitString(std::string content, std::string delimiter) {
		std::vector<std::string> result;
		size_t pos = 0;
		std::string token;
		while ((pos = content.find(delimiter)) != std::string::npos) {
			token = content.substr(0, pos);
			result.push_back(token);
			content.erase(0, pos + delimiter.length());
		}
		result.push_back(content);
		return result;
	}
	void draw(sf::RenderWindow& window, const Inventory& inventory);
	void drawItem(sf::RenderWindow& window, sf::Vector2f backgroundPos, Item* item, int index, const Inventory& inventory);
	inline bool isCraftOpen() { return m_isCraftOpen; };
	inline void toggleCraftMenu() { m_isCraftOpen = !m_isCraftOpen; };

private:
	sf::Texture m_craftTexture;
	sf::Text m_craftText;
	sf::Font m_font;
	std::map<std::string, Item*> m_itemsMap; // Mapping from string to objects
	std::vector<std::vector<Item*>> m_items; // Contains the items we can craft
	std::vector<std::vector<std::map<std::string, int>>> m_craftItems; // Contains the items necessary to craft each of craftable items
	bool m_isCraftOpen;
	int m_actualCategory;
};

