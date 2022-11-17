
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

void HAPI_Main()
{
	//int height = vis->returnScreenHeight();
	//int width = vis->returnScreenWidth();
	int height{ 1024 };
	int width{ 768 };
	if (!HAPI.Initialise(width, height, "jooony's Demo"))
		return;
	Visualisation* vis = new Visualisation(HAPI.GetScreenPointer());

	HAPI.SetShowFPS(true);
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();

	Rectangle screenRect(0, width, 0, height);

	vis->CreateSprite("backgroundTexture", "Data/background.tga", false);
	vis->CreateSprite("alphaTexture", "Data/alphaThing.tga", true);
	vis->CreateSprite("PlayerTexture", "Data/playerSprite.tga", true);
	Player* player = new Player("PlayerTexture");
	

	float speed{ 0.5f };

	while (HAPI.Update() == true) //This is the whole game
	{
		vis->clearScreenToGray(width, height); // Calling screen refresh function
		vis->DrawSprite("backgroundTexture", width, 0, 0);
		vis->DrawSprite("alphaTexture", width, 200,-50);
		vis->DrawSprite("PlayerTexture", width, player->GetPlayerPositionX(), player->GetPlayerPositionY()); //TODO: intergrate the player to the texture
		//player->UpdatePlayerMovement(keyData, width, height); //TODO figure oput why thes function works differently in the class

		//int2 velocity{ 0,0 };
		//if (keyData.scanCode['A'] && spritePos.x > 0)
		//{
		//	velocity.x -= speed;
		//}
		//if (keyData.scanCode['D'] && spritePos.x + texWidth < width)
		//{
		//	velocity.x += speed;
		//}
		//if (keyData.scanCode['W'] && spritePos.y > 0)
		//{
		//	velocity.y -= speed;
		//}
		//if (keyData.scanCode['S'] && spritePos.y + texHeight < height)
		//{
		//	velocity.y += speed;
		//}

		//if (velocity.x != 0 && velocity.y != 0)
		//{
		//	velocity.x *= 0.7071f;
		//	velocity.y *= 0.7071f;
		//}

		//spritePos.x += velocity.x;
		//spritePos.y += velocity.y;
	}
	//delete[] backtexture;
	//delete[] texture;
	delete vis;
}