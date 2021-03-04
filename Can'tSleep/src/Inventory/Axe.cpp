#include "./../../header/Inventory/Axe.h"

Axe::Axe() {
	m_name = "Wood Axe";
	m_texture = TextureLoader::GetInstance()->getTexture("PlayerWoodAxe");
	m_textureIcon = TextureLoader::GetInstance()->getTexture("WoodAxe");
	// TODO: add items to construct it, not yet implemented, need craft components
	//m_craftList.push_back();


}

void Axe::use(EnvironmentElement* target) {

}
