#pragma once
#include <string>
#include "Visualisation.h"

class Entity
{
private:
	//std::string m_gfxName;
	
	int m_health{ 1 };
	std::string texture_ID;
public:

	float m_posX {0}, m_posY{0}; //TEMP - will become private again
	
	Entity() {}
	virtual ~Entity() {};
	virtual void Update() = 0;
	void Render(Visualisation* vis);
	void linkSprite(std::string SpriteName);
	std::string ReturnTexID() { return texture_ID; }
};

