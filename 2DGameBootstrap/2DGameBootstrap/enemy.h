#pragma once
#include <glm\vec2.hpp>
#include <vector>
namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
	class Font;
}
class enemyBullet;
class enemy
{
public:
	enemy();
	enemy(glm::vec2* pos);
	~enemy();

	void Draw(aie::Renderer2D* spriteBatch);
	void Update(float deltaTime);
	glm::vec2* m_enemyPos;
	aie::Texture* m_EnemyTex;
	float timer2 = 0.0f;
	enemyBullet*				m_EnemyBullet;
	std::vector<enemyBullet*>	m_activeEnemyBullets;
	std::vector<enemyBullet*>	m_inActiveEnemyBullets;
	bool						firstWave;


private:
};