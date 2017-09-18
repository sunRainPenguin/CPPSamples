#pragma once
#include <vector>
using namespace std;

class SegmentTreeNode
{
public:
	int start;
	int end;
	int sum;
	SegmentTreeNode* left;
	SegmentTreeNode* right;
	SegmentTreeNode(int s, int e)
	{
		this->start = s;
		this->end = e;
		this->sum = 0;
	}
};

// build tree; update tree; get sum;
class NumArray {
private:
	SegmentTreeNode* root;

public:
	SegmentTreeNode* buildTree(vector<int> nums, int left, int right)
	{
		SegmentTreeNode* root = new SegmentTreeNode(left, right);
		if (left == right)
		{
			root->sum = nums[left];
		}
		else
		{
			int mid = (left + right) / 2;
			root->left = buildTree(nums, left, mid);
			root->right = buildTree(nums, mid + 1, right);
			root->sum = root->left->sum + root->right->sum;
		}
		return root;
	}

	void updateTree(SegmentTreeNode* root, int i, int val)
	{
		if (root->start == i && root->end == i)
		{
			root->sum = val;
			return;
		}

		int mid = (root->start + root->end) / 2;
		if (i <= mid)
		{
			updateTree(root->left, i, val);
		}
		else
		{
			updateTree(root->right, i, val);
		}
		root->sum = root->left->sum + root->right->sum;
	}

	int getSum(SegmentTreeNode* root, int i, int j)
	{
		if (root->start == i && root->end == j)
		{
			return root->sum;
		}

		int mid = (root->start + root->end) / 2;
		if (j <= mid)
		{
			return getSum(root->left, i, j);
		}
		else if (i > mid)
		{
			return getSum(root->right, i, j);
		}
		else
		{
			return getSum(root->left, i, mid) + getSum(root->right, mid + 1, j);
		}
	}

	NumArray(vector<int> nums) {
		if (nums.empty())
		{
			return;
		}
		this->root = buildTree(nums, 0, nums.size() - 1);
	}

	void update(int i, int val) {
		updateTree(this->root, i, val);
	}

	int sumRange(int i, int j) {
		return getSum(this->root, i, j);
	}
};

//class NumArray
//{
//public:
//	vector<int> tree;
//	int n;
//
//	void buildTree(vector<int> nums)
//	{
//		for (int i = n,j=0; i < tree.size(); i++)
//		{
//			tree[i] = nums[j++];
//		}
//
//		for (int i = n-1; i >0; i--)
//		{
//			tree[i] = tree[2 * i] + tree[2 * i + 1];
//		}
//	}
//
//	NumArray(vector<int> nums)
//	{
//		n = nums.size();
//		if (n > 0)
//		{
//			tree.resize(2 * nums.size());
//			buildTree(nums);
//		}
//	}
//
//	void update(int i, int val)
//	{
//		tree[i + n] = val;
//		for (int k = (i+n)/2; k > 0; k/=2)
//		{
//			tree[k] = tree[2 * k] + tree[2 * k + 1];
//		}
//	}
//
//	int sumRange(int i, int j)
//	{
//		int sum = 0;
//		for (i+=n,j+=n;  i<= j; i/=2,j/=2)
//		{
//			sum += i % 2 == 1 ? tree[i++] : 0;
//			sum += j % 2 == 0 ? tree[j--] : 0;
//		}
//		return sum;
//	}
//};
