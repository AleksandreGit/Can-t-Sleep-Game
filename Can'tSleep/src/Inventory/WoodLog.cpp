#include "./../../header/Inventory/WoodLog.h"

WoodLog::WoodLog() {
	m_name = "Wood Log";
	m_texture = TextureLoader::GetInstance()->getTexture("PlayAttack");
	m_textureIcon = TextureLoader::GetInstance()->getTexture("WoodLog");
	m_sizeOfStack = 30;
}
