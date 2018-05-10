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
	//spawns 3 enemies
	m_enemy = new enemy(new glm::vec2(60, 680));
	m_enemy2 = new enemy(new glm::vec2(1229, 640));
	m_enemy3 = new enemy(new glm::vec2(640, 600));

	//sets the player's position and texture
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_pos = pos;
	//true or false statements for when an enemy dies
	enemyDead = false;
	enemyTwoDead = false;
	enemyThreeDead = false;
	playerDead = false; 
	//initialises the timer
	timer = 0.0f;
	//sets the bullet limit and creates a new bullet everytime the ship shoots
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
	//if the enemies die they are set to null or else the code will crash
	if (m_enemy != nullptr) {
		delete m_enemy;
	}
	if (m_enemy2 != nullptr) {
		delete m_enemy2;
	}
	if (m_enemy3 != nullptr) {
		delete m_enemy3;
	}
}

void Player::Update(float deltaTime, aie::Input* input)
{ 
	//sets timer to delta time
	timer += deltaTime;
	//every 0.7f seconds you can shoot again as long as space is held down
	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && timer > 0.75f && playerDead == false) 
	{
		Bullet* newBullet;
		if (m_inActiveBullets.size() > 0) {
			//bullet one come out of the middle of the ship
			newBullet = m_inActiveBullets.at(m_inActiveBullets.size() - 1);
			newBullet->bullPosX = m_pos->x;
			newBullet->bullPosY = m_pos->y;
			m_activeBullets.push_back(newBullet);
			m_inActiveBullets.pop_back();
			//prints out how many bullets are left to the console
			std::cout << "inactive: " << m_inActiveBullets.size() << std::endl;
			std::cout << "active: " << m_activeBullets.size() << std::endl;
			
			//bullet 2 and 3 come out of the wings of the ship
			newBullet = m_inActiveBullets.at(m_inActiveBullets.size() - 1);
			newBullet->bullPosX = m_pos->x - 30;
			newBullet->bullPosY = m_pos->y - 10;
			m_activeBullets.push_back(newBullet);
			m_inActiveBullets.pop_back();
			//prints out how many bullets are left to the console
			std::cout << "inactive: " << m_inActiveBullets.size() << std::endl;
			std::cout << "active: " << m_activeBullets.size() << std::endl;

			newBullet = m_inActiveBullets.at(m_inActiveBullets.size() - 1);
			newBullet->bullPosX = m_pos->x + 30;
			newBullet->bullPosY = m_pos->y - 10;
			m_activeBullets.push_back(newBullet);
			m_inActiveBullets.pop_back();
			//prints out how many bullets are left to the console
			std::cout << "inactive: " << m_inActiveBullets.size() << std::endl;
			std::cout << "active: " << m_activeBullets.size() << std::endl;
		}
		else {
			//outOfBullets = true; 
			std::cout << "No bullets left" << std::endl;
		}
		//sets timer to 0 so you can't shoot a continuous stream of bullets
		timer = 0.0f;
	}

	//once you have used 1900 bullets the code refills your bullets
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

	//goes through each bullet to detect if it has hit the enemy
	for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
	{
		(*it)->update(deltaTime);
		if (!enemyDead) {
			float distEnemyX = m_enemy->m_enemyPos->x - (*it)->bullPosX;
			float distEnemyY = m_enemy->m_enemyPos->y - (*it)->bullPosY;
			//between the two values so it can account for the size of the enemy
			if ((distEnemyX) < 30 && (distEnemyY) < 20 && distEnemyX > -30 && distEnemyY > -20)
			{
				std::cout << "collided with enemy" << std::endl;
				enemyDead = true;
			}
		}
		if (!enemyTwoDead) {
			float distEnemyXTwo = m_enemy2->m_enemyPos->x - (*it)->bullPosX;
			float distEnemyYTwo = m_enemy2->m_enemyPos->y - (*it)->bullPosY;
			//between the two values so it can account for the size of the enemy
			if ((distEnemyXTwo) < 30 && (distEnemyYTwo) < 20 && distEnemyXTwo > -30 && distEnemyYTwo > -20)
			{
				std::cout << "collided with enemy 2" << std::endl;
				enemyTwoDead = true;
			}
		}
		if (!enemyThreeDead) {
			float distEnemyXThree = m_enemy3->m_enemyPos->x - (*it)->bullPosX;
			float distEnemyYThree = m_enemy3->m_enemyPos->y - (*it)->bullPosY;
			//between the two values so it can account for the size of the enemy
			if ((distEnemyXThree) < 30 && (distEnemyYThree) < 20 && distEnemyXThree > -30 && distEnemyYThree > -20)
			{
				std::cout << "collided with enemy 3" << std::endl;
				enemyThreeDead = true;
			}
		}
	}
	if(!enemyDead){
		for (auto ree = m_enemy->m_activeEnemyBullets.begin(); ree != m_enemy->m_activeEnemyBullets.end(); ree++) {
			(*ree)->update(deltaTime);
			if (!playerDead && m_enemy != nullptr) {
				//checks if the enemy bullet has hit the player
				float distPlayerX = (*ree)->bullEnemyPosX - m_pos->x;
				float distPlayerY = (*ree)->bullEnemyPosY - m_pos->y;
				//between the two values so it can account for the size of the player
				if ((distPlayerX) < 40 && (distPlayerY) < 10 && distPlayerX > -40 && distPlayerY > -10)
				{
					std::cout << "collided with player" << std::endl;
					playerDead = true;
				}
			}
		}
	}
	if (!enemyTwoDead) {
		for (auto reed = m_enemy2->m_activeEnemyBullets.begin(); reed != m_enemy2->m_activeEnemyBullets.end(); reed++) {
			(*reed)->update(deltaTime);
			if (!playerDead && m_enemy2 != nullptr) {
				//checks if the enemy bullet has hit the player
				float distPlayerXo = (*reed)->bullEnemyPosX - m_pos->x;
				float distPlayerYo = (*reed)->bullEnemyPosY - m_pos->y;
				//between the two values so it can account for the size of the player
				if ((distPlayerXo) < 40 && (distPlayerYo) < 10 && distPlayerXo > -40 && distPlayerYo > -10)
				{
					std::cout << "collided with player" << std::endl;
					playerDead = true;
				}
			}
		}
	}
	if (!enemyThreeDead) {
		for (auto red = m_enemy3->m_activeEnemyBullets.begin(); red != m_enemy3->m_activeEnemyBullets.end(); red++) {
			(*red)->update(deltaTime);
			if (!playerDead && m_enemy3 != nullptr) {
				//checks if the enemy bullet has hit the player
				float distPlayerXt = (*red)->bullEnemyPosX - m_pos->x;
				float distPlayerYt = (*red)->bullEnemyPosY - m_pos->y;
				//between the two values so it can account for the size of the player
				if ((distPlayerXt) < 40 && (distPlayerYt) < 10 && distPlayerXt > -40 && distPlayerYt > -10)
				{
					std::cout << "collided with player" << std::endl;
					playerDead = true;
				}
			}
		}
	}

	//able to use both arrow keys and wsad to move
	//numbers at the end restrict the player movement so that the player can't move off the screen
	if ((input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A)) && m_pos->x >= 50)
	{
		//sets player speed in the left direction
		m_pos->x -= 150.0f * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D)) && m_pos->x <= 1230)
	{
		//sets player speed in the right direction
		m_pos->x += 150.0f * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_W)) && m_pos->y <= 350)
	{
		//sets player speed in the up direction
		m_pos->y += 150.0f * deltaTime;
	}

	if ((input->isKeyDown(aie::INPUT_KEY_DOWN)||input->isKeyDown(aie::INPUT_KEY_S)) && m_pos->y >= 50)
	{
		//sets player speed in the down direction
		m_pos->y -= 150.0f * deltaTime;
	}

	//if the enemies aren't dead their positions will continue to update 
	if (!enemyDead) {
		m_enemy->Update(deltaTime);
	}
	if (!enemyTwoDead) {
		m_enemy2->Update(deltaTime);
	}
	if (!enemyThreeDead) {
		m_enemy3->Update(deltaTime);
	}
}

