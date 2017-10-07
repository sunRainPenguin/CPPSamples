#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
//    vector<vector<int>> input = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    vector<int> x = {};
    vector<vector<int>> input = {{}};
    int h = input.size();
    int target = 50;
    Solution solution;
    cout << solution.searchMatrix(input, target) << endl;
    return 0;
}
