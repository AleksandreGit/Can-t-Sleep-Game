#pragma once
#include <SFML/Graphics.hpp>
#include "./../TextureLoader.h"

class Item
{
public:
	Item() = default;
	Item(std::string name, std::string textureName, std::string iconTextureName);
	virtual void drawIcon(sf::RenderWindow& window, sf::Vector2f pos, float scale = 0.5f);
	inline int getStackSize() { return m_sizeOfStack; };
	inline float getItemTextureSize() { return m_textureIcon.getSize().x; }
	inline std::string getName() { return m_name; };
protected:
	std::string m_name;
	sf::Texture m_texture;
	sf::Texture m_textureIcon;
	int m_sizeOfStack;
};

