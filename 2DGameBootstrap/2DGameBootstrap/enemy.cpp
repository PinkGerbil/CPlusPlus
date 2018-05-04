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
	timer2 = 0.0f;
	firstWave = true;
	m_EnemyTex = new aie::Texture(".../bin/textures/car.png");
}

enemy::enemy(glm::vec2 * pos)
{
	m_EnemyTex = new aie::Texture("../bin/textures/car.png");
	m_enemyPos = pos;
	for (int i = 0; i < 200; ++i) {
		m_EnemyBullet = new enemyBullet();
		m_inActiveEnemyBullets.push_back(m_EnemyBullet);
	}
}


enemy::~enemy()
{
	delete m_EnemyTex;
}

void enemy::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_EnemyTex, m_enemyPos->x, m_enemyPos->y, 30.0f, 30.0f, 9.4f);
	for (auto it = m_activeEnemyBullets.begin(); it != m_activeEnemyBullets.end(); ++it)
	{
		(*it)->Draw(spriteBatch);
	}
}

void enemy::Update(float deltaTime)
{
	timer2 += deltaTime;
	if (timer2 > 0.4f) {
		enemyBullet* newenemyBullet;
		if (m_inActiveEnemyBullets.size() > 0) {
			newenemyBullet = m_inActiveEnemyBullets.at(m_inActiveEnemyBullets.size() - 1);
			newenemyBullet->bullEnemyPosX = m_enemyPos->x;
			newenemyBullet->bullEnemyPosY = m_enemyPos->y;
			m_activeEnemyBullets.push_back(newenemyBullet);
			m_inActiveEnemyBullets.pop_back();
		}
		timer2 = 0.0f;
	}
	if (m_activeEnemyBullets.size() >= 1900)
	{
		for (auto it = m_activeEnemyBullets.begin(); it != m_activeEnemyBullets.end(); ++it)
		{
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