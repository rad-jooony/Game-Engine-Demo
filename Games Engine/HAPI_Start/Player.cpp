#include "Player.h"
#include "Visualisation.h"
void Player::Update(World& world)
{
	int leftThumbX = m_contData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X];
	int leftThumbY = m_contData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y];
	bool contAttached = m_contData.isAttached;
	
	this->Movement(world);

	if ((m_keyData.scanCode[HK_SPACE] || m_contData.digitalButtons[HK_DIGITAL_A]) && m_lastShot < HAPI.GetTime() - 1000)
	{
		world.Shoot(this, p_firePoint);
		m_lastShot = HAPI.GetTime();
	}
}

void Player::Movement(World& world)
{
	p_velocity.x = 0;
	p_velocity.y = 0;
	//if (m_contData.isAttached);

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
	p_position += p_velocity; //* deltaTime

	return;
}

