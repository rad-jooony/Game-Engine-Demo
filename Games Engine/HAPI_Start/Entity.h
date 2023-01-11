#pragma once
#include <string>
#include "Visualisation.h"
#include "Vector2.h"
#include "World.h"

enum class EFaction
{
	eNeutral,
	ePlayer,
	eEnemy,
	eBullet
};

class Entity
{
private:

	std::string texture_ID;

protected:

	Vector2 p_position{ 0.f ,0.f };
	Vector2 p_velocity{ 0.f, 0.f };

	bool p_alive{ false };
	int p_frame{ 0 };
	Rectangle p_colliderBox{};

	// Change Per Child
	int p_health{ 1 };
	float p_speed{ 0.5f };

public:

	virtual ~Entity() {};

	virtual void Update(World& world) = 0;
	virtual void Movement(World& world) = 0;
	virtual EFaction GetFaction() { return EFaction::eNeutral; };

	void SetVelocity(Vector2 velocity);
	void SetPosition(Vector2 position);
	bool CheckCollison(Entity& other);
	bool IsAlive() { return p_alive; }
	void SetAlive(bool state);
	Vector2 GetPosition() { return p_position; };

	void Render(Visualisation* vis);
	void linkSprite(std::string SpriteName);
	void CreateHitbox(Visualisation* vis);
	Rectangle ReturnHitbox() { return p_colliderBox; };
	std::string ReturnTexID() { return texture_ID; };
};

