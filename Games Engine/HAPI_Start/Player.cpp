#include "Player.h"
#include "Visualisation.h"
void Player::Update()
{
	
	//this->Movement(const HAPI_TKeyboardData &keyData, int width, int height);
}

void Player::Movement(const HAPI_TKeyboardData& keyData, int width, int height)
{
	m_velocity.x = 0;
	m_velocity.y = 0;
	if (keyData.scanCode['A'])
	{
		m_velocity.x -= speed;
	}
	if (keyData.scanCode['D'])
	{
		m_velocity.x += speed;
	}
	if (keyData.scanCode['W'])
	{
		m_velocity.y -= speed;
	}
	if (keyData.scanCode['S'])
	{
		m_velocity.y += speed;
	}

	if (m_velocity.x != 0 && m_velocity.y != 0)
	{
		m_velocity.x *= 0.7071f;
		m_velocity.y *= 0.7071f;
	}

	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;
	return;
}