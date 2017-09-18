#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
};
int main()
{
	int n,sum;	// n-目标，sum-用于计算的临时变量
	int num,index;		// num-每一层的个数,index-用于计数；
	Node* curr = NULL;		// 当前节点
	queue<Node*> q;	
	int result;		// 结果

	// 输入
	string line;
	int input;
	vector<int> inputs;
	getline(cin, line);
	istringstream stream(line);
	while (stream >> input)
		inputs.push_back(input);

	sum = 0;
	num = 1;
	result = 0;
	for (vector<int>::iterator iter = inputs.begin(); iter != inputs.end(); ++iter)
	{
		result = 0;
		if (iter == inputs.begin())
		{
			n = *iter;
		}
		else if (iter == inputs.begin()+1)
		{
			curr = new Node();
			curr->data = *iter;
			q.push(curr);
		}
		else
		{
			// 输入一个数字遍历一层
			num = num * 2;		// 每层个数倍增
			index = num;
			while (!q.empty() && index != 0)
			{
				curr = q.front();
				q.pop();

				sum = curr->data + *iter;
				curr->left = new Node();
				curr->left->data = sum;
				q.push(curr->left);
				if (sum == n)
				{
					result++;
				}
				index--;

				sum = curr->data - *iter;
				curr->right = new Node();
				curr->right->data = sum;
				q.push(curr->right);
				if (sum == n)
				{
					result++;
				}
				index--;
			}
		}
	}
	cout << result << endl;

	return 0;
}