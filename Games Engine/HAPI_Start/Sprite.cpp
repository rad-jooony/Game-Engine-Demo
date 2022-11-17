#include "Sprite.h"

bool Sprite::Load(const std::string& filename, bool hasAlpha)
{
	m_hasAlpha = hasAlpha;

	if (HAPI.LoadTexture(filename, &m_texture, m_texWidth, m_texHeight))
	{
		m_textureRect = Rectangle(0, m_texWidth, 0, m_texHeight);
		return true;
	}
}

void Sprite::Draw(BYTE* screen, const Rectangle& screenRect, int posX, int posY, int frameNumber)
{
	if (m_hasAlpha)
	{
		this->BlitTransparency(screen, m_texture, screenRect, m_textureRect, posX, posY);
	}
	else
	{
		this->BlitFast(screen, m_texture, screenRect, m_textureRect, posX, posY);
	}
}

void Sprite::BlitFast(BYTE* screen, BYTE* texture, const Rectangle& screenRect, const Rectangle& textureRect, int posX, int posY)
{
	int screenOffset = (posX + posY * screenRect.Width()) * 4;
	int textureOffset = 0;

	for (int y = 0; y < textureRect.Height(); y++)
	{
		memcpy(screen + screenOffset,
			texture + textureOffset, textureRect.Width() * 4);

		screenOffset += screenRect.Width() * 4;
		textureOffset += textureRect.Width() * 4;
	}
};

void Sprite::BlitTransparency(BYTE* screen, BYTE* texture, const Rectangle& screenRect, const Rectangle& textureRect, int posX, int posY)
{
	Rectangle clippedRect(textureRect);
	clippedRect.Translate(posX, posY);
	clippedRect.ClipTo(screenRect);
	clippedRect.Translate(-posX, -posY);
	screenRect.Width();

	int screenOffset = (posX + posY * screenRect.Width()) * 4;
	int endOfLineOffest = (screenRect.Width() - textureRect.Width()) * 4;

	for (int y = 0; y < textureRect.Height(); y++)
	{
		for (int x = 0; x < textureRect.Width(); x++)
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
