#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

enum PlayerState {
	IDLE,
	WALK, 
	ATTACK,
	JUMP
};

class Player
{
public:
	Player();
	~Player();
	void loadTextures();
	void draw(sf::RenderWindow& window);
	void animate(float deltaTime);
	void updateSprite();

	const string ASSETS_PATH = "./Assets/";
	const float FRAMERATE_LIMIT = 0.2f;
	const int FRAME_SIZE = 128;
	const float SCALE_VAL = 2.0f;

private:
	sf::Sprite m_sprite;
	vector<sf::Texture> m_textures; // Contains all the player textures : IDLE, WALK, ATTACK, ...

	// ANIMATION
	PlayerState m_currentState; // Contains the current state of the player
	unsigned int m_currentFrame; // Contains the current frame of the animation
	sf::Vector2i m_numbersOfFrames; // Contains number of frames on x and y axis
	unsigned int m_currentTotalFrames;
	float m_currentTime;
	float m_nextFrame;



};

