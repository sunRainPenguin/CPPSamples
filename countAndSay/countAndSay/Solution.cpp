#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	Solution solution;
	for (int i = 1; i < 6; i++)
	{
		cout << i << " : "<< solution.countAndSay(i) << endl;
	}
	
	return 0;
}