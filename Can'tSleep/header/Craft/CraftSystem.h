#pragma once

#include "./../TextureLoader.h"
#include "./../Inventory/Item.h"
#include "./../Inventory/Axe.h"
#include "./../Inventory/WoodLog.h"
#include <fstream>
#include <string>

class CraftSystem
{
public:
	CraftSystem();
	~CraftSystem() = default;
	Item* getItemWithName(std::string name);
	void readJSONFile(std::string path);
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

private:
	sf::Texture m_craftTexture;
	sf::Text m_craftText;
	sf::Font m_font;
	std::vector<Item*> m_items; // Contains the items we can craft
	std::vector<Item*> m_craftItems; // Contains the items necessary to craft

};

