#include "Map.h"

Map::Map() {
	for (int i = 0; i < MAP_SIZE; i++) {
		m_tiles.push_back(GRASS);
	}
	if (!m_tilesTexture.loadFromFile("./Assets/tiles.png")) {
		cout << "Problem with tiles loading" << endl;
	}
}

void Map::draw(sf::RenderWindow& window, int currentPos, float zoom) const {
	for (int i = 0; i < m_tiles.size(); i++) {
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
				sprite.setTextureRect(sf::IntRect(2*TILE_WIDTH, 0, TILE_WIDTH, TILE_HEIGHT));
				break;
		}
		sprite.setPosition(TILE_WIDTH * i, -30);
		window.draw(sprite);
	}
}