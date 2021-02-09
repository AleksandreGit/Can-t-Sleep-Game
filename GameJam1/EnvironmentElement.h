#pragma once
#include "Animable.h"
#include "MovingEntity.h"

class EnvironmentElement : public Animable, public Entity {

public:
	EnvironmentElement() = default;
	EnvironmentElement(sf::Texture& texture, int width, int position);
	~EnvironmentElement();
	virtual void animate(float deltaTime);
	virtual void draw(sf::RenderWindow& window) const;
	virtual void reset();
	virtual void defend(Entity* attacker);
	void remove();

protected:
	int m_health;
	int m_width;
	sf::Texture m_texture;
	sf::Sprite m_currentSprite;
};

