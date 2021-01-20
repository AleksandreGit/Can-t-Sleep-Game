#include "Map.h"

Map::Map() {
	for (int i = 0; i < MAP_SIZE; i++) {
		m_tiles.push_back(GRASS);
	}
	if (!m_tilesTexture.loadFromFile("./Assets/tiles.png")) {
		cout << "Problem with tiles loading" << endl;
	}
}


// TODO r�duire cette fonction
void Map::draw(sf::RenderWindow& window, int currentPos, float zoom) const {
	int bound = BLOC_TO_SHOW / 2;
	int lowerBound = currentPos - bound + 1;
	int upperBound = currentPos + bound;
	std::cout << "Current: " << currentPos << std::endl;
	std::cout << "Lower: " << lowerBound << std::endl;
	std::cout << "Upper: " << upperBound << std::endl;

	if (lowerBound < 0) {
		lowerBound = 0;
	}
	if (upperBound > Map::MAP_SIZE) {
		upperBound = Map::MAP_SIZE;
	}

	int firstValue = lowerBound;

	for (int i = lowerBound; i < upperBound; i++) {
		sf::Sprite sprite;
		sprite.setTexture(m_tilesTexture);
		switch (m_tiles[i]) {
		case GRASS:
			sprite.setTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_HEIGHT));
			break;
		case SAND:
			sprite.setTextureRect(sf::IntRect(TILE_WIDTH, 0, TILE_WIDTH, TILE_HEIGHT));
			break;
		case ROCK:
			sprite.setTextureRect(sf::IntRect(2 * TILE_WIDTH, 0, TILE_WIDTH, TILE_HEIGHT));
			break;
		}
		sprite.setPosition(TILE_WIDTH * firstValue, -30);
		firstValue++;
		window.draw(sprite);
	}
}