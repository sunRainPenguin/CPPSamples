#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	Solution* solution = new Solution();
	vector<int> input = { 2,3,6,7 };
	vector<vector<int>> result = solution->combinationSum(input, 7);
	cout << "[" << endl;
	for each (vector<int> resultEle in result)
	{
		cout << "[";
		for each (int baseElement in resultEle)
		{
			cout << baseElement<<",";
		}
		cout << "]," << endl;
	}
	cout << "]" << endl;
	return 0;
}
