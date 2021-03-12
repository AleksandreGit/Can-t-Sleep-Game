#include "./../../header/Inventory/TrapItem.h"

TrapItem::TrapItem() : ConstructionItem(new Trap(10)){
	m_name = "Trap";
	m_texture = TextureLoader::GetInstance()->getTexture("PlayIdle");
	m_textureIcon = TextureLoader::GetInstance()->getTexture("TrapItem");
	m_sizeOfStack = 30;
}