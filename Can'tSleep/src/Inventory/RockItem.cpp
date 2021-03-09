#include "./../../header/Inventory/RockItem.h"

RockItem::RockItem() {
	m_name = "Rock item";
	m_texture = TextureLoader::GetInstance()->getTexture("PlayAttack");
	m_textureIcon = TextureLoader::GetInstance()->getTexture("RockItem");
	m_sizeOfStack = 30;
}