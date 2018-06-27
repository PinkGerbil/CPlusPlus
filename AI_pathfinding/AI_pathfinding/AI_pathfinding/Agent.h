#pragma once
#include <Vector2.h>
#include <vector>

namespace aie
{
	class Renderer2D;
	class Texture;
}
class IBehavior;

class Agent
{
public:
	Agent();
	Agent(aie::Texture* texture, Vector2 position);
	void Update(float deltaTime);
	void draw(aie::Renderer2D* renderer);
	void AddForce(Vector2 force);
	void AddBehaviour(IBehavior* behaviour);
	Vector2 setPosition(Vector2 pos);
	Vector2 getPosition();
	~Agent();
	Vector2 acceleration;
	Vector2 velocity; 
	Vector2 position; 
	aie::Texture* texture; 
protected:
	std::vector<IBehavior*>  m_behaviour;
};