#include "./../../header/Inventory/TrapItem.h"

TrapItem::TrapItem() : ConstructionItem(){
	m_name = "Trap";
	m_texture = TextureLoader::GetInstance()->getTexture("PlayIdle");
	m_textureIcon = TextureLoader::GetInstance()->getTexture("TrapItem");
	m_sizeOfStack = 30;
	m_constructible = nullptr;
}