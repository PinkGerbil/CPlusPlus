#include "Graph.h"
#include <stack>


Graph::Graph()
{
}

void Graph::AddNode(GraphNode * node)
{
}

void Graph::ConnectNode(GraphNode * a, GraphNode * b)
{
}

std::vector<GraphNode*> Graph::GetNodes()
{
	return m_nodes; 
}

//std::vector<GraphNode*> Graph::DFS(GraphNode * startNode, GraphNode * endNode)
//{
//	std::stack<GraphNode*> nodeStack; 
//	nodeStack.push(startNode);
//	while (!nodeStack.empty())
//	{
//		//get the top off the stack and remove it
//		GraphNode* currentNode = nodeStack.top();
//		//remove top item from stack
//		nodeStack.pop();
//		//mark as traversed
//		currentNode->SetVisited(true);
//		//loop through all edges of current node
//	//	for (auto e : currentNode->GetConnections) {
//	//		if (!e->GetNode()->GetVisited()) {
//	//			nodeStack.push(e->GetNode());
//	//
//	//		}
//	//	}
//	}
//}

std::vector<GraphNode*> Graph::DjikstraSearch(GraphNode * startNode, GraphNode * endNode)
{
	return std::vector<GraphNode*>();
}

void Graph::Draw(aie::Renderer2D * renderer)
{
	for (auto node : m_nodes) {
		for (auto it : node->GetConnections()) {
			renderer->drawLine(node->GetPosition().m_x, node->GetPosition().m_y, it->GetNode()->GetPosition().m_x, it->GetNode()->GetPosition().m_y);
		}
		renderer->drawCircle(node->GetPosition().m_x, node->GetPosition().m_y, 20.0f);
	}
}


Graph::~Graph()
{
}
