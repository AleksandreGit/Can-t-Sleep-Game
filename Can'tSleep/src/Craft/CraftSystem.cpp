#include "./../../header/Craft/CraftSystem.h"


CraftSystem::CraftSystem() {
	readJSONFile("./Assets/Craft/Tools.txt");
}

Item* CraftSystem::getItemWithName(std::string name) {
	if(name ==  "WoodAxe"){
		return new Axe();
	}
	else if (name == "WoodLog") {
		return new WoodLog();
	}
}


void CraftSystem::readJSONFile(std::string path) {
	std::ifstream ifs(path);
	std::string line;

	while (std::getline(ifs, line)) {
		// Line containing the category name
		if (std::isdigit(line[0])) {
			std::cout << "Category number : " << line[0] << std::endl;
			std::cout << "Category name : " << splitString(line, " ")[1] << std::endl;
		}
		// Line containing an item
		else {
			std::vector<std::string> splitted = splitString(line, ":");
			std::string element = splitted[0];
			std::vector<std::string> ingredients = splitString(splitted[1], " ");
			std::map<std::string, int> numIngredients;
			for (std::string in : ingredients) {
				if (numIngredients[in]) {
					int val = numIngredients[in];
					numIngredients.emplace(in, val + 1);
				}
			}

			std::map<std::string, int>::iterator it;
		}

	}

}

