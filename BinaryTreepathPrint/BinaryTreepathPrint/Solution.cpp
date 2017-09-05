#include "Solution.h"

vector<string> Solution::binaryTreePaths(TreeNode* root)
{
	vector<string> result;
	stack<TreeNode*> stackNode;
	TreeNode* curr = NULL;
	vector<int> path;
	string pathS;
	stringstream ss;
	string tempStr;
	set<TreeNode*> visited;
	if (root == NULL)
	{
		return result;
	}
	stackNode.push(root);
	path.push_back(root->val);
	visited.insert(root);
	while (!stackNode.empty())
	{
		curr = stackNode.top();
		if (curr->left != NULL && visited.find(curr->left)==visited.end())
		{
			stackNode.push(curr->left);
			path.push_back(curr->left->val);
			visited.insert(curr->left);
		}
		else if (curr->right != NULL && visited.find(curr->right)==visited.end())
		{
			stackNode.push(curr->right);
			path.push_back(curr->right->val);
			visited.insert(curr->right);
		}
		else
		{
			stackNode.pop();
			if (curr->left == NULL && curr->right == NULL)
			{
				pathS = "";
				for (int i = 0; i<path.size(); i++)
				{
					if (i != 0)
					{
						pathS.append("->");
					}
					ss.str("");
					ss << path[i];
					pathS.append(ss.str());
				}
				result.push_back(pathS);
			}
			path.pop_back();
		}
	}
	return result;
}
