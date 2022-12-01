#include "Visualisation.h"
#include "Sprite.h"
#include "Player.h"
#include <cassert>

Visualisation::Visualisation()
{
	m_screenRect = Rectangle(0, m_screenWidth, 0, m_screenHeight);
}
bool Visualisation::ScreenSetup()
{
	if (!HAPI.Initialise(m_screenWidth, m_screenHeight, "jooony's Demo"))
		return false;
	assert(HAPI.GetScreenPointer() != NULL);
	m_screen = HAPI.GetScreenPointer();
	HAPI.SetShowFPS(true);
	return true;
}

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

void Visualisation::DrawSprite(const std::string& spriteName, int posX, int posY, int frameNumber)
{
	m_spriteMap[spriteName]->Draw(m_screen, m_screenRect, posX, posY, frameNumber);
}

void Visualisation::clearScreenToGray(int screenWidth, int screenHeight)
{
	memset(m_screen, 50, screenWidth * screenHeight * 4);
	return;
};