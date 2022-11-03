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
	void Draw(BYTE* screen, int x, int y, int frameNumber=0);
};

