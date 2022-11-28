
#include <HAPI_lib.h>
#include <vector>
#include <string>
#include "Visualisation.h"
#include "Player.h"

#include "Rectangle.h"
#include "World.h"
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
	World world;

	
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();

	Rectangle screenRect(0, width, 0, height);

	while (HAPI.Update() == true) //This is the whole game
	{

	}
}