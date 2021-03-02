#include "Item.h"


Item::Item(std::string name, std::string textureName, std::string iconTextureName) {
	this->m_name = name;
	this->m_texture = TextureLoader::GetInstance()->getTexture(textureName);
	this->m_textureIcon = TextureLoader::GetInstance()->getTexture(iconTextureName);
}

void Item::drawIcon(sf::RenderWindow& window, sf::Vector2f pos) {
	// TODO: draw the icon
}
