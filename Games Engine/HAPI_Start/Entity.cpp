#include "Entity.h"

void Entity::Render(Visualisation* vis)
{
	vis->DrawSprite(texture_ID, p_position);
}

void Entity::linkSprite(std::string spriteName)
{
	texture_ID = spriteName;
}

void Entity::CreateHitbox(Visualisation* vis)
{
	Rectangle rectangle = vis->GetSpriteRectangle(texture_ID);
	// OPTION: Enlarge the hitbox by 10% making it feel more fair, the player will not miss whenever they feel like they should've hit.
	// This also means re-aligning the hitbox to be centre of the sprite. The change in size half, to move up and left
	//rectangle.right *= 1.1f;
	//rectangle.bottom *= 1.1f; 

	p_colliderBox = rectangle;
}

void Entity::SetVelocity(Vector2 velocity)
{
	p_velocity = velocity;
}

void Entity::SetPosition(Vector2 position)
{
	p_position = position;
}

bool Entity::CheckCollison(Entity& other)
{

	p_colliderBox.Translate(p_position);
	other.p_colliderBox.Translate(other.p_position);

	if (p_colliderBox.left < other.p_colliderBox.right &&
		p_colliderBox.right > other.p_colliderBox.left &&
		p_colliderBox.top < other.p_colliderBox.bottom &&
		p_colliderBox.bottom > other.p_colliderBox.top)
	{
		p_colliderBox.Translate(-p_position);
		other.p_colliderBox.Translate(-other.p_position);
		return true;
	}
	else
	{
		p_colliderBox.Translate(-p_position);
		other.p_colliderBox.Translate(-other.p_position);
		return false;
	}
}

void Entity::SetAlive(bool state)
{
	p_alive = state;
}