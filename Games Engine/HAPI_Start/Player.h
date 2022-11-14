#pragma once
#include "HAPI_lib.h"
#include <string>
#include "Sprite.h"
using namespace HAPISPACE;

struct float2
{
	float x, y;
};

class Player :
	public Sprite
{
private:
	float2 m_position{ 0,0 };
	float speed{ 0.5f };
	float2 m_velocity{0,0};
	std::string m_playerID;
public:
	Player::Player(std::string playerID)
	{
		m_playerID = playerID;
	};
	void updatePlayerMovement(HAPI_TKeyboardData& keyData);

};
//TODO all of this
