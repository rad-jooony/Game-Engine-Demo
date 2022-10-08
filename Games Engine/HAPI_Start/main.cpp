/*
	HAPI Start
	----------
	This solution contains an already set up HAPI project and this main file

	The directory structure and main files are:

	HAPI_Start - contains the Visual Studio solution file (.sln)
		HAPI_Start - contains the Visual Studio HAPI_APP project file (.vcxproj) and source code
			HAPI - the directory with all the HAPI library files
			Data - a place to put your data files with a few sample ones provided

	Additionally in the top directory there is a batch file for creating a redistributable Demo folder

	For help using HAPI please see the Reference folder in the HAPI sub-directory
*/


// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>
#include <vector>

using namespace HAPISPACE; // HAPI itself is wrapped in the HAPISPACE namespace
#define CAUGHT std::cout<<"CAUGHT!"<<std::endl

void Tempcode()
{
	// position for a one pixel position on screen

	std::vector<int>position(386, 423);
	//int offset = (position[0] + position[1] * width) * 4;
	//memcpy(screen + offset, &fillColour, 4);


	HAPI.RenderText(30, 30, HAPI_TColour(255, 80, 0), "Orange Text", 30);

	//memset(screen, 128, width * height * 4);
	HAPI.SetControllerRumble(0, WORD(65535), WORD(65535));
}

// Every HAPI program has a HAPI_Main as an entry point
// When this function exits the program will close down

void RefreshScreen(BYTE* screen, int width, int height)
{
	memset(screen, 0, width * height * 4);
	//for (int i = 0; i < width * height; i++)
	//	{
	//		int offset = i * 4;
	//		memcpy(screen + offset, &Gray, 4);
	//	}
	//*(HAPI_TColour*)screen = Orange;
	// ^^^ ask what this does again
};

void HAPI_Main()
{
	int width{ 1024 };
	int height{ 768 };

	if (!HAPI.Initialise(width, height, "jooony's Demo"))
		return;

	BYTE* screen{ HAPI.GetScreenPointer() };
	HAPI_TColour Orange(255, 128, 0);
	HAPI_TColour Gray(128, 128, 128);
	HAPI.SetShowFPS(true);
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
	const int kNumStars{ 1000 };
	// std::vector<float> starPos{ 0,0,0 }; //Stars will have X, Y, and Z positions
	float starPosX[kNumStars];
	float starPosY[kNumStars];
	float starPosZ[kNumStars];

	float eyeDist{ 100 };
	const float screenCent[2]{ width / 2,height / 2 };
	for (int i = 0; i < kNumStars; i++)
	{
		starPosX[i] = rand() % width;
		starPosY[i] = rand() % height;
		starPosZ[i] = rand() % 500;
	}
	while (HAPI.Update() == true) //This is the whole game
	{
		RefreshScreen(screen, width, height);
		// This segment of code will create stars and project them toward the viewer
		if (keyData.scanCode[HK_UP])
		{
			eyeDist++;
		}
		if (keyData.scanCode[HK_DOWN])
		{
			if (eyeDist <= 1)
				continue;
			eyeDist--;
		}

		int screenStarPosX;
		int screenStarPosY;
		for (int i = 0; i < kNumStars; i++)
		{
			screenStarPosX = ((eyeDist * (starPosX[i] - screenCent[0])) / (eyeDist + starPosZ[i])) + screenCent[0];
			screenStarPosY = ((eyeDist * (starPosY[i] - screenCent[1])) / (eyeDist + starPosZ[i])) + screenCent[1];
			if (screenStarPosX < 0 || screenStarPosX > width)
			{
				CAUGHT;
				continue;
			}
			if (screenStarPosY < 0 || screenStarPosY > height)
			{
				CAUGHT;
				continue;
			}

			starPosZ[i]--;
			int screenStar = (screenStarPosX + screenStarPosY * width) * 4;
			memcpy(screen + screenStar, &Orange, 4);

			if (starPosZ[i] <= 1)
			{
				starPosX[i] = rand() % width;
				starPosY[i] = rand() % height;
				starPosZ[i] = rand() % 500;
			}
		}
	}
}

