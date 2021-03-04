#include "./../../header/Inventory/Craftable.h"

bool Craftable::checkItems(std::vector<std::string> itemNames) {
	for (int i = 0; i < m_craftList.size(); i++) {
		bool res = false;
		for (int j = 0; j < itemNames.size(); j++) {
			if (m_craftList[i] == itemNames[j]) {
				res = true;
				break;
			}
		}
		if (!res) {
			return false;
		}
	}
	return true;
}