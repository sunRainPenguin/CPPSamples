#include "Solution.h"

vector<vector<int>> Solution::pathSum(TreeNode* root, int sumTar)
{
	vector<vector<int>> result;
	int sum = 0;
	stack<TreeNode*> stackNode;
	TreeNode* curr = NULL;
	vector<int> path;
	set<TreeNode*> visited;
	if (root == NULL)
	{
		return result;
	}
	stackNode.push(root);
	path.push_back(root->val);
	sum = sum + root->val;
	visited.insert(root);
	while (!stackNode.empty())
	{
		curr = stackNode.top();
		if (curr->left != NULL && visited.find(curr->left) == visited.end())
		{
			stackNode.push(curr->left);
			path.push_back(curr->left->val);
			sum = sum + curr->left->val;
			visited.insert(curr->left);
		}
		else if (curr->right != NULL && visited.find(curr->right) == visited.end())
		{
			stackNode.push(curr->right);
			path.push_back(curr->right->val);
			sum = sum + curr->right->val;
			visited.insert(curr->right);
		}
		else
		{
			stackNode.pop();
			if (curr->left == NULL && curr->right == NULL && sum == sumTar)
			{
				result.push_back(path);
			}
			path.pop_back();
			sum = sum - curr->val;
		}
	}
	return result;
}
