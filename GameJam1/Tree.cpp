#include "Tree.h"


Tree::Tree(TreeType treeType, int position) : Natural(DefaultEnvironmentElementBuilder()
	.setPosition(position)
	.setWidth(1)
	.setTexture("./Assets/tree.png")
	.build()), m_type(treeType)
{
	this->setSize(250, TILE_HEIGHT);
	m_animation = &DefaultAnimableBuilder().setFrameRate(1.0f).setTotalFrame(1).setTexture("./Assets/tree.png").build();
	m_animation->moveTo(m_realPosition);
};


void Tree::draw(sf::RenderWindow& window) const {
	EnvironmentElement::draw(window);
	this->drawColliderBox(window);
}