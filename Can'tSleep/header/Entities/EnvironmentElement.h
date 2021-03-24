#pragma once
#include "./../Animation/AnimableEntity.h"
#include "./../Animation/DefaultAnimableBuilder.h"
#include "MovingEntity.h"

class EnvironmentElement : public Entity {

public:
	EnvironmentElement() = default;
	EnvironmentElement(sf::Texture& texture, int width, int position);
	~EnvironmentElement();
	virtual void draw(sf::RenderWindow& window, bool showFilter = false);
	virtual void animate(float deltaTime);
	virtual void defend(Entity* attacker);
	void remove();
	inline int getWidth() const { return m_width; };
	virtual inline void debugCollision(sf::RenderWindow& window) { m_hitBox.setColor(0, 255, 0, 100); m_hitBox.draw(window); };
	inline AnimableEntity* getAnimation() { return m_animation; };

	virtual inline void setWorldPosition(int pos) {
		Entity::setWorldPosition(pos);
		m_animation->moveTo((m_worldPosition+0.5f)*TILE_WIDTH);

	};
	virtual inline void setRealPosition(float pos) {
		Entity::setRealPosition(pos);
		m_animation->moveTo(m_realPosition);
	};

protected:
	int m_width;
	AnimableEntity* m_animation;
};

