#pragma once
#include "Animable.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

class AnimableEntity : public Animable
{
public:
	AnimableEntity();
	virtual void animate(float deltaTime);
	virtual void draw() const;

protected:
	vector<sf::Sprite> m_spriteSheet; // Contains all the sprite used for the animation
	int m_frameRate; // Speed of the animation	
	int m_framePerCol;
	int m_framePerLig;
	int m_totalFrame; 
	int m_currentFrame;
	float m_elapsedTime; // Time elapsed since the beginning of the animation
};

