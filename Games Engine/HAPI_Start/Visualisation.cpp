#include "Visualisation.h"
#include "Sprite.h"

Visualisation::Visualisation(BYTE* p_screen)
{
	m_screen = p_screen;
};

bool Visualisation::CreateSprite(std::string spriteName, const std::string& filename, bool hasAlpha)
{
	Sprite* newSprite = new Sprite();
	if (!newSprite->Load(filename, hasAlpha))
	{
		std::cout << "Error loading sprite (" << filename << ")\n";
		delete newSprite;
		return false;
	}
	else
	{
		this->m_spriteMap[spriteName] = newSprite;
		return true;
	}
}

void Visualisation::DrawSprite(const std::string& spriteName, int screenWidth, int posX, int posY, int frameNumber)
{
	 m_spriteMap[spriteName]->Draw(m_screen, screenWidth, posX, posY, frameNumber);
}

void Visualisation::clearScreenToGray(int screenWidth, int screenHeight)
{
	memset(m_screen, 50, screenWidth * screenHeight * 4);
	return;
};