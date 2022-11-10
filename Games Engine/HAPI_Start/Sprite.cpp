#include "Sprite.h"

bool Sprite::Load(const std::string& filename, bool hasAlpha)
{
	m_hasAlpha = hasAlpha;
	return HAPI.LoadTexture(filename, &m_texture, m_texWidth, m_texHeight);
}

void Sprite::Draw(BYTE* screen, int screenWidth, int x, int y, int frameNumber)
{
	if (m_hasAlpha)
	{
		this->BlitTransparency(screen, screenWidth, m_texture, m_texWidth, m_texHeight, x, y);
	}
	else
	{
		this->BlitFast(screen, screenWidth, m_texture, m_texWidth, m_texHeight, x, y);
	}
}

void Sprite::BlitFast(BYTE* screen, int screenWidth, BYTE* texture, int texWidth, int texHeight, int posX, int posY)
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

void Sprite::BlitTransparency(BYTE* screen, int screenWidth, BYTE* texture, int texHeight, int texWidth, int posX, int posY)
{
	int screenOffset = (posX + posY * screenWidth) * 4;
	int endOfLineOffest = (screenWidth - texWidth) * 4;

	for (int y = 0; y < texHeight; y++)
	{
		for (int x = 0; x < texWidth; x++)
		{
			if (texture[3] > 0)
			{
				BYTE texR = texture[0];
				BYTE texG = texture[1];
				BYTE texB = texture[2];
				BYTE texA = texture[3];
				float ratio = texA / 255.0f;

				BYTE screenR = screen[screenOffset];
				BYTE screenG = screen[screenOffset + 1];
				BYTE screenB = screen[screenOffset + 2];

				if (texture[3] == 255)
				{
					memcpy(screen + screenOffset, &HAPI_TColour(texR, texG, texB), 4);
				}
				else
				{
					BYTE finalR = (BYTE)(ratio * texR + (1.0f - ratio) * screenR);
					BYTE finalG = (BYTE)(ratio * texG + (1.0f - ratio) * screenG);
					BYTE finalB = (BYTE)(ratio * texB + (1.0f - ratio) * screenB);
					screen[screenOffset] = finalR;
					screen[screenOffset + 1] = finalG;
					screen[screenOffset + 2] = finalB;
				}
			}
			texture += 4;
			screenOffset += 4;
		}
		screenOffset += endOfLineOffest;
	}
}

Sprite::~Sprite()
{
	delete[] m_texture;
};
