#pragma once
#include "Animable.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

class AnimableEntity : public Animable
{
public:
	inline AnimableEntity() = default;
	AnimableEntity(sf::Texture &texture, vector<sf::Sprite> spriteSheet, float frameRate,
		int framePerCol, int framePerLig,
		int totalFrame);
	virtual void animate(float deltaTime);
	virtual void draw(sf::RenderWindow& window) const;

	// SETTERS
	inline void setTexture(sf::Texture texture) { m_texture = texture; };
	inline void setSpriteSheet(vector<sf::Sprite> spriteSheet) { m_spriteSheet = spriteSheet; };
	inline void setFrameRate(float frameRate) { m_frameRate = frameRate; };
	inline void setFramePerCol(int framePerCol) { m_framePerCol = framePerCol; };
	inline void setFramePerLig(int framePerLig) { m_framePerLig = framePerLig; };
	inline void setTotalFrame(int totalFrame) { m_totalFrame = totalFrame; };

	// GETTERS
	inline const sf::Texture getTexture() { return m_texture; };
	inline const vector<sf::Sprite> getSpriteSheet() { return  m_spriteSheet; };
	inline const float getFrameRate() { return m_frameRate; };
	inline const int getFramePerCol() { return m_framePerCol; };
	inline const int getFramePerLig() { return m_framePerLig; };
	inline const int getTotalFrame() { return m_totalFrame; };

protected:
	// TODO: vérifier que ça passe bien sans pointeurs
	sf::Texture m_texture;
	vector<sf::Sprite> m_spriteSheet; // Contains all the sprite used for the animation

	// Animation handlers
	float m_frameRate; // Speed of the animation	
	int m_framePerCol;
	int m_framePerLig;
	int m_totalFrame; 
	int m_currentFrame;
	float m_elapsedTime; // Time elapsed since the beginning of the animation
};

