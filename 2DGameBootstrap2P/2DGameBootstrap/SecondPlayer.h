#pragma once
#include <glm\vec2.hpp>
#include <vector>

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
	class Font;
}

class SecondBullet;
class SecondPlayer
{
public:
	SecondPlayer();
	SecondPlayer(glm::vec2* pos);
	~SecondPlayer();

	SecondBullet* m_Secbullet;
	void Update(float deltaTime, aie::Input* input);
	void Draw(aie::Renderer2D* spriteBatch);
	glm::vec2* m_SecPos;
	std::vector<SecondBullet*> m_activeSecBullets;
	std::vector<SecondBullet*> m_inActiveSecBullets;
private:
	aie::Texture* m_SecTexture;
	float timer;
};

