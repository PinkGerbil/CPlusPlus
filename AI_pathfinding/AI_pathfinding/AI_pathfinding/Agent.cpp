#include "Agent.h"
#include <Renderer2D.h>
#include <Texture.h>
#include "AABB.h"
#include <iostream>
#include "SeekBehaviour.h"

Agent::Agent()
{
	texture = nullptr; 
	position = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
	m_box = nullptr;
	overlapped = false; 
}

Agent::Agent(aie::Texture * Ttexture, Vector2 Pposition)
{
	this->texture = Ttexture;
	this->position = Pposition;
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
	m_box = new AABB();
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
	int w = texture->getWidth();
	int h = texture->getHeight();
	m_box->Min = Vector2(-w / 2 + position.m_x, -h / 2 + position.m_y);
	m_box->Max = Vector2(w / 2 + position.m_x, h / 2 + position.m_y);
	m_box->center();
}

void Agent::draw(aie::Renderer2D * renderer)
{
	//renderer->drawBox(m_box->center().m_x, m_box->center().m_y, m_box->extents().m_x * 2, m_box->extents().m_y * 2);
	auto corners = m_box->corners();
	renderer->drawLine(corners[0].m_x, corners[0].m_y,
		corners[1].m_x, corners[1].m_y, 5);
	renderer->drawLine(corners[1].m_x, corners[1].m_y,
		corners[2].m_x, corners[2].m_y, 5);
	renderer->drawLine(corners[2].m_x, corners[2].m_y,
		corners[3].m_x, corners[3].m_y, 5);
	renderer->drawLine(corners[3].m_x, corners[3].m_y,
		corners[0].m_x, corners[0].m_y, 5);
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

int Agent::setHealth(int health)
{
	return Health = health; 
}

int Agent::getHealth()
{
	return Health;
}

AABB* Agent::getAABB()
{
	return m_box; 
}

Vector2 Agent::setPosition(Vector2 pos)
{
	return position = pos;
}

Vector2 Agent::getPosition()
{
	return position;
}

Agent::~Agent()
{
	delete texture;
	delete m_box;
}

bool Agent::Overlap(Agent * other)
{	
	if (m_box->overlaps(*other->getAABB())) {
		std::cout << "Collided" << std::endl;
		return true; 
	}
}
