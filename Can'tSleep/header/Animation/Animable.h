#pragma once
#include <SFML/Graphics.hpp>

/**
	Interface that represents an Animable Object
	Must override two methods: draw and animate
*/
class Animable {
public:
	virtual void animate(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow &window, bool drawFilter = false) const = 0;
	virtual void reset() = 0;
};
