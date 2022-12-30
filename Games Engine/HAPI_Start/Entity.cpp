#include "Entity.h"

void Entity::Render(Visualisation* vis)
{
	vis->DrawSprite(texture_ID, p_position);
}

void Entity::linkSprite(std::string spriteName)
{
	 texture_ID = spriteName;
}

void Entity::setPosition(Vector2 position)
{
	p_position = position;
}
