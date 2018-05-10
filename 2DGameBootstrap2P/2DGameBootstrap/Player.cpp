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
#include "SecondPlayer.h"
#include "SecondBullet.h"
#include "enemyBullet.h"

Player::Player()
{
}

Player::Player(glm::vec2 * pos)
{
	m_texture = new aie::Texture("../bin/textures/shipGreen.png");
	m_pos = pos;
	timer = 0.0f;
	for (int i = 0; i < 2000; ++i)
	{
		m_bullet = new Bullet();
		m_inActiveBullets.push_back(m_bullet);
	}
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_SecondPlayer = new SecondPlayer(new glm::vec2(1180, 200));
	m_enemy = new enemy(new glm::vec2(60, 680));
	m_enemy2 = new enemy(new glm::vec2(640, 680));
	m_enemy3 = new enemy(new glm::vec2(960, 680));
	m_enemy4 = new enemy(new glm::vec2(1229, 680));
	playerOneDead = false;
	playerTwoDead = false;
	enemyDead = false;
	enemyTwoDead = false;
	enemyThreeDead = false;
	enemyFourDead = false;
}


Player::~Player()
{
	delete m_texture;
	delete m_bullet;
	if (m_enemy != nullptr) {
		delete m_enemy;
	}
	if (m_enemy2 != nullptr) {
		delete m_enemy2;
	}
	if (m_enemy3 != nullptr) {
		delete m_enemy3;
	}
	if (m_enemy4 != nullptr) {
		delete m_enemy4;
	}
	if (m_SecondPlayer != nullptr) {
		delete m_SecondPlayer;
	}
}

