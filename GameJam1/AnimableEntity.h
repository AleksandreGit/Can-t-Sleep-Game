#pragma once
#include "Animable.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

class AnimableEntity : public Animable
{
public:
	AnimableEntity(sf::Texture &texture, vector<sf::Sprite> spriteSheet, int frameRate,
		int framePerCol, int framePerLig,
		int totalFrame);
	virtual void animate(float deltaTime);
	virtual void draw(sf::RenderWindow& window) const;

protected:
	// TODO: vérifier que ça passe bien sans pointeurs
	sf::Texture m_texture;
	vector<sf::Sprite> m_spriteSheet; // Contains all the sprite used for the animation

	// Animation handlers
	int m_frameRate; // Speed of the animation	
	int m_framePerCol;
	int m_framePerLig;
	int m_totalFrame; 
	int m_currentFrame;
	float m_elapsedTime; // Time elapsed since the beginning of the animation
};

