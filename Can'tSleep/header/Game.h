#pragma once
#include <SFML/Graphics.hpp>
#include "./Animation/AnimableBuilder.h"
#include "./Entities/Player.h"
#include "./Inventory/ConstructionItem.h"
#include "Map.h"
#include "./Craft/CraftSystem.h"

class Game
{
public:
	Game();

	void draw();
	void handleEvents(float deltaTime);
	void handleCamera();
	void update();

	const static float WORLD_UNIT;
	const static int W_WIDTH = 1920;
	const static int W_HEIGHT = 1080;
	const static int DAY_DURATION = 20;

private:
	sf::RenderWindow m_window;
	sf::View m_playerView;
	sf::Clock m_clock;
	sf::Vertex m_sky[4];
	Player m_player;
	Map m_map;
	CraftSystem m_craftSystem;
	float m_currentTime;
	bool m_state; // 0 : day; 1 : night

	const float ratio = 9 / 16;
	const unsigned int S_SIZE = 200;
	const unsigned int SCALE_FACTOR = 2;
};

