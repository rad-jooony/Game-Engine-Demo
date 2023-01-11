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
#include "DeltaTime.h"

void World::Run(Visualisation* vis, World& world)
{
	int defeated = 0;
	while (HAPI.Update() == true) //This is the whole game
	{

		vis->clearScreenToGray(vis->returnScreenWidth(), vis->returnScreenHeight());
		if (m_level >= 5) // win condition
		{
			HAPI.UserMessage("You've escaped the gang... for now", "Congratulations");
			break;
		}

		if (!m_entities[m_playerStart]->IsAlive())
		{
			HAPI.UserMessage("The gang finally killed you.", "Game Over");
			break;
		}
		//check for living enemies, spawn more if all are dead.	
		if (defeated == m_level)
		{
			NextLevel(vis);
		}
		//here all checks for bullets will take place
		for (int i = m_bulletStart; i != m_entities.size(); i++)
		{
			if (m_entities[i]->IsAlive())
			{
				//first check if alive bullets are still within the playzone. since bullets only move left or right i only need to check those bounds
				if (m_entities[i]->GetPosition().x > vis->returnScreenWidth() || m_entities[i]->GetPosition().x < 0)
				{
					m_entities[i]->SetAlive(false);
				}

				// now i check if any are hitting the player or enemies
				for (Entity* other : m_entities)
				{
					if ((other->GetFaction() == EFaction::ePlayer || other->GetFaction() == EFaction::eEnemy) && other->IsAlive())
					{
						if (m_entities[i]->CheckCollison(*other))
						{
							other->SetAlive(false);
							if (other->GetFaction() == EFaction::eEnemy)
								defeated++;
							m_entities[i]->SetAlive(false); //if bullets collide, then kill entity, then itself. includes other bullets. 
						}
					}
				}
			}
		}

		for (Entity* entity : m_entities)
		{
			if (entity->IsAlive())
			{
				entity->Render(vis);
				entity->Update(world);
				if (entity->GetFaction() == EFaction::eEnemy)
				{
					for (Entity* other : m_entities)
					{
						if (other->GetFaction() == EFaction::ePlayer)
						{
							if (entity->CheckCollison(*other))
								other->SetAlive(false); //AI kills player if there is contact. AI advantage against player here
						}
					}
				}
			}
		}
		//here is where I can add more

		if (m_level >= 5)
			continue;
	}
	for (int i = 0; i < m_entities.size(); i++)
		delete m_entities[i];
}

void World::Load(Visualisation* vis)
{

	vis->CreateSprite("backgroundSprite", "Data\\backdrop.png", false);
	vis->CreateSprite("alphaSprite", "Data\\alphaThing.tga", true);
	vis->CreateSprite("playerSprite", "Data\\playerSprite.png", true);
	vis->CreateSprite("EnemySprite", "Data\\EnemySprite.png", true);
	vis->CreateSprite("PlayerBullet", "Data\\PlayerBullet.png", true);
	vis->CreateSprite("EnemyBullet", "Data\\EnemyBullet.png", true);

	//currently the background kills frames. This almost certainly to do with inefficent blitting. Disable if needed
	NeutralEntity* background = new NeutralEntity;
	background->linkSprite("backgroundSprite");
	m_entities.push_back(background); // e0
	background->SetPosition(Vector2(-100, -100));
	background->SetAlive(true);

	m_playerStart = m_entities.size();
	Player* player = new Player;
	player->linkSprite("playerSprite");
	player->CreateHitbox(vis);
	m_entities.push_back(player); // e1
	player->SetPosition(Vector2(vis->returnScreenWidth() / 1.2, vis->returnScreenHeight() / 2));
	player->SetAlive(true);

	m_enemyStart = m_entities.size();
	for (int i = 0; i < 5; i++)
	{
		Enemy* enemy = new Enemy;
		enemy->linkSprite("EnemySprite");
		enemy->CreateHitbox(vis);
		m_entities.push_back(enemy); // e2 to e7
	};

	m_bulletStart = m_entities.size();
	for (int i = 0; i < 30; i++)
	{
		Bullet* bullet = new Bullet;
		bullet->linkSprite("PlayerBullet");
		bullet->CreateHitbox(vis);
		m_entities.push_back(bullet); // e7 to e17
	}

	vis->ScreenSetup();
}

void World::NextLevel(Visualisation* vis)
{
	m_level += 1;
	for (int i = m_enemyStart; i != m_enemyStart + m_level; i++)
	{
		m_entities[i]->SetAlive(true);
		m_entities[i]->SetPosition(Vector2(i * 40, i * 60));
	}
}

bool World::AIShoot(Entity* AI, Vector2 firepoint)
{
	Rectangle detectBox(AI->ReturnHitbox());
	detectBox.Translate(AI->GetPosition());
	detectBox.right = 3000; //create a hitbox in front of the AI that looks for the player
	for (Entity* other : m_entities)
	{
		if (other->GetFaction() == EFaction::ePlayer)
		{
			Rectangle hitbox = other->ReturnHitbox();
			hitbox.Translate(other->GetPosition());

			if (detectBox.left < hitbox.right &&
				detectBox.right > hitbox.left &&
				detectBox.top < hitbox.bottom &&
				detectBox.bottom > hitbox.top)
			{
				Shoot(AI, firepoint);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}


void World::Shoot(Entity* shooter, Vector2 firePoint)
{
	for (int i = m_bulletStart; i < m_entities.size(); i++)
	{
		if (!m_entities[i]->IsAlive())
		{
			if (shooter->GetFaction() == EFaction::ePlayer)
			{
				m_entities[i]->linkSprite("PlayerBullet");
				m_entities[i]->SetVelocity(Vector2(-1, 0));

			}
			else if (shooter->GetFaction() == EFaction::eEnemy)
			{
				m_entities[i]->linkSprite("EnemyBullet");
				m_entities[i]->SetVelocity(Vector2(1, 0));
			}
			else
			{
				HAPI.UserMessage("Shooter faction not found", "Error");
				continue;
			}
			m_entities[i]->SetAlive(true);
			m_entities[i]->SetPosition((shooter->GetPosition()) + firePoint);
			return;
		}
		else
		{
			std::cout << "No more bullets avalable in memory\n";
		}
	}
}