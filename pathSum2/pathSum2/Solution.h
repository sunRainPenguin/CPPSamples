#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum);
};

#endif // SOLUTION_H
