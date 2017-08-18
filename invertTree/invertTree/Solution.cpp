#include "Solution.h"



int main()
{
	Solution solution;
	TreeNode n1(4);
	TreeNode n2(2);
	TreeNode n3(7);
	TreeNode n4(1);
	TreeNode n5(3);
	TreeNode n6(6);
	TreeNode n7(9);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;
	solution.displayTree(&n1);
	solution.invertTree(&n1);
	cout << endl;
	solution.displayTree(&n1);
	return 0;
}
