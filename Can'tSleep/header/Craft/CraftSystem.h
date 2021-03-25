#pragma once

#include "./../TextureLoader.h"
class CraftSystem
{
public:
	CraftSystem() = default;
	~CraftSystem() = default;

private:
	sf::Texture m_craftTexture;
	sf::Text m_craftText;
	sf::Font m_font;
};

