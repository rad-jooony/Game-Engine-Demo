#pragma once
#include <string>
#include <unordered_map>
#include "HAPI_lib.h"
#include "Rectangle.h"

/*

*/


using namespace HAPISPACE;

class Sprite;

class Visualisation
{
private:
	int m_screenWidth{ 1024 };
	int m_screenHeight{ 768 };
	BYTE* m_screen{ nullptr };
	std::unordered_map<std::string, Sprite*> m_spriteMap;
	Rectangle m_screenRect;
public:
	Visualisation();
	~Visualisation();

	bool ScreenSetup();

	int returnScreenWidth() { return m_screenWidth; };
	int returnScreenHeight() { return m_screenHeight; };

	// Loads the sprite from files. Needs to be given a name, followed by the file location and whether or not there are active alpha channels
	bool CreateSprite(std::string spriteName, const std::string& filename, bool hasAlpha);

	// Draws the sprite at a point on screen. animation frame number is an optional input.
	void DrawSprite(const std::string& spriteName, Vector2 position, int frameNumber = 0);

	Rectangle GetSpriteRectangle(const std::string& spriteName);
	// Clear's the screen to gray
	void clearScreenToGray(int screenWidth, int screenHeight);
};

