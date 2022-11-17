
#include <HAPI_lib.h>
#include <vector>
#include <string>
#include "Visualisation.h"
#include "Player.h"
#include "Rectangle.h"

using namespace HAPISPACE; // HAPI itself is wrapped in the HAPISPACE namespace
#define CAUGHT std::cout<<"CAUGHT!"<<std::endl
#define LOG(X) std::cout<<X<<std::endl

HAPI_TColour Orange(255, 128, 0);
HAPI_TColour Gray(128, 128, 128);
int height{ 1024 };
int width{ 768 };
void HAPI_Main()
{
	//int height = vis->returnScreenHeight();
	//int width = vis->returnScreenWidth();

	if (!HAPI.Initialise(width, height, "jooony's Demo"))
		return;
	Visualisation* vis = new Visualisation(HAPI.GetScreenPointer(), width, height);

	HAPI.SetShowFPS(true);
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();

	Rectangle screenRect(0, width, 0, height);
	// TODO m_texwidth/height dont get assigned anything
	vis->CreateSprite("backgroundTexture", "Data/background.tga", false);
	vis->CreateSprite("alphaTexture", "Data/alphaThing.tga", true);
	vis->CreateSprite("PlayerTexture", "Data/playerSprite.tga", true);
	Player* player = new Player("PlayerTexture");

	while (HAPI.Update() == true) //This is the whole game
	{
		vis->clearScreenToGray(width, height); // Calling screen refresh function
		vis->DrawSprite("backgroundTexture", width, 0, 0);
		vis->DrawSprite("alphaTexture", width, 100, -10);
		vis->DrawSprite("PlayerTexture", width, player->GetPlayerPositionX(), player->GetPlayerPositionY());
		player->UpdatePlayerMovement(keyData, width, height);
	}
	delete vis;
}