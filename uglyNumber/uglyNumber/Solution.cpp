#include "Solution.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int input = 14;
	Solution* solution = new Solution();
	string result = solution->isUgly(input) ? "True" : "False";
	cout<< result <<endl;
	return 0;
}