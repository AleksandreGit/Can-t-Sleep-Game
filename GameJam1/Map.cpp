#include "Map.h"

Map::Map() {
	for (int i = 0; i < MAP_SIZE; i++) {
		m_tiles.push_back(GRASS);
		m_elements.push_back(nullptr);
	}
	if (!m_tilesTexture.loadFromFile("./Assets/tiles2.png")) {
		cout << "Problem with tiles loading" << endl;
	}
	m_elements[MAP_SIZE / 2] = new Tree(OAK, MAP_SIZE / 2);
	m_elements[MAP_SIZE / 2 +4] = new Tree(OAK, MAP_SIZE / 2 +4);
	m_elements[MAP_SIZE / 2 - 2] = new Mineral(STONE, MAP_SIZE / 2 - 2);

}


void Map::draw(sf::RenderWindow& window, int currentPos, float zoom) const {
	int bound = BLOC_TO_SHOW / 2;
	int lowerBound = currentPos - bound + 1;
	int upperBound = currentPos + bound;

	if (lowerBound < 0) {
		lowerBound = 0;
	}
	if (upperBound > Map::MAP_SIZE) {
		upperBound = Map::MAP_SIZE;
	}

	int firstValue = lowerBound;
	for (int i = lowerBound; i < upperBound; i++) {
		if (m_elements[i]) {
			m_elements[i]->draw(window);
		}
	}

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
		sprite.setPosition(TILE_WIDTH * firstValue, 0);
		firstValue++;
		window.draw(sprite);
	}
}

void Map::generateRandom() {

}