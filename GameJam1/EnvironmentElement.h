#include "Animable.h"
#include "Map.h"

class EnvironmentElement : public Animable
{

public:
	EnvironmentElement() = default;
	EnvironmentElement(sf::Texture& texture, int width, int position);
	virtual void animate(float deltaTime);
	virtual void draw(sf::RenderWindow& window) const;
	virtual void reset();
	void remove();
	void receiveDamages(int damages);

protected:
	int m_health;
	int m_width;
	int m_position;
	sf::Texture m_texture;

};

