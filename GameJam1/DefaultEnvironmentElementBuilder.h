#include <iostream>
#include "EnvironmentElementBuilder.h"

using namespace std;

class DefaultEnvironmentElementBuilder : public EnvironmentElementBuilder
{
public:
	DefaultEnvironmentElementBuilder();
	virtual EnvironmentElement& build();

	DefaultEnvironmentElementBuilder setWidth(int width);
	DefaultEnvironmentElementBuilder setPosition(int position);
	DefaultEnvironmentElementBuilder setTexture(string path);

private:
	int width;
	int position;
	sf::Texture texture;
};

