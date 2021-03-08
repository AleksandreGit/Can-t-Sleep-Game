#include "./../../header/Inventory/WoodLog.h"


WoodLog::WoodLog() {
	m_name = "Wood Log";
	m_texture = TextureLoader::GetInstance()->getTexture("PlayIdle");
	m_textureIcon = TextureLoader::GetInstance()->getTexture("WoodLog");


}
