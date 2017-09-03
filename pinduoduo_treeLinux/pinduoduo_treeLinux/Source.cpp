#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
	int ID;
	int parent;
	string name;
	bool isEnd;
	string prefix;
	vector<Node*> children;
};

bool compare_dec(const Node* a, const Node* b)
{
	return a->name > b->name;
}

bool compare_inc(const Node* a, const Node* b)
{
	return a->name < b->name;
}

int main()
{
	int num = 0;
	int count = 0;
	vector<Node*> vecNode;
	Node* node = NULL;
	Node* root = NULL;
	while (cin >> num)
	{
		vecNode.clear();
		count = 0;
		while (count<num)
		{
			node = new Node();
			cin >> node->name >> node->parent;
			node->ID = count;
			node->isEnd = false;
			vecNode.push_back(node);
			count++;
		}

		// root
		for (int i = 0; i < vecNode.size(); i++)
		{
			if (vecNode[i]->parent == -1)
			{
				root = vecNode[i];
			}
		}
		
		// ½¨Ê÷
		queue<Node*> queueNode;
		queueNode.push(root);
		Node* curr = NULL;
		while (!queueNode.empty())
		{
			curr = queueNode.front();
			queueNode.pop();
			for (int i = 0; i < vecNode.size(); i++)
			{
				if (vecNode[i]->parent == curr->ID)
				{
					curr->children.push_back(vecNode[i]);
				}
			}
			sort(curr->children.begin(), curr->children.end(), compare_dec);
			for (int i = 0; i < curr->children.size(); i++)
			{
				queueNode.push(curr->children[i]);
			}
			if (!curr->children.empty())
			{
				curr->children[0]->isEnd = true;
			}
		}

		// Êä³ö
		stack<Node*> stackNode;
		sort(root->children.begin(), root->children.end(), compare_inc);
		root->prefix = "";
		cout << root->name << endl;
		for (int i = 0; i < root->children.size(); i++)
		{
			root->children[i]->prefix = "";
			if (root->children[i]->isEnd)
			{
				cout << "!--" << root->children[i]->name << endl;
			}
			else
			{
				cout << "|--" << root->children[i]->name << endl;
			}
			for (int j = 0; j < root->children[i]->children.size(); j++)
			{
				stackNode.push(root->children[i]->children[j]);
			}
		}
		

		while (!stackNode.empty())
		{
			curr = stackNode.top();
			stackNode.pop();

			curr->prefix = vecNode[curr->parent]->prefix;
			if (vecNode[curr->parent]->isEnd)
			{
				curr->prefix = curr->prefix + "\t";
			}
			else
			{
				curr->prefix = curr->prefix + "|\t";
			}
			cout << curr->prefix;

			if (curr->isEnd)
			{
				cout << "!--" << curr->name << endl;
			}
			else
			{
				cout << "|--" << curr->name << endl;
			}

			for (int i = 0; i < curr->children.size(); i++)
			{
				stackNode.push(curr->children[i]);
			}
		}

	}
	return 0;
}
