#pragma once
#include "IBehavior.h"

class SeekBehaviour : public IBehavior
{
public:
	SeekBehaviour();
	SeekBehaviour(Agent* target);
	void update(Agent* agent, float deltaTime); 
	~SeekBehaviour();

private:
	Agent* m_target; 
};

