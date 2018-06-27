#include "StateMachine.h"



StateMachine::StateMachine()
{
	currentState = nullptr;
	prevState = nullptr;
}

void StateMachine::ChangeState(Agent * agent, State * state)
{
}

State * StateMachine::GetCurrentState()
{
	return currentState;
}

State * StateMachine::GetPrevState()
{
	return prevState;
}


StateMachine::~StateMachine()
{
	delete currentState;
	delete prevState;	
}