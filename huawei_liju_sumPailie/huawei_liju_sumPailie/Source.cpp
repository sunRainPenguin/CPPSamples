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
	int n,sum;	// n-Ŀ�꣬sum-���ڼ������ʱ����
	int num,index;		// num-ÿһ��ĸ���,index-���ڼ�����
	Node* curr = NULL;		// ��ǰ�ڵ�
	queue<Node*> q;	
	int result;		// ���

	// ����
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
			// ����һ�����ֱ���һ��
			num = num * 2;		// ÿ���������
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