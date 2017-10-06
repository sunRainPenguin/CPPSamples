#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
    vector<int> input;
    int in[6] = {3,2,1,5,6,4};
    for(int i=0; i<6; i++)
    {
        input.push_back(in[i]);
    }
    Solution solution;
    cout<<solution.findKthLargest(input, 2)<<endl;
    return 0;
}
