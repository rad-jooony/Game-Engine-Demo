#include "World.h"
#include "Player.h"

void World::Run()
{
	Visualisation vis;
	// TODO

}

void World::LoadLevel()
{
	Player* newPlayer = new Player();

	//m_entities.push_back(newPlayer);

	/*
	 for  (size_t i=0; i < VALUE; i++)
		someEntity newEntity = new someEntity;
		m_entities.pushback(newEntity);
	*/
}

void World::Update()
{
	for (Entity* entity : m_entities)
		entity->Update();
}
