#include "Player.h"
#include "Visualisation.h"
void Player::Update()
{
	this->Movement();
}

void Player::Movement()
{
	p_velocity.x = 0;
	p_velocity.y = 0;
	if (m_keyData.scanCode['A'])
	{
		p_velocity.x -= p_speed;
	}
	if (m_keyData.scanCode['D'])
	{
		p_velocity.x += p_speed;
	}
	if (m_keyData.scanCode['W'])
	{
		p_velocity.y -= p_speed;
	}
	if (m_keyData.scanCode['S'])
	{
		p_velocity.y += p_speed;
	}

	// so diagonal movement is not faster than up/down, left/right
	if (p_velocity.x != 0 && p_velocity.y != 0)
	{
		p_velocity.x *= 0.7071f; //this number is a result of normalising diagonal movement
		p_velocity.y *= 0.7071f;
	}
	p_position += p_velocity; // * deltaTime;

	return;
}

void Player::Shoot()
{
}

	