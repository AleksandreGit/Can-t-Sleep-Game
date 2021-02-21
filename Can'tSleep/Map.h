#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "EnvironmentElement.h"
#include "PerlinNoise.h"
#include "Tree.h"
#include "Mineral.h"
#include "Chest.h"
#include "TileType.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <random>

class Map {
public:
	Map();
	void draw(sf::RenderWindow& window, int currentPos) const;
	void generateRandom();
	std::vector<EnvironmentElement*> getCurrentElements(int currentPos);

private:
	std::vector<TileType> m_tiles;
	std::vector<EnvironmentElement*> m_elements;
	sf::Texture m_tilesTexture;
};

