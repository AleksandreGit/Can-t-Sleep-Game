#include "Map.h"

Map::Map() {
	for (int i = 0; i < MAP_SIZE; i++) {
		m_tiles.push_back(GRASS);
		m_elements.push_back(nullptr);
	}
	if (!m_tilesTexture.loadFromFile("./Assets/tiles2.png")) {
		std::cout << "Problem with tiles loading" << std::endl;
	}
	generateRandom();

}


void Map::draw(sf::RenderWindow& window, int currentPos) const {
	int bound = BLOC_TO_SHOW / 2;
	int lowerBound = currentPos - bound + 1;
	int upperBound = currentPos + bound;

	if (lowerBound < 0) {
		lowerBound = 0;
	}
	if (upperBound > MAP_SIZE) {
		upperBound = MAP_SIZE;
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
		case FOREST:
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
	int j = 0;
	float proba = 0.0f;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<float> distribution(0.0, 1.0);
	std::uniform_real_distribution<float> seed(-10000.0f, 10000.0f);

	// -30
	PerlinNoise perlin(seed(generator), 0.015f, 1.0f, 5);

	for (int i = 0; i < MAP_SIZE; i++) {
		proba = distribution(generator);
		if (perlin.noise1D(i) <= -0.4f) {
			m_tiles[j] = ROCK;
			if (proba <= 0.6f) {
				m_elements[j] = new Mineral(STONE, j);
			}

		}
		else if (perlin.noise1D(i) > -0.4f && perlin.noise1D(i) <= 0.2f) {
			m_tiles[j] = FOREST;
			if (proba <= 0.7f) {
				m_elements[j] = new Tree(OAK, j);
			}

		}
		else {
			m_tiles[j] = GRASS;
			if (proba <= 0.10f) {
				m_elements[j] = new Mineral(STONE, j);
			}
			else if (proba > 0.40f && proba <= 0.50f) {
				m_elements[j] = new Tree(OAK, j);
			}
		}
		j++;
	}
}

EnvironmentElement* Map::checkCollisions(Player& player) {

	int bound = BLOC_TO_SHOW / 2;
	int lowerBound = player.getWorldPosition() - bound + 1;
	int upperBound = player.getWorldPosition() + bound;

	if (lowerBound < 0) {
		lowerBound = 0;
	}
	if (upperBound > MAP_SIZE) {
		upperBound = MAP_SIZE;
	}

	float playerPos = player.getRealPosition();
	float playerWidth = player.getSize().x;
	Direction playerDir = player.getCollisionDirection();

	for (int i = lowerBound; i < upperBound; i++) {
		if (m_elements[i] != nullptr) {
			float upperBorder = m_elements[i]->getRealPosition() + m_elements[i]->getSize().x * 0.5f;
			float lowerBorder = m_elements[i]->getRealPosition() - m_elements[i]->getSize().x * 0.5f;
			if (
				upperBorder > (playerPos - playerWidth * 0.5f)
				&& upperBorder < (playerPos + playerWidth * 0.5f)
				&& playerDir == LEFT) {
				return m_elements[i];
			}
			else if (
				lowerBorder < (playerPos + playerWidth * 0.5f)
				&& lowerBorder >(playerPos - playerWidth * 0.5f)
				&& playerDir == RIGHT) {
				return m_elements[i];
			}
			else if (
				upperBorder > (playerPos + playerWidth * 0.5f)
				&& lowerBorder < (playerPos - playerWidth * 0.5f)) {
				return m_elements[i];
			}
		}	 
	}

	return nullptr;
}