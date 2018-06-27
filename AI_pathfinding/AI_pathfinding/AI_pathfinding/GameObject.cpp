#include "GameObject.h"
#include <Renderer2D.h>


GameObject::GameObject()
{
}

GameObject::GameObject(GameObject * target, aie::Texture * texture, glm::vec2 pos, float width, float height)
{
	this->texture = texture;
	this->position = pos;
	this->width = width;
	this->height = height;
	//seek = new SeekBehaviour(target);
	velocity = glm::vec2(0, 0);
	acceleration = glm::vec2(0, 0);
}

GameObject::~GameObject()
{
}

void GameObject::update(float deltaTime)
{
	AddForce(velocity * -1.0f);
	velocity += acceleration * deltaTime; 
	position += velocity * deltaTime; 
	acceleration = glm::vec2(0, 0); 
	//if (seek->target != nullptr) {
	//	seek->update(this, deltaTime);
	//}
}

void GameObject::draw(aie::Renderer2D * rendered)
{
	rendered->drawSprite(texture, position.x, position.y, width, height);
}

void GameObject::AddForce(glm::vec2 force)
{
	acceleration += force;
}
