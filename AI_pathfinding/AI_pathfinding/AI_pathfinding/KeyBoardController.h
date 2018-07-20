#pragma once
#include "Behavior.h"

namespace aie {
	class Input;
}

class KeyBoardController : public IBehavior
{
public:
	KeyBoardController();
	KeyBoardController(aie::Input* input);
	virtual void update(Agent* agent, float deltaTime);
	~KeyBoardController();
private:
	aie::Input* input; 
};