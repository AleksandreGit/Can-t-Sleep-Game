#pragma once
#include "AnimableEntity.h"
#include "DefaultAnimableBuilder.h"
#include "MovingEntity.h"

class EnvironmentElement : public Entity {

public:
	EnvironmentElement() = default;
	EnvironmentElement(sf::Texture& texture, int width, int position);
	~EnvironmentElement();
	virtual void draw(sf::RenderWindow& window) const;
	virtual void animate(float deltaTime);
	virtual void defend(Entity* attacker);
	void remove();
	inline int getWidth() const { return m_width; };

protected:
	int m_width;
	AnimableEntity* m_animation;
};

