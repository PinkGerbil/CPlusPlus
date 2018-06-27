#pragma once
#include <Vector2.h>
#include <vector>
class GraphNode; 

class GraphEdge
{
public:
	GraphEdge();

	void SetNode(GraphNode* target);

	GraphNode* GetNode();

	~GraphEdge();

private:
	GraphNode * m_target; 
};

