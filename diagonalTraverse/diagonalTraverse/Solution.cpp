#include "Solution.h"


int main()
{
	Solution solution;
	vector<vector<int>> Mat = { {1,2,3},{4,5,6},{7,8,9} };
	//vector<vector<int>> Mat = { {1,2,3} };
	vector<int> result = solution.findDiagonalOrder(Mat);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}