#include "GraphNode.h"


GraphNode::GraphNode()
{
	m_position = Vector2(0, 0);
	m_isVisited = false;
}

void GraphNode::SetPosition(Vector2 position)
{
	m_position = position;
}

Vector2 GraphNode::GetPosition()
{
	return m_position;
}

void GraphNode::SetVisited(bool visited)
{
	m_isVisited = visited;
}

bool GraphNode::GetVisited()
{
	return m_isVisited;
}

void GraphNode::AddConnections(GraphEdge* node)
{
	GraphEdge* edge = new GraphEdge(); 
	//edge->SetNode();
}

std::vector<GraphEdge*> GraphNode::GetConnections()
{
	return std::vector<GraphEdge*>();
}


GraphNode::~GraphNode()
{
	for (auto c : m_connections) {
		delete c; 
	}
}

void GraphNode::SetParent(GraphNode * node)
{
}

Vector2 GraphNode::GetParent()
{
	return Vector2();
}

void GraphNode::SetGScore(float gScore)
{
}

float GraphNode::GetGScore()
{
	return 0.0f;
}
