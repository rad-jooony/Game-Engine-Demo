#pragma once
#include <string>
#include <unordered_map>
#include "HAPI_lib.h"
using namespace HAPISPACE;

class Sprite;

class Visualisation
{
private:
	//BYTE* m_screen{ nullptr };
	//std::unordered_map<std::string, Sprite*> m_spriteMap;
public:
	//bool CreateSprite(std::string spriteName,
	//	const std::string& filename);
	//void DrawSprite(const std::string& spriteName, int x, int y, int frameNumber = 0);

	void clearScreenGray(BYTE* screen, int screenWidth, int screenHeight);
};

