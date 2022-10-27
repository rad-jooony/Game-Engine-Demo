#include "Visualisation.h"
#include "Sprite.h"

//bool Visualisation::CreateSprite(std::string spriteName, const std::string& filename)
//{
	//TODO
//	Sprite* newSprite = new Sprite();
//	if (!newSprite->Load(filename))
//	{
	//	std::cout << "Error loading sprite (" << filename << ")\n";
	//	delete newSprite;
	//	return false;
//	}

//}

//void Visualisation::DrawSprite(const std::string& spriteName, int x, int y, int frameNumber)
//{
	// TODO
	//m_spriteMap[spriteName]->Draw(m_screen, x, y, frameNumber);
//}

void Visualisation::clearScreenGray(BYTE* screen, int screenWidth, int screenHeight)
{
	memset(screen, 50, screenWidth * screenHeight * 4);
};