void Player::Draw(aie::Renderer2D * spriteBatch)
{
	//if the player is alive draw it's sprite
	if (!playerDead) {
		spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y);
	}
	//if player is dead print the following
	else {
		spriteBatch->drawText(m_font, "You died!", 550, 500);
	}
	//draws each individual bullet
	for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
	{
		(*it)->Draw(spriteBatch);
	}
	//if the enemy is alive draw it
	if (!enemyDead)
	{
		m_enemy->Draw(spriteBatch);
	}
	//else delete the enemy, set enemy to null, and draw the following 
	else
	{
		delete m_enemy;
		m_enemy = nullptr;
		spriteBatch->drawText(m_font, "2 enemies left!", 540, 600);
	}
	//if the second enemy is alive draw it
	if (!enemyTwoDead) {
		m_enemy2->Draw(spriteBatch);
	}
	//else delete enemy 2, set enemy 2 to null, and draw the following 
	else {
		delete m_enemy2;
		m_enemy2 = nullptr;
		spriteBatch->drawText(m_font, "2 enemies left!", 540, 600);
	}
	//if the third enemy is alive draw it
	if (!enemyThreeDead) {
		m_enemy3->Draw(spriteBatch);
	}
	//else delete enemy 3, set enemy 3 to null, and draw the following 
	else {
		delete m_enemy3;
		m_enemy3 = nullptr;
		spriteBatch->drawText(m_font, "2 enemies left!", 540, 600);
	}
	if (enemyDead && enemyTwoDead && enemyThreeDead) {
		spriteBatch->drawText(m_font, "You Win!", 550, 500);
	}
	//if two enemies die print 1 enemy left
	if (enemyTwoDead && enemyThreeDead) {
		spriteBatch->drawText(m_font, "1 Enemy left!", 540, 550);
	}
	if (enemyTwoDead && enemyThreeDead) {
		spriteBatch->drawText(m_font, "1 Enemy left!", 540, 550);
	}
	if (enemyTwoDead && enemyThreeDead) {
		spriteBatch->drawText(m_font, "1 Enemy left!", 540, 550);
	}
}