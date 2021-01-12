#pragma once

#include "AnimableBuilder.h"
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

	void setSpriteSheet(string path);
	void setFrameRate(int frameRate);
	void setFrameRatePerCol(int frameRatePerCol);
	void setFrameRatePerLig(int frameRatePerLig);
	void setTotalFrame(int totalFrame);

protected:
	vector<sf::Sprite> spriteSheet;
	int frameRate;
	int framePerCol;
	int framePerLig;
	int totalFrame;

};

