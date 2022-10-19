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
#define LOG(X) std::cout<<X<<std::endl

HAPI_TColour Orange(255, 128, 0);
HAPI_TColour Gray(128, 128, 128);

void Tempcode() //code that might be good to hold onto for now
{
	// position for a one pixel position on screen
	std::vector<int>position(386, 423);

	//int offset = (position[0] + position[1] * width) * 4;
	//memcpy(screen + offset, &fillColour, 4);


	HAPI.RenderText(30, 30, HAPI_TColour(255, 80, 0), "Orange Text", 30);

	//memset(screen, 128, width * height * 4);
	HAPI.SetControllerRumble(0, WORD(65535), WORD(65535));
}

void RefreshScreen(BYTE* screen, int width, int height)
{
	memset(screen, 50, width * height * 4);
	//for (int i = 0; i < width * height; i++)
	//	{
	//		int offset = i * 4;
	//		memcpy(screen + offset, &Gray, 4);
	//	}
	//*(HAPI_TColour*)screen = Orange;
	// ^^^ ask what this does again
};

void BlitFast(BYTE* screen, int screenWidth, BYTE* texture, int texHeight, int texWidth, int posX, int posY);
void BlitTransparency(BYTE* screen, int screenWidth, BYTE* texture, int texHeight, int texWidth, int posX, int posY);

void Stars(BYTE* screen, const int stars, std::vector<float> starX, std::vector<float> starY, std::vector<float> starZ, float eyeDistance,
	int screenWidth, int screenHeight, std::vector<float> screenCent);

void HAPI_Main()
{
	int width{ 1024 };
	int height{ 768 };

	if (!HAPI.Initialise(width, height, "jooony's Demo"))
		return;

	BYTE* screen{ HAPI.GetScreenPointer() };

	HAPI.SetShowFPS(true);
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
	int posX = 100;
	int posY = 200;


	int backtexWidth, backtexHeight;
	BYTE* backtexture{ nullptr };
	if (!HAPI.LoadTexture("Data/background.tga", &backtexture, backtexWidth, backtexHeight))
	{
		HAPI.UserMessage("Could not laod texture (Background)", "Error");
		return;
	}

	int texWidth, texHeight;
	BYTE* texture{ nullptr };
	if (!HAPI.LoadTexture("Data/alphaThing.tga", &texture, texWidth, texHeight))
	{
		HAPI.UserMessage("Could not laod texture (PlayerSprite)", "Error");
		return;
	}

	// Variable for the stars, inc. number and initialising position arrays
	const int kNumStars{ 1000 };
	// std::vector<float> starPos{ 0,0,0 }; //Stars will have X, Y, and Z positions
	std::vector<float> starPosX{};
	std::vector<float> starPosY{};
	std::vector<float> starPosZ{};

	float eyeDist{ 100 }; // eye dist acts like positon of the camera or eye distance from the screen
	std::vector<float> screenCent;
	screenCent.push_back(width / 2);
	screenCent.push_back(height / 2);

	for (int i = 0; i < kNumStars; i++)
	{
		starPosX.push_back(rand() % width);
		starPosY.push_back(rand() % height);
		starPosZ.push_back(rand() % 500);
	}

	while (HAPI.Update() == true) //This is the whole game
	{
		RefreshScreen(screen, width, height); // Calling screen refresh function

		BlitFast(screen, width, backtexture, backtexWidth, backtexHeight, 0, 0);
		BlitTransparency(screen, width, texture, texWidth, texHeight, posX, posY);
		if (keyData.scanCode['A'])
			posX--;
		if (keyData.scanCode['D'])
			posX++;
		if (keyData.scanCode['W'])
			posY--;
		if (keyData.scanCode['S'])
			posY++;


		if (keyData.scanCode[HK_UP])
		{
			eyeDist++;
		}
		if (keyData.scanCode[HK_DOWN])
		{
			if (eyeDist <= 1) // Stops crashing when eyeDist goes below 0
			{
				eyeDist = 1;
				continue;
			}
			eyeDist--;
		}
		//Stars(screen, kNumStars, starPosX, starPosY, starPosZ, eyeDist, width, height, screenCent);

	}
}

