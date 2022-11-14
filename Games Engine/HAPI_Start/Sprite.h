#pragma once
#include "HAPI_lib.h"
using namespace HAPISPACE;

class Sprite
{
private:
	int m_texWidth, m_texHeight;
	bool m_hasAlpha{ false };
	BYTE* m_texture{ nullptr };
public:
	bool Load(const std::string& filename, bool hasAlpha);
	void Draw(BYTE* screen, int screenWidth, int x, int y, int frameNumber=0);
	void BlitFast(BYTE* screen, int screenWidth, BYTE* texture, int texWidth, int texHeight, int posX, int posY);
	void BlitTransparency(BYTE* screen, int screenWidth, BYTE* texture, int texHeight, int texWidth, int posX, int posY);

	~Sprite();
};

