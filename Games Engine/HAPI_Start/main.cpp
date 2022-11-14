
#include <HAPI_lib.h>
#include <vector>
#include <string>
#include "Visualisation.h"

using namespace HAPISPACE; // HAPI itself is wrapped in the HAPISPACE namespace
#define CAUGHT std::cout<<"CAUGHT!"<<std::endl
#define LOG(X) std::cout<<X<<std::endl

HAPI_TColour Orange(255, 128, 0);
HAPI_TColour Gray(128, 128, 128);


void Tempcode() //code that might be good to hold onto for now
{

	//int offset = (position[0] + position[1] * width) * 4;
	//memcpy(screen + offset, &fillColour, 4);


	HAPI.RenderText(30, 30, HAPI_TColour(255, 80, 0), "Orange Text", 30);

	//memset(screen, 128, width * height * 4);
	HAPI.SetControllerRumble(0, WORD(65535), WORD(65535));

	//for (int i = 0; i < width * height; i++)
		//	{
		//		int offset = i * 4;
		//		memcpy(screen + offset, &Gray, 4);
		//	}
	//*(HAPI_TColour*)screen = Orange;
	// ^^^ ask what this does again
}

void HAPI_Main()
{
	int width{ 1024 };
	int height{ 768 };

	if (!HAPI.Initialise(width, height, "jooony's Demo"))
		return;
	Visualisation* vis = new Visualisation(HAPI.GetScreenPointer());
	HAPI.SetShowFPS(true);
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();

	//int2 spritePos{ 200, 200 };

	vis->CreateSprite("backgroundTexture", "Data/background.tga", false);
	vis->CreateSprite("alphaTexture", "Data/alphaThing.tga", true);
	vis->CreateSprite("PlayerTexture", "Data/Player.tga", true);

	std::vector<float> screenCent;
	screenCent.push_back(width / 2);
	screenCent.push_back(height / 2);

	float speed{ 0.5f };

	while (HAPI.Update() == true) //This is the whole game
	{
		vis->clearScreenToGray(width, height); // Calling screen refresh function

		vis->DrawSprite("backgroundTexture", width, 0, 0);
		vis->DrawSprite("alphaTexture", width, 0, 0);
		vis->DrawSprite("PlayerSprite", width, 0, 0);
		//player->updateMovement();

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