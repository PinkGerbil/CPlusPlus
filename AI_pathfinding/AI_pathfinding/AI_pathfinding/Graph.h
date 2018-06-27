#pragma once
#include "GraphEdge.h"
#include "GraphNode.h"
#include <Renderer2D.h>

namespace aie {
	class Renderer2D;
}

class Graph
{
public:
	Graph();

	void AddNode(GraphNode* node);
	void ConnectNode(GraphNode* a, GraphNode* b);

	std::vector<GraphNode*> GetNodes(); 

	std::vector<GraphNode*> DFS(GraphNode* startNode, GraphNode* endNode);

	void Draw(aie::Renderer2D * renderer);

private:

	std::vector<GraphNode*> m_nodes; 

	~Graph();
};

