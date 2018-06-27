#include "KeyBoardController.h"
#include <Input.h>


KeyBoardController::KeyBoardController()
{
	input = nullptr; 
}

KeyBoardController::KeyBoardController(aie::Input * input)
{
	this->input = input; 
}

void KeyBoardController::update(Agent * agent, float deltaTime)
{
	if (input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_W)) {
		agent->AddForce(Vector2(0, 100.0f));
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN) || input->isKeyDown(aie::INPUT_KEY_S)) {
		agent->AddForce(Vector2(0, -100.0f));
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A)) {
		agent->AddForce(Vector2(-100.0f, 0));
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D)) {
		agent->AddForce(Vector2(100.0f, 0));
	}
}

KeyBoardController::~KeyBoardController()
{
}