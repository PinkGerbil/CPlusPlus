#include "AI_pathfindingApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "KeyBoardController.h"
#include "SeekBehaviour.h"
#include "WanderState.h"
#include "FleeState.h"
#include <imgui.h>
#include "BehaviorChange.h"

AI_pathfindingApp::AI_pathfindingApp() {

}

AI_pathfindingApp::~AI_pathfindingApp() {

}

bool AI_pathfindingApp::startup() {
	timer = 0.0f;
	windowWidth = getWindowWidth();
	windowHeight = getWindowHeight();
	spawn = Vector2 (40, 40); 
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	/*Graphs*/
	m_graph = new Graph();
	/*set up the graph nodes*/
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			GraphNode* node = new GraphNode();
			node->SetPosition(Vector2(i * 32, j * 32));
			m_graph->AddNode(node);
		}
	}

	for (auto x : m_graph->GetNodes())
	{
		for (auto y : m_graph->GetNodes())
		{
			if (x == y)
				continue;

			// find the distance btw x and y node
			int xDist = x->GetPosition().m_x - y->GetPosition().m_x;
			int yDist = x->GetPosition().m_y - y->GetPosition().m_y;
			// find the magnitude
			int mag = sqrt((xDist * xDist) + (yDist * yDist)); 
			// check the length with scalar value 
			if (mag <= 50 && mag >= -50) {
				m_graph->ConnectNode(x, y); 
			}
		}
	}


	/*Player*/	
	m_player = new Agent(new aie::Texture("../bin/textures/ship.png"), Vector2(40, 40)); 
	m_player->AddBehaviour(new KeyBoardController(aie::Input::getInstance()));
	m_player->setHealth(3); 

	/*enemies*/
	m_enemy = new Agent(new aie::Texture("../bin/textures/carPolice.png"), Vector2(800, 100));
	//m_enemy->AddBehaviour(new BehaviorChange(new SeekBehaviour(m_player)));
	m_enemy->AddBehaviour(new BehaviorChange(new WanderState(30.0f, 400.0f, 5.0f, m_player, 0)));

	//m_enemyWan = new Agent(new aie::Texture("../bin/textures/carWanderer.png"), Vector2(400, 100));
	//m_enemyWan->AddBehaviour(new BehaviorChange(new WanderState(30.0f, 400.0f, 5.0f, m_player)));

	m_enemyFlee = new Agent(new aie::Texture("../bin/textures/carRed.png"), Vector2(600, 100));
	m_enemyFlee->AddBehaviour(new BehaviorChange(new WanderState(30.0f, 400.0f, 5.0f, m_player, 1)));

	/*background*/
	m_background.load("../images/snow.png");
	m_background.setPosition(windowWidth / 2, windowHeight / 2);

	die			 = false; 
	enemyDie	 = false; 
	enemyFleeDie = false; 

	return true;
}

void AI_pathfindingApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_player;
	delete m_enemy;
	delete m_enemyFlee;
}

void AI_pathfindingApp::update(float deltaTime) {
	/*input example*/
	PHealth = m_player->getHealth();
	timer += deltaTime;
	aie::Input* input = aie::Input::getInstance();

	/*true false statements to make the player & enemy die*/
	if (timer > 1.0f) { //timer used so you can't "die" as soon as you spawn
		if (m_player->Overlap(m_enemy)) {
			die = true;
		}
		if (m_player->Overlap(m_enemyFlee)) {
			enemyFleeDie = true;
		}
	}
	

	/*starts updates*/
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

	if (!die){
		m_player->Update(deltaTime);
	}
	else {
		if (input->wasKeyPressed(aie::INPUT_KEY_R) && m_player->getHealth() > 0)
		{
			m_player->setPosition(spawn); 
			m_player->setHealth(m_player->getHealth() - 1); 
			die = false; 
		}
	}

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

	//m_enemyWan->Update(deltaTime);

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
	//if (!m_enemyFlee->Overlap(m_player)) {
	if(!enemyFleeDie){
		m_enemyFlee->Update(deltaTime);
	}

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
	/*death functions*/
	if(!die){
		m_player->draw(m_2dRenderer);
		m_2dRenderer->drawText(m_font, "Space Cowboy", m_player->position.m_x - 110, m_player->position.m_y + 30);
	}
	else {
		m_2dRenderer->drawText(m_font, "arrested", m_player->position.m_x - 110, m_player->position.m_y + 30);
	}
	m_enemy->draw(m_2dRenderer);
	m_2dRenderer->drawText(m_font, "Police", m_enemy->position.m_x - 50, m_enemy->position.m_y + 25);

	if(!enemyFleeDie){
		m_enemyFlee->draw(m_2dRenderer);
		m_2dRenderer->drawText(m_font, "Scaredy Boi", m_enemyFlee->position.m_x - 110, m_enemyFlee->position.m_y + 30);
	}

	/*graph*/
	m_graph->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	/*statistics window*/
	ImGui::Begin("Stats:");
	ImGui::Text("Player's Health: (%1.0f)", PHealth);
	ImGui::Text("Window Width: (%1.0f)", windowWidth);
	ImGui::Text("Window Height: (%1.0f)", windowHeight);
	ImGui::Text("Timer (%1.2f)", timer);
	ImGui::Text("Player's X Position: (%1.0f)", m_player->getPosition().m_x);
	ImGui::Text("Player's Y Position: (%1.0f)", m_player->getPosition().m_y);
	ImGui::End();

	// done drawing sprites
	m_2dRenderer->end();
}