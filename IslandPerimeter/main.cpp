#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    Solution solution;
    cout << solution.islandPerimeter(grid) << endl;
    return 0;
}
