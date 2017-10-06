#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
	vector<int> input = { 10,1,2,7,6,1,5 };
	Solution solution;
	vector<vector<int>> result = solution.combinationSum2(input, 8);
	return 0;
}
