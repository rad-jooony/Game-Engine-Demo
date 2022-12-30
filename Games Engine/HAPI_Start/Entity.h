#pragma once
#include <string>
#include "Visualisation.h"
#include "Vector2.h"
class Entity
{
private:
	
	std::string texture_ID;

protected:

	int p_health{ 1 };
	Vector2 p_position{ 0.f ,0.f };

	Vector2 p_velocity{ 0.f, 0.f };
	float p_speed{ 0.5f };

public:

	Entity() {}
	virtual ~Entity() {};
	virtual void Update() = 0;
	virtual void Movement() = 0;
	void Render(Visualisation* vis);
	void linkSprite(std::string SpriteName);
	std::string ReturnTexID() { return texture_ID; }
	void setPosition(Vector2 position);
};