// this doesn't work since being put into a function 
void Stars(BYTE* screen, const int stars, std::vector<float> starX, std::vector<float> starY, std::vector<float> starZ, float eyeDistance,
	int screenWidth, int screenHeight, std::vector<float> screenCent)
{

	int screenStar;
	std::vector<int> oldScreenStar;
	for (int i = 0; i < stars; i++)
		oldScreenStar.push_back(0); // so values are initialised
	int screenStarPosX;
	int screenStarPosY;
	for (int i = 0; i < stars; i++)
	{

		if (oldScreenStar[i] > 0 && oldScreenStar[i] < screenWidth * screenHeight * 4)
		{
			memcpy(screen + oldScreenStar[i], &Gray, 4); // star trails
		}
		//calculates the stars position on the screen
		screenStarPosX = ((eyeDistance * (starX[i] - screenCent[0])) / (eyeDistance + starZ[i])) + screenCent[0];
		screenStarPosY = ((eyeDistance * (starY[i] - screenCent[1])) / (eyeDistance + starZ[i])) + screenCent[1];
		if (screenStarPosX < 0 || screenStarPosX > screenWidth) // keeps all data changes for the screen within the array
		{
			CAUGHT;
			continue;
		}
		if (screenStarPosY < 0 || screenStarPosY > screenHeight)
		{
			CAUGHT;
			continue;
		}
		starZ[i]--;
		screenStar = (screenStarPosX + screenStarPosY * screenWidth) * 4;
		memcpy(screen + screenStar, &Orange, 4); // The stars are Orange 
		oldScreenStar[i] = screenStar;


		if (starZ[i] <= 1) // putting the stars back on screen once they reach Z = 0
		{
			starX[i] = rand() % screenWidth;
			starY[i] = rand() % screenHeight;
			starZ[i] = rand() % 500;
		}
	}

};

void BlitFast(BYTE* screen, int screenWidth, BYTE* texture, int texWidth, int texHeight, int posX, int posY)
{
	int screenOffset = (posX + posY * screenWidth) * 4;
	int textureOffset = 0;

	for (int y = 0; y < texHeight; y++)
	{
		memcpy(screen + screenOffset,
			texture + textureOffset, texWidth * 4);

		screenOffset += screenWidth * 4;
		textureOffset += texWidth * 4;
	}
};

void BlitTransparency(BYTE* screen, int screenWidth, BYTE* texture, int texHeight, int texWidth, int posX, int posY)
{
	int screenOffset = (posX + posY * screenWidth) * 4;
	int endOfLineOffest = (screenWidth - texWidth) * 4;

	for (int y = 0; y < texHeight; y++)
	{
		for (int x = 0; x < texWidth; x++)
		{
			// TODO: figure out why there's colour discrepancy
			BYTE texR = texture[0];
			BYTE texG = texture[1];
			BYTE texB = texture[2];
			BYTE texA = texture[3];
			float ratio = texA / 255.0f;

			BYTE screenR = screen[screenOffset];
			BYTE screenG = screen[screenOffset + 1];
			BYTE screenB = screen[screenOffset + 2];

			BYTE finalR = (BYTE)(ratio * texR + (1.0f - ratio) * screenR);
			BYTE finalG = (BYTE)(ratio * texG + (1.0f - ratio) * screenG);
			BYTE finalB = (BYTE)(ratio * texB + (1.0f - ratio) * screenB);


			screen[screenOffset] = finalR;
			screen[screenOffset + 1] = finalG;
			screen[screenOffset + 2] = finalG;
			texture += 4;
			screenOffset += 4;
		}
		screenOffset += endOfLineOffest;
	}
};
