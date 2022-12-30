#include <HAPI_lib.h>
#include <vector>
#include <string>
#include "World.h"
#include "Visualisation.h"
#include "Player.h"
#include "Rectangle.h"
#include "TempEntity.h"

int height{ 768 }; //figure something else out
int width{ 1024 }; //these are a bit awkward here

void World::Run(Visualisation* vis)
{

	Rectangle screenRect(0, width, 0, height); // Add this?
	while (HAPI.Update() == true) //This is the whole game
	{
		vis->clearScreenToGray(screenRect.Width(), screenRect.Height());

		for (Entity* entity : m_entities)
		{
				entity->Render(vis);
				entity->Update();
		}
		
	}
	for (int i = 0; i < m_entities.size(); i++)
		delete m_entities[i];
}

void World::Load(Visualisation* vis)
{
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& contData = HAPI.GetControllerData(0);
	
	vis->CreateSprite("backgroundSprite", "Data\\background.tga", false);
	vis->CreateSprite("alphaSprite", "Data\\alphaThing.tga", true);
	vis->CreateSprite("playerSprite", "Data\\playerSprite.tga", true);

	Player* player = new Player;
	player->linkSprite("playerSprite");
	m_entities.push_back(player);

	for (int i = 0; i < 20; i++)
	{
		TempEntity* alpha = new TempEntity;
		alpha->linkSprite("alphaSprite");
		m_entities.push_back(alpha);
		alpha->setPosition(Vector2(i * 10, i * 10));
	}
	vis->ScreenSetup();
}
