#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <Matrix3.h>
#include <glm\vec2.hpp>
#include "SpriteObject.h"
//class GameObject;

class Agent;
class AI_pathfindingApp : public aie::Application {
public:

	AI_pathfindingApp();
	virtual ~AI_pathfindingApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	float				windowWidth;
	float				windowHeight;
	float				timer;
	float				PHealth; 
	//Vector2				spawn; 
	glm::vec2			pos;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_Ptex;
	aie::Texture*		m_Etex;
	SpriteObject		m_background;
	Agent*				m_player;
	Agent*				m_enemy;
	Agent*				m_enemyWan;
	Agent*				m_enemyFlee;
	/*BehaviorChange*		m_stateMachine;*/
	bool die;
	bool enemyDie;
	bool enemyWanDie;
	bool enemyFleeDie;
};