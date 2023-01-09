#pragma once
#include "Entity.h"
class Bullet :
	public Entity
{
private:
	int m_damage = { 1 };
	Vector2 m_direction;
	EFaction m_faction;
protected:
	int p_speed = 20;
public:

	void SetDamage(int val) { m_damage = val; };
	void Update() override final;
	void Movement() override final;
	void SetDirection();

	//bullet needs spawnpoint, direction and Faction(player/enemy)
	// to fire loop through bullet entities
};

