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

void CraftSystem::draw(sf::RenderWindow& window) {
	if (m_isCraftOpen) {
		sf::Sprite backgroundSprite;
		backgroundSprite.setTexture(m_craftTexture);
		backgroundSprite.setPosition(
			window.getView().getCenter().x - m_craftTexture.getSize().x / 2,
			window.getView().getCenter().y - m_craftTexture.getSize().y / 2);
		window.draw(backgroundSprite);

		int i = 0;
		for (Item* item : m_items[m_actualCategory]) {
			drawItem(window, backgroundSprite.getPosition(), item, i);
			i++;
		}
	}
}

void CraftSystem::drawItem(sf::RenderWindow& window, sf::Vector2f backgroundPos, Item* item, int index) {
	float offsetX = 435;
	float offsetY = 292;
	sf::Vector2f pos(
		backgroundPos.x + 235,
		backgroundPos.y + offsetY);
	sf::Vector2f textPos(
		backgroundPos.x + 35,
		backgroundPos.y + 35);
	float textSize = item->getItemTextureSize();
	sf::Vector2f current(pos.x + index * offsetX - textSize / 2, pos.y - textSize / 2);
	sf::Text text;
	text.setString(item->getName());
	text.setFont(m_font);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setPosition(sf::Vector2f(textPos.x + 20, textPos.y + 20));
	item->drawIcon(window, current, 1.0);
	window.draw(text);
}

