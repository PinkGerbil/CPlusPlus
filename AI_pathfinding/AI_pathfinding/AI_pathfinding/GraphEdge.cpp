#include "GraphEdge.h"



GraphEdge::GraphEdge()
{
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
}
