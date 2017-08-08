#include "Graph.h"

int main()
{
	Graph graph;
	graph.addVertex("A"); //0
	graph.addVertex("B"); //1
	graph.addVertex("C"); //2
	graph.addVertex("D"); //3
	graph.addVertex("E"); //4
	graph.addVertex("F"); //5
	graph.addVertex("G"); //6
	graph.addEdge(0, 1,1);
	graph.addEdge(0, 3,1);
	graph.addEdge(1, 3,1);
	graph.addEdge(1, 4,1);
	graph.addEdge(2, 5,1);
	graph.addEdge(3, 5,1);
	graph.addEdge(3, 6,1);
	graph.addEdge(4, 6,1);
	graph.addEdge(6, 5,1);
	cout << "No weight short path:" << endl;
	graph.getShortestPath(0);
	Graph graph2;
	graph2.addVertex("A"); //0
	graph2.addVertex("B"); //1
	graph2.addVertex("C"); //2
	graph2.addVertex("D"); //3
	graph2.addVertex("E"); //4
	graph2.addEdge(0, 2, 1);
	graph2.addEdge(0, 1, 4);
	graph2.addEdge(2, 1, 2);
	graph2.addEdge(2, 3, 4);
	graph2.addEdge(1, 4, 4);
	graph2.addEdge(3, 4, 4);
	cout << "Dijkstra:" << endl;
	graph2.Dijkstra(0);

	cout << "sort vector:" << endl;		// 看一下升序还是降序
	graph2.sortVec();

	cout << "sort heap：" << endl;	// 看一下最大堆还是最小堆
	graph2.sortHeap();
	return 0;
}