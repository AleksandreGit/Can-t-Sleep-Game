#include "./../../header/Inventory/Item.h"


Item::Item(std::string name, std::string textureName, std::string iconTextureName) {
	this->m_name = name;
	this->m_texture = TextureLoader::GetInstance()->getTexture(textureName);
	this->m_textureIcon = TextureLoader::GetInstance()->getTexture(iconTextureName);
}

void Item::drawIcon(sf::RenderWindow& window, sf::Vector2f pos) {
	sf::Sprite iconSprite;
	iconSprite.setTexture(m_textureIcon);
	iconSprite.setPosition(pos);
	window.draw(iconSprite);
}
