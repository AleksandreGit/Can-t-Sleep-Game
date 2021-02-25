#pragma once
#include <SFML/Graphics.hpp>

class Item
{
public:
	Item();
	void drawIcon(sf::RenderWindow& window, sf::Vector2f pos);
protected:
	std::string m_name;
	sf::Texture m_texture;
	sf::Texture m_textureIcon;
};

