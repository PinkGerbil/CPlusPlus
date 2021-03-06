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
	SecondPlayer*			m_SecondPlayer;
	enemy*					m_enemy;
	enemy*					m_enemy2;
	enemy*					m_enemy3;
	enemy*					m_enemy4;
	float					timer;
	bool					playerOneDead;
	bool					playerTwoDead;
	bool					enemyDead;
	bool					enemyTwoDead;
	bool					enemyThreeDead;
	bool					enemyFourDead;
};