void Player::Update(float deltaTime, aie::Input* input)
{ 
	if (!playerOneDead) {
		timer += deltaTime;
		if (input->isKeyDown(aie::INPUT_KEY_SPACE) && timer > 1.0f && playerOneDead == false)
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
				if ((distEnemyX) < 20 && (distEnemyY) < 10 && distEnemyX > -20 && distEnemyY > -10)
				{
					std::cout << "collided with enemy" << std::endl;
					enemyDead = true;
				}
			}
			if (!enemyDead) {
				float distEnemyXtwo = m_enemy2->m_enemyPos->x - (*it)->bullPosX;
				float distEnemyYtwo = m_enemy2->m_enemyPos->y - (*it)->bullPosY;
				if ((distEnemyXtwo) < 20 && (distEnemyYtwo) < 10 && distEnemyXtwo > -20 && distEnemyYtwo > -10)
				{
					std::cout << "collided with enemy" << std::endl;
					enemyDead = true;
				}
			}
			if (!enemyDead) {
				float distEnemyXthree = m_enemy3->m_enemyPos->x - (*it)->bullPosX;
				float distEnemyYthree = m_enemy3->m_enemyPos->y - (*it)->bullPosY;
				if ((distEnemyXthree) < 20 && (distEnemyYthree) < 10 && distEnemyXthree > -20 && distEnemyYthree > -10)
				{
					std::cout << "collided with enemy" << std::endl;
					enemyDead = true;
				}
			}
			if (!enemyDead) {
				float distEnemyXfour = m_enemy4->m_enemyPos->x - (*it)->bullPosX;
				float distEnemyYfour = m_enemy4->m_enemyPos->y - (*it)->bullPosY;
				if ((distEnemyXfour) < 20 && (distEnemyYfour) < 10 && distEnemyXfour > -20 && distEnemyYfour > -10)
				{
					std::cout << "collided with enemy" << std::endl;
					enemyDead = true;
				}
			}
		}
	}
	if (!playerTwoDead) {
		for (auto owo = m_SecondPlayer->m_activeSecBullets.begin(); owo != m_SecondPlayer->m_activeSecBullets.end(); ++owo) {
			if (!enemyDead) {
				float distEnemyXx = m_enemy->m_enemyPos->x - (*owo)->bullSecPosX;
				float distEnemyYy = m_enemy->m_enemyPos->y - (*owo)->bullSecPosY;
				if ((distEnemyXx) < 20 && (distEnemyYy) < 10 && distEnemyXx > -20 && distEnemyYy > -10)
				{
					std::cout << "collided with enemy 2" << std::endl;
					enemyDead = true;
				}
			}
			if (!enemyDead) {
				float distEnemyXx = m_enemy2->m_enemyPos->x - (*owo)->bullSecPosX;
				float distEnemyYy = m_enemy2->m_enemyPos->y - (*owo)->bullSecPosY;
				if ((distEnemyXx) < 20 && (distEnemyYy) < 10 && distEnemyXx > -20 && distEnemyYy > -10)
				{
					std::cout << "collided with enemy 2" << std::endl;
					enemyDead = true;
				}
			}
			if (!enemyDead) {
				float distEnemyXxx = m_enemy3->m_enemyPos->x - (*owo)->bullSecPosX;
				float distEnemyYyy = m_enemy3->m_enemyPos->y - (*owo)->bullSecPosY;
				if ((distEnemyXxx) < 20 && (distEnemyYyy) < 10 && distEnemyXxx > -20 && distEnemyYyy > -10)
				{
					std::cout << "collided with enemy 2" << std::endl;
					enemyDead = true;
				}
			}
			if (!enemyDead) {
				float distEnemyXxy = m_enemy4->m_enemyPos->x - (*owo)->bullSecPosX;
				float distEnemyYyx = m_enemy4->m_enemyPos->y - (*owo)->bullSecPosY;
				if ((distEnemyXxy) < 20 && (distEnemyYyx) < 10 && distEnemyXxy > -20 && distEnemyYyx > -10)
				{
					std::cout << "collided with enemy 2" << std::endl;
					enemyDead = true;
				}
			}
		}
	}
	if (input->isKeyDown(aie::INPUT_KEY_A) && m_pos->x >= 50)
	{
		m_pos->x -= 250.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D) && m_pos->x <= 1230)
	{
		m_pos->x += 250.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_W) && m_pos->y <= 400)
	{
		m_pos->y += 200.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_S) && m_pos->y >= 50)
	{
		m_pos->y -= 200.0f * deltaTime;
	}

	if (!enemyDead) {
		for (auto en = m_enemy->m_activeEnemyBullets.begin(); en != m_enemy->m_activeEnemyBullets.end(); en++) {
			if (m_enemy != nullptr) {
				if (!playerOneDead) {
					float distPlayerX = m_pos->x - (*en)->bullEnemyPosX;
					float distPlayerY = m_pos->y - (*en)->bullEnemyPosY;
					if ((distPlayerX) < 30 && (distPlayerY) < 20 && distPlayerX > -30 && distPlayerY > -20)
					{
						std::cout << "collided with player" << std::endl;
						playerOneDead = true;
					}
				}
			}
			if (!playerTwoDead) {
				float distPlayerTwoX = m_SecondPlayer->m_SecPos->x - (*en)->bullEnemyPosX;
				float distPlayerTwoY = m_SecondPlayer->m_SecPos->y - (*en)->bullEnemyPosY;
				if ((distPlayerTwoX) < 30 && (distPlayerTwoY) < 20 && distPlayerTwoX > -30 && distPlayerTwoY > -20)
				{
					std::cout << "collided with player2" << std::endl;
					playerTwoDead = true;
				}
			}
		}
	}
	if (!enemyTwoDead) {
		for (auto enTwo = m_enemy2->m_activeEnemyBullets.begin(); enTwo != m_enemy2->m_activeEnemyBullets.end(); enTwo++) {
			if (m_enemy2 != nullptr) {
				if (!playerOneDead) {
					float distPlayerX = m_pos->x - (*enTwo)->bullEnemyPosX;
					float distPlayerY = m_pos->y - (*enTwo)->bullEnemyPosY;
					if ((distPlayerX) < 30 && (distPlayerY) < 20 && distPlayerX > -30 && distPlayerY > -20)
					{
						std::cout << "collided with player" << std::endl;
						playerOneDead = true;
					}
				}
			}
			if (!playerTwoDead) {
				float distPlayerTwoX = m_SecondPlayer->m_SecPos->x - (*enTwo)->bullEnemyPosX;
				float distPlayerTwoY = m_SecondPlayer->m_SecPos->y - (*enTwo)->bullEnemyPosY;
				if ((distPlayerTwoX) < 30 && (distPlayerTwoY) < 20 && distPlayerTwoX > -30 && distPlayerTwoY > -20)
				{
					std::cout << "collided with player2" << std::endl;
					playerTwoDead = true;
				}
			}
		}
	}
	if (!enemyThreeDead) {
		for (auto enThree = m_enemy3->m_activeEnemyBullets.begin(); enThree != m_enemy3->m_activeEnemyBullets.end(); enThree++) {
			if (m_enemy3 != nullptr) {
				if (!playerOneDead) {
					float distPlayerX = m_pos->x - (*enThree)->bullEnemyPosX;
					float distPlayerY = m_pos->y - (*enThree)->bullEnemyPosY;
					if ((distPlayerX) < 30 && (distPlayerY) < 20 && distPlayerX > -30 && distPlayerY > -20)
					{
						std::cout << "collided with player" << std::endl;
						playerOneDead = true;
					}
				}
			}
			if (!playerTwoDead) {
				float distPlayerTwoX = m_SecondPlayer->m_SecPos->x - (*enThree)->bullEnemyPosX;
				float distPlayerTwoY = m_SecondPlayer->m_SecPos->y - (*enThree)->bullEnemyPosY;
				if ((distPlayerTwoX) < 30 && (distPlayerTwoY) < 20 && distPlayerTwoX > -30 && distPlayerTwoY > -20)
				{
					std::cout << "collided with player2" << std::endl;
					playerTwoDead = true;
				}
			}
		}
	}
	if (!enemyFourDead) {
		for (auto enFour = m_enemy4->m_activeEnemyBullets.begin(); enFour != m_enemy4->m_activeEnemyBullets.end(); enFour++) {
			if (m_enemy4 != nullptr) {
				if (!playerOneDead) {
					float distPlayerX = m_pos->x - (*enFour)->bullEnemyPosX;
					float distPlayerY = m_pos->y - (*enFour)->bullEnemyPosY;
					if ((distPlayerX) < 30 && (distPlayerY) < 20 && distPlayerX > -30 && distPlayerY > -20)
					{
						std::cout << "collided with player" << std::endl;
						playerOneDead = true;
					}
				}
			}
			if (!playerTwoDead) {
				float distPlayerTwoX = m_SecondPlayer->m_SecPos->x - (*enFour)->bullEnemyPosX;
				float distPlayerTwoY = m_SecondPlayer->m_SecPos->y - (*enFour)->bullEnemyPosY;
				if ((distPlayerTwoX) < 30 && (distPlayerTwoY) < 20 && distPlayerTwoX > -30 && distPlayerTwoY > -20)
				{
					std::cout << "collided with player2" << std::endl;
					playerTwoDead = true;
				}
			}
		}
	}
	if (!playerTwoDead) {
		m_SecondPlayer->Update(deltaTime, input);
	}
	if (!enemyDead) {
		m_enemy->Update(deltaTime);
	}
	if (!enemyTwoDead) {
		m_enemy2->Update(deltaTime);
	}
	if (!enemyThreeDead) {
		m_enemy3->Update(deltaTime);
	}
	if (!enemyFourDead) {
		m_enemy4->Update(deltaTime);
	}
}

