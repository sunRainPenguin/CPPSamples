#include "Graph.h"

int main()
{
	Graph graph;
	graph.addVertex("7"); //0
	graph.addVertex("5"); //1
	graph.addVertex("3"); //2
	graph.addVertex("11"); //3
	graph.addVertex("8"); //4
	graph.addVertex("2"); //5
	graph.addVertex("9"); //6
	graph.addVertex("10"); //7
	graph.addEdge(0, 3); 
	graph.addEdge(1, 3);
	graph.addEdge(0, 4);
	graph.addEdge(2, 4);
	graph.addEdge(2, 7);
	graph.addEdge(3, 5);
	graph.addEdge(3, 6);
	graph.addEdge(3, 7);
	graph.addEdge(4, 6);
	graph.topologicalSort();
	return 0;
}