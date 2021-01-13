#pragma once

#include "AnimableBuilder.h"
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

/**
	Create a Animable with default size : 298 x 421
*/
class DefaultAnimableBuilder : public AnimableBuilder
{

public:
	DefaultAnimableBuilder();
	virtual AnimableEntity build();

	/**
		Set the spritesheet with the given path
		/!\ The number total of frames must be defined first !
	*/
	DefaultAnimableBuilder setSpriteSheet(string path);
	/**
		Set the framerate
	*/
	DefaultAnimableBuilder setFrameRate(float frameRate);
	/**
		Set the number total of frames
	*/
	DefaultAnimableBuilder setTotalFrame(int totalFrame);

protected:
	sf::Texture texture;
	vector<sf::Sprite> spriteSheet;
	float frameRate;
	int totalFrame;

private:
	const int DEFAULT_WIDTH = 298;
	const int DEFAULT_HEIGHT = 421;

};

