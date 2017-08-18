#include<iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return root;
		}
		TreeNode* temp = NULL;
		temp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(temp);
		return root;
	}

	void displayTree(TreeNode* root) {
		if (root != NULL)
		{
			cout << root->val << endl;
			displayTree(root->left);
			displayTree(root->right);
		}
	}
};