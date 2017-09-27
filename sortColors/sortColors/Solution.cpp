#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	Solution sol;
	vector<int> vecI = {0};
	sol.sortColors(vecI);
	for each (int var in vecI)
	{
		cout << var << endl;
	}
	return 0;
}

