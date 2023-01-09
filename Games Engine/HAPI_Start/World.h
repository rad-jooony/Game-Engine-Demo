#pragma once
#include <vector>

// The World class holds the game loop, and is where most other elements of the game are held, such as entities

class Entity; //a prototype of the entity class is needed to create the entity vector
class Visualisation;
class World
{
private:
	std::vector<Entity*> m_entities;
	int m_bulletsStart;
public:
	//World();
	~World()
	{
		//for (Entity* entities : m_entities)
		//	delete entities;
	}

	void Run(Visualisation* vis);
	void Load(Visualisation* vis);
	void Shoot(Entity* shooter);
};

