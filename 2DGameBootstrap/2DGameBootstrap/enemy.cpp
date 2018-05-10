#include "enemy.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Font.h>
#include <Windows.h>
#include "Bullet.h"
#include "Player.h"
#include "enemyBullet.h"

enemy::enemy()
{
	//initialises the variables
	timer2 = 0.0f;
	firstWave = true;
}

enemy::enemy(glm::vec2 * pos)
{
	//sets the enemy's texture and position
	m_EnemyTex = new aie::Texture("../bin/textures/car.png");
	m_enemyPos = pos;
	//sets the enemy's bullets
	for (int i = 0; i < 200; ++i) {
		m_EnemyBullet = new enemyBullet();
		m_inActiveEnemyBullets.push_back(m_EnemyBullet);
	}
}


enemy::~enemy()
{
	//deletes the enemy's texture
	delete m_EnemyTex;
}

void enemy::Draw(aie::Renderer2D * spriteBatch)
{
	//draws the enemy
	spriteBatch->drawSprite(m_EnemyTex, m_enemyPos->x, m_enemyPos->y, 30.0f, 30.0f, 9.4f);
	//draws each of the enemy's bullets
	for (auto it = m_activeEnemyBullets.begin(); it != m_activeEnemyBullets.end(); ++it)
	{
		(*it)->Draw(spriteBatch);
	}
}

void enemy::Update(float deltaTime)
{
	//initalise the timer to deltaTime
	timer2 += deltaTime;
	//the enemy shoots another bullet every 0.4 seconds 
	if (timer2 > 0.4f) {
		enemyBullet* newenemyBullet;
		if (m_inActiveEnemyBullets.size() > 0) {
			newenemyBullet = m_inActiveEnemyBullets.at(m_inActiveEnemyBullets.size() - 1);
			newenemyBullet->bullEnemyPosX = m_enemyPos->x;
			newenemyBullet->bullEnemyPosY = m_enemyPos->y;
			m_activeEnemyBullets.push_back(newenemyBullet);
			m_inActiveEnemyBullets.pop_back();
		}
		//sets timer back to 0 so it will be able to start the loop again
		timer2 = 0.0f;
	}
	//iterates throught the bullets
	if (m_activeEnemyBullets.size() >= 1900)
	{
		for (auto it = m_activeEnemyBullets.begin(); it != m_activeEnemyBullets.end(); ++it)
		{
			//generates each bullet
			enemyBullet* usedEnemyBullet;
			if ((*it)->bullEnemyPosY >= 720)
			{
				usedEnemyBullet = m_activeEnemyBullets.at(m_activeEnemyBullets.size() - 1);
				usedEnemyBullet->bullEnemyPosX = m_enemyPos->x;
				usedEnemyBullet->bullEnemyPosY = m_enemyPos->y;
				m_inActiveEnemyBullets.push_back(usedEnemyBullet);
				m_activeEnemyBullets.pop_back();
			}
		}
	}

	//sets the movement of the enemy so it can move left and right
	if (m_enemyPos->x <= 1230 && firstWave) {
		m_enemyPos->x += 200.0f * deltaTime;
		if (m_enemyPos->x >= 1230)
			firstWave = false;
	}
	if (!firstWave)
	{
		m_enemyPos->x -= 200.0f * deltaTime;
		if (m_enemyPos->x <= 60)
			firstWave = true;
	}
}