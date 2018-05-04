#include "SecondBullet.h"
#include <Texture.h>
#include <Renderer2D.h>


SecondBullet::SecondBullet()
{
	bullSecPosX = 0.0f;
	bullSecPosY = 0.0f;
	m_bulletSecTex = new aie::Texture("../bin/textures/bullet.png");
}


SecondBullet::~SecondBullet()
{
	delete m_bulletSecTex;
}

void SecondBullet::Update(float deltaTime)
{
	bullSecPosY += 400.0f * deltaTime;
}

void SecondBullet::Draw(aie::Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_bulletSecTex, bullSecPosX, bullSecPosY);
}
