#include "./../header/TextureLoader.h"

TextureLoader* TextureLoader::textureLoader = nullptr;;

TextureLoader::TextureLoader() {

	// TODO: WOULD BE BETTER IF ALL OF THOSE TEXTURES WOULD BE THE SAME !
	// Could get coordinates intos a .json file to then index datas
	// ENVIRONMENT
	if (!m_textures["Tree"].loadFromFile("./Assets/Environment/tree.png")) {
		std::cout << "Can't load tree texture" << std::endl;
	}
	if (!m_textures["Rock"].loadFromFile("./Assets/Environment/rock.png")) {
		std::cout << "Can't load rock texture" << std::endl;
	}
	if (!m_textures["Chest"].loadFromFile("./Assets/Items/chest.png")) {
		std::cout << "Can't load chest texture" << std::endl;
	}
	if (!m_textures["Floor"].loadFromFile("./Assets/Environment/tiles.png")) {
		std::cout << "Can't load floor texture" << std::endl;
	}
	if (!m_textures["Trap"].loadFromFile("./Assets/Environment/trap.png")) {
		std::cout << "Can't load trap texture" << std::endl;
	}

	// PLAYER
	if (!m_textures["PlayIdle"].loadFromFile("./Assets/Player/idle.png")) {
		std::cout << "Can't load player idle texture" << std::endl;
	}
	if (!m_textures["PlayAttack"].loadFromFile("./Assets/Player/attack.png")) {
		std::cout << "Can't load player attack texture" << std::endl;
	}
	if (!m_textures["PlayInteract"].loadFromFile("./Assets/Player/interact.png")) {
		std::cout << "Can't load player interact texture" << std::endl;
	}
	if (!m_textures["PlayWalk"].loadFromFile("./Assets/Player/walk.png")) {
		std::cout << "Can't load player walk texture" << std::endl;
	}
	if (!m_textures["PlayWoodAxeAttack"].loadFromFile("./Assets/Player/attackAxe.png")) {
		std::cout << "Can't load player axe attack texture" << std::endl;
	}
	if (!m_textures["PlayWoodAxeIdle"].loadFromFile("./Assets/Player/idleAxe.png")) {
		std::cout << "Can't load player axe idle texture" << std::endl;
	}
	if (!m_textures["PlayWoodAxeWalk"].loadFromFile("./Assets/Player/walkAxe.png")) {
		std::cout << "Can't load player axe walk texture" << std::endl;
	}

	// INVENTORY
	if (!m_textures["ToolBar"].loadFromFile("./Assets/Inventory/toolBar.png")) {
		std::cout << "Can't load toolbar texture" << std::endl;
	}
	if (!m_textures["Inventory"].loadFromFile("./Assets/Inventory/inventory.png")) {
		std::cout << "Can't load inventory texture" << std::endl;
	}
	if (!m_textures["SelectedItem"].loadFromFile("./Assets/Inventory/selectItem.png")) {
		std::cout << "Can't load selected item texture" << std::endl;
	}
	if (!m_textures["CraftBackground"].loadFromFile("./Assets/Craft/backgroundCraft.png")) {
		std::cout << "Can't load selected craft background texture" << std::endl;
	}

	// ITEMS
	if (!m_textures["WoodAxe"].loadFromFile("./Assets/Tools/axeWood.png")) {
		std::cout << "Can't load axe texture" << std::endl;
	}
	if (!m_textures["WoodLog"].loadFromFile("./Assets/Items/log.png")) {
		std::cout << "Can't load log texture" << std::endl;
	}
	if (!m_textures["RockItem"].loadFromFile("./Assets/Items/rock.png")) {
		std::cout << "Can't load rock item texture" << std::endl;
	}
	if (!m_textures["TrapItem"].loadFromFile("./Assets/Items/trap.png")) {
		std::cout << "Can't load trap item texture" << std::endl;
	}
}

TextureLoader* TextureLoader::GetInstance()
{
	if (textureLoader == nullptr) {
		textureLoader = new TextureLoader();
	}
	return textureLoader;
}