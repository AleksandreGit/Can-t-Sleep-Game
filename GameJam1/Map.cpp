#include "Map.h"

Map::Map() {
	for (int i = 0; i < MAP_SIZE; i++) {
		m_tilesTypes[i] = 0;
	}

	vector<sf::Sprite> m_shownSprites;
}

Map::~Map() {

}

void Map::loadTextures() {
	sf::Texture texture;
	if (!texture.loadFromFile("./Assets/grass.png")) {
		std::cout << "Can't load the tile texture !" << std::endl;
	}
	m_tilesTextures.push_back(texture);
}