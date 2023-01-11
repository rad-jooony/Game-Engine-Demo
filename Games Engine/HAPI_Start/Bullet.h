#pragma once
#include "Entity.h"
class Bullet :
	public Entity
{
private:
	int m_damage = { 1 };
	Vector2 m_direction;
protected:
	int p_speed = 5;
public:

	void SetDamage(int val) { m_damage = val; };
	void Update(World& world) override final;
	void Movement(World& world) override final;
	//bullet needs spawnpoint, direction and Faction(player/enemy)
	// to fire loop through bullet entities
};

