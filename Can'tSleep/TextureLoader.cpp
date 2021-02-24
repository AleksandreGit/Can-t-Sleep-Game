#include "TextureLoader.h"

TextureLoader* TextureLoader::textureLoader = nullptr;;

TextureLoader::TextureLoader() {

	// TODO: WOULD BE BETTER IF ALL OF THOSE TEXTURES WOULD BE THE SAME !
	// Could get coordinates intos a .json file to then index datas
	// ENVIRONMENT
	if (!m_textures["Tree"].loadFromFile("./Assets/tree.png")) {
		std::cout << "Can't load tree texture" << std::endl;
	}
	if (!m_textures["Rock"].loadFromFile("./Assets/rock.png")) {
		std::cout << "Can't load rock texture" << std::endl;
	}
	if (!m_textures["Chest"].loadFromFile("./Assets/chest.png")) {
		std::cout << "Can't load chest texture" << std::endl;
	}
	if (!m_textures["Floor"].loadFromFile("./Assets/tiles2.png")) {
		std::cout << "Can't load floor texture" << std::endl;
	}

	// PLAYER
	if (!m_textures["PlayIdle"].loadFromFile("./Assets/idle2.png")) {
		std::cout << "Can't load player idle texture" << std::endl;
	}
	if (!m_textures["PlayAttack"].loadFromFile("./Assets/attack.png")) {
		std::cout << "Can't load player attack texture" << std::endl;
	}
	if (!m_textures["PlayInteract"].loadFromFile("./Assets/interact.png")) {
		std::cout << "Can't load player interact texture" << std::endl;
	}
	if (!m_textures["PlayWalk"].loadFromFile("./Assets/walk2.png")) {
		std::cout << "Can't load player walk texture" << std::endl;
	}
}

TextureLoader* TextureLoader::GetInstance()
{
	if (textureLoader == nullptr) {
		textureLoader = new TextureLoader();
	}
	return textureLoader;
}