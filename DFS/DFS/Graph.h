#pragma once
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class Vertex
{
public:
	char label;
	bool visited;
	Vertex(char label)
	{
		this->label = label;
		this->visited = false;
	}
};

class Graph
{
public:
	Graph()
	{
		vertexCount = 0;
		for (int i = 0; i < maxVertices; i++)
		{
			for (int j = 0; j < maxVertices; j++)
			{
				adjMatrix[i][j] = 0;
			}
		}
	}

	const int maxVertices = 20;
	Vertex* vertexList[20];
	int adjMatrix[20][20];
	int vertexCount;
	stack<int> vStack;
	queue<int> vQueue;
	void addVertex(char lab)
	{
		vertexList[vertexCount++] = new Vertex(lab);
	}

	void addEdge(int start, int end)
	{
		adjMatrix[start][end] = 1;
		adjMatrix[end][start] = 1;
	}

	void displayVertex(int v)
	{
		cout << vertexList[v]->label << endl;
	}

	void dfs(int s)
	{
		vertexList[s]->visited = true;
		displayVertex(s);
		vStack.push(s);
		int v = -1;
		while (!vStack.empty())
		{
			v = getAdjUnvisited(vStack.top());
			if (v == -1)
			{
				vStack.pop();
			}
			else
			{
				vertexList[v]->visited = true;
				displayVertex(v);
				vStack.push(v);
			}
		}

		// ≥ı ºªØ∑√Œ ◊¥Ã¨
		for (int i = 0; i < vertexCount; i++)
		{
			vertexList[i]->visited = false;
		}
	}

	void bfs(int s)
	{
		vertexList[s]->visited = true;
		displayVertex(s);
		vQueue.push(s);
		int v1 = -1;
		int v2 = -1;
		while (!vQueue.empty())
		{
			v1 =vQueue.front();
			vQueue.pop();
			v2 = getAdjUnvisited(v1);
			while (v2 != -1)
			{
				vertexList[v2]->visited = true;
				displayVertex(v2);
				vQueue.push(v2);
				v2 = getAdjUnvisited(v1);
			}
		}
		for (int i = 0; i < vertexCount; i++)
		{
			vertexList[i]->visited = false;
		}
	}

	int getAdjUnvisited(int v)
	{
		for (int i = 0; i < vertexCount; i++)
		{
			if (vertexList[i]->visited==false && adjMatrix[v][i] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};

