#include "./../../header/Craft/CraftSystem.h"
#include "./../../header/Inventory/Axe.h"
#include "./../../header/Inventory/WoodLog.h"
#include "./../../header/Inventory/RockItem.h"
#include "./../../header/Inventory/TrapItem.h"
#include "./../../header/TextureLoader.h"


CraftSystem::CraftSystem() {
	m_itemsMap["WoodAxe"] = new Axe();
	m_itemsMap["WoodLog"] = new WoodLog();
	m_itemsMap["Stone"] = new RockItem();
	m_itemsMap["Trap"] = new TrapItem();
	m_craftTexture = TextureLoader::GetInstance()->getTexture("CraftBackground");
	readJSONFile("./Assets/Craft/Tools.txt"); 
	m_isCraftOpen = false;
}

void CraftSystem::readJSONFile(std::string path) {
	std::ifstream ifs(path);
	std::string line;

	while (std::getline(ifs, line)) {
		// Line containing the category name
		if (std::isdigit(line[0])) {
			//std::cout << "Category number : " << line[0] << std::endl;
			//std::cout << "Category name : " << splitString(line, " ")[1] << std::endl;
		}
		// Line containing an item
		else {

			std::vector<std::string> splitted = splitString(line, ":");
			// We get the item
			std::string element = splitted[0];
			m_items.push_back(m_itemsMap[element]);
			//std::cout << element << std::endl;
			// We get the recipe
			std::vector<std::string> ingredients = splitString(splitted[1], " ");
			std::map<std::string, int> numIngredients;
			for (std::string in : ingredients) {
				if (numIngredients[in]) {
					numIngredients[in] += 1;
				}
				else {
					numIngredients[in] = 1;
				}
			}
			m_craftItems.push_back(numIngredients);
			/*
			for (std::map<std::string, int>::iterator iter = numIngredients.begin(); iter != numIngredients.end(); ++iter)
			{
				std::cout << "Total : " << iter->first << std::endl;
				std::cout << "Nombre requis : " << iter->second << std::endl;
			}
			std::cout << "" << std::endl;*/
		}

	}

}

void CraftSystem::draw(sf::RenderWindow& window) {
	if (m_isCraftOpen) {
		sf::Sprite backgroundSprite;
		backgroundSprite.setTexture(m_craftTexture);
		backgroundSprite.setPosition(
			window.getView().getCenter().x - m_craftTexture.getSize().x / 2,
			window.getView().getCenter().y - m_craftTexture.getSize().y / 2);
		window.draw(backgroundSprite);
		float offsetX = 435;
		float offsetY = 292;
		sf::Vector2f pos(
			backgroundSprite.getPosition().x + 235, 
			backgroundSprite.getPosition().y + offsetY);
		int i = 0;
		for (Item* item : m_items) {
			float textSize = item->getItemTextureSize() * 2;
			sf::Vector2f current(pos.x + i * offsetX - textSize / 2, pos.y - textSize / 2);
			item->drawIcon(window, current, 2.0f);
			i++;
		}
	}
}

void CraftSystem::drawItem(sf::RenderWindow& window, sf::Vector2f pos, int size) {

}

