#pragma once

#include "AnimableBuilder.h"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

class DefaultAnimableBuilder : public AnimableBuilder
{

public:
	DefaultAnimableBuilder();
	virtual AnimableEntity build();

	void setSpriteSheet(string path);
	void setFrameRate(int frameRate);
	void setTotalFrame(int totalFrame);

protected:
	vector<sf::Sprite> spriteSheet;
	int frameRate;
	int totalFrame;

};

