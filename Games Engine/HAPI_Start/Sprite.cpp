#include "Sprite.h"

bool Sprite::Load(const std::string& filename, bool hasAlpha)
{
	m_hasAlpha = hasAlpha;
	return HAPI.LoadTexture(filename, &m_texture, m_texWidth, m_texHeight);
}

void Sprite::Draw(BYTE* screen, int x, int y, int frameNumber)
{

}
