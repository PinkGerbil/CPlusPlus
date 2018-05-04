#include "enemyBullet.h"
#include <Texture.h>
#include <Renderer2D.h>

enemyBullet::enemyBullet()
{
	bullEnemyPosX = 0.0f;
	bullEnemyPosY = 0.0f;
	m_bullEnemyTex = new aie::Texture("../bin/textures/bullet.png");
}


enemyBullet::~enemyBullet()
{
	delete m_bullEnemyTex;
}

void enemyBullet::update(float deltaTime)
{
	bullEnemyPosY -= 3.0f;
}

void enemyBullet::Draw(aie::Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_bullEnemyTex, bullEnemyPosX, bullEnemyPosY);
}
