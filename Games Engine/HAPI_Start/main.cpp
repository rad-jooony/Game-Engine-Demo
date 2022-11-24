
#include <HAPI_lib.h>
#include <vector>
#include <string>
#include "Visualisation.h"
#include "Player.h"
#include "Rectangle.h"
#include <cassert>
using namespace HAPISPACE; // HAPI itself is wrapped in the HAPISPACE namespace
#define CAUGHT std::cout<<"CAUGHT!"<<std::endl
#define LOG(X) std::cout<<X<<std::endl

HAPI_TColour Orange(255, 128, 0);
HAPI_TColour Gray(128, 128, 128);
int height{ 768 };
int width{ 1024 };
void HAPI_Main()
{
	//int height = vis->returnScreenHeight();
	//int width = vis->returnScreenWidth();

	if (!HAPI.Initialise(width, height, "jooony's Demo"))
		return;
	assert(HAPI.GetScreenPointer() != NULL);
	Visualisation* vis = new Visualisation(HAPI.GetScreenPointer(), width, height);

	HAPI.SetShowFPS(true);
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();

	Rectangle screenRect(0, width, 0, height);
	vis->CreateSprite("backgroundTexture", "Data/background.tga", false);
	vis->CreateSprite("alphaTexture", "Data/alphaThing.tga", true);
	vis->CreateSprite("PlayerTexture", "Data/playerSprite.tga", true);
	Player* player = new Player("PlayerTexture");

	while (HAPI.Update() == true) //This is the whole game
	{
		vis->clearScreenToGray(width, height); // Calling screen refresh function

		//vis->DrawSprite("backgroundTexture", 0, 0);
		vis->DrawSprite("backgroundTexture", player->GetPlayerPositionX(), player->GetPlayerPositionY());
		//vis->DrawSprite("alphaTexture", 100, -10);
		//vis->DrawSprite("PlayerTexture", player->GetPlayerPositionX(), player->GetPlayerPositionY());
		player->UpdatePlayerMovement(keyData, width, height);
	}
	delete vis;
}