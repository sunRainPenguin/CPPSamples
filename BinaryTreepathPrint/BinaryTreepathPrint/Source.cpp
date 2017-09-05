#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
	Solution solution;
	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	//TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	//TreeNode* node6 = new TreeNode(6);
	//TreeNode* node7 = new TreeNode(7);
	root->left = node2;
	root->right = node3;
	node2->left = node5;
	//node2->right = node4;
	//node5->left = node6;
	//node5->right = node7;

	vector<string> result = solution.binaryTreePaths(root);
	for (int i = 0; i<result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
