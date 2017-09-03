#include "Solution.h"

int main()
{
	int input;
	Solution solution;
	while (cin>>input)
	{
		cout << solution.largestPalindrome(input);
	}
	return 0;
}