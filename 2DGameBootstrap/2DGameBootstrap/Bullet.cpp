#include "Bullet.h"
#include <Texture.h>
#include <Renderer2D.h>


Bullet::Bullet()
{
	//sets the bullets initial positions to 0, 0
	bullPosX = 0.0f;
	bullPosY = 0.0f;
	//sets the bullets texture
	m_bulletTex = new aie::Texture("../bin/textures/bullet.png");
}


Bullet::~Bullet()
{
	//deletes the bullet texture
	delete m_bulletTex;
}

void Bullet::update(float deltaTime)
{
	//sets the bullets speed
	bullPosY += 350.0f * deltaTime;
}

void Bullet::Draw(aie::Renderer2D * m_2dRenderer)
{
	//draw function for the bullet
	m_2dRenderer->drawSprite(m_bulletTex, bullPosX, bullPosY);
}
