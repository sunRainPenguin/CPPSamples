#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Vertex
{
public:
	string label;
	int indgree;
	Vertex(string label)
	{
		this->label = label;
		this->indgree = 0;
	}
};

class Graph
{
public:
	int maxVertexNum = 20;
	Vertex* vertexList[20];
	int adjMatrix[20][20];
	int vertexNum;
	queue<int> vQueue;
	Graph()
	{
		this->vertexNum = 0;
		for (int i = 0; i < maxVertexNum; i++)
		{
			vertexList[i] = nullptr;
		}
	}

	void addVertex(string label)
	{
		vertexList[vertexNum++] = new Vertex(label);
	}

	void addEdge(int start, int end)
	{
		adjMatrix[start][end] = 1;
		vertexList[end]->indgree++;
	}

	void displayVertex(int v)
	{
		cout << vertexList[v]->label << endl;
	}

	vector<int> getAdjVertex(int v)
	{
		vector<int> vList;
		for (int i = 0; i < vertexNum; i++)
		{
			if (adjMatrix[v][i] == 1)
			{
				vList.push_back(i);
			}
		}
		return vList;
	}

	void topologicalSort()
	{
		for (int i = 0; i < vertexNum; i++)
		{
			if (vertexList[i]->indgree == 0)
			{
				vQueue.push(i);
			}
		}
		int v1 = -1;
		int v2 = -1;
		vector<int> vList;
		while (!vQueue.empty())
		{
			v1 = vQueue.front();
			vQueue.pop();
			displayVertex(v1);
			vList = getAdjVertex(v1);
			for (int i = 0; i < vList.size(); i++)
			{
				v2 = vList[i];
				if (--vertexList[v2]->indgree == 0)		
				{
					vQueue.push(v2);
				}
			}
		}
	}
};

