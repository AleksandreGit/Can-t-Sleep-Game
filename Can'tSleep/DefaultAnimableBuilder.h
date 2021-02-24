#pragma once

#include "AnimableBuilder.h"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


/**
	Create a Animable with default size : 298 x 421
*/
class DefaultAnimableBuilder : public AnimableBuilder
{

public:
	DefaultAnimableBuilder();
	virtual AnimableEntity& build();

	/**
		Set the spritesheet with the given path
		/!\ The number total of frames must be defined first !
	*/
	DefaultAnimableBuilder setTexture(std::string id);
	/**
		Set the framerate
	*/
	DefaultAnimableBuilder setFrameRate(float frameRate);
	/**
		Set the number total of frames
	*/
	DefaultAnimableBuilder setTotalFrame(int totalFrame);
	DefaultAnimableBuilder setHeight(int height);
	DefaultAnimableBuilder setWidth(int width);

protected:
	sf::Texture texture;
	float frameRate;
	int totalFrame;
	sf::Vector2<int> spriteSize;

};

