#pragma once
#include <Vector2.h>
#include <vector>
#include "GraphEdge.h"
class GraphEdge;

class GraphNode
{
public:
	GraphNode();

	void SetPosition(Vector2 position);
	Vector2 GetPosition();

	void SetVisited(bool visited);
	bool GetVisited();

	void AddConnections(GraphEdge* node);
	std::vector<GraphEdge*> GetConnections();
	~GraphNode();

	void SetParent(GraphNode* node);
	Vector2 GetParent(); 

private:
	bool m_isVisited;
	Vector2				m_position;
	std::vector<GraphEdge*>  m_connections;

};

