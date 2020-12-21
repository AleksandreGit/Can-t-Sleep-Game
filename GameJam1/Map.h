#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Map
{
public:
	Map();
	~Map();

	void loadTextures();
	const static unsigned int MAP_SIZE = 100;

private:
	vector<int> m_tilesTypes;
	vector<sf::Sprite> m_shownSprites;
	vector<sf::Texture> m_tilesTextures;
};

