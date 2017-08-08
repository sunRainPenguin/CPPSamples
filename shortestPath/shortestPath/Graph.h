#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include   <algorIThm>
#include <functional>
using namespace std;

class Vertex
{
public:
	string label;
	int indgree;
	int distance;
	bool inQueue;
	Vertex(string label)
	{
		this->label = label;
		this->indgree = 0;
		this->distance = -1;
		this->inQueue = false;
	}
};

Vertex* vertexList[20];			// 比较函数不能作为类成员，否则编译不通过；所以为了方便，这个list也写成全局的
bool compare(const int &a, const int &b)
{
	return vertexList[a]->distance > vertexList[b]->distance;
}

bool   lessmark(const   int&   s1, const   int&   s2)

{

	return   s1   <   s2;

}

class Graph
{
public:
	int maxVertexNum = 20;
	int adjMatrix[20][20];
	//int distance[20];
	int path[20];
	int vertexNum;
	queue<int> vQueue;
	Graph()
	{
		this->vertexNum = 0;
		for (int i = 0; i < maxVertexNum; i++)
		{
			vertexList[i] = nullptr;
			path[i] = -1;
		}
	}

	void addVertex(string label)
	{
		vertexList[vertexNum++] = new Vertex(label);
	}

	void addEdge(int start, int end, int weight)
	{
		adjMatrix[start][end] = weight;
		vertexList[end]->indgree++;
	}

	void displayVertex(int v, int distance)
	{
		cout << vertexList[v]->label << "	" << distance << endl;
	}

	vector<int> getAdjVertex(int v)
	{
		vector<int> vList;
		for (int i = 0; i < vertexNum; i++)
		{
			if (adjMatrix[v][i] >0)
			{
				vList.push_back(i);
			}
		}
		return vList;
	}

	void getShortestPath(int s)
	{
		vertexList[s]->distance = 0;
		vQueue.push(s);
		vector<int> vList;
		int v1 = -1;
		int v2 = -1;
		while (!vQueue.empty())
		{
			v1 = vQueue.front();
			vQueue.pop();
			displayVertex(v1, vertexList[v1]->distance);
			vList = getAdjVertex(v1);
			for (int i = 0; i < vList.size(); i++)
			{
				v2 = vList[i];
				if (vertexList[v2]->distance == -1)		// 不用往回更新，因此不用inQueue来判断
				{
					vertexList[v2]->distance = vertexList[v1]->distance + 1;
					path[v2] = v1;
					vQueue.push(v2);
				}
			}
		}

		// 重置所有distance
		for (int i = 0; i < vertexNum; i++)
		{
			vertexList[i]->distance = -1;
		}
	}

	void Dijkstra(int s)
	{
		vector<int> PQVector;
		PQVector.push_back(s);
		vertexList[s]->inQueue = true;
		make_heap(PQVector.begin(), PQVector.end(), compare);
		vertexList[s]->distance = 0;
		int v1 = -1;
		int v2 = -1;
		int newDistance = -1;
		vector<int> vList;
		while (!PQVector.empty())
		{
			v1 = PQVector.front();
			pop_heap(PQVector.begin(), PQVector.end(), compare); PQVector.pop_back();
			vertexList[v1]->inQueue = false;
			vList = getAdjVertex(v1);
			for (int i = 0; i < vList.size(); i++)
			{
				v2 = vList[i];
				newDistance = vertexList[v1]->distance + adjMatrix[v1][v2];
				if (vertexList[v2]->distance == -1 || newDistance < vertexList[v2]->distance)
				{
					// 当newDistance比较小时，仍旧需要将它加入优先队列中，否则与v2邻接的结点无法更新到最小值
					vertexList[v2]->distance = newDistance;
					if (vertexList[v2]->inQueue == false)
					{
						PQVector.push_back(v2);
						vertexList[v2]->inQueue = true;
						push_heap(PQVector.begin(), PQVector.end(), compare);
					}
					else
					{
						sort_heap(PQVector.begin(), PQVector.end(), compare);
					}
					path[v2] = v1;
				}
			}
		}

		// 重置所有distance
		for (int i = 0; i < vertexNum; i++)
		{
			cout << vertexList[i]->label << "	" << vertexList[i]->distance << endl;
			vertexList[i]->distance = -1;
		}
	}
	
	void sortVec()
	{
		vector<int> vec = { 9,6,34,57,2,5,1 };
		sort(vec.begin(), vec.end(), lessmark);
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << endl;
		}
	}

	void sortHeap()
	{
		vector<int> vec = { 9,6,34,57,2,5,1 };
		make_heap(vec.begin(), vec.end(), lessmark);
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << endl;
		}
	}
};

