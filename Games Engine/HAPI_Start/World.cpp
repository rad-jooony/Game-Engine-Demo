#include <HAPI_lib.h>
#include <vector>
#include <string>
#include "World.h"
#include "Visualisation.h"
#include "Player.h"
#include "Rectangle.h"

int height{ 768 }; //figure something else out
int width{ 1024 }; //these are a bit awkward here

void World::Run()
{
	Rectangle screenRect(0, width, 0, height);
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& contData = HAPI.GetControllerData(0); // Add this?

	Visualisation* vis = new Visualisation();
	vis->ScreenSetup();

	Player* player = new Player;
	vis->CreateSprite("backgroundSprite", "Data\\background.tga", false);
	vis->CreateSprite("alphaSprite", "Data\\alphaThing.tga", true);
	vis->CreateSprite("playerSprite", "Data\\playerSprite.tga", true);

	while (HAPI.Update() == true) //This is the whole game
	{
		vis->clearScreenToGray(screenRect.Width(), screenRect.Height());
		vis->DrawSprite("backgroundSprite", -40, -40);
		vis->DrawSprite("alphaSprite", 200, 200);
		vis->DrawSprite("playerSprite", player->GetPlayerPositionX(), player->GetPlayerPositionY());
		player->Movement(keyData, screenRect.Width(), screenRect.Height());
	}
	delete vis;
	delete player;
}

//void World::LoadLevel()
//{
//	Player* newPlayer = new Player();
//
//	//m_entities.push_back(newPlayer);
//
//	/*
//	 for  (size_t i=0; i < VALUE; i++)
//		someEntity newEntity = new someEntity;
//		m_entities.pushback(newEntity);
//	*/
//}

//void World::Update()
//{
//	for (Entity* entity : m_entities)
//		entity->Update();
//}
