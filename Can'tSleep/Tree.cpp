#include "Tree.h"


Tree::Tree(TreeType treeType, int position) : Natural(DefaultEnvironmentElementBuilder()
	.setPosition(position)
	.setWidth(1)
	.setTexture("./Assets/tree.png")
	.build()), m_type(treeType)
{
	m_animation = &DefaultAnimableBuilder()
		.setFrameRate(1.0f)
		.setTotalFrame(1)
		.setTexture("./Assets/tree.png")
		.setHeight(1677)
		.setWidth(817)
		.build();
	m_animation->moveTo(m_realPosition);
	m_animation->setOffsetY(10);
	m_hitBox.setSize(150, TILE_HEIGHT / 1.5f);
	m_hitBox.setPosition(m_realPosition - m_hitBox.getWidth() / 2, -m_hitBox.getHeight());
};


void Tree::draw(sf::RenderWindow& window) {
	EnvironmentElement::draw(window);
	debugCollision(window);
}