#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

enum class PlayerState {
	IDLE,
	WALK, 
	ATTACK,
	JUMP
};

enum class MovementDirection {
	LEFT,
	RIGHT,
	UP,
	NOT
};

class Player
{
public:
	Player();
	~Player();
	void loadTextures();
	void draw(sf::RenderWindow& window);

	/**
		Animate the player accordingly to its current state
		@param: deltaTime, the current delta time
	*/
	void animate(float deltaTime);

	/**
		Permits to update the sprite after setting the state
		of the player
	*/
	void updateSprite();

	/**
		Activate/Desactivate the player movement
		@param: direction, integer indicating the direction of the movement 
		--> left=0; right=1; up=2; nodirection=others
	*/
	void toggleMovement(unsigned int direction = 3);

	void handleTime(float deltaTime);

	/**
		Check if the player is moving
	*/
	bool isPlayerMoving();

	void setState(unsigned int state);

	const string ASSETS_PATH = "./Assets/";
	const float IDLE_FRAMERATE = 0.02f;
	const float WALK_FRAMERATE = 0.05f;
	const int FRAME_WIDTH = 298;
	const int FRAME_HEIGHT = 421;
	const float SCALE_VAL = 1.0f;
	const float SPEED = 200.0f;

private:
	sf::Sprite m_sprite;
	vector<sf::Texture> m_textures; // Contains all the player textures : IDLE, WALK, ATTACK, ...

	// ANIMATION
	PlayerState m_currentState; // Contains the current state of the player
	unsigned int m_currentFrame; // Contains the current frame of the animation
	sf::Vector2i m_numbersOfFrames; // Contains number of frames on x and y axis
	unsigned int m_currentTotalFrames; // Total number of frames of the current animation
	float m_currentTime; // Current time of the animation
	float m_nextFrame; // Time of the next frame
	bool m_isPlayerMoving;
	MovementDirection m_movementDirection;

};

