#pragma once

class Animable {
public:
	virtual void animate(float deltaTime) = 0;
	virtual void draw() const = 0;
};
