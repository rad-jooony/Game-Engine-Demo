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

	EFaction m_faction = EFaction::ePlayer;
	Vector2 m_firePoint{ 129, -32 }; //this should be around the area of the gun's barrel. this could be made dynamically using the sprites hitbox, for example.
public:
	void Update() override final;
	void Movement() override final;
	void Shoot();
};

