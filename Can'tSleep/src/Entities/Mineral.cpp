#include "./../../header/Entities/Mineral.h"

Mineral::Mineral(MineralType mineralType, int position) : Natural(DefaultEnvironmentElementBuilder()
	.setPosition(position)
	.setWidth(1)
	.setTexture("Rock")
	.build()), m_type(mineralType)
{
	m_animation = &DefaultAnimableBuilder()
		.setFrameRate(1.0f)
		.setTotalFrame(1)
		.setTexture("Rock")
		.setHeight(241)
		.setWidth(300)
		.build();
	m_animation->moveTo(m_realPosition);
	m_animation->setOffsetY(10);
	m_hitBox.setSize(230, 210);
	m_hitBox.setPosition(m_realPosition - m_hitBox.getWidth() / 2, -m_hitBox.getHeight());
	m_dropedItem.push_back(new DropedItem(new RockItem(), m_realPosition - m_hitBox.getWidth() / 2));
	m_dropedItem.push_back(new DropedItem(new RockItem(), m_realPosition - m_hitBox.getWidth() / 2));
	m_dropedItem.push_back(new DropedItem(new RockItem(), m_realPosition - m_hitBox.getWidth() / 2));
};
