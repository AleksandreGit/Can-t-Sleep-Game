#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"

class HitBox
{
public:
	inline HitBox(float x, float y) { 
		m_box.setSize(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
		m_box.setPosition(x, y);
	};

	inline HitBox(float x, float y, float width, float height) {
		m_box.setSize(sf::Vector2f(width, height));
		m_box.setPosition(x, y);
	}

	bool collide(const HitBox& hB) const;

	inline sf::FloatRect getBoundingBox() const { return m_box.getGlobalBounds(); };
	inline void draw(sf::RenderWindow& window) { window.draw(m_box); };
	inline void setColor(float r, float g, float b, float a) { m_box.setFillColor(sf::Color(r, g, b, a)); };
	inline void setSize(float width, float height) { m_box.setSize(sf::Vector2f(width, height)); };
	inline void setPosition(float x, float y) { m_box.setPosition(x, y); };
	inline float getWidth() const { return m_box.getSize().x; };

private:
	sf::RectangleShape m_box;
};

