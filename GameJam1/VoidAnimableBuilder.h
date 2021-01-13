#pragma once

#include "AnimableBuilder.h"
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

class VoidAnimableBuilder : public AnimableBuilder
{
public:
	VoidAnimableBuilder();
	virtual AnimableEntity& build();

	/**
		Set the spriteSheet
		/!\ Muste define the number total of frames, the number
		of frames per columns and per rows before
	*/
	VoidAnimableBuilder setTexture(string path);
	VoidAnimableBuilder setFrameRate(float frameRate);
	VoidAnimableBuilder setFrameRatePerCol(int frameRatePerCol);
	VoidAnimableBuilder setFrameRatePerLig(int frameRatePerLig);
	VoidAnimableBuilder setTotalFrame(int totalFrame);

protected:
	sf::Texture texture;
	float frameRate;
	int framePerCol;
	int framePerLig;
	int totalFrame;

};

