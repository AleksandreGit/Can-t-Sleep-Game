#pragma once
#include "Animable.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class AnimableEntity : public Animable
{
public:
	AnimableEntity() = default;
	AnimableEntity(sf::Texture &texture, float frameRate,
		int framePerCol, int totalFrame);

	virtual void animate(float deltaTime);
	virtual void draw(sf::RenderWindow& window) const;
	virtual void reset();

	// SETTERS
	inline void setTexture(sf::Texture texture) { m_texture = texture; };
	inline void setFrameRate(float frameRate) { m_frameRate = frameRate; };
	inline void setFramePerCol(int framePerCol) { m_framePerCol = framePerCol; };
	inline void setTotalFrame(int totalFrame) { m_totalFrame = totalFrame; };
	inline void moveTo(float movementValue) { sf::Vector2f pos = m_currentSprite.getPosition(); m_currentSprite.setPosition(movementValue, pos.y);}

	// GETTERS
	inline const sf::Texture getTexture() { return m_texture; };
	inline const float getFrameRate() { return m_frameRate; };
	inline const int getFramePerCol() { return m_framePerCol; };
	inline const int getTotalFrame() { return m_totalFrame; };
	inline const float getPosition() { return m_currentSprite.getPosition().y; }
	inline const bool isAnimationFinished() { return m_elapsedTime > (m_totalFrame / m_frameRate); }

protected:
	// TODO: vérifier que ça passe bien sans pointeurs
	sf::Texture m_texture;
	sf::Sprite m_currentSprite;

	// Animation handlers
	float m_frameRate; // Speed of the animation	
	int m_framePerCol;
	int m_totalFrame; 
	int m_currentFrame;
	float m_elapsedTime; // Time elapsed since the beginning of the animation

private:
	const int DEFAULT_WIDTH = 298;
	const int DEFAULT_HEIGHT = 421;

};

