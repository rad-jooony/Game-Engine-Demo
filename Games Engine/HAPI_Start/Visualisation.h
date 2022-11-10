#pragma once
#include <string>
#include <unordered_map>
#include "HAPI_lib.h"
using namespace HAPISPACE;

class Sprite;

class Visualisation
{
private:
	BYTE* m_screen{ nullptr }; //TODO figure out how to have the screenpointer here
	std::unordered_map<std::string, Sprite*> m_spriteMap;
public:
	Visualisation(BYTE* screen);

	// Loads the sprite from files. Needs to be given a name, followed by the file location and whether or not there are active alpha channels
	bool CreateSprite(std::string spriteName, const std::string& filename, bool hasAlpha);

	// Draws the sprite at a point on screen. animation frame number is an optional input.
	void DrawSprite(const std::string& spriteName, int screenWidth, int posX, int posY, int frameNumber = 0);

	// Clear's the screen to gray
	void clearScreenToGray(int screenWidth, int screenHeight);

	~Visualisation()
	{
		//for (Sprite : m_spriteMap)
		//delete m_spritemap
	}
};

