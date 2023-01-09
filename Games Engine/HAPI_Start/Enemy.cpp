#include "Enemy.h"

void Enemy::Update()
{
	this->Movement();
	this->Shoot();
}

void Enemy::Movement()
{
	//dont go too far towards the player, maintain distance
	//try keep away from allies, so they're not bunched up
	//pick a direction, go that way for a while
}

void Enemy::Shoot()
{
	// if player is in area of danger, shoot
	// area of danger is decided by a rectangle extended out from the enemy to the edge of the screen
}