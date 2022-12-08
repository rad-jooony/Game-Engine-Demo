#include "Entity.h"

void Entity::Render(Visualisation* vis)
{
	vis->DrawSprite(texture_ID, m_posX, m_posY);
}

void Entity::linkSprite(std::string spriteName)
{
	 texture_ID = spriteName;
}
