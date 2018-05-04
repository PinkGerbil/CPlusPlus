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

	float enemyPosX;
	float enemyPosY;
	void Draw(aie::Renderer2D* spriteBatch);
	void Update(float deltaTime);
	glm::vec2* m_enemyPos;
	aie::Texture* m_EnemyTex;
	enemyBullet* m_EnemyBullet;
	std::vector<enemyBullet*> m_activeEnemyBullets;
	std::vector<enemyBullet*> m_inActiveEnemyBullets;


private:
	float timer2 = 0.0f;
	float timer3 = 0.0f;
	bool firstWave;
};