#pragma once
namespace aie {
	class Renderer2D;
	class Texture;
}
class enemyBullet
{
public:
	float bullEnemyPosX;
	float bullEnemyPosY;

	enemyBullet();
	~enemyBullet();

	void update(float deltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);
	aie::Texture* m_bullEnemyTex;
};