#pragma once
#include "HAPI_lib.h"
#include "Entity.h"
#include <string>
#include "Sprite.h"
#include "Vector2.h"

using namespace HAPISPACE;

class Player :
	public Entity
{
private:
	const HAPI_TKeyboardData& m_keyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& m_contData = HAPI.GetControllerData(0);
public:
	void Update() override final;
	void Movement() override final;
};
