#include "Bullet.h"

void Bullet::Update()
{
	this->SetDirection();
	this->Movement();
}

void Bullet::Movement()
{
	p_position += m_direction * p_speed;
}

void Bullet::SetDirection()
{
	if (m_faction == EFaction::ePlayer)
		m_direction = Vector2(-1, 0);
	else if (m_faction == EFaction::eEnemy)
		m_direction = Vector2(1, 0);
	else
		HAPI.UserMessage("Bullet Direction is unsecified", "Please specify the Bullet's faction in shoot function");
}

