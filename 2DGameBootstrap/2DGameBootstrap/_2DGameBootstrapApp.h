#pragma once

#include "Application.h"
#include "Renderer2D.h"
class Player;
class enemy;
//class Bullet;
class _2DGameBootstrapApp : public aie::Application {
public:

	_2DGameBootstrapApp();
	virtual ~_2DGameBootstrapApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Player*				m_player;
	float				m_timer; 
	//enemy*				m_enemy;
	//bool outOfBullets = false; 
};