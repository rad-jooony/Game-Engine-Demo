#pragma once
#include <string>
#include "Visualisation.h"

class Entity
{
private:
	std::string m_gfxName;
	float m_posX, m_posY {0};
public:
	~Entity() {};
	virtual void Update() = 0;
	void Render(Visualisation& vis);
};

