#pragma once
#include <SFML/Graphics.hpp>
#include "./../TextureLoader.h"

class Item
{
public:
	Item() = default;
	Item(std::string name, std::string textureName, std::string iconTextureName);
	virtual void drawIcon(sf::RenderWindow& window, sf::Vector2f pos);
protected:
	std::string m_name;
	sf::Texture m_texture;
	sf::Texture m_textureIcon;
};

