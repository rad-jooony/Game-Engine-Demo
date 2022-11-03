#pragma once
#include <string>
#include <unordered_map>
#include "HAPI_lib.h"
using namespace HAPISPACE;

class Sprite;

class Visualisation
{
private:
	BYTE* m_screen{ nullptr };
	std::unordered_map<std::string, Sprite*> m_spriteMap;
public:
	// Loads the sprite from files. Needs to be given a name, followed by the file location and whether or not there are active alpha channels
	bool CreateSprite(std::string spriteName, const std::string& filename, bool hasAlpha);

	// Draws the sprite at a point on screen. animation frame number is an optional input.
	void DrawSprite(const std::string& spriteName, int x, int y, int frameNumber = 0);

	// Clear's the screen to gray
	void clearScreenToGray(BYTE* screen, int screenWidth, int screenHeight);

	// maybe move these to the sprite draw function?
	void BlitFast(BYTE* screen, int screenWidth, BYTE* texture, int texWidth, int texHeight, int posX, int posY);
	void BlitTransparency(BYTE* screen, int screenWidth, BYTE* texture, int texHeight, int texWidth, int posX, int posY);
};

