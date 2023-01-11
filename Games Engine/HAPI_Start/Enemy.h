#include "HAPI_lib.h"
#include "Entity.h"
#include <string>
#include "Sprite.h"
#include "Vector2.h"

#pragma once
class Enemy
	: public Entity
{
private:

private:
	Vector2 p_firePoint{ 129, 32 }; //this should be around the area of the gun's barrel. this could be made dynamically using the sprites hitbox, for example.
	double m_lastShot = 0;
public:
	void Update(World& world) override final;
	void Movement(World& world) override final;
	EFaction GetFaction() override final { return EFaction::eEnemy; };

	void Shoot(World& world);

	Vector2 GetFirePoint() { return p_firePoint; };
};

