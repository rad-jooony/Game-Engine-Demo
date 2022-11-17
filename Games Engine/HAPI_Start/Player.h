#pragma once
#include "HAPI_lib.h"
#include <string>
#include "Sprite.h"
using namespace HAPISPACE;

struct float2
{
	float x, y;
};

class Player
{
private:
	float2 m_position{ 0,0 };
	float speed{ 0.1f };
	float2 m_velocity{0,0};
	std::string m_playerID;
public:
	Player::Player(std::string playerID)
	{
		m_playerID = playerID;
	};
	void Player::UpdatePlayerMovement(const HAPI_TKeyboardData& keyData, int width, int height);
	float Player::GetPlayerPositionX() { return m_position.x; };
	float Player::GetPlayerPositionY() { return m_position.y; };

};
//TODO all of this
