#pragma once
#include "./../Animation/AnimableEntity.h"
#include "./../Animation/DefaultAnimableBuilder.h"
#include "MovingEntity.h"

class EnvironmentElement : public Entity {

public:
	EnvironmentElement() = default;
	EnvironmentElement(sf::Texture& texture, int width, int position);
	~EnvironmentElement();
	virtual void draw(sf::RenderWindow& window);
	virtual void animate(float deltaTime);
	virtual void defend(Entity* attacker);
	void remove();
	inline int getWidth() const { return m_width; };
	virtual inline void debugCollision(sf::RenderWindow& window) { m_hitBox.setColor(0, 255, 0, 100); m_hitBox.draw(window); };

protected:
	int m_width;
	AnimableEntity* m_animation;
};

