#include "Bullet.h"

void Bullet::Update(World& world)
{
	this->Movement(world);
}

void Bullet::Movement(World& world)
{
	p_position += p_velocity * p_speed;
}

