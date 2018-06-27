#include "AI_pathfindingApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "KeyBoardController.h"
#include "Agent.h"
#include "SeekBehaviour.h"
#include "WanderState.h"
#include "FleeState.h"
#include <imgui.h>

AI_pathfindingApp::AI_pathfindingApp() {

}

AI_pathfindingApp::~AI_pathfindingApp() {

}

bool AI_pathfindingApp::startup() {
	timer = 0.0f;
	windowWidth = getWindowWidth();
	windowHeight = getWindowHeight();

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	/*Player*/
	
	m_player = new Agent(new aie::Texture("../bin/textures/ship.png"), Vector2(40, 40)); 
	m_player->AddBehaviour(new KeyBoardController(aie::Input::getInstance()));

	m_enemy = new Agent(new aie::Texture("../bin/textures/carPolice.png"), Vector2(800, 100));
	m_enemy->AddBehaviour(new SeekBehaviour(m_player));

	m_enemyWan = new Agent(new aie::Texture("../bin/textures/carWanderer.png"), Vector2(400, 100));
	m_enemyWan->AddBehaviour(new WanderState(5.0f, 5.0f, 5.0f));

	m_enemyFlee = new Agent(new aie::Texture("../bin/textures/carRed.png"), Vector2(600, 100));
	m_enemyFlee->AddBehaviour(new FleeState(m_player));

	/*background*/
	m_background.load("../images/snow.png");
	m_background.setPosition(windowWidth / 2, windowHeight / 2);

	return true;
}

void AI_pathfindingApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_player;
	delete m_enemy;
	delete m_enemyWan;
	delete m_enemyFlee;
}

void AI_pathfindingApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	/*starts updates*/
	timer += deltaTime;
	m_background.update(deltaTime);
	if (m_player->position.m_x > getWindowWidth() + 100) {
		m_player->position.m_x = -95;
	}
	if (m_player->position.m_x < -95) {
		m_player->position.m_x =  getWindowWidth() + 100;
	}
	if (m_player->position.m_y > getWindowHeight() + 70) {
		m_player->position.m_y = -70;
	}
	if (m_player->position.m_y < -70) {
		m_player->position.m_y = getWindowHeight() + 70;
	}
	m_player->Update(deltaTime);

	if (m_enemy->position.m_x > getWindowWidth() + 100) {
		m_enemy->position.m_x = -95;
	}
	if (m_enemy->position.m_x < -95) {
		m_enemy->position.m_x = getWindowWidth() + 100;
	}	
	if (m_enemy->position.m_y > getWindowHeight() + 70) {
		m_enemy->position.m_y = -70;
	}	
	if (m_enemy->position.m_y < -70) {
		m_enemy->position.m_y = getWindowHeight() + 70;
	}
	m_enemy->Update(deltaTime);

	if (m_enemyWan->position.m_x > getWindowWidth() + 100) {
		m_enemyWan->position.m_x = -95;
	}		  
	if (m_enemyWan->position.m_x < -95) {
		m_enemyWan->position.m_x = getWindowWidth() + 100;
	}		   
	if (m_enemyWan->position.m_y > getWindowHeight() + 60) {
		m_enemyWan->position.m_y = -60;
	}		   
	if (m_enemyWan->position.m_y < -60) {
		m_enemyWan->position.m_y = getWindowHeight() + 60;
	}
	m_enemyWan->Update(deltaTime);

	if (m_enemyFlee->position.m_x > getWindowWidth() - 80) {
		m_enemyFlee->position.m_x = 75;
	}		   
	if (m_enemyFlee->position.m_x < 75) {
		m_enemyFlee->position.m_x = getWindowWidth() - 80;
	}		   
	if (m_enemyFlee->position.m_y > getWindowHeight() - 70) {
		m_enemyFlee->position.m_y = 70;
	}		   
	if (m_enemyFlee->position.m_y < 70) {
		m_enemyFlee->position.m_y = getWindowHeight() - 70;
	}
	m_enemyFlee->Update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AI_pathfindingApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_background.draw(m_2dRenderer);
	m_player->draw(m_2dRenderer);
	m_enemy->draw(m_2dRenderer);
	m_enemyWan->draw(m_2dRenderer);
	m_enemyFlee->draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	m_2dRenderer->drawText(m_font, "Space Cowboy", m_player->position.m_x - 110, m_player->position.m_y + 30);

	m_2dRenderer->drawText(m_font, "Police", m_enemy->position.m_x - 50, m_enemy->position.m_y + 25);
	m_2dRenderer->drawText(m_font, "The Wanderer", m_enemyWan->position.m_x - 110, m_enemyWan->position.m_y + 30);
	m_2dRenderer->drawText(m_font, "Scaredy Boi", m_enemyFlee->position.m_x - 110, m_enemyFlee->position.m_y + 30);

	ImGui::Begin("Stats:");
	ImGui::Text("Window Width: (%1.0f)", windowWidth);
	ImGui::Text("Window Height: (%1.0f)", windowHeight);
	ImGui::Text("Timer (%1.2f)", timer);
	ImGui::Text("Player's X Position: (%1.0f)", m_player->getPosition().m_x);
	ImGui::Text("Player's Y Position: (%1.0f)", m_player->getPosition().m_y);
	ImGui::End();

	// done drawing sprites
	m_2dRenderer->end();
}