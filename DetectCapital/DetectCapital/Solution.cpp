#include "Solution.h"

int main()
{
	string input;
	Solution* solution = new Solution();
	cout << "Please enter a word:\n";
	cin >> input;
	cout << "\n";
	cout << "The usage of capitals is right or not :" << endl;
	if (solution->detectCapitalUse(input))
	{
		cout << "Right" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
}
