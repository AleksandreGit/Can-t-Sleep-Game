#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "TileType.h"

using namespace std;

class Map
{
public:
	Map();
	void draw(sf::RenderWindow& window, int currentPos, float zoom) const;

	const static unsigned int MAP_SIZE = 10;
	const static int TILE_WIDTH = 298;
	const static int TILE_HEIGHT = 842;

private:
	vector<TileType> m_tiles;
	sf::Texture m_tilesTexture;
};

