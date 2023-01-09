#include "Sprite.h"
#include <cassert>
#include "Vector2.h"
bool Sprite::Load(const std::string& filename, bool hasAlpha)
{
	if (HAPI.LoadTexture(filename, &m_texture, m_texWidth, m_texHeight))
	{
		m_hasAlpha = hasAlpha;
		m_textureRect = Rectangle(0, m_texWidth, 0, m_texHeight);
		return true;
	}
	return false;
}

void Sprite::Draw(BYTE* screen, const Rectangle& screenRect, Vector2 position, int frameNumber)
{
	assert(screen != nullptr);
	if (m_hasAlpha)
	{
		this->BlitTransparency(screen, m_texture, screenRect, m_textureRect, position);
	}
	else
	{
		this->BlitFast(screen, m_texture, screenRect, m_textureRect, position);
	}
}

void Sprite::BlitFast(BYTE* screen, BYTE* texture, const Rectangle& screenRect, const Rectangle& textureRect, Vector2 position)
{
	Rectangle clippedRect(textureRect);
	clippedRect.Translate(position); // transform the source to the screen space
	clippedRect.ClipTo(screenRect); // apply clipping to the screeen
	clippedRect.Translate(-position); //tranform the source back
	if (position.x < 0)
		position.x = 0;
	if (position.y < 0)
		position.y = 0;
	int screenOffset = (screenRect.Width() - clippedRect.Width()) * 4; //the point that the sprite starts
	int textureOffset = (textureRect.Width() - clippedRect.Width()) * 4;

	BYTE* tempTexture{ texture + (clippedRect.left + clippedRect.top * textureRect.Width()) * 4 };
	BYTE* tempScreen{ screen + ((int)position.x + (int)position.y * screenRect.Width()) * 4 };

	for (int y = 0; y < clippedRect.Height(); y++)
	{
		for (int x = 0; x < clippedRect.Width(); x++)
		{
			memcpy(tempScreen, tempTexture, 4);
			tempScreen += 4;
			tempTexture += 4;
		}
		tempScreen += screenOffset;
		tempTexture += textureOffset;
	}
}

void Sprite::BlitTransparency(BYTE* screen, BYTE* texture, const Rectangle& screenRect, const Rectangle& textureRect, Vector2 position)
{
	Rectangle clippedRect(textureRect);
	clippedRect.Translate(position); // transform the source to the screen space
	clippedRect.ClipTo(screenRect); // apply clipping to the screeen
	clippedRect.Translate(-position); //tranform the source back
	if (position.x < 0)
		position.x = 0;
	if (position.y < 0)
		position.y = 0;
	int screenOffset = (screenRect.Width() - clippedRect.Width()) * 4; //the point that the sprite starts
	int textureOffset = (textureRect.Width() - clippedRect.Width()) * 4;

	BYTE* tempTexture{ texture + (clippedRect.left + clippedRect.top * textureRect.Width()) * 4 };
	BYTE* tempScreen{ screen + ((int)position.x + (int)position.y * screenRect.Width()) * 4 };

	for (int y = 0; y  < clippedRect.Height(); y++)
	{
		for (int x = 0; x < clippedRect.Width(); x++) //Known issue, the left and bottom most line of pixels does not render. adding 1 to the Y line works to rectify that line, but adding one to the x line breaks the implomentation 
		{
			if (tempTexture[3] > 0)
			{

				if (tempTexture[3] == 255)
				{
					memcpy(tempScreen, tempTexture, 4);
				}
				else
				{
					float alpha = tempTexture[3] / 255.0f;
					tempScreen[0] = alpha * tempTexture[0] + (1.0f - alpha) * tempScreen[0]; //R
					tempScreen[1] = alpha * tempTexture[1] + (1.0f - alpha) * tempScreen[1]; //G
					tempScreen[2] = alpha * tempTexture[2] + (1.0f - alpha) * tempScreen[2]; //B
				}
			}
			tempScreen += 4;
			tempTexture += 4;
		}
		tempScreen += screenOffset;
		tempTexture += textureOffset;
	}
}
