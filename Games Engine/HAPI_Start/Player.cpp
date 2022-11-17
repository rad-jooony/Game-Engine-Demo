#include "Player.h"
#include "Sprite.h"
void Player::UpdatePlayerMovement(const HAPI_TKeyboardData& keyData, int width, int height)
{
	m_velocity.x = 0;
	m_velocity.y = 0;
	if (keyData.scanCode['A'] && m_position.x > 0)
	{
		m_velocity.x -= speed;
	}
	if (keyData.scanCode['D'] && m_position.x + 64 < width) 
	{
		m_velocity.x += speed;
	}
	if (keyData.scanCode['W'] && m_position.y > 0)
	{
		m_velocity.y -= speed;
	}
	if (keyData.scanCode['S'] && m_position.y + 64 < height)
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