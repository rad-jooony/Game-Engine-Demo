#pragma once
#include "HAPI_lib.h"
#include "Visualisation.h"
#include "Rectangle.h"

using namespace HAPISPACE;
class Sprite
{
private:

	bool m_hasAlpha{ false };
	BYTE* m_texture{ nullptr };
	int m_texWidth;
	int m_texHeight;
	Rectangle m_textureRect;
public:

	bool Load(const std::string& filename, bool hasAlpha);
	void Draw(BYTE* screen, const Rectangle& screenRect, int posX, int posY, int frameNumber = 0);
	void BlitFast(BYTE* screen, BYTE* texture, const Rectangle& screenRect, const Rectangle& textureRect, int posX, int posY);
	void BlitTransparency(BYTE* screen, BYTE* texture, const Rectangle& screenRect, const Rectangle& textureRect, int posX, int posY);

	~Sprite();
};

