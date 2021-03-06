#pragma once

#include "Natural.h"
#include "TreeType.h"
#include "DefaultEnvironmentElementBuilder.h"
#include "./../Inventory/WoodLog.h"

class Tree : public Natural {
public :
	Tree() = default;
	Tree(TreeType treeType, int position);
private:
	TreeType m_type;
};

