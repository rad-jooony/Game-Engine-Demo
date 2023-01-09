#pragma once
#include "HAPI_lib.h"
#include "Entity.h"
#include <string>
#include "Sprite.h"
#include "Vector2.h"

using namespace HAPISPACE;

class Player :
	public Entity
{
private:
	const HAPI_TKeyboardData& m_keyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& m_contData = HAPI.GetControllerData(0);
	EFaction m_faction = EFaction::ePlayer;
	Vector2 m_firePoint{ 0,-32 }; //this should be around the area of the gun's barrel. this could be made dynamically using the sprites hitbox, for example.
public:
	void Update() override final;
	void Movement() override final;
	void Shoot();
};
