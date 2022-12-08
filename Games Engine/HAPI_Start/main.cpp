
#include <HAPI_lib.h>
#include <vector>
#include <string>
#include "Visualisation.h"
#include "Player.h"

#include "Rectangle.h"
#include "World.h"

using namespace HAPISPACE; // HAPI itself is wrapped in the HAPISPACE namespace
#define CAUGHT std::cout<<"CAUGHT!"<<std::endl
#define LOG(X) std::cout<<X<<std::endl

HAPI_TColour Orange(255, 128, 0);
HAPI_TColour Gray(128, 128, 128);
//int height{ 768 };
//int width{ 1024 };
void HAPI_Main()
{
	World world;
	Visualisation* vis = new Visualisation;
	world.Load(vis);

	world.Run(vis);
	delete vis;
}