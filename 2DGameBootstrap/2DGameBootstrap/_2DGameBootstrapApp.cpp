#include "_2DGameBootstrapApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include "Player.h"
#include "Bullet.h"
#include "enemy.h"

_2DGameBootstrapApp::_2DGameBootstrapApp() {

}

_2DGameBootstrapApp::~_2DGameBootstrapApp() {

}

bool _2DGameBootstrapApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_player = new Player(new glm::vec2(60, 60)); 
	//m_enemy = new enemy(new glm::vec2(60, 680));
	m_timer = 0;
	return true;
}

void _2DGameBootstrapApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_player; 
	
}

void _2DGameBootstrapApp::update(float deltaTime) {

	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->Update(deltaTime, input);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void _2DGameBootstrapApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	ImGui::Begin("Sample Window"); 
	ImGui::Text("timer: (%1.1f)", m_timer); 
	static float defValue = 50.0f;
	ImGui::SliderFloat("test slide", &defValue, 0.0f, 100.0f, "%.1f");
	ImGui::End();

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	//if (outOfBullets = true) {
	//	m_2dRenderer->drawText(m_font, "Out Of Bullets", 550, 500);
	//}
	m_player->Draw(m_2dRenderer);
	//m_enemy->Draw(m_2dRenderer);
	// done drawing sprites
	m_2dRenderer->end();
}