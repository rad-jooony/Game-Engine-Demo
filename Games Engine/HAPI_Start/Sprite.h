#pragma once
#include "HAPI_lib.h"
#include "Visualisation.h"
#include "Rectangle.h"

/*
The sprite class holds sprite information and handles the loading and drawing of textures
It works in tandem with the Visualisation class, but is not directly interacted with unlike the Visualisation class
*/

using namespace HAPISPACE;
class Sprite
{
private:

	BYTE* m_texture{ nullptr };

	bool m_hasAlpha{ false };
	int m_texWidth;
	int m_texHeight;

	Rectangle m_textureRect; // it uses the support Rectangle class to create a box that represents the size of the texture, this is used for clipping
public:
	~Sprite() { delete m_texture; };
	bool Load(const std::string& filename, bool hasAlpha);
	void Draw(BYTE* screen, const Rectangle& screenRect, Vector2 position, int frameNumber = 0);

	// BlitFast is a function that draws without concerning itself with checking for Alpha values
	void BlitFast(BYTE* screen, BYTE* texture, const Rectangle& screenRect, const Rectangle& textureRect, Vector2 position);

	// BlitTransparency is used for drawing sprites with transparent values. It is slower than BlitFast
	void BlitTransparency(BYTE* screen, BYTE* texture, const Rectangle& screenRect, const Rectangle& textureRect, Vector2 position);

};

