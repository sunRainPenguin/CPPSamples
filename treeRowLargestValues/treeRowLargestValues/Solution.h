#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};
};


class Solution
{
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}
		deque<TreeNode*> Q1;
		Q1.push_back(root);
		deque<TreeNode*> Q2;
		TreeNode* curr = NULL;
		int max = -1;
		bool hasNoMax = true;	// 还没遍历一层开始
		while (!Q1.empty())
		{
			while (!Q1.empty())
			{
				curr = Q1.back();
				Q1.pop_back();
				if (hasNoMax)
				{
					hasNoMax = false;
					max = curr->val;
				}
				else if(curr->val>max)
				{
					max = curr->val;
				}
				if (curr->left)
				{
					Q2.push_back(curr->left);
				}
				if (curr->right)
				{
					Q2.push_back(curr->right);
				}	
			}
			result.push_back(max);
			hasNoMax = true;
			Q1.swap(Q2);
		}
		return result;
	}
};

// 别人的做法：
// 用一个数组存储每一层的最大值，如果该层最大值已被占坑，则用当前该层上的值与该最大值比较，看是否需要更新该值
//class Solution {
//public:
//	vector<int> largestValues(TreeNode* root) {
//		vector<int> res;
//		go(root, 0, res);
//		return res;
//	}
//private:
//	void go(TreeNode* root, int deep, vector<int>& res) {
//
//		if (root == NULL) return;
//
//		if (deep == res.size()) res.push_back(root->val);
//		else
//			res[deep] = max(res[deep], root->val);
//
//		go(root->left, deep + 1, res);
//		go(root->right, deep + 1, res);
//
//	}
//};

