#include "./../../header/Craft/CraftSystem.h"
#include "./../../header/Inventory/Axe.h"
#include "./../../header/Inventory/WoodLog.h"
#include "./../../header/Inventory/RockItem.h"
#include "./../../header/Inventory/TrapItem.h"
#include "./../../header/Inventory/Inventory.h"
#include "./../../header/TextureLoader.h"


CraftSystem::CraftSystem() {
	m_itemsMap["WoodAxe"] = new Axe();
	m_itemsMap["WoodLog"] = new WoodLog();
	m_itemsMap["Stone"] = new RockItem();
	m_itemsMap["Trap"] = new TrapItem();
	if (!m_font.loadFromFile("./Assets/Fonts/arial.ttf")) {
		std::cout << "Can't load inventory font correctly" << std::endl;
	}
	m_craftTexture = TextureLoader::GetInstance()->getTexture("CraftBackground");
	m_actualCategory = 0;
	readJSONFile("./Assets/Craft/Tools.txt"); 
	m_isCraftOpen = false;
}

std::string CraftSystem::getItemNameWithPos(int xPos, int yPos, sf::RenderWindow& window) {
	sf::Vector2f offset(35, 92);
	sf::Vector2f craftPos(
		window.getView().getCenter().x - m_craftTexture.getSize().x / 2,
		window.getView().getCenter().y - m_craftTexture.getSize().y / 2);
	craftPos += offset;
	float blockSize = 400;
	bool clickOnItem = false;
	int index = 0;
	for (int i = 0; i < 3; i++) {
		sf::Vector2f current(craftPos.x + i * (blockSize+ 35), craftPos.y);
		if (xPos > current.x && xPos < current.x + blockSize) {
			if (yPos > current.y && yPos < current.y + blockSize) {
				clickOnItem = true;
				index = i;
				break;
			}
		}
		index++;
	}
	if (clickOnItem) {
		if (index < m_items[m_actualCategory].size()) {
			return m_items[m_actualCategory][index]->getName();
		}
	}
	return "None";

}

void CraftSystem::craftItem(int xPos, int yPos, sf::RenderWindow& window, Inventory& inventory) {
	if (m_isCraftOpen) {
		sf::Vector2f offset(35, 92);
		sf::Vector2f craftPos(
			window.getView().getCenter().x - m_craftTexture.getSize().x / 2,
			window.getView().getCenter().y - m_craftTexture.getSize().y / 2);
		craftPos += offset;
		float blockSize = 400;
		bool clickOnItem = false;
		int index = 0;
		for (int i = 0; i < 3; i++) {
			sf::Vector2f current(craftPos.x + i * (blockSize + 35), craftPos.y);
			if (xPos > current.x && xPos < current.x + blockSize) {
				if (yPos > current.y && yPos < current.y + blockSize) {
					clickOnItem = true;
					index = i;
					break;
				}
			}
			index++;
		}
		if (clickOnItem) {
			if (index < m_items[m_actualCategory].size()) {
				if (canCraftItem(index, inventory)) {
					if (inventory.canAddItem()) {
						std::map<Item*, int> recipe;
						std::map<std::string, int>::iterator it = m_craftItems[m_actualCategory][index].begin();
						while (it != m_craftItems[m_actualCategory][index].end()) {
							Item* recipeItem = m_itemsMap[it->first];
							recipe[recipeItem] = it->second;
							it++;
						}
						inventory.craftItem(m_items[m_actualCategory][index], recipe);
					}
				}
			}
		}
	}
}

bool CraftSystem::canCraftItem(int index, Inventory& inventory) {
	std::map<std::string, int>::iterator it = m_craftItems[m_actualCategory][index].begin();
	while (it != m_craftItems[m_actualCategory][index].end()) {
		Item* recipeItem = m_itemsMap[it->first];
		int quantityOfItem = inventory.getQuantityOfItem(recipeItem);
		if (quantityOfItem < it->second) {
			return false;
		}
		it++;
	}
	return true;
}

void CraftSystem::readJSONFile(std::string path) {
	std::ifstream ifs(path);
	std::string line;
	std::vector<Item*> tabItem; 
	std::vector<std::map<std::string, int>> tabRecipe;

	int actual = 0;
	while (std::getline(ifs, line)) {
		// Line containing the category name
		if (std::isdigit(line[0])) {
			if (actual != line[0]) {
				actual = line[0];
				if (tabItem.size() > 0) {
					m_items.push_back(tabItem);
					m_craftItems.push_back(tabRecipe);
				}
			}
		}
		// Line containing an item
		else {
			std::vector<std::string> splitted = splitString(line, ":");
			// We get the item
			std::string element = splitted[0];
			tabItem.push_back(m_itemsMap[element]);
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
			tabRecipe.push_back(numIngredients);
		}
	}

}

void CraftSystem::draw(sf::RenderWindow& window, const Inventory& inventory) {
	if (m_isCraftOpen) {
		sf::Sprite backgroundSprite;
		backgroundSprite.setTexture(m_craftTexture);
		backgroundSprite.setPosition(
			window.getView().getCenter().x - m_craftTexture.getSize().x / 2,
			window.getView().getCenter().y - m_craftTexture.getSize().y / 2);
		window.draw(backgroundSprite);

		int i = 0;
		for (Item* item : m_items[m_actualCategory]) {
			drawItem(window, backgroundSprite.getPosition(), item, i, inventory);
			i++;
		}
	}
}

void CraftSystem::drawItem(sf::RenderWindow& window, sf::Vector2f backgroundPos, Item* item, int index, const Inventory& inventory) {

	// Show item
	float offsetX = 435;
	float offsetY = 292;
	sf::Vector2f pos(
		backgroundPos.x + 235,
		backgroundPos.y + offsetY);
	sf::Vector2f textPos(
		backgroundPos.x + 35,
		backgroundPos.y + 35);
	sf::Vector2f recipePos(
		backgroundPos.x + 35,
		backgroundPos.y + 502);

	float textSize = item->getItemTextureSize();
	sf::Vector2f current(pos.x + index * offsetX - textSize / 2, pos.y - textSize / 2);

	// Show item name
	sf::Text itemName;
	itemName.setString(item->getName());
	itemName.setFont(m_font);
	itemName.setCharacterSize(25);
	itemName.setFillColor(sf::Color::White);
	itemName.setStyle(sf::Text::Bold);
	itemName.setPosition(sf::Vector2f(textPos.x + 20, textPos.y + 20));
	item->drawIcon(window, current, 1.0);
	window.draw(itemName);

	std::map<std::string, int>::iterator it = m_craftItems[m_actualCategory][index].begin();
	
	int i = 0;
	while (it != m_craftItems[m_actualCategory][index].end()) {
		Item* recipeItem = m_itemsMap[it->first];
		sf::Text recipeName;
		int quantityOfItem = inventory.getQuantityOfItem(recipeItem);
		recipeName.setString(std::to_string(quantityOfItem) + " / " + std::to_string(it->second));
		recipeName.setFont(m_font);
		recipeName.setCharacterSize(25);
		if (quantityOfItem > it->second) {
			recipeName.setFillColor(sf::Color::Green);
		}
		else{
			recipeName.setFillColor(sf::Color::Red);
		}
		recipeName.setStyle(sf::Text::Bold);
		recipeName.setPosition(sf::Vector2f(recipePos.x + 100, recipePos.y + i * 80 + 20));
		recipeItem->drawIcon(window, sf::Vector2f(recipePos.x, recipePos.y + i * 80), 0.25f);
		window.draw(recipeName);
		i++;
		it++;
	}
}

