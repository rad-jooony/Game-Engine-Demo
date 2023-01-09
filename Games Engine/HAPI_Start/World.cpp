#include <HAPI_lib.h>
#include <vector>
#include <string>
#include "World.h"
#include "Visualisation.h"
#include "Player.h"
#include "Rectangle.h"
#include "NeutralEntity.h"
#include "Enemy.h"
#include "Bullet.h"

void World::Run(Visualisation* vis)
{

	while (HAPI.Update() == true) //This is the whole game
	{
		vis->clearScreenToGray(vis->returnScreenWidth(), vis->returnScreenHeight());

		for (Entity* entity : m_entities)
		{
			if (entity->IsAlive())
			{
				entity->Render(vis);
				entity->Update();
				if (entity->GetFaction() == EFaction::eEnemy)
				{
					for (Entity* other : m_entities)
					{
						if (other->GetFaction() == EFaction::ePlayer)
						{
							entity->CheckCollison(*other);
						}
					}
				}
			}

		}
	}
	for (int i = 0; i < m_entities.size(); i++)
		delete m_entities[i];
}

void World::Load(Visualisation* vis)
{
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& contData = HAPI.GetControllerData(0);

	vis->CreateSprite("backgroundSprite", "Data\\backdrop.png", false);
	vis->CreateSprite("alphaSprite", "Data\\alphaThing.tga", true);
	vis->CreateSprite("playerSprite", "Data\\playerSprite.png", true);
	vis->CreateSprite("EnemySprite", "Data\\EnemySprite.png", true);
	vis->CreateSprite("PlayerBullet", "Data\\PlayerBullet.png", true);
	vis->CreateSprite("EnemyBullet", "Data\\EnemyBullet.png", true);

	//currently the background kills frames. This almost certainly to do with inefficent blitting. Disable if needed
	NeutralEntity* background = new NeutralEntity;
	background->linkSprite("backgroundSprite");
	m_entities.push_back(background);
	background->setPosition(Vector2(-100, -100));
	background->SetAlive(true);

	Player* player = new Player;
	player->linkSprite("playerSprite");
	m_entities.push_back(player);
	player->setPosition(Vector2(vis->returnScreenWidth() / 1.2, vis->returnScreenHeight() / 2));
	player->SetAlive(true);

	for (int i = 0; i < 5; i++)
	{
		Enemy* enemy = new Enemy;
		enemy->linkSprite("EnemySprite");
		m_entities.push_back(enemy);
	};

	m_bulletsStart = m_entities.size();
	for (int i = 0; i < 10; i++)
	{
		Bullet* bullet = new Bullet;
		m_entities.push_back(bullet);
	}

	vis->ScreenSetup();
}

void World::Shoot(Entity* shooter)
{
	for (int i = m_bulletsStart; i < m_entities.size(); i++)
	{
		if (!m_entities[i]->IsAlive())
		{
			if (shooter->GetFaction() == EFaction::ePlayer)
			{
				m_entities[i]->linkSprite("PlayerBullet");
				m_entities[i]->SetFaction(EFaction::ePlayer);
			}
			if (shooter->GetFaction() == EFaction::eEnemy)
			{
				m_entities[i]->linkSprite("EnemyBullet");
				m_entities[i]->SetFaction(EFaction::eEnemy);
			}
			m_entities[i]->SetAlive(true);
		}
	}
}