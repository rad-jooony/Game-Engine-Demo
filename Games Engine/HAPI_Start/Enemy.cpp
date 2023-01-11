#include "Enemy.h"

void Enemy::Update(World& world)
{
	this->Movement(world);

	if (m_lastShot < HAPI.GetTime() - 1000)
	{
		if (world.AIShoot(this, p_firePoint))
			m_lastShot = HAPI.GetTime();
	}
}

void Enemy::Movement(World& world)
{
	//dont go too far towards the player, maintain distance
	//try keep away from allies, so they're not bunched up
	//pick a direction, go that way for a while
}

void Enemy::Shoot(World& world)
{
	// AI shoot in world.cpp exists
}