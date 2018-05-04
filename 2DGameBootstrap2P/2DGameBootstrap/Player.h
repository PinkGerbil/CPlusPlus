#pragma once
#include <glm\vec2.hpp>
#include <vector>

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
	class Font;
}
class Bullet;
class enemy;
class SecondPlayer; 
class Player
{
public:
	Player();
	Player(glm::vec2* pos);
	~Player();

	void Update(float deltaTime, aie::Input* input);
	void Draw(aie::Renderer2D* spriteBatch);


private:
	glm::vec2*				m_pos;
	aie::Texture*			m_texture;
	std::vector<Bullet*>	m_activeBullets;
	std::vector<Bullet*>	m_inActiveBullets;
	Bullet*					m_bullet; 
	aie::Font*				m_font;
	enemy*					m_enemy;
	SecondPlayer*			m_SecondPlayer;
	float					timer;
	bool					playerOneDead;
	bool					playerTwoDead;
	bool					enemyDead;
};

