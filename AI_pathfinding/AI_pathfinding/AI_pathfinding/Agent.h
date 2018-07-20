#pragma once
#include <Vector2.h>
#include <vector>
#include "IBehavior.h"
class AABB;

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
	/*Base*/
	void Update(float deltaTime);
	void draw(aie::Renderer2D* renderer);
	void AddBehaviour(IBehavior* behaviour);
	aie::Texture* texture; 
	/*Health*/
	int setHealth(int health); 
	int getHealth(); 
	int	Health;
	/*Position*/
	Vector2 position; 
	Vector2 setPosition(Vector2 pos);
	Vector2 getPosition();
	~Agent();
	/*Movement*/
	void AddForce(Vector2 force);
	Vector2 acceleration;
	Vector2 velocity; 
	/*Collision*/
	bool Overlap(Agent* other);
	AABB* getAABB();
	AABB*		m_box;
	AABB*		aA;
	AABB*		bA;
	bool overlapped;
//	int tag; 
protected:
	std::vector<IBehavior*>  m_behaviour;
};