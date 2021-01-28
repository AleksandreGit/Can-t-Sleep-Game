#pragma once
#include <SFML/Graphics.hpp>
#include "EnvironmentElement.h"
#include "PerlinNoise.h"
#include "Tree.h"
#include "Mineral.h"
#include "TileType.h"
#include <iostream>
#include <vector>
#include <random>

class Map {
public:
	Map();
	void draw(sf::RenderWindow& window, int currentPos, float zoom) const;
	void generateRandom();

	const static unsigned int MAP_SIZE = 500;
	const static unsigned int BLOC_TO_SHOW = 14;
	const static int TILE_WIDTH = 298;
	const static int TILE_HEIGHT = 842;

private:
	std::vector<TileType> m_tiles;
	std::vector<EnvironmentElement*> m_elements;
	sf::Texture m_tilesTexture;
};