void Player::Draw(aie::Renderer2D * spriteBatch)
{
	if (!playerOneDead) {
		spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y);
	}
	else {
		spriteBatch->drawText(m_font, "Player 1 is dead!", 525, 500);
	}
	for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
	{
		(*it)->Draw(spriteBatch);
	}

	if (m_inActiveBullets.size() <= 2)
	{
		spriteBatch->drawText(m_font, "out of bullets", 550, 500);
	}
	if (!playerTwoDead) {
		m_SecondPlayer->Draw(spriteBatch);
	}
	else {
		delete m_SecondPlayer;
		m_SecondPlayer = nullptr;
		spriteBatch->drawText(m_font, "Player 2 died!", 550, 450);
	}

	if (!enemyDead) {
		m_enemy->Draw(spriteBatch);
	}
	else {
		spriteBatch->drawText(m_font, "You Win!", 575, 550);
		delete m_enemy;
		m_enemy = nullptr;
	}
	if (!enemyTwoDead) {
		m_enemy2->Draw(spriteBatch);
	}
	else {
		spriteBatch->drawText(m_font, "You Win!", 575, 550);
		delete m_enemy2;
		m_enemy2 = nullptr;
	}
	if (!enemyThreeDead) {
		m_enemy3->Draw(spriteBatch);
	}
	else {
		spriteBatch->drawText(m_font, "You Win!", 575, 550);
		delete m_enemy3;
		m_enemy3 = nullptr;
	}
	if (!enemyFourDead) {
		m_enemy4->Draw(spriteBatch);
	}
	else {
		spriteBatch->drawText(m_font, "You Win!", 575, 550);
		delete m_enemy4;
		m_enemy4 = nullptr;
	}
	if (playerOneDead && playerTwoDead) {
		spriteBatch->drawText(m_font, "You're both failures", 515, 550);
	}
}