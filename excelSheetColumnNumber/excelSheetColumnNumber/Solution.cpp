#include "Solution.h"

int main()
{
	Solution solution;
	string input;
	while (cin>>input)
	{
		cout << solution.titleToNumber(input) << endl;
	}
	return 0;
}
