#include "Entity.h"

void Entity::Render(Visualisation& vis)
{
	vis.DrawSprite(m_gfxName, m_posX, m_posY);
}
