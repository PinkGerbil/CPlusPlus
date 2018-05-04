#include "SecondPlayer.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>
#include <iostream>
#include "SecondBullet.h"
#include <cstdlib>
#include <ctime>
#include <Font.h>
#include <Windows.h>

SecondPlayer::SecondPlayer()
{
}

SecondPlayer::SecondPlayer(glm::vec2 * pos)
{
	m_SecTexture = new aie::Texture("../bin/textures/shipPink.png");
	m_SecPos = pos;
	timer = 0.0f;
	for (int i = 0; i < 2000; ++i)
	{
		m_Secbullet = new SecondBullet();
		m_inActiveSecBullets.push_back(m_Secbullet);
	}
}


SecondPlayer::~SecondPlayer()
{
	delete m_SecTexture;
	delete m_Secbullet;
}

void SecondPlayer::Update(float deltaTime, aie::Input * input)
{
	timer += deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_KP_0) && timer > 1.0f)
	{
		SecondBullet* newSecBullet;
		if (m_inActiveSecBullets.size() > 0) {
			newSecBullet = m_inActiveSecBullets.at(m_inActiveSecBullets.size() - 1);
			newSecBullet->bullSecPosX = m_SecPos->x;
			newSecBullet->bullSecPosY = m_SecPos->y;
			m_activeSecBullets.push_back(newSecBullet);
			m_inActiveSecBullets.pop_back();
			std::cout << "inactive: " << m_inActiveSecBullets.size() << std::endl;
			std::cout << "active: " << m_activeSecBullets.size() << std::endl;
		}
		else {
			//outOfBullets = true; 
			std::cout << "No bullets left" << std::endl;
		}
		timer = 0.0f;
	}

	if (m_activeSecBullets.size() >= 1900)
	{
		for (auto it = m_activeSecBullets.begin(); it != m_activeSecBullets.end(); ++it)
		{
			SecondBullet* usedSecBullet;
			if ((*it)->bullSecPosY >= 720)
			{
				usedSecBullet = m_activeSecBullets.at(m_activeSecBullets.size() - 1);
				usedSecBullet->bullSecPosX = m_SecPos->x;
				usedSecBullet->bullSecPosY = m_SecPos->y;
				m_inActiveSecBullets.push_back(usedSecBullet);
				m_activeSecBullets.pop_back();
			}
		}
	}

	for (auto it = m_activeSecBullets.begin(); it != m_activeSecBullets.end(); ++it)
	{
		(*it)->Update(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) && m_SecPos->x >= 50)
	{
		m_SecPos->x -= 250.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) && m_SecPos->x <= 1230)
	{
		m_SecPos->x += 250.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_UP) && m_SecPos->y <= 400)
	{
		m_SecPos->y += 200.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN) && m_SecPos->y >= 50)
	{
		m_SecPos->y -= 200.0f * deltaTime;
	}
}

void SecondPlayer::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_SecTexture, m_SecPos->x, m_SecPos->y);
	for (auto it = m_activeSecBullets.begin(); it != m_activeSecBullets.end(); ++it)
	{
		(*it)->Draw(spriteBatch);
	}
	
}
