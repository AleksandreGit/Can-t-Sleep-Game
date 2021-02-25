#pragma once
#include "Item.h"

class Craftable : public Item
{
public:
	Craftable();
	bool checkItems(std::vector<std::string> itemNames);

protected:
	std::vector<std::string> m_craftList;
};

