#include "Tree.h"


Tree::Tree(TreeType treeType, int position) : Natural(DefaultEnvironmentElementBuilder()
	.setPosition(position)
	.setWidth(1)
	.setTexture(".Assets/tree.png")
	.build()), m_type(treeType)
{
};