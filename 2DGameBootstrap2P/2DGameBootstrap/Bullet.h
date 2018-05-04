#pragma once
namespace aie {
	class Renderer2D;
	class Texture;
}

class Bullet {
public:
	float bullPosX;
	float bullPosY;

	Bullet();
	~Bullet();

	void update(float deltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);
	aie::Texture* m_bulletTex; 
private:
};