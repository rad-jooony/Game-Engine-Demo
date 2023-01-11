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
	double m_lastShot = 0;
protected:
	Vector2 p_firePoint{ -3, 30 }; //this should be around the area of the gun's barrel. this could be made dynamically using the sprites hitbox, for example.
public:

	void Update(World& world) override final;
	void Movement(World& world) override final;
	Vector2 GetFirePoint() { return p_firePoint; };
	EFaction GetFaction() override final { return EFaction::ePlayer; };

};
