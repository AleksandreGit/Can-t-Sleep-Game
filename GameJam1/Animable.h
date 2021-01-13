#pragma once

/**
	Interface that represents an Animable Object
	Must override two methods: draw and animate
*/
class Animable {
public:
	virtual void animate(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow &window) const = 0;
};
