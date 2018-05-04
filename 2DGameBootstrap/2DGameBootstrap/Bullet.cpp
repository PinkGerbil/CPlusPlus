#include "Bullet.h"
#include <Texture.h>
#include <Renderer2D.h>


Bullet::Bullet()
{
	bullPosX = 0.0f;
	bullPosY = 0.0f;
	m_bulletTex = new aie::Texture("../bin/textures/bullet.png");
}


Bullet::~Bullet()
{
	delete m_bulletTex;
}

void Bullet::update(float deltaTime)
{
	bullPosY += 200.0f * deltaTime;
}

void Bullet::Draw(aie::Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_bulletTex, bullPosX, bullPosY);
}
