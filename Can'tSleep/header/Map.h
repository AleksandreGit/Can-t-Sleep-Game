#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "TextureLoader.h"
#include "./Entities/EnvironmentElement.h"
#include "PerlinNoise.h"
#include "./Entities/Tree.h"
#include "./Entities/Mineral.h"
#include "./Entities/Chest.h"
#include "TileType.h"
#include "./Entities/Player.h"
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

