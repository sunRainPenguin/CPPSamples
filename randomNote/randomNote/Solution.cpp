#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	Solution* s = new Solution();
	cout<<s->canConstruct("a", "b")<<endl;
	cout << s->canConstruct("aa", "ab")<<endl;
	cout << s->canConstruct("aa", "aab") << endl;
	return 0;
}