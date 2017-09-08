#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* node3 = new TreeNode(2);
	TreeNode* node4 = new TreeNode(5);
	TreeNode* node5 = new TreeNode(3);
	TreeNode* node6 = new TreeNode(9);
	root->left = node2;
	root->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->right = node6;
	Solution solution;
	vector<int> result = solution.largestValues(root);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
