#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
    Solution* s = new Solution();
    cout << s->compareVersion("1.0.1","1.0.2") << endl;
    return 0;
}
