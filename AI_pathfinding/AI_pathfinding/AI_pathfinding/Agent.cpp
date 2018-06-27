#include "Agent.h"
#include <Renderer2D.h>
#include <Texture.h>
#include "IBehavior.h"


Agent::Agent()
{
	texture = nullptr; 
	position = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
}

Agent::Agent(aie::Texture * Ttexture, Vector2 Pposition)
{
	this->texture = Ttexture;
	this->position = Pposition;
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
}

void Agent::Update(float deltaTime)
{
	AddForce(velocity * -0.15f);
	velocity = velocity + acceleration * deltaTime;
	position = position + velocity * deltaTime;
	acceleration = Vector2(0, 0);
	for (auto behavior : m_behaviour) {
		behavior->update(this, deltaTime);
	}
}

void Agent::draw(aie::Renderer2D * renderer)
{
	renderer->drawSprite(texture, position.m_x, position.m_y);
}

void Agent::AddForce(Vector2 force)
{
	acceleration = acceleration + force; 
}

void Agent::AddBehaviour(IBehavior * behaviour)
{
	m_behaviour.push_back(behaviour);
}

Vector2 Agent::setPosition(Vector2 pos)
{
	return Vector2();
}

Vector2 Agent::getPosition()
{
	return position;
}

Agent::~Agent()
{
	delete texture;
}
