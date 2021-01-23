#include "EnvironmentElement.h"

class Natural : public EnvironmentElement
{
public :
	Natural() = default;
	inline Natural(EnvironmentElement e) : EnvironmentElement(e) {};
	inline Natural(sf::Texture& texture, int width, int position) : EnvironmentElement(texture, width, position) {};
};

