#pragma once
namespace aie {
	class Renderer2D;
	class Texture;
}

class SecondBullet
{
public:
	float bullSecPosX;
	float bullSecPosY;

	SecondBullet();
	~SecondBullet();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);
	aie::Texture* m_bulletSecTex;
};