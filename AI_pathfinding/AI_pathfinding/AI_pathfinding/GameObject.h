#pragma once
#include <glm\vec2.hpp>
#include "SeekBehaviour.h"
#include <vector>
#include "IBehavior.h"
namespace aie {
	class Renderer2D;
	class Texture;
}

class SeekBehaviour;

class GameObject
{
public:
	GameObject();
	GameObject(GameObject* target, aie::Texture* texture, glm::vec2 pos, float width, float height);
	~GameObject();

	void update(float deltaTime);
	void draw(aie::Renderer2D* rendered);

	//void addBehavior(IBehavior* behavior); 

	void AddForce(glm::vec2 force);
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 acceleration;

private:
	std::vector<IBehavior*> m_behaviors;
	aie::Texture* texture;
	SeekBehaviour* seek;
	float width;
	float height;
};

