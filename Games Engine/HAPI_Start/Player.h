#pragma once
#include "HAPI_lib.h"
#include "Entity.h"
#include <string>
#include "Sprite.h"
using namespace HAPISPACE;

struct float2
{
	float x, y;
};

class Player :
	public Entity
{
private:
	float2 m_position{ 0,0 };
	float speed{ 0.5f };
	float2 m_velocity{0.f, 0.f};
public:
	void Update() override final;
	void Movement(const HAPI_TKeyboardData& keyData, int width, int height);
	float Player::GetPlayerPositionX() { return m_position.x; };
	float Player::GetPlayerPositionY() { return m_position.y; };

};
