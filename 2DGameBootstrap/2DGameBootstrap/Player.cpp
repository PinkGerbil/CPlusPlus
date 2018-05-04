#include "Player.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>
#include <iostream>
#include "Bullet.h"
#include <cstdlib>
#include <ctime>
#include <Font.h>
#include <Windows.h>
#include "enemy.h"
#include "enemyBullet.h"

Player::Player()
{
}

Player::Player(glm::vec2 * pos)
{
	m_enemy = new enemy(new glm::vec2(60, 680));
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_pos = pos;
	enemyDead = false;
	playerDead = false; 
	timer = 0.0f;
	//m_enemy = new enemy();
	for (int i = 0; i < 2000; ++i)
	{
		m_bullet = new Bullet();
		m_inActiveBullets.push_back(m_bullet);
	}
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
}


Player::~Player()
{
	delete m_texture;
	delete m_bullet;
	if (m_enemy != nullptr)
		delete m_enemy;
}

void Player::Update(float deltaTime, aie::Input* input)
{ 


	timer += deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && timer > 0.75f && playerDead == false) 
	{
		Bullet* newBullet;
		if (m_inActiveBullets.size() > 0) {
			newBullet = m_inActiveBullets.at(m_inActiveBullets.size() - 1);
			newBullet->bullPosX = m_pos->x;
			newBullet->bullPosY = m_pos->y;
			m_activeBullets.push_back(newBullet);
			m_inActiveBullets.pop_back();
			std::cout << "inactive: " << m_inActiveBullets.size() << std::endl;
			std::cout << "active: " << m_activeBullets.size() << std::endl;
			
			newBullet = m_inActiveBullets.at(m_inActiveBullets.size() - 1);
			newBullet->bullPosX = m_pos->x - 30;
			newBullet->bullPosY = m_pos->y - 10;
			m_activeBullets.push_back(newBullet);
			m_inActiveBullets.pop_back();
			std::cout << "inactive: " << m_inActiveBullets.size() << std::endl;
			std::cout << "active: " << m_activeBullets.size() << std::endl;

			newBullet = m_inActiveBullets.at(m_inActiveBullets.size() - 1);
			newBullet->bullPosX = m_pos->x + 30;
			newBullet->bullPosY = m_pos->y - 10;
			m_activeBullets.push_back(newBullet);
			m_inActiveBullets.pop_back();
			std::cout << "inactive: " << m_inActiveBullets.size() << std::endl;
			std::cout << "active: " << m_activeBullets.size() << std::endl;
		}
		else {
			//outOfBullets = true; 
			std::cout << "No bullets left" << std::endl;
		}
		timer = 0.0f;
	}

	if (m_activeBullets.size() >= 1900)
	{
		for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
		{
			Bullet* usedBullet;
			if ((*it)->bullPosY >= 720)
			{
				usedBullet = m_activeBullets.at(m_activeBullets.size() - 1);
				usedBullet->bullPosX = m_pos->x;
				usedBullet->bullPosY = m_pos->y;
				m_inActiveBullets.push_back(usedBullet);
				m_activeBullets.pop_back();
			}
		}
	}

	for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
	{
		(*it)->update(deltaTime);
		if (!enemyDead) {
			float distEnemyX = m_enemy->m_enemyPos->x - (*it)->bullPosX;
			float distEnemyY = m_enemy->m_enemyPos->y - (*it)->bullPosY;
			if ((distEnemyX) < 20 && (distEnemyY) < 20 && distEnemyX > -20 && distEnemyY > -20)
			{
				std::cout << "collided with enemy" << std::endl;
				enemyDead = true;
			}
		}
	}
	if(!enemyDead){
		for (auto ree = m_enemy->m_activeEnemyBullets.begin(); ree != m_enemy->m_activeEnemyBullets.end(); ree++) {
			(*ree)->update(deltaTime);
			if (!playerDead && m_enemy != nullptr) {
				float distPlayerX = (*ree)->bullEnemyPosX - m_pos->x;
				float distPlayerY = (*ree)->bullEnemyPosY - m_pos->y;
				if ((distPlayerX) < 20 && (distPlayerY) < 20 && distPlayerX > -20 && distPlayerY > -20)
				{
					std::cout << "collided with player" << std::endl;
					playerDead = true;
				}
			}
		}
	}
	if ((input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A)) && m_pos->x >= 50)
	{
		m_pos->x -= 150.0f * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D)) && m_pos->x <= 1230)
	{
		m_pos->x += 150.0f * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_W)) && m_pos->y <= 670)
	{
		m_pos->y += 150.0f * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_DOWN)||input->isKeyDown(aie::INPUT_KEY_S)) && m_pos->y >= 50)
	{
		m_pos->y -= 150.0f * deltaTime;
	}
	if (!enemyDead) {
		m_enemy->Update(deltaTime);
	}
}

void Player::Draw(aie::Renderer2D * spriteBatch)
{
	if (!playerDead) {
		spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y);
	}
	else {
		spriteBatch->drawText(m_font, "You died!", 550, 500);
	}
	for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
	{
		(*it)->Draw(spriteBatch);
	}
	if (!enemyDead)
	{
		m_enemy->Draw(spriteBatch);
	}
	else
	{
		delete m_enemy;
		m_enemy = nullptr;
		spriteBatch->drawText(m_font, "You WIN!", 550, 500);
	}
	if (m_inActiveBullets.size() <= 2)
	{
		spriteBatch->drawText(m_font, "out of bullets", 550, 500);
	}
}
