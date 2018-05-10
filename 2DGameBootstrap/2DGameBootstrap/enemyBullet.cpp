#include "enemyBullet.h"
#include <Texture.h>
#include <Renderer2D.h>

enemyBullet::enemyBullet()
{
	//sets the enemy's bullet position
	bullEnemyPosX = 0.0f;
	bullEnemyPosY = 0.0f;
	//sets the enemy's bullet texture
	m_bullEnemyTex = new aie::Texture("../bin/textures/bullet.png");
}


enemyBullet::~enemyBullet()
{
	//delete the bullet texture
	delete m_bullEnemyTex;
}

void enemyBullet::update(float deltaTime)
{
	//sets the speed of the enemy bullet
	bullEnemyPosY -= 200.0f * deltaTime;
}

void enemyBullet::Draw(aie::Renderer2D * m_2dRenderer)
{
	//draws the bullet
	m_2dRenderer->drawSprite(m_bullEnemyTex, bullEnemyPosX, bullEnemyPosY);
}
