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

	// -30
	PerlinNoise perlin(600.0f, 0.02f);

	// QUALITY METRICS
	int nbBiome = 0;
	std::map<std::string, int> biomesDiversite;
	biomesDiversite.insert(std::pair<std::string, int>("forest", 0));
	biomesDiversite.insert(std::pair<std::string, int>("rock", 0));
	biomesDiversite.insert(std::pair<std::string, int>("classic", 0));
	std::vector<int> biomesSizes;
	TileType currentBiome = NOTYPE;
	int currentSize = 0;

	for (int i = 0; i < Map::MAP_SIZE; i++) {
		proba = distribution(generator);
		if (perlin.noise1D(i) <= -0.4f) {
			if (currentBiome != ROCK) {
				currentBiome = ROCK;
				biomesDiversite.at("rock")++;
				if (nbBiome != 0) {
					biomesSizes.push_back(currentSize);
				}
				nbBiome++;
				currentSize = 0;
			}
			m_tiles[j] = ROCK;
			if (proba <= 0.6f) {
				m_elements[j] = new Mineral(STONE, j);
			}

		}
		else if (perlin.noise1D(i) > -0.4f && perlin.noise1D(i) <= 0.2f) {
			if (currentBiome != FOREST) {
				currentBiome = FOREST;
				biomesDiversite.at("forest")++;
				if (nbBiome != 0) {
					biomesSizes.push_back(currentSize);
				}
				nbBiome++;
				currentSize = 0;
			}
			m_tiles[j] = FOREST;
			if (proba <= 0.7f) {
				m_elements[j] = new Tree(OAK, j);
			}

		}
		else {
			if (currentBiome != GRASS) {
				currentBiome = GRASS;
				biomesDiversite.at("classic")++;
				if (nbBiome != 0) {
					biomesSizes.push_back(currentSize);
				}
				nbBiome++;
				currentSize = 0;
			}
			m_tiles[j] = GRASS;
			if (proba <= 0.10f) {
				m_elements[j] = new Mineral(STONE, j);
			}
			else if (proba > 0.40f && proba <= 0.50f) {
				m_elements[j] = new Tree(OAK, j);
			}
		}
		currentSize++;
		j++;
	}

	/*COMPUTE METRICS*/
	biomesSizes.push_back(currentSize);
	std::cout << "Taille map : " << m_tiles.size() << std::endl;
	std::cout << "Nombre biomes : " << nbBiome << std::endl;
	float moyenne = 0;
	for (int i = 0; i < biomesSizes.size(); i++) {
		moyenne += biomesSizes[i];
		std::cout << "Taille biome " << i << " " << biomesSizes[i] << std::endl;
	}
	moyenne /= biomesSizes.size();
	std::cout << "Taille moyenne des biomes : " << moyenne << std::endl;
	std::cout << "Nombre de biomes 'foret' : " << biomesDiversite.at("forest") << std::endl;
	std::cout << "Nombre de biomes 'rock' : " << biomesDiversite.at("rock") << std::endl;
	std::cout << "Nombre de biomes 'classic' : " << biomesDiversite.at("classic") << std::endl;
}