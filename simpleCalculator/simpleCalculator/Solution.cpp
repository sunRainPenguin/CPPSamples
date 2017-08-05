#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	Solution* solution = new Solution();
	//string result = solution->infix2suffix(" 1 + 2 + 3 + (4 + 5 + 6) - 7 ");
	//if (result == "error")
	//{
	//	cout << "error";
	//}
	//else
	//{
	//	cout << result;
	//}
	int intResult = solution->calculate("1 + 2 + 3 + (4 + 5 + 6) - 7 ");
	return 0;
}
