#include "./../../header/Inventory/TrapItem.h"

TrapItem::TrapItem() {
	m_constructible = new Trap();
	m_name = "Trap";
	m_texture = TextureLoader::GetInstance()->getTexture("PlayIdle");
	m_textureIcon = TextureLoader::GetInstance()->getTexture("Trap");
	m_sizeOfStack = 30;
}