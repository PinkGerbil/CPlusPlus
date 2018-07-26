#include "GraphNode.h"


GraphNode::GraphNode()
{
	m_parent = nullptr;
	m_position = Vector2(0, 0);
	m_isVisited = false;
	m_gScore = 0;
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

void GraphNode::AddConnections(GraphNode* node)
{
	GraphEdge* edge = new GraphEdge(); 
	edge->SetNode(node);
	m_connections.push_back(edge);
}

std::vector<GraphEdge*> GraphNode::GetConnections()
{
	return m_connections; 
}


GraphNode::~GraphNode()
{
	delete m_parent; 
	for (auto c : m_connections) {
		delete c; 
	}
}

void GraphNode::SetParent(GraphNode * node)
{
	m_parent = node; 
}

Vector2 GraphNode::GetParent()
{
	return m_parent->GetPosition(); 
}

void GraphNode::SetGScore(float gScore)
{
	m_gScore = gScore; 
}

float GraphNode::GetGScore()
{
	return m_gScore; 
}
