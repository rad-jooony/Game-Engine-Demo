#pragma once
#include <vector>
#include "Vector2.h"
#include "DeltaTime.h"
// The World class holds the game loop, and is where most other elements of the game are held, such as entities

class Entity; //a prototype of the entity class is needed to create the entity vector
class Visualisation;
class World
{
private:
	std::vector<Entity*> m_entities;
	int m_playerStart = 0;
	int m_bulletStart = 0;
	int m_enemyStart = 0;
	int m_level = 0;
public:

	bool AIShoot(Entity* AI, Vector2 firepoint);
	void Run(Visualisation* vis, World& world);
	void Load(Visualisation* vis);
	void NextLevel(Visualisation* vis);
	void Shoot(Entity* shooter, Vector2 firePoint);
};

