#include "Player.h"

void Player::updatePlayerMovement(HAPI_TKeyboardData& keyData)
{
	if (keyData.scanCode['A'] && m_position.x > 0)
{
	m_velocity.x -= speed;
}
if (keyData.scanCode['D'] && m_position.x + m_texWidth < width)
{
	m_velocity.x += speed;
}
if (keyData.scanCode['W'] && m_position.y > 0)
{
	M_velocity.y -= speed;
}
if (keyData.scanCode['S'] && m_position.y + m_texHeight < height)
{
	m_velocity.y += speed;
}

if (m_velocity.x != 0 && m_velocity.y != 0)
{
	m_velocity.x *= 0.7071f;
	m_velocity.y *= 0.7071f;
}

spritePos.x += m_velocity.x;
spritePos.y += m_velocity.y;
}
