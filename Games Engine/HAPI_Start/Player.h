#pragma once
#include "HAPI_lib.h"
#include <string>
using namespace HAPISPACE;

struct float2
{
	float x, y;
};

class Player
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
	void DrawPlayer();
	void updatePlayerMovement(HAPI_TKeyboardData& keyData);

};
//TODO all of this
