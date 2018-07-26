#include "GraphEdge.h"



GraphEdge::GraphEdge()
{
	m_target = nullptr;
}

void GraphEdge::SetNode(GraphNode* target)
{
	this->m_target = target;
}


GraphNode * GraphEdge::GetNode()
{
	return m_target;
}

GraphEdge::~GraphEdge()
{
	delete m_target; 
}
