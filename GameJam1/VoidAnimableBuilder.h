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
	virtual AnimableEntity build();

	/**
		Set the spriteSheet
		/!\ Muste define the number total of frames, the number
		of frames per columns and per rows before
	*/
	void setSpriteSheet(string path);
	void setFrameRate(int frameRate);
	void setFrameRatePerCol(int frameRatePerCol);
	void setFrameRatePerLig(int frameRatePerLig);
	void setTotalFrame(int totalFrame);

protected:
	sf::Texture texture;
	vector<sf::Sprite> spriteSheet;
	int frameRate;
	int framePerCol;
	int framePerLig;
	int totalFrame;

};

