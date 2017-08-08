#include "Graph.h"

int main()
{
	Graph graph = Graph();
	char temp = NULL;
	for (int i = 0; i < 8; i++)
	{
		temp = 'A' + i;
		graph.addVertex(temp);
	}
	graph.addEdge(0, 1);
	graph.addEdge(1, 7);
	graph.addEdge(1, 2);
	graph.addEdge(2, 4);
	graph.addEdge(4, 7);
	graph.addEdge(2, 3);
	graph.addEdge(4, 5);
	graph.addEdge(4, 6);
	graph.dfs(0);
	graph.bfs(0);
	return 0;
}